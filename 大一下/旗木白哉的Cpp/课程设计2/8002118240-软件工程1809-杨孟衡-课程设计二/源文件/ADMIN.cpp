#include"Admin.h"
#include<iostream>
#include"Assist.h"
#include<Windows.h>
using namespace std;

void ADMIN::SetAD()
{
	for (int i = 0; i < 11; i++)
	{
		this->Admin[i] = '\0';
	}
	for (int i = 0; i < 11; i++)
	{
		this->ADP[i] = '\0';
	}
	system("cls");
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ��ʼ����ʦ�˻���" << endl;
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ��������˺�(���10���ַ�):" << endl;
	Mouse(30, 4);
	cin.width(11);
	cin >> this->Admin;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ����������루���10���ַ�����" << endl;
	Mouse(30, 7);
	cin.width(11);
	cin >> this->ADP;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ��ʼ���ɹ���2��󷵻����˵���" << endl;
	cout << "                              ����������������������������������������������������" << endl;
	Sleep(2000);
}

bool ADMIN::CheckADPS(char * c)
{
	if (strncmp(c, this->ADPS, 9) != 0)
	{
		return false;
	}
	else
		return true;
}

ADMIN::ADMIN() :Admin("0")
{
}

ADMIN::~ADMIN()
{

}

void ADMIN::ADMenu()
{
	int op;
	int j = 0;

	system("cls");
	cout << "                              ����������������������������������������������������" << endl << endl;
	cout << "                              ********************��ʦ����ģ��********************" << endl << endl;
	cout << "                              (1) ����γ���Ϣ" << endl << endl;
	cout << "                              (2) ���������Ϣ" << endl << endl;
	cout << "                              (3) �޸Ŀγ���Ϣ" << endl << endl;
	cout << "                              (4) �������" << endl << endl;
	cout << "                              (5) ɾ������" << endl << endl;
	cout << "                              (6) �˳�ϵͳ" << endl << endl;
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���������(1, 2, 3, 4, 5, 6):";
	Mouse(30, 18);
	while (1)
	{
		cin.width(1);
		cin >> op;
		j++;
		Check();
		if (j > 3)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ����������������Σ���⵽����ʹ�ñ�ϵͳ�������˳�ϵͳ��" << endl;
			cout << "                              ����������������������������������������������������" << endl;
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
			cout << "                              ����������������������������������������������������" << endl << endl;
			cout << "                              ********************ѧ������ģ��********************" << endl << endl;
			cout << "                              (1) ����γ���Ϣ" << endl << endl;
			cout << "                              (2) ���������Ϣ" << endl << endl;
			cout << "                              (3) �޸Ŀγ���Ϣ" << endl << endl;
			cout << "                              (4) �������" << endl << endl;
			cout << "                              (5) ɾ������" << endl << endl;
			cout << "                              (6) �˳�ϵͳ" << endl << endl;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ���������(1, 2, 3, 4, 5, 6):";
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
		this->Reference(1);
		break;
	}
	case 2:
	{
		this->Reference(2);
		char op[3];
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              �Ƿ����ʹ�ñ�ϵͳ������/��:" << endl;
		Mouse(30, 7);
		cin.width(3);
		cin >> op;
		Check();
		if (strcmp(op, "��") == 0)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              2��󷵻�������!" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
		else if (strcmp(op, "��") == 0)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              2����˳�ϵͳ!" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(2000);
			exit(0);
		}
		else
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ��������˳�ϵͳ��" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(1000);
			exit(0);
		}
		break;
	}
	case 3:
	{
		this->Modify();
		break;
	}
	case 4:
	{
		this->Add();
		break;
	}
	case 5:
	{
		this->Delete();
		break;
	}
	default:
	{
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              2����˳�ϵͳ��" << endl;
		Sleep(2000);
		exit(0);
	}
	}
}
