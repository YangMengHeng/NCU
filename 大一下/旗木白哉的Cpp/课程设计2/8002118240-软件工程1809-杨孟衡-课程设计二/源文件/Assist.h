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
}  //����������ĺ���

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
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ���������ʧ�ܣ�������ͣ���������������" << endl;
			system("pause");
			Sleep(3000);
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              3����˳�ϵͳ��:" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(3000);
			exit(0);
		}
		else
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ��������δ֪������������ϵ������Ա��3����˳�ϵͳ��" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(3000);
			exit(0);
		}
	}
}  //����������������

inline void Mouse(short x, short y)
{
	COORD point = { x, y };//���Ҫ���õ�λ��x,y
	HANDLE Output = GetStdHandle(STD_OUTPUT_HANDLE);//ʹ��GetStdHandle(STD_OUTPUT_HANDLE)����ȡ��׼����ľ��
	SetConsoleCursorPosition(Output, point);//���ù��λ��
}  //��λ��꺯��
