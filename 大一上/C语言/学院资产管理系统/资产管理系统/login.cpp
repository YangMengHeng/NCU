#include <iostream>
#include <string>
#include "basic.h"
#include "manager.h"
#include "user.h"
#include"login.h"
using namespace std;

string massages[3] = { "620354","666520","1" };
bool checkmassage(string &mas)
{
	for (int i = 0; i <= 3; i++)
	{
		if (massages[i] == mas) return 1;
		else if (3 == i) return 0;
	}

	return 0;
}

int menu1()
{
	int o;
	int order = 0, n = 0;
	cout << "-----------------------------------------\n"
		<< "      请选择您想进行的操作：\n\n"
		<< "         1.查询物品；\n\n"
		<< "         2.物品库浏览；\n\n"
		<< "         3.物品数据添加功能；\n\n"
		<< "         4.物品借用功能；\n\n"
		<< "         5.物品归还功能；\n\n"
		<< "         6.历史记录查询；\n\n";
	cin >> order;

	while (true)
	{
		if (order < 7 || order > 0) break;
		else
		{
			cout << "      暂无此功能选项，请重新输入：\n\n";
			cin >> order;
			n++;
			if (3 == n)
			{
				cout << "-----------------------------------------\n"
					<< "         请问您想继续进入吗？\n\n"
					<< "   请注意:输入其他数字其他则视为输入2)\n\n"
					<< "          1.继续   2.退出\n\n";
				cin >> o;
				if (1 == o)
				{
					cout << "-----------------------------------------\n"
						<< "            请重新选择：\n\n"
						<< "            1.查询物品；\n\n"
						<< "            2.物品库浏览；\n\n"
						<< "            3.物品数据添加功能；\n\n"
						<< "            4.物品借用功能；\n\n"
						<< "            5.物品归还功能；\n\n"
						<< "         6.历史记录查询；\n\n";
					cin >> order;
					break;
				}
				else
				{
					exit(0);
				}
			}
		}
	}
	if (order != 1 && order != 2 && order != 3 && order != 4 && order != 5 && order != 6)
	{
		cout << "     警告:多次输入错误，请退出重试(按任意键退出)！";
		system("pause");
		exit(0);
	}
	return order;
}
int menu2()
{
	int o;
	int order = 0, n = 0;

	cout << "-----------------------------------------\n"
		<< "      请选择您想进行的操作：\n\n"
		<< "         1.查询物品；\n\n"
		<< "         2.物品借用功能；\n\n"
		<< "         3.物品归还功能；\n\n";
	cin >> order;

	while (order < 4 || order > 0)
	{
		if (order <= 3 && order >= 1)
		{

			order += 6;
			break;
		}
		else
		{
			cout << "     暂无此功能选项，请重新输入：\n\n";
			cin >> order;
			n++;
			if (3 == n)
			{
				cout << "     请问您想继续进入吗？(请注意，输入1将继续执行程序，输入其他数字其他则视为输入2)\n\n";
				cout << "        1.继续   2.退出\n";
				cin >> o;
				if (1 == o)
				{
					cout << "       请重新选择：\n\n"
						<< "       1.查询物品；\n\n"
						<< "       2.物品库浏览；\n\n"
						<< "       3.物品数据添加功能；\n\n";
					cin >> order;
					order = order + 6;
					break;
				}
				else
				{
					exit(0);
				}
			}
		}
	}
	if (order != 7 && order != 8 && order != 9)
	{
		cout << "-----------------------------------------\n";
		cout << "     警告:多次输入错误，请退出重试(请按任意键退出)！";
		system("pause");
		exit(0);
	}
	return order;
}

int login1()
{
	int o;
	int order = 0, n = 0;
	cout << "-----------------------------------------\n"
		<< "      请选择您想要的使用模式：\n\n"
		<< "           1.管理员模式\n\n"
		<< "           2.普通模式\n\n";
	cin >> order;
	while (order != 1 && order != 2)
	{
		cout << "-----------------------------------------\n"
			<< "     未能识别指令，请重新选择：\n\n"
			<< "     1.管理员模式   2.普通模式\n\n";
		cin >> order;
		n++;
		if (3 == n)
		{
			cout << "     请问您想继续进入吗？(请注意，输入1将继续执行程序，输入其他数字其他则视为输入2)\n\n";
			cout << "     1.继续   2.退出\n\n";
			cin >> o;
			if (1 == o)
			{
				cout << "-----------------------------------------\n";
				cout << "            请重新选择：\n\n"
					<< "     1.管理员模式   2.普通模式\n\n";
				cin >> order;
				break;
			}
			else
			{
				exit(0);
			}
		}
	}

	if (order != 1 && order != 2)
	{
		cout << "     警告:多次输入错误，请退出重试(请按任意键退出)！";
		system("pause");
		exit(0);
	}
	return order;
}
void login()
{
	string m;
	int c = login1(), order1(0), n(0);
	if (1 == c)
	{
		cout << "      请输入密码(请注意，您只有三次机会)：";
		cin >> m;
		system("cls");
		while (1)
		{
			if (checkmassage(m))
			{
				order1 = menu1();
				break;
			}
			else if (2 == n)
			{
				cout << "-----------------------------------------\n";
				cout << "Sorry,密码错误三次，请确认密码后再重新进入\n\n";
				system("pause");
				exit(0);//退出函数；
			}
			else
			{
				cout << "密码输入错误，请重新输入：";
				cin >> m;
				n++;
			}
		}
	}
	else if (2 == c)
	{
		system("cls");
		order1 = menu2();
	}

	if (order1 > 0 && order1 <= 5)
	{
		string a = "wpy";
		manager man(a, massages[1]);
		switch (order1)
		{
		case 0:
			break;
		case 1:
			man.search();//查询模块
			break;
		case 2:
			man.Reference();//浏览模块
			break;
		case 3:
			man.change();//数据添加
			break;
		case 4:
			man.Borrow();//借用模块
			break;
		case 5:
			man.Return();//归还模块
			break;
		case 6:
			//历史记录
			break;
		}
	}
	else if (order1 > 5 && order1 <= 8)
	{
		string name = "lyh";
		user use2(name);
		system("cls");
		switch (order1)
		{
		case 0:
			break;
		case 7:
			use2.search();//查询模块
			break;
		case 8:
			use2.Borrow();//借用模块
			break;
		case 9:
			use2.Return();//归还模块
			break;
		}
	}
}
