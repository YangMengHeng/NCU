package gundamGUI;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.BindException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class GUIWebServer {
    private Map<String,ClientInServer>  clientsMap
        = new HashMap<String,ClientInServer>();
    private static int Count = 1;

    public void setCount(int num) {
    	GUIWebServer.Count = num;
    }
    public int getCount() {
    	return GUIWebServer.Count;
    }
    public void initServer(int port) {
        ServerSocket serverSocket = null;
        ClientInServer clientInServer = null;
        Socket  socket = null;
        if (port>1024&&port<65535) {
            try {
                serverSocket = new ServerSocket(port);
            } catch (BindException e) {
            	e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            } 
        } else {
            System.out.println("The port need to be in 1024 to 65535£¡");
        }
        while (true) {
            String userName = "ÓÃ»§"+Count;
            Count++;
            try {
                socket = serverSocket.accept();
            } catch (IOException e) {
                e.printStackTrace();
            }
            clientInServer = new ClientInServer(socket, userName);
            clientsMap.put(userName, clientInServer);
            new Thread(clientInServer).start();     
            }
    }
    class ClientInServer implements Runnable{
        private Socket socket;
        InputStream in = null;
        DataInputStream din = null;
        OutputStream out = null;
        DataOutputStream dout = null;
        boolean flag = true;
        String userName;

        public ClientInServer(Socket socket, String userName) {
            this.socket = socket;
            this.userName = userName;
            try {
                in = socket.getInputStream();
                din = new DataInputStream(in);
            } catch (IOException e) {
                e.printStackTrace();
            }

        }

        @Override
        public void run() {
            String message;
            try {
                while (flag) {
                    message = din.readUTF();
                    toAllClients(message);
                }
            } catch (SocketException e) {
                flag = false;
                clientsMap.remove(userName, this);
            } catch (EOFException e) {
                flag = false;
                clientsMap.remove(userName, this);
            } catch (IOException e) {
                flag = false;
                clientsMap.remove(userName, this);
                e.printStackTrace();
            }

            if (din != null) {
                try {
                    din.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (in != null) {
                try {
                    in.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (socket != null) {
                try {
                    socket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        public void toAllClients(String message) {
            ClientInServer cs;
            String userInfo = message;
            ArrayList<ClientInServer> csList = new ArrayList<ClientInServer>();

            for (String key :clientsMap.keySet() ) {
                 cs = clientsMap.get(key);
                if (cs == this) {
                    userInfo = message;
                } else {
                    csList.add(cs);
                }
            }
            for (ClientInServer c:csList) {
                try {
                    out = c.socket.getOutputStream();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                dout = new DataOutputStream(out);
                sentMes(userInfo);              
            }
        }
        public void sentMes(String message) {
            try {
                dout.writeUTF(message);
                dout.flush();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}