#include <iostream>
#include <string>
#include "basic.h"
#include "manager.h"
#include "user.h"
#include "login.h"
#include <Windows.h>
using namespace std;

int main(void)
{
	char choice;//用于对菜单内容进行选择
	string password1 = "666520";//对密码进行定义
	string name_1 = "hi";//用户名的定义
	manager a(name_1,password1);//构造一个管理者类

	while (1)//永真循环
	{
		cout << "                                \n\n\n";
		cout << "-----------------------------------------\n";
		cout << "       欢迎进入学院资产管理系统      \n\n";
		cout << "             1 进入系统             \n\n";
		cout << "             2 关于             \n\n";
		cout << "             3 帮助             \n\n";
		cout << "             0 退出系统             \n\n";
		cout << "-----------------------------------------\n";
		cout << "       请输入你的选择：";
		cin >> choice;
		
			switch (choice)
			{
			case '1':
				login();
				break;
			case '2':
				cout << "-----------------------------------------\n";
				cout << "       程序名称：学院资产管理系统\n\n";
				cout << "       版本信息：2.1c++升级版\n\n";
				cout << "       开发时间：2019年5月21日\n\n";
				cout << "开发者信息列表：\n";
				cout << "-----------------------------------------\n";
				cout << "姓名    学号\t\t专业\t\t班级\n\n";
				cout << "王鹏云\t8002118230\t软件工程\t1809班\n\n";
				cout << "杨孟衡\t8002118240\t软件工程\t1809班\n\n";
				cout << "廖严浩\t8002118225\t软件工程\t1809班\n\n";
				cout << "-----------------------------------------\n";
				cout << "           返回主界面";
				system("pause");
				system("cls");
				break;
			case '3':
				cout << "----------------------------------------------------\n";
				cout << "    本产品包含两大模块，管理员模块与普通模块。其中，\n";
				cout << "管理员模块包含物品查询、浏览以及添加三大功能，而普通\n";
				cout << "模块包含物品查询、借用以及归还三大功能。通过输入屏幕\n";
				cout << "提示的数字可以选择对应功能，祝大家使用愉快!\n\n";
				cout << "----------------------------------------------------\n";
				cout << "    本产品分为五大块：主函数，登陆区域（login)以及两\n";
				cout << "个类（manager类与user类）的定义以及为了数据存储而设 \n";
				cout << "计的公用结构体集合（basic）。\n";
				cout << "-----------------------------------------\n";
				cout << "           返回主界面";
				system("pause");
				system("cls");
				break;
			case '0':
				cout << "   Thank you for your use!\n\n";
				cout << "   Press random button to exit.\n\n";
				system("pause");
				exit(0);
			default:
				cout << "   your input is invalid!\n";
				break;
			}
	}
	return 0;
}