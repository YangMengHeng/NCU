#include "basic.h"
#include "manager.h"
#include <cmath>
#include <iostream>
#include<fstream>
#include<Windows.h>
using namespace std;

//��basic.h���ﹲ�ýṹ��
extern struct books book[15];
extern struct object ncupe[6];
extern struct classroom classes[15];

manager::manager(const string Name, string Password):user(Name)
{
	password = Password;
}

void manager::Reference()
{
	int i;    //����ѭ��ʹ��
	int OSN;    //��������ѡ�����ģ�������1����ʾ������Ϣ������2����ʾ����������Ϣ������3����ʾ�鼮��Ϣ

	cout << "-----------------------------------------\n";
	cout << "            1�鼮��Ϣ\n\n";
	cout << "            2����������Ϣ\n\n";
	cout << "            3������Ϣ\n\n";
	cout << "         ��ѡ������Ҫ�������Ϣ:";
	cin >> OSN;
	//scanf_s("%d", &OSN);

	while (OSN != 1 && OSN != 2 && OSN != 3)
	{
		cout << "-----------------------------------------\n";
		cout << "              �������\n";
		cout << "          ��ѡ������Ҫ�������Ϣ��";
		cin >> OSN;
	}

	switch (OSN)
	{
	case 1:
	{
		string s;

		ifstream is("books", ios_base::in);
		ifstream is1("RecordBooks", ios_base::in);
		if (!is)
		{
			cout << "���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		if (!is1)
		{
			cout << "���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		is1.read(reinterpret_cast<char *>(&s), sizeof(s));
		is.read(reinterpret_cast<char *>(&book), sizeof(book));
		is.close();
		is1.close();
		cout << "-----------------------------------------\n";
		cout << "            ��ȡ�ļ���Ϣ\n\n";
		cout << "-----------------------------------------\n";
		cout << "          ����������\t����\n\n";
		for (i = 0; i < 15; i++)
		{
			/*if (book[i].book_name == "0")
			{
				break;
			}*/
			cout << "          " << book[i].book_name << "\t" << book[i].author << "\t" << book[i].num << endl << endl;
		}
		cout << "          ��ʷ��¼��\n" << s << endl;

		break;
	}
	case 2:
	{
		string s;

		ifstream is("object", ios_base::in);
		ifstream is1("RecordObject", ios_base::in);
		if (!is)
		{
			cout << "���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		if (!is1)
		{
			cout << "���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		is1.read(reinterpret_cast<char *>(&s), sizeof(s));
		is.read(reinterpret_cast<char *>(&ncupe), sizeof(object));
		is.close();
		is1.close();
		cout << "-----------------------------------------\n";
		cout << "            ��ȡ�ļ���Ϣ\n\n";
		cout << "-----------------------------------------\n";
		cout << "          ������Ϣ����������\t����\n\n";
		for (i = 0; i < 6; i++)
		{
			cout << "          " << ncupe[i].type << "\t\t" << ncupe[i].num << endl << endl;
		}
		cout << "          ��ʷ��¼��\n" << s << endl;

		break;
	}
	case 3:
	{
		string s;

		ifstream is("classroom", ios_base::in);
		ifstream is1("RecordClassroom", ios_base::in);
		if (!is)
		{
			cout << "���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		if (!is1)
		{
			cout << "���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		is1.read(reinterpret_cast<char *>(&s), sizeof(s));
		is.read(reinterpret_cast<char *>(&classes), sizeof(classroom));
		is.close();
		is1.close();
		cout << "-----------------------------------------\n";
		cout << "            ��ȡ�ļ���Ϣ\n\n";
		cout << "-----------------------------------------\n";
		cout << "������Ϣ: ¥��\t������\t״̬��1����ɽ��ã�0�����ɽ��ã�\n\n";
		for (i = 0; i < 15; i++)
		{
			cout << "         " << classes[i].floor << "\t" << classes[i].name << "\t" << classes[i].statu << endl << endl;
		}
		cout << "          ��ʷ��¼��\n" << s << endl;

		break;
	}
	}
}

void manager::change()
{
	FILE *fp;//�ļ�ָ��
	errno_t err;//�����ж�
	int a, choice, cho;//cho��Ϊ����ѭ�����ж�
	int i, j = 0;
	struct books bookfile;
	struct object objectfile;
	struct classroom classfile;
	cout << "     ��ȷ����Ҫ���ĵ���Ʒ���ͣ�\n\n";
	cout << "            1 �鼮             \n\n";
	cout << "            2 ��������         \n\n";
	cout << "            3 ����             \n\n";
	  cin >>choice;

	switch (choice)
	{
	case 1://�鼮����޸�
		cout << "-----------------------------------------\n";
		cout << "            ��ȡ�ļ���Ϣ\n\n";
		if ((err = fopen_s(&fp, "books.txt", "r")) != 0)
		{
			cout << "     �޷��򿪴��ļ�\n\n";
		}
		for (i = 0; !feof(fp); i++)
		{
			fread(&book[i], sizeof(struct books), 1, fp);
			j++;
		}
		fclose(fp);
		a = search_return1();
		if (a != -1)
		{
			cout << "     ������Ҫ�ı��������\n\n";
			cin>>book[a].num;
			cout << "     �޸���Ϣ�ɹ���\n\n";
			if ((err = fopen_s(&fp, "books.txt", "w")) != 0)
			{
				cout << "     �޷��򿪴��ļ�\n\n";
			}
			for (i = 0; i < j - 1; i++)
			{
				fwrite(&book[i], sizeof(struct books), 1, fp);
			}
			fclose(fp);
		}
		else
		{
			if ((err = fopen_s(&fp, "books.txt", "a")) != 0)
			{
				cout << "�޷��򿪴��ļ�\n\n";
			}
			else
			{
				cout << "      ������Ҫ��ӵ���Ϣ���鱾���֡����ߡ���������\n\n";
				//scanf_s("%s%s%d", &bookfile.book_name, 30, &bookfile.author, 20, &bookfile.num);//�ȱ�������
				cin >> bookfile.book_name >> bookfile.author >> bookfile.num;//�����鼮��Ϣ
				cout << bookfile.book_name << bookfile.author << bookfile.num;
				fwrite(&bookfile, sizeof(struct books), 1, fp);
				fclose(fp);
			}
			//�ƶ����ļ�β����
		}
		break;
	case 2:
		cout << "-----------------------------------------\n";
		cout << "            ��ȡ�ļ���Ϣ\n\n";
		if ((err = fopen_s(&fp, "object.txt", "r")) != 0)
		{
			cout << "     �޷��򿪴��ļ�\n\n";
		}
		for (i = 0; !feof(fp); i++)
		{
			fread(&ncupe[i], sizeof(struct object), 1, fp);
			j++;
		}
		fclose(fp);
		a = search_return2();
		if (a != -1)
		{
			cout << "     ������Ҫ�ı��������\n\n";//��ʾ
			cin >> ncupe[a].num;//����Ҫ�ı������
			cout << "     �޸���Ϣ�ɹ���\n\n";
			if ((err = fopen_s(&fp, "object.txt", "w")) != 0)
			{
				cout << "     �޷��򿪴��ļ�\n\n";
			}
			for (i = 0; i < j - 1; i++)
			{
				fwrite(&ncupe[i], sizeof(struct object), 1, fp);
			}
			fclose(fp);
		}
		else
		{
			if ((err = fopen_s(&fp, "object.txt", "a")) != 0)
			{
				cout << "�޷��򿪴��ļ�\n\n";
			}
			else
			{
				cout << "-----------------------------------------\n";
				cout << "   ������Ҫ��ӵ���Ϣ���������ࡢ��������\n\n";
				//scanf_s("%s%d", &objectfile.type, 10, &objectfile.num);//�ȱ�����ֹ�µĳ�bug
				cin >> objectfile.type >> objectfile.num;
				fwrite(&objectfile, sizeof(struct object), 1, fp);
				//�ƶ����ļ�β����
				fclose(fp);
			}
		}
		break;
	case 3:
		readfile(3);
		if ((err = fopen_s(&fp, "classroom.txt", "a")) != 0)
		{
			cout << "�޷��򿪴��ļ�\n\n";
		}
		cout << "-------------------------------------------------------------------\n";
		cout << "������Ҫ��ӵ���Ϣ��¥�㡢��������״̬��1����ɽ��ã�0�����ɽ��ã���\n\n";
		//scanf_s("%d%s%d", &classfile.floor, &classfile.name, 256, &classfile.statu);�ȱ�����ֹ�µ���������

		fwrite(&classfile, sizeof(struct classroom), 1, fp);
		//�ƶ����ļ�β����
		fclose(fp);
		break;
	}
	cout << "-----------------------------------------\n";
	cout << "  �Ƿ�Ҫ������ӣ���0�ɷ������\n\n";
	cout << "        ���������ֿɷ���������\n\n";
	cin >> cho;
	  if (0 == cho) change();//�Ժ������������һ�ε��ã����ж���޸�
}

int search_return1()
{
	int i, j, k;
	int flag = 0;
	char str2[20];

	cout << "-----------------------------------------\n";
	cout << "        ������Ҫ��ӵ��鼮���ƣ�";
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
			cout << "������" << book[i].book_name << "  ��棺" << book[i].num << "��" << endl;
			flag++;
			break;
		}
	}
	if (!flag)
	{
		return -1;
	}
	else return i;
}//�����鼮����Ӽ��

int search_return2()
{
	int i, j, k;
	int flag = 0;
	char str[20];

	cout << "-----------------------------------------\n";
	cout << "           ����������ӵ����ģ�";
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
			break;
		}
	}
	if (!flag)
	{
		return -1;
	}
	else return i;
}//�������ĵ���Ӽ��

void readfile(int choice)//�����ļ�����
{
	FILE *fp;
	errno_t err;

	if (choice == 1)
	{
		if ((err = fopen_s(&fp, "books.txt", "r")) != 0)
		{
			cout << "     �޷��򿪴��ļ�\n\n";
		}
		fread(book, sizeof(struct books), 15, fp);
	}
	else if (choice == 2)
	{
		if ((err = fopen_s(&fp, "object.txt", "r")) != 0)
		{
			cout << "     �޷��򿪴��ļ�\n\n";
		}
		fread(ncupe, sizeof(struct object), 6, fp);
	}
	else if (choice == 3)
	{
		if ((err = fopen_s(&fp, "classroom.txt", "r")) != 0)
		{
			cout << "     �޷��򿪴��ļ�\n\n";
		}
		fread(classes, sizeof(struct classroom), 15, fp);
	}
	else
	{
		cout << "   ллʹ�ã�  ";
		exit(0);
	}
	fclose(fp);
}

void writefile(int choice)//д���ļ�����
{
	FILE *fp;
	errno_t err;

	if (choice == 1)
	{
		if ((err = fopen_s(&fp, "books.txt", "w")) != 0)
		{
			cout << "     �޷��򿪴��ļ�\n\n";
		}
		fwrite(book, sizeof(struct books), 15, fp);
	}
	else if (choice == 2)
	{
		if ((err = fopen_s(&fp, "object.txt", "w")) != 0)
		{
			cout << "     �޷��򿪴��ļ�\n\n";
		}
		fwrite(ncupe, sizeof(struct object), 6, fp);
	}
	else if (choice == 3)
	{
		if ((err = fopen_s(&fp, "classroom.txt", "w")) != 0)
		{
			cout << "     �޷��򿪴��ļ�\n\n";
		}
		fwrite(classes, sizeof(struct classroom), 15, fp);
	}
	else
	{
		cout << "   ллʹ�ã�  ";
		exit(0);
	}
	fclose(fp);
}
