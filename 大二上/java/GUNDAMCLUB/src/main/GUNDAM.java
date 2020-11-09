package main;

import gundamGUI.GUILoginRegister;
import gundamGUI.GUIWebServer;

public class GUNDAM {
	public static void main(String[] args) {
		GUILoginRegister mainbody = new GUILoginRegister();
		mainbody.validate();
		GUIWebServer gwe = new GUIWebServer();
		gwe.initServer(4008);
	}
}
