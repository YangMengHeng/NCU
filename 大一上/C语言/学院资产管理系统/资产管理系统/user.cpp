#include "basic.h"
#include "user.h"
#include "login.h"
#include "manager.h"
#include <cmath>
#include <iostream>
#include<fstream>
#include <Windows.h>//����sleep()
using namespace std;

//��basic.h���ﹲ�ýṹ��
extern struct books book[15];
extern struct object ncupe[6];
extern struct classroom classes[15];

user::user(const string Name)
{
	name = Name;
}

void user::Return()
{
	int op;
	int i;

	cout << "-----------------------------------------\n";
	cout << "------------------�˵�-------------------\n";
	cout << "              (1)����\n\n";
	cout << "              (2)����������\n\n";
	cout << "              (3)������\n\n";
	cout << "              ���������ѡ��";
	cin >> op;
	//scanf_s("%d", &op);
	while (op != 1 && op != 2 && op != 3)
	{
		cout << "����������������룡\n";
		cout << "-----------------------------------------\n";
		cout << "------------------�˵�-------------------\n";
		cout << "              (1)����\n\n";
		cout << "              (2)����������\n\n";
		cout << "              (3)������\n\n";
		cout << "              ���������ѡ��";
		//scanf_s("%d", &op);
		cin >> op;
	}

	switch (op)
	{
	case 1:
	{
		char BookName[30];
		struct books *p = NULL;
		char Name[30];
		int exist = 0;

		ifstream is("books", ios_base::in);
		if (!is)
		{
			cout << "���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&book), sizeof(book));
		is.close();
		//readfile(1);
		cout << "-----------------------------------------\n";
		cout << "             �����������:";
		for (i = 0; i < 30; i++)
		{
			cin >> Name[i];
		}
		//scanf_s("%s", Name, 30);
		cout << "-----------------------------------------\n";
		cout << "         ��������Ҫ�黹���鼮:";
		for (i = 0; i < 30; i++)
		{
			cin >> BookName[i];
		}
		//scanf_s("%s", BookName, 30);
		p = book;
		if (p != NULL)
		{
			for (i = 0; i < 15; i++)
			{
				if (strcmp(BookName, p->book_name) == 0)
				{
					p->num++;
					exist = 1;

					ofstream os("books", ios_base::in);
					if (!os)
					{
						cout << "д���ļ�ʧ�ܣ�3����˳�����" << endl;
						Sleep(3000);
						exit(0);
					}
					os.write(reinterpret_cast<char *>(&book), sizeof(book));
					os.close();
					//writefile(1);
					cout << "-----------------------------------------\n";
					//cout << "������%s\t���ߣ�%s\t������%d\n", p->name, p->author, p->num);
					//cout << "             %s�黹%s�ɹ���\n", Name, BookName);
					cout << "������" << p->book_name << "\t���ߣ�" << p->author << "\t������" << p->num << endl;
					cout << "             " << Name << "�黹" << BookName << "�ɹ���" << endl;
					//����д�벿����Ϊ��д����ʷ��¼�ļ��Ĵ���
					string s1 = Name;
					string s2 = BookName;
					string s = s1 + s2;
					ofstream os1("RecordBooks", ios_base::in);
					if (!os1)
					{
						cout << "д���ļ�ʧ�ܣ�3����˳�����" << endl;
						Sleep(3000);
						exit(0);
					}
					os1.write(reinterpret_cast<char *>(&s), sizeof(s));
					os1.close();

					break;
				}
				p++;
			}
			if (exist == 0)
			{
				cout << "-----------------------------------------\n";
				cout << "   �������û���Ȿ�飡�˳��黹ģ�飡\n";
				break;
			}
		}
		cout << "3��󷵻�������...\n";
		Sleep(3000);
		login();
	}
	case 2:
	{
		char ObjectName[10];
		struct object *p = NULL;
		char Name[30];
		int exist = 0;

		ifstream is("object", ios_base::in);
		if (!is)
		{
			cout << "���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&ncupe), sizeof(object));
		is.close();
		//readfile(2);
		cout << "-----------------------------------------\n";
		cout << "�����������:";
		for (i = 0; i < 30; i++)
		{
			cin >> Name[i];
		}
		//scanf_s("%s", Name, 30);
		cout << "-----------------------------------------\n";
		cout << "         ��������Ҫ�黹������:";
		for (i = 0; i < 10; i++)
		{
			cin >> ObjectName[i];
		}
		//scanf_s("%s", ObjectName, 30);
		p = ncupe;
		if (p != NULL)
		{
			for (i = 0; i < 6; i++)
			{
				if (strcmp(ObjectName, p->type) == 0)
				{
					p->num++;
					exist = 1;

					ofstream os("object", ios_base::in);
					if (!os)
					{
						cout << "д���ļ�ʧ�ܣ�3����˳�����" << endl;
						Sleep(3000);
						exit(0);
					}
					os.write(reinterpret_cast<char *>(&ncupe), sizeof(object));
					os.close();
					//writefile(2);
					cout << "-----------------------------------------\n";
					//printf("���ࣺ%s\t������%d\n", p->type, p->num);
					//printf("              %s�黹%s�ɹ���\n", Name, ObjectName);
					cout << "���ࣺ" << p->type << "\t������" << p->num << endl;
					cout << "              " << Name << "�黹" << ObjectName << "�ɹ���" << endl;
					//����д�벿����Ϊ��д����ʷ��¼�ļ��Ĵ���
					string s1 = Name;
					string s2 = ObjectName;
					string s = s1 + s2;
					ofstream os1("RecordObject", ios_base::in);
					if (!os1)
					{
						cout << "д���ļ�ʧ�ܣ�3����˳�����" << endl;
						Sleep(3000);
						exit(0);
					}
					os1.write(reinterpret_cast<char *>(&s), sizeof(s));
					os1.close();

					break;
				}
				p++;
			}
			if (exist == 0)
			{
				cout << "-----------------------------------------\n";
				cout << "  �������û���������ģ��˳��黹ģ�飡\n";
				break;
			}
		}
		cout << "3��󷵻�������...\n";
		Sleep(3000);
		login();
	}
	case 3:
	{
		char ClassName[15];
		struct classroom *p = NULL;
		char Name[30];
		int exist = 0;

		ifstream is("classroom", ios_base::in);
		if (!is)
		{
			cout << "���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&classes), sizeof(classroom));
		is.close();
		//readfile(3);
		cout << "-----------------------------------------\n";
		cout << "             �����������:";
		for (i = 0; i < 30; i++)
		{
			cin >> Name[i];
		}
		//scanf_s("%s", Name, 30);
		cout << "-----------------------------------------\n";
		cout << "          ��������Ҫ�黹�Ľ���:";
		for (i = 0; i < 15; i++)
		{
			cin >> ClassName[i];
		}
		//scanf_s("%s", ClassName, 30);
		p = classes;
		if (p != NULL)
		{
			for (i = 0; i < 15; i++)
			{
				if (strcmp(ClassName, p->name) == 0)
				{
					p->statu = 1;
					exist = 1;

					ofstream os("classroom", ios_base::in);
					if (!os)
					{
						cout << "д���ļ�ʧ�ܣ�3����˳�����" << endl;
						Sleep(3000);
						exit(0);
					}
					os.write(reinterpret_cast<char *>(&classes), sizeof(book));
					os.close();
					//writefile(3);
					cout << "-----------------------------------------\n";
					//printf("¥�㣺%d\t��ţ�%s\t״̬��%d\n", p->floor, p->name, p->statu);
					//printf("              %s�黹%s�ɹ���\n", Name, ClassName);
					cout << "¥��: " << p->floor << "\t��ţ�" << p->name << "\t״̬��" << p->statu << endl;
					cout << "              " << Name << "�黹" << ClassName << "�ɹ�!" << endl;
					//����д�벿����Ϊ��д����ʷ��¼�ļ��Ĵ���
					string s1 = Name;
					string s2 = ClassName;
					string s = s1 + s2;
					ofstream os1("RecordClassroom", ios_base::in);
					if (!os1)
					{
						cout << "д���ļ�ʧ�ܣ�3����˳�����" << endl;
						Sleep(3000);
						exit(0);
					}
					os1.write(reinterpret_cast<char *>(&s), sizeof(s));
					os1.close();
					break;
				}
				p++;
			}
			if (exist == 0)
			{
				cout << "-----------------------------------------\n";
				cout << "  �������û�������ң��˳��黹ģ�飡\n";
				break;
			}
		}
		cout << "3��󷵻�������...\n";
		Sleep(3000);
		login();
	}
	}
}//�黹����

void user::search()
{
	int i, j, k;
	int flag = 0;
	char str[20];

	char str2[20];

	FILE *fp;
	errno_t err;
	int choice;
	cout << "-----------------------------------------\n"
		<< "            1 �鼮             \n\n"
		<< "            2 ��������         \n\n"
		<< "            3 ����             \n\n"
		<< "            0 �˳�ϵͳ         \n\n"
		<< "            ���������ѡ��";
	cin >> choice;
	switch (choice)
	{
	case 1:
		if ((err = fopen_s(&fp, "books.txt", "r")) != 0)
		{
			printf("�޷��򿪴��ļ�\n\n");
		}
		fread(book, sizeof(struct books), 15, fp);

		cout << "-----------------------------------------\n";
		cout << "  ������Ҫ���ҵ��鼮(�������鼮����)��";
		cin >> str2;
		for (i = 0; i < 15; i++)
		{
			for (k = 0, j = 0; book[i].book_name[k] != '\0' && str2[j] != '\0';)
			{
				if (book[i].book_name[k] == str2[j])
				{
					k++;
					j++;
				}
				else
				{
					k++;
					j = 0;
				}
			}
			if (str2[j] == '\0')
			{
				cout << "-----------------------------------------\n";
				cout << "  ������" << book[i].book_name << "  ��棺" << book[i].num << "��" << endl;
				flag++;
			}
		}
		if (!flag)
		{
			cout << "-----------------------------------------\n";
			cout << "              not found!\n";
		}
		break;
	case 2:
		if ((err = fopen_s(&fp, "object.txt", "r")) != 0)
		{
			cout << "�޷��򿪴��ļ�\n\n";
		}
		fread(ncupe, sizeof(struct object), 6, fp);
		cout << "-----------------------------------------\n";
		cout << "          ��������Ҫ�ҵ��������ͣ�";
		cin >> str;
		for (i = 0; i < 6; i++)
		{
			for (k = 0, j = 0; ncupe[i].type[k] != '\0' && str[j] != '\0';)
			{
				if (ncupe[i].type[k] == str[j])
				{
					k++;
					j++;
				}
				else
				{
					k++;
					j = 0;
				}
			}
			if (str[j] == '\0')
			{
				cout << "-----------------------------------------\n";
				cout << "���ҵ������ģ� " << ncupe[i].type << ", �������" << ncupe[i].num << endl;
				flag++;
			}
		}
		if (!flag)
		{
			cout << "-----------------------------------------\n"
				<< "             not found!\n";
		}
		break;
	case 3:
		if ((err = fopen_s(&fp, "classroom.txt", "r")) != 0)
		{
			cout << "�޷��򿪴��ļ�\n\n";
		}
		fread(classes, sizeof(struct classroom), 15, fp);
		cout << "-----------------------------------------\n";
		cout << "        ����Ҫ���ҵĽ���������106����\n\n";
		cin >> str;
		for (i = 0; i < 15; i++)
		{
			for (k = 0, j = 0; classes[i].name[k] != '\0' && str[j] != '\0';)
			{
				if (classes[i].name[k] == str[j])
				{
					k++;
					j++;
				}
				else
				{
					k++;
					j = 0;
				}
			}
			if (str[j] == '\0')
			{
				cout << "--------------------------------------------------------------\n";
				cout << "         ¥��\t������\t״̬\n\n";
				cout << "������Ϣ��" << classes[i].floor << "\t" << classes[i].name << "\t";
				if (classes[i].statu == 1)
					cout << "�ɽ���\n\n";
				else cout << "���ɽ���\n\n";
				flag++;
			}
		}
		if (!flag)
		{
			cout << "-----------------------------------------\n";
			cout << "             not found!\n";
		}
		break;
	case 0:
		cout << "-----------------------------------------\n";
		cout << "                ллʹ��";
		exit(0);
	}
	cout << "-----------------------------------------\n";
	cout << "           ����������";
	system("pause");
	system("cls");
}//��������

void user::Borrow()
{
	int op;
	int i;

	cout << "-----------------------------------------\n";
	cout << "------------------�˵�-------------------\n";
	cout << "              (1)����\n\n";
	cout << "              (2)����������\n\n";
	cout << "              (3)�����\n\n";
	cout << "              ���������ѡ��";
	cin >> op;
	//scanf_s("%d", &op);
	while (op != 1 && op != 2 && op != 3)
	{
		cout << "����������������룡\n\n";
		cout << "-----------------------------------------\n";
		cout << "------------------�˵�-------------------\n";
		cout << "              (1)����\n\n";
		cout << "              (2)����������\n\n";
		cout << "              (3)�����\n\n";
		cout << "              ���������ѡ��";
		//scanf_s("%d", &op);
		cin >> op;
	}

	switch (op)
	{
	case 1:
	{
		char BookName[30];
		struct books *p = NULL;
		char Name[30];
		int exist = 0;

		ifstream is("books", ios_base::in);
		if (!is)
		{
			cout << "���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&book), sizeof(book));
		is.close();
		//readfile(1);
		cout << "-----------------------------------------\n";
		cout << "             �����������:";
		//scanf_s("%s", Name, 30);
		for (i = 0; i < 30; i++)
		{
			cin >> Name[i];
		}
		cout << "-----------------------------------------\n";
		cout << "          ��������Ҫ���ĵ��鼮:";
		for (i = 0; i < 30; i++)
		{
			cin >> BookName[i];
		}
		//scanf_s("%s", BookName, 30);
		p = book;
		if (p != NULL)
		{
			for (i = 0; i < 15; i++)
			{
				if (strcmp(BookName, p->book_name) == 0)
				{
					if (p->num == 0)
					{
						cout << "-----------------------------------------\n";
						cout << "              �����޿�棡\n";
						exist = -1;
						break;
					}
					else
					{
						p->num--;
						exist = 1;

						ofstream os("books", ios_base::in);
						if (!os)
						{
							cout << "д���ļ�ʧ�ܣ�3����˳�����" << endl;
							Sleep(3000);
							exit(0);
						}
						os.write(reinterpret_cast<char *>(&book), sizeof(book));
						os.close();
						//writefile(1);
						cout << "-----------------------------------------\n";
						cout << "����:" << p->book_name << "\t���ߣ�" << p->author << "\t����:" << p->num << endl;
						//printf("������%s\t���ߣ�%s\t������%d\n", p->name, p->author, p->num);
						cout << "             " << Name << "����" << BookName << "�ɹ���" << endl;
						//printf("             %s����%s�ɹ���\n", Name, BookName);
						//����д�벿����Ϊ��д����ʷ��¼�ļ��Ĵ���
						string s1 = Name;
						string s2 = BookName;
						string s = s1 + s2;
						ofstream os1("RecordBooks", ios_base::in);
						if (!os1)
						{
							cout << "д���ļ�ʧ�ܣ�3����˳�����" << endl;
							Sleep(3000);
							exit(0);
						}
						os1.write(reinterpret_cast<char *>(&s), sizeof(s));
						os1.close();

						break;
					}
				}
				p++;
			}
			if (exist == 0)
			{
				cout << "-----------------------------------------\n";
				cout << "    �������û���Ȿ�飡�˳�����ģ�飡\n";
				break;
			}
		}
		cout << "-----------------------------------------\n";
		cout << "         3��󷵻�������...\n";
		Sleep(3000);
		login();
	}
	case 2:
	{
		char ObjectName[10];
		struct object *p = NULL;
		char Name[30];
		int exist = 0;

		ifstream is("object", ios_base::in);
		if (!is)
		{
			cout << "���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&ncupe), sizeof(object));
		is.close();
		//readfile(2);
		cout << "-----------------------------------------\n";
		cout << "               �����������:";
		//scanf_s("%s", Name, 30);
		for (i = 0; i < 30; i++)
		{
			cin >> Name[i];
		}
		cout << "-----------------------------------------\n";
		cout << "        ��������Ҫ���õ���������:";
		for (i = 0; i < 10; i++)
		{
			cin >> ObjectName[i];
		}
		//scanf_s("%s", ObjectName, 30);
		p = ncupe;
		if (p != NULL)
		{
			for (i = 0; i < 6; i++)
			{
				if (strcmp(ObjectName, p->type) == 0)
				{
					if (p->num == 0)
					{
						cout << "-----------------------------------------\n";
						cout << "            �������޿�棡\n";
						exist = -1;
						break;
					}
					else
					{
						p->num--;
						exist = 1;

						ofstream os("object", ios_base::in);
						if (!os)
						{
							cout << "д���ļ�ʧ�ܣ�3����˳�����" << endl;
							Sleep(3000);
							exit(0);
						}
						os.write(reinterpret_cast<char *>(&ncupe), sizeof(object));
						os.close();
						//writefile(2);
						cout << "-----------------------------------------\n";
						//cout << "���ࣺ%s\t������%d\n", p->type, p->num);
						//cout << "             %s����%s�ɹ���\n", Name, ObjectName);
						cout << "����:" << p->type << "\t����:" << p->num << endl;
						cout << "             " << Name << "����" << ObjectName << "�ɹ���" << endl;
						//����д�벿����Ϊ��д����ʷ��¼�ļ��Ĵ���
						string s1 = Name;
						string s2 = ObjectName;
						string s = s1 + s2;
						ofstream os1("RecordObject", ios_base::in);
						if (!os1)
						{
							cout << "д���ļ�ʧ�ܣ�3����˳�����" << endl;
							Sleep(3000);
							exit(0);
						}
						os1.write(reinterpret_cast<char *>(&s), sizeof(s));
						os1.close();

						break;
					}
				}
				p++;
			}
			if (exist == 0)
			{
				cout << "-----------------------------------------\n";
				cout << "   �������û���������ģ��˳�����ģ�飡\n";
				break;
			}
		}
		cout << "-----------------------------------------\n";
		cout << "           3��󷵻�������...\n";
		Sleep(3000);
		login();
	}
	case 3:
	{
		char ClassName[15];
		struct classroom *p = NULL;
		char Name[30];
		int exist = 0;

		ifstream is("classroom", ios_base::in);
		if (!is)
		{
			cout << "���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&classes), sizeof(classroom));
		is.close();
		//readfile(3);
		cout << "-----------------------------------------\n";
		cout << "              �����������:";
		for (i = 0; i < 30; i++)
		{
			cin >> Name[i];
		}
		//scanf_s("%s", Name, 30);
		cout << "-----------------------------------------\n";
		cout << "         ��������Ҫ���õĽ������:";
		for (i = 0; i < 15; i++)
		{
			cin >> ClassName[i];
		}
		//scanf_s("%s", ClassName, 30);
		p = classes;
		if (p != NULL)
		{
			for (i = 0; i < 15; i++)
			{
				if (strcmp(ClassName, p->name) == 0)
				{
					if (p->statu == 0)
					{
						cout << "-----------------------------------------\n";
						cout << "            �˽��Ҳ��ɽ��ã�\n\n";
						exist = -1;
						break;
					}
					else
					{
						p->statu = 0;
						exist = 1;

						ofstream os("classroom", ios_base::in);
						if (!os)
						{
							cout << "д���ļ�ʧ�ܣ�3����˳�����" << endl;
							Sleep(3000);
							exit(0);
						}
						os.write(reinterpret_cast<char *>(&classes), sizeof(book));
						os.close();
						//writefile(3);
						cout << "-----------------------------------------\n";
						//printf("¥�㣺%d\t��ţ�%s\t״̬��%d\n", p->floor, p->name, p->statu);
						//printf("             %s����%s�ɹ���\n", Name, ClassName);
						cout << "¥��:" << p->floor << "\t��ţ�" << p->name << "\t״̬��" << p->statu << endl;
						cout << "             " << Name << "����" << ClassName << "�ɹ���" << endl;
						//����д�벿����Ϊ��д����ʷ��¼�ļ��Ĵ���
						string s1 = Name;
						string s2 = ClassName;
						string s = s1 + s2;
						ofstream os1("RecordClassroom", ios_base::in);
						if (!os1)
						{
							cout << "д���ļ�ʧ�ܣ�3����˳�����" << endl;
							Sleep(3000);
							exit(0);
						}
						os1.write(reinterpret_cast<char *>(&s), sizeof(s));
						os1.close();

						break;
					}
				}
				p++;
			}
			if (exist == 0)
			{
				cout << "-----------------------------------------\n";
				cout << "  �������û�������ң��˳�����ģ�飡\n";
				break;
			}
		}
		cout << "3��󷵻�������...\n";
		Sleep(3000);
		login();
	}
	}
}//���ú���