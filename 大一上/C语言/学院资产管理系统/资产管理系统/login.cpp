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
		<< "      ��ѡ��������еĲ�����\n\n"
		<< "         1.��ѯ��Ʒ��\n\n"
		<< "         2.��Ʒ�������\n\n"
		<< "         3.��Ʒ������ӹ��ܣ�\n\n"
		<< "         4.��Ʒ���ù��ܣ�\n\n"
		<< "         5.��Ʒ�黹���ܣ�\n\n"
		<< "         6.��ʷ��¼��ѯ��\n\n";
	cin >> order;

	while (true)
	{
		if (order < 7 || order > 0) break;
		else
		{
			cout << "      ���޴˹���ѡ����������룺\n\n";
			cin >> order;
			n++;
			if (3 == n)
			{
				cout << "-----------------------------------------\n"
					<< "         �����������������\n\n"
					<< "   ��ע��:��������������������Ϊ����2)\n\n"
					<< "          1.����   2.�˳�\n\n";
				cin >> o;
				if (1 == o)
				{
					cout << "-----------------------------------------\n"
						<< "            ������ѡ��\n\n"
						<< "            1.��ѯ��Ʒ��\n\n"
						<< "            2.��Ʒ�������\n\n"
						<< "            3.��Ʒ������ӹ��ܣ�\n\n"
						<< "            4.��Ʒ���ù��ܣ�\n\n"
						<< "            5.��Ʒ�黹���ܣ�\n\n"
						<< "         6.��ʷ��¼��ѯ��\n\n";
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
		cout << "     ����:�������������˳�����(��������˳�)��";
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
		<< "      ��ѡ��������еĲ�����\n\n"
		<< "         1.��ѯ��Ʒ��\n\n"
		<< "         2.��Ʒ���ù��ܣ�\n\n"
		<< "         3.��Ʒ�黹���ܣ�\n\n";
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
			cout << "     ���޴˹���ѡ����������룺\n\n";
			cin >> order;
			n++;
			if (3 == n)
			{
				cout << "     �����������������(��ע�⣬����1������ִ�г�����������������������Ϊ����2)\n\n";
				cout << "        1.����   2.�˳�\n";
				cin >> o;
				if (1 == o)
				{
					cout << "       ������ѡ��\n\n"
						<< "       1.��ѯ��Ʒ��\n\n"
						<< "       2.��Ʒ�������\n\n"
						<< "       3.��Ʒ������ӹ��ܣ�\n\n";
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
		cout << "     ����:�������������˳�����(�밴������˳�)��";
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
		<< "      ��ѡ������Ҫ��ʹ��ģʽ��\n\n"
		<< "           1.����Աģʽ\n\n"
		<< "           2.��ͨģʽ\n\n";
	cin >> order;
	while (order != 1 && order != 2)
	{
		cout << "-----------------------------------------\n"
			<< "     δ��ʶ��ָ�������ѡ��\n\n"
			<< "     1.����Աģʽ   2.��ͨģʽ\n\n";
		cin >> order;
		n++;
		if (3 == n)
		{
			cout << "     �����������������(��ע�⣬����1������ִ�г�����������������������Ϊ����2)\n\n";
			cout << "     1.����   2.�˳�\n\n";
			cin >> o;
			if (1 == o)
			{
				cout << "-----------------------------------------\n";
				cout << "            ������ѡ��\n\n"
					<< "     1.����Աģʽ   2.��ͨģʽ\n\n";
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
		cout << "     ����:�������������˳�����(�밴������˳�)��";
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
		cout << "      ����������(��ע�⣬��ֻ�����λ���)��";
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
				cout << "Sorry,����������Σ���ȷ������������½���\n\n";
				system("pause");
				exit(0);//�˳�������
			}
			else
			{
				cout << "��������������������룺";
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
			man.search();//��ѯģ��
			break;
		case 2:
			man.Reference();//���ģ��
			break;
		case 3:
			man.change();//�������
			break;
		case 4:
			man.Borrow();//����ģ��
			break;
		case 5:
			man.Return();//�黹ģ��
			break;
		case 6:
			//��ʷ��¼
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
			use2.search();//��ѯģ��
			break;
		case 8:
			use2.Borrow();//����ģ��
			break;
		case 9:
			use2.Return();//�黹ģ��
			break;
		}
	}
}
