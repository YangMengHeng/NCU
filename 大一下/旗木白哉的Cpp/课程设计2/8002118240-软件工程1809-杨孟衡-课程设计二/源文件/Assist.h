#pragma once
#include<iostream>
#include<fstream>
#include<istream>
#include<ostream>
#include<Windows.h>
#include"Admin.h"
#include"Student.h"
#include"Course.h"
#include"BaseCourse.h"
using namespace std;

void Register();
void Login();
void Help();
void Menu();

inline const bool SYNC()
{
	if (cin.sync() == 0) return 0;
	else { cout << "Error!" << endl; throw 1; }
}  //清除缓冲区的函数

inline void Check()
{
	try
	{
		SYNC();
	}
	catch (int Eng)
	{
		if (Eng == 1)
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              缓冲区清空失败！程序暂停！按任意键继续！" << endl;
			system("pause");
			Sleep(3000);
			cout << "                              ——————————————————————————" << endl;
			cout << "                              3秒后退出系统！:" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(3000);
			exit(0);
		}
		else
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              函数调用未知错误发生！请联系开发人员！3秒后退出系统！" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(3000);
			exit(0);
		}
	}
}  //检查清除缓冲区函数

inline void Mouse(short x, short y)
{
	COORD point = { x, y };//光标要设置的位置x,y
	HANDLE Output = GetStdHandle(STD_OUTPUT_HANDLE);//使用GetStdHandle(STD_OUTPUT_HANDLE)来获取标准输出的句柄
	SetConsoleCursorPosition(Output, point);//设置光标位置
}  //定位光标函数
