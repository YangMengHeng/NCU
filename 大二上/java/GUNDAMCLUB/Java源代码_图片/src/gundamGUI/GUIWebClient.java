package gundamGUI;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.Frame;
import java.awt.TextArea;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.sql.Date;
import java.text.SimpleDateFormat;

public class GUIWebClient extends Frame {
    private TextField textFieldContent = new TextField();
    private TextArea textAreaContent = new TextArea();
    private Socket socket = null;
    private OutputStream out = null;
    private DataOutputStream dout = null;
    private InputStream in = null;
    private DataInputStream din = null;
    private boolean flag = false;
    private String Name;
    
    public GUIWebClient(String name) {
    	this.Name = name;
    }
    public void init() {
    	this.setBounds(650, 400, 500, 400);
        setVisible(true);
        setTitle("GundamChatRoom");

        textAreaContent.setBackground(Color.LIGHT_GRAY);
        textAreaContent.setEditable(false);
        this.add(textAreaContent);
        this.add(textFieldContent, BorderLayout.SOUTH);
        textAreaContent.setFocusable(false);
        textAreaContent.setFont(new Font("¿¬Ìå", Font.BOLD, 20));

        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                disconnect();
                closew();
            }
        });
        textFieldContent.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                Click();
            }
        });

        this.Connect();
        new Thread(new ReciveMessage()).start();
    }

    private class ReciveMessage implements Runnable {
        @Override
        public void run() {
            String time = new SimpleDateFormat("h:m:s").format(new Date(System.currentTimeMillis()));
            flag = true;
            try {
                while (flag) {
                    String message = din.readUTF();
                    String mess = time + ":\n" + message + "\n";
                    textAreaContent.append(mess);
                }
            } catch (EOFException e) {
                flag = false;
            } catch (SocketException e) {
                flag = false;
            } catch (IOException e) {
                flag = false;
                e.printStackTrace();
            }
        }
    }

    private void Click() {
        String message = textFieldContent.getText().trim();
        if (message != null && !message.equals("")) {
            String time = new SimpleDateFormat("h:m:s").format(new Date(System.currentTimeMillis()));
            textAreaContent.append(time + "\nI say:" + message + "\n");
            message = GUIShop.userName + ":" + textFieldContent.getText().trim();
            textFieldContent.setText("");
            sendMessageToServer(message);
        }
    }

    public void sendMessageToServer(String message) {
        try {
            dout.writeUTF(message);
            dout.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void Connect() {
        try {
            socket = new Socket("localhost", 4008);
            out = socket.getOutputStream();
            dout = new DataOutputStream(out);
            in = socket.getInputStream();
            din = new DataInputStream(in);
        } catch (UnknownHostException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void disconnect() {
        flag = false;
        if (dout != null) {
            try {
                dout.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        if (out != null) {
            try {
                out.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        if (socket != null) {
            try {
                socket.close();
            } catch (IOException e) {
                e.printStackTrace();
            };
        }
    }
    public void setName(String name) {
    	this.Name = name;
    }
    public void closew() {
    	this.dispose();
    }
}