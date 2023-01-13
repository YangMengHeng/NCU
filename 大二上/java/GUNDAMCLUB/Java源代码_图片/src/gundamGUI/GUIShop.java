package gundamGUI;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Desktop;
import java.awt.Dialog;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.Label;
import java.awt.Panel;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.net.URI;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import gundamTools.GundamGUITools;
import gundamdata.Admin;
import gundamdata.Shop;
import gundamdata.User;
import gundamdata.gundamData;

public class GUIShop extends JFrame{
	//JLabel, title
	private Label Title;
	//Button, Link, exit, search, user, charge
	private Button charge;
	private Button search;
	private Button Link;
	private Button EXIT;
	private Button user;
	private Button chat;
	//Shop connectors
	private gundamData gd;
	//BorderLayout br
	private BorderLayout br;
	//current User Number
	private int num;
	public static String userName;
	
	public GUIShop(int num) {
		JPanel p = new JPanel();
		this.setSize(GundamGUITools.getScreenWidth() - 100, GundamGUITools.getScreenHeight());
		this.setResizable(false);
		
		gundamData gd2 = new gundamData("user");
		this.userName = gd2.user.get(num).getUserName();
		this.num = num;
		this.gd = new gundamData("gundamprc");
		this.br = new BorderLayout();
		this.Title = new Label("SHOP");
		this.search = new Button("Search");
		this.Link = new Button("Link");
		this.EXIT = new Button("EXIT");
		this.user = new Button("PersonalPage");
		this.charge = new Button("Charge");
		this.chat = new Button("Chat");
		
		this.chat.setFont(new Font("Times New Roman", Font.BOLD, 30));
		this.charge.setFont(new Font("Times New Roman", Font.BOLD, 30));
		this.Title.setFont(new Font("Times New Roman", Font.BOLD+Font.ITALIC, 40));
		this.search.setFont(new Font("Times New Roman", Font.BOLD, 30));
		this.Link.setFont(new Font("Times New Roman", Font.BOLD, 30));
		this.EXIT.setFont(new Font("Times New Roman", Font.BOLD, 30));
		this.user.setFont(new Font("Times New Roman", Font.BOLD, 30));
		this.Title.setAlignment(FlowLayout.CENTER);
		this.br.setVgap(20);
		this.setLayout(br);
		this.setTitle("Shop");
		FlowLayout fl = new FlowLayout(FlowLayout.CENTER);
		p.setLayout(fl);
		p.add(this.chat);
		p.add(this.charge);
		p.add(this.search);
		p.add(this.user);
		p.add(this.Link);
		p.add(this.EXIT);
		this.add(this.Title, BorderLayout.NORTH);
		this.add(p, BorderLayout.SOUTH);
		this.add(getCenterp(), BorderLayout.CENTER);
		GundamGUITools.setTitleImage(this, "images/Icon.png");
		
		this.chat.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent act) {
				CHAT();
			}
		});
		this.charge.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent act) {
				CHARGE();
			}
		});
		this.Link.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent act) {
				LINK();
			}
		});
		this.user.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent act) {
				USER();
			}
		});
		this.search.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent act) {
				SEARCH();
			}
		});
		this.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent we) {
				CLOSE();
			}
		});
		this.EXIT.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent act) {
				CLOSE();
			}
		});
	}
	public JPanel getCenterp() {
		JPanel p = new JPanel();
		JLabel[] shopp;
		shopp = new JLabel[Shop.Count + 1];
		shopP[] sp = new shopP[Shop.Count + 1];
		FlowLayout fl = new FlowLayout(FlowLayout.LEFT);
	
		p.setSize(1600, 900);
		
		
		for(int i = 0 ; i < Shop.Count; i++) {
			Shop so = gd.shop.get(i);
			String t = "photos/" + so.getIdentifier() + ".jpg";
			ImageIcon ico = new ImageIcon(t);
			shopp[i] = new JLabel(ico);
			shopp[i].setBorder(BorderFactory.createBevelBorder(1));
			sp[i] = new shopP(shopp[i]);
			p.add(sp[i]);
			
			sp[i].browse.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent act) {
					BROWSE(so);
				}
			});
		}
	
		return p;
	}
	public void CHAT() {
		GUIWebClient gwc = new GUIWebClient(GUIUser.Name);
		gwc.init();
	}
	public void CHARGE() {
		OnlineCharge oc = new OnlineCharge(null, false);
		oc.setVisible(true);
	}
	public void SHOPDialog(Shop s) {
		SHOP sp = new SHOP(null, true, s, this.num);
		sp.setVisible(true);
	}
	public void CLOSE() {
		this.dispose();
	}
	public void BROWSE(Shop sh) {
		SHOP sp = new SHOP(null, false, sh, num);
		sp.setVisible(true);
	}
	public void LINK() {
		Desktop dst = Desktop.getDesktop();
		try {
			dst.browse(new URI("https://www.taobao.com/"));
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	public void SEARCH() {
		Search sch = new Search(null, true, num);
		sch.setVisible(true);
	}
	public void USER() {
		GUIUser us = new GUIUser(this.num);
		this.setVisible(false);
		us.setVisible(true);
		CLOSE();
	}
	class shopP extends JPanel{
		public Button browse;
		public BorderLayout brl;
		
		public shopP(JLabel t) {
			this.setSize(300, 320);
			this.browse = new Button("Browse");
			this.browse.setFont(new Font("Times New Roman", Font.BOLD, 20));
			this.brl = new BorderLayout();
			this.brl.setVgap(0);
			this.setLayout(brl);
			this.add(this.browse, BorderLayout.SOUTH);
			this.add(t, BorderLayout.NORTH);
		}
	}
}

class SHOP extends JDialog{
	private Shop sh;
	//Button, buy good, cancel
	private Button buy;
	private Button cancel;
	//Label, ProductArea, Seller, Series, Gundam, Identifier, Proportion, ProductCapacity, Price, Camp, picture
	private Label proArea;
	private Label seller;
	private Label series;
	private Label gundam;
	private Label id;
	private Label pro;
	private Label proCapacity;
	private Label price;
	private Label camp;
	private Label title;
	private JLabel picture;
	private BorderLayout br;
	//current user number
	private int num;
	
	public SHOP(JFrame upper, boolean sign, Shop sh, int num) {
		super(upper, sign);
		this.sh = sh;
		this.num = num;
		this.setTitle(sh.getIdentifier() + " " + sh.getGundam());
		this.setSize(800, 800);
		GundamGUITools.center(this);
		GundamGUITools.setTitleImage(this, "images/Icon.png");
		
		this.Initialize();
		this.addComponent();
		this.addListener();
	}
	public void Initialize() {
		this.buy = new Button("Buy");
		this.cancel = new Button("Cancel");
		
		this.proArea = new Label("ProductArea:" + sh.getProductArea());
		this.seller = new Label("Seller:" + sh.getBrand());
		this.series = new Label("Series:" + sh.getSeries());
		this.gundam = new Label("Gundam:" + sh.getGundam());
		this.id = new Label("IDentifier" + sh.getIdentifier());
		this.pro = new Label("Proportion:" + sh.getProportion());
		this.proCapacity = new Label("Capacity:" + sh.getProductCapacity());
		this.price = new Label("Price:" + sh.getPrice());
		this.title = new Label(sh.getGundam());
		if(sh.getCamp() == 1) {
			this.camp = new Label("Camp:free");
		}
		else this.camp = new Label("Camp:fee");
		String t = "photos/" + sh.getGundam() + ".jpg";
		ImageIcon ico = new ImageIcon(t);
		picture = new JLabel(ico);
		picture.setBorder(BorderFactory.createEtchedBorder(1));
		
		this.br = new BorderLayout();
		br.setHgap(10);
		this.setLayout(br);
		
		this.buy.setFont(new Font("楷体", Font.BOLD, 20));
		this.cancel.setFont(new Font("楷体", Font.BOLD, 20));
		this.proArea.setFont(new Font("楷体", Font.BOLD, 20));
		this.seller.setFont(new Font("楷体", Font.BOLD, 20));
		this.series.setFont(new Font("楷体", Font.BOLD, 20));
		this.gundam.setFont(new Font("楷体", Font.BOLD, 20));
		this.id.setFont(new Font("楷体", Font.BOLD, 20));
		this.pro.setFont(new Font("楷体", Font.BOLD, 20));
		this.proCapacity.setFont(new Font("楷体", Font.BOLD, 20));
		this.price.setFont(new Font("楷体", Font.BOLD, 20));
		this.camp.setFont(new Font("楷体", Font.BOLD, 20));
		this.title.setFont(new Font("楷体", Font.BOLD, 30));
		this.title.setAlignment(FlowLayout.CENTER);
		this.proArea.setAlignment(FlowLayout.CENTER);
		this.seller.setAlignment(FlowLayout.CENTER);
		this.series.setAlignment(FlowLayout.CENTER);
		this.gundam.setAlignment(FlowLayout.CENTER);
		this.id.setAlignment(FlowLayout.CENTER);
		this.pro.setAlignment(FlowLayout.CENTER);
		this.proCapacity.setAlignment(FlowLayout.CENTER);
		this.price.setAlignment(FlowLayout.CENTER);
		this.camp.setAlignment(FlowLayout.CENTER);
	}
	public void addComponent() {
		Panel p = new Panel();
		GridLayout gr = new GridLayout(0, 1);
		
		gr.setVgap(10);
		p.add(this.buy);
		p.add(this.cancel);
		
		this.add(this.title, BorderLayout.NORTH);
		this.add(p, BorderLayout.SOUTH);
		p = new Panel();
		p.setLayout(gr);
		p.add(this.proArea);
		p.add(this.seller);
		p.add(this.series);
		p.add(gundam);
		p.add(id);
		p.add(pro);
		p.add(proCapacity);
		p.add(price);
		p.add(camp);
		this.add(p, BorderLayout.WEST);
		this.add(this.picture, BorderLayout.CENTER);
	}
	public void addListener() {
		this.buy.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent act) {
				BUY();
			}
		});
		this.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent we) {
				dis();
			}
		});
		this.cancel.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent act) {
				dis();
			}
		});
	}
	public void BUY() {
		if(sh.getProductCapacity() <= 0) {
			GUIDialogError gde = new GUIDialogError("BuyFailure", " The good doesn't have capacity!"
					+ " Pls check your account!");
			return;
		}
		String name = sh.getBrand();
		gundamData gd = new gundamData(true);
		Admin ad;
		User us = gd.user.get(num);
		
		for(int i = 0;i < Admin.Count; i++) {
			ad = gd.admin.get(i);
			String t = ad.getAdminName();
			int mon = us.getUserMoney();
			if(t.equals(name) && mon >= sh.getPrice()) {
				us.setUserMoney(mon - sh.getPrice());
				ad.setCapital(ad.getCapital() + sh.getPrice());
				t = sh.getGundam() + "\n\r";
				us.setGoods(us.getGoods() + t);
				ad.setGoods(ad.getGoods() + t);
				sh.setProductCapacity(sh.getProductCapacity() - 1);
				this.proCapacity.setText("Capacity:" + sh.getProductCapacity());
				gd.updateData(ad);
				gd.updateData(sh);
				gd.updateData(us);
				GUITips gt = new GUITips("BuySuccess", " You have been bought one for this! "
						+ "Thank you!");
				return;
			}
		}
		GUIDialogError gde = new GUIDialogError("BuyError", " You cannot buy this good!"
				+ " Pls check your account!");
	}
	public void dis() {
		this.dispose();
	}
}

