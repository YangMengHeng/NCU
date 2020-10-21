#include"Student.h"
#include<iostream>
#include"Assist.h"
#include<Windows.h>
using namespace std;

void STUDENT::SetSTU()
{
	system("cls");
	cout << "                              ——————————————————————————" << endl;
	cout << "                              初始化学生账户：" << endl;
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置你的账号(最多10个字符):" << endl;
	Mouse(30, 4);
	cin.width(11);
	cin >> this->SNumber;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置你的密码（最多10个字符）：" << endl;
	Mouse(30, 7);
	cin.width(11);
	cin >> this->STPa;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              输入你的姓名（最多10个字符）：" << endl;
	Mouse(30, 10);
	cin.width(11);
	cin >> this->SName;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置你的联系方式（最多12个字符）：" << endl;
	Mouse(30, 13);
	cin.width(13);
	cin >> this->SP;
	Check();
	this->CNum = 0;
	for (int i = 0; i < 4; i++)
	{
		this->AC[i][0] = { '\0' };
	}
	cout << "                              ——————————————————————————" << endl;
	cout << "                              初始化成功！2秒后返回主菜单！" << endl;
	cout << "                              ——————————————————————————" << endl;
	Sleep(2000);
}

STUDENT::STUDENT() :SNumber("0"), OS(0) {}

STUDENT::~STUDENT(){}

void STUDENT::STMenu()
{
	int op;
	int j = 0;

	system("cls");
	cout << "                              ——————————————————————————" << endl << endl;
	cout << "                              ********************学生功能模块********************" << endl << endl;
	cout << "                              (1) 选修课程" << endl << endl;
	cout << "                              (2) 退选已选课程" << endl << endl;
	cout << "                              (3) 查看已选课程信息" << endl << endl;
	cout << "                              (4) 查询课程信息" << endl << endl;
	cout << "                              (5) 查看个人信息" << endl << endl;
	cout << "                              (6) 退出系统" << endl << endl;
	cout << "                              ——————————————————————————" << endl;
	cout << "                              输入操作数(1, 2, 3, 4, 5, 6):";
	Mouse(30, 18);
	while (1)
	{
		cin.width(1);
		cin >> op;
		j++;
		Check();
		if (j > 3)
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              输入操作数超过三次！检测到恶意使用本系统！即将退出系统！" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(1000);
			exit(0);
		}
		if (op == 1 || op == 2 || op == 3 || op == 4 || op == 5 || op == 6)
		{
			break;
		}
		else
		{
			system("cls");
			cout << "                              ——————————————————————————" << endl << endl;
			cout << "                              ********************学生功能模块********************" << endl << endl;
			cout << "                              (1) 选修课程" << endl << endl;
			cout << "                              (2) 退选已选课程" << endl << endl;
			cout << "                              (3) 查看已选课程信息" << endl << endl;
			cout << "                              (4) 查询课程信息" << endl << endl;
			cout << "                              (5) 查看个人信息" << endl << endl;
			cout << "                              (6) 退出系统" << endl << endl;
			cout << "                              ——————————————————————————" << endl;
			cout << "                              输入操作数(1, 2, 3, 4, 5, 6):";
			Mouse(30, 18);
			cin.width(1);
			cin >> op;
			j++;
			Check();
		}
	}
	switch (op)
	{
	case 1:
	{
		this->Option();
		break;
	}
	case 2:
	{
		this->Drop();
		break;
	}
	case 3:
	{
		this->Reference(1);
		char op[3];
		cout << "                              是否继续使用本系统？（是/否）:" << endl;
		Mouse(30, 16);
		cin.width(3);
		cin >> op;
		Check();
		if (strcmp(op, "是") == 0)
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              2秒后返回主菜单!" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(2000);
			this->STMenu();
		}
		else if (strcmp(op, "否") == 0)
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              2秒后退出系统!" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(2000);
			exit(0);
		}
		else
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              输入错误！退出系统！" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(1000);
			exit(0);
		}
		break;
	}
	case 4:
	{
		this->Sear();
		break;
	}
	case 5:
	{
		this->Reference(2);
		char op[3];
		cout << "                              是否继续使用本系统？（是/否）:" << endl;
		Mouse(30, 8);
		cin.width(3);
		cin >> op;
		Check();
		if (strcmp(op, "是") == 0)
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              2秒后返回主菜单!" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(2000);
			this->STMenu();
		}
		else if (strcmp(op, "否") == 0)
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              2秒后退出系统!" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(2000);
			exit(0);
		}
		else
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              输入错误！退出系统！" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(1000);
			exit(0);
		}
		break;
	}
	default:
	{
		cout << "                              ——————————————————————————" << endl;
		cout << "                              2秒后退出系统！" << endl;
		Sleep(2000);
		exit(0);
	}
	}
}
