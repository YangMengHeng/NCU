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
	char choice;//���ڶԲ˵����ݽ���ѡ��
	string password1 = "666520";//��������ж���
	string name_1 = "hi";//�û����Ķ���
	manager a(name_1,password1);//����һ����������

	while (1)//����ѭ��
	{
		cout << "                                \n\n\n";
		cout << "-----------------------------------------\n";
		cout << "       ��ӭ����ѧԺ�ʲ�����ϵͳ      \n\n";
		cout << "             1 ����ϵͳ             \n\n";
		cout << "             2 ����             \n\n";
		cout << "             3 ����             \n\n";
		cout << "             0 �˳�ϵͳ             \n\n";
		cout << "-----------------------------------------\n";
		cout << "       ���������ѡ��";
		cin >> choice;
		
			switch (choice)
			{
			case '1':
				login();
				break;
			case '2':
				cout << "-----------------------------------------\n";
				cout << "       �������ƣ�ѧԺ�ʲ�����ϵͳ\n\n";
				cout << "       �汾��Ϣ��2.1c++������\n\n";
				cout << "       ����ʱ�䣺2019��5��21��\n\n";
				cout << "��������Ϣ�б�\n";
				cout << "-----------------------------------------\n";
				cout << "����    ѧ��\t\tרҵ\t\t�༶\n\n";
				cout << "������\t8002118230\t�������\t1809��\n\n";
				cout << "���Ϻ�\t8002118240\t�������\t1809��\n\n";
				cout << "���Ϻ�\t8002118225\t�������\t1809��\n\n";
				cout << "-----------------------------------------\n";
				cout << "           ����������";
				system("pause");
				system("cls");
				break;
			case '3':
				cout << "----------------------------------------------------\n";
				cout << "    ����Ʒ��������ģ�飬����Աģ������ͨģ�顣���У�\n";
				cout << "����Աģ�������Ʒ��ѯ������Լ���������ܣ�����ͨ\n";
				cout << "ģ�������Ʒ��ѯ�������Լ��黹�����ܡ�ͨ��������Ļ\n";
				cout << "��ʾ�����ֿ���ѡ���Ӧ���ܣ�ף���ʹ�����!\n\n";
				cout << "----------------------------------------------------\n";
				cout << "    ����Ʒ��Ϊ���飺����������½����login)�Լ���\n";
				cout << "���ࣨmanager����user�ࣩ�Ķ����Լ�Ϊ�����ݴ洢���� \n";
				cout << "�ƵĹ��ýṹ�弯�ϣ�basic����\n";
				cout << "-----------------------------------------\n";
				cout << "           ����������";
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