class Search extends Dialog{
	public JLabel se;
	public TextField set;
	public int num;
	
	public Search(Frame up, boolean sign, int num) {
		super(up, sign);
		this.setSize(400, 150);
		this.setTitle("SearchMenu");
		this.num = num;
		GundamGUITools.center(this);
		GundamGUITools.setTitleImage(this, "images/Icon.png");
		this.se = new JLabel("GundamName:");
		this.set = new TextField(30);
		this.se.setFont(new Font("Times New Roman", Font.BOLD, 30));
		this.setLayout(new BorderLayout());
		Panel p = new Panel();
		p.add(this.se);
		p.add(this.set);
		this.add(p, BorderLayout.CENTER);
		
		this.set.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent act) {
				searching();
			}
		});
		this.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent we) {
				close();
			}
		});
	}
	public void searching() {
		String t = set.getText();
		gundamData gd = new gundamData("gundamprc");
		
		for(int i = 0; i < Shop.Count; i++) {
			Shop sp1 = gd.shop.get(i);
			String sname = sp1.getGundam();
			if(sname.indexOf(t) != -1) {
				SHOP sp = new SHOP(null, false, sp1, num);
				this.setVisible(false);
				sp.setVisible(true);
				close();
				return;
			}
		}
		
		GUIDialogError gde = new GUIDialogError("SearchError", "Don't have such as a good "
				+ "called the Name!");
		set.setText("");
	}
	public void close() {
		this.dispose();
	}
}