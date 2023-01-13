#include "basic.h"
#include "user.h"
#include "login.h"
#include "manager.h"
#include <cmath>
#include <iostream>
#include<fstream>
#include <Windows.h>//用了sleep()
using namespace std;

//从basic.h那里共用结构体
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
	cout << "------------------菜单-------------------\n";
	cout << "              (1)还书\n\n";
	cout << "              (2)还体育器材\n\n";
	cout << "              (3)还教室\n\n";
	cout << "              请输入你的选择：";
	cin >> op;
	//scanf_s("%d", &op);
	while (op != 1 && op != 2 && op != 3)
	{
		cout << "输入错误！请重新输入！\n";
		cout << "-----------------------------------------\n";
		cout << "------------------菜单-------------------\n";
		cout << "              (1)还书\n\n";
		cout << "              (2)还体育器材\n\n";
		cout << "              (3)还教室\n\n";
		cout << "              请输入你的选择：";
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
			cout << "打开文件失败！3秒后退出程序。" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&book), sizeof(book));
		is.close();
		//readfile(1);
		cout << "-----------------------------------------\n";
		cout << "             输入你的名字:";
		for (i = 0; i < 30; i++)
		{
			cin >> Name[i];
		}
		//scanf_s("%s", Name, 30);
		cout << "-----------------------------------------\n";
		cout << "         输入你需要归还的书籍:";
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
						cout << "写入文件失败！3秒后退出程序！" << endl;
						Sleep(3000);
						exit(0);
					}
					os.write(reinterpret_cast<char *>(&book), sizeof(book));
					os.close();
					//writefile(1);
					cout << "-----------------------------------------\n";
					//cout << "书名：%s\t作者：%s\t数量：%d\n", p->name, p->author, p->num);
					//cout << "             %s归还%s成功！\n", Name, BookName);
					cout << "书名：" << p->book_name << "\t作者：" << p->author << "\t数量：" << p->num << endl;
					cout << "             " << Name << "归还" << BookName << "成功！" << endl;
					//以下写入部分是为了写入历史记录文件的代码
					string s1 = Name;
					string s2 = BookName;
					string s = s1 + s2;
					ofstream os1("RecordBooks", ios_base::in);
					if (!os1)
					{
						cout << "写入文件失败！3秒后退出程序！" << endl;
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
				cout << "   输入错误！没有这本书！退出归还模块！\n";
				break;
			}
		}
		cout << "3秒后返回主界面...\n";
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
			cout << "打开文件失败！3秒后退出程序。" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&ncupe), sizeof(object));
		is.close();
		//readfile(2);
		cout << "-----------------------------------------\n";
		cout << "输入你的名字:";
		for (i = 0; i < 30; i++)
		{
			cin >> Name[i];
		}
		//scanf_s("%s", Name, 30);
		cout << "-----------------------------------------\n";
		cout << "         输入你需要归还的器材:";
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
						cout << "写入文件失败！3秒后退出程序！" << endl;
						Sleep(3000);
						exit(0);
					}
					os.write(reinterpret_cast<char *>(&ncupe), sizeof(object));
					os.close();
					//writefile(2);
					cout << "-----------------------------------------\n";
					//printf("种类：%s\t数量：%d\n", p->type, p->num);
					//printf("              %s归还%s成功！\n", Name, ObjectName);
					cout << "种类：" << p->type << "\t数量：" << p->num << endl;
					cout << "              " << Name << "归还" << ObjectName << "成功！" << endl;
					//以下写入部分是为了写入历史记录文件的代码
					string s1 = Name;
					string s2 = ObjectName;
					string s = s1 + s2;
					ofstream os1("RecordObject", ios_base::in);
					if (!os1)
					{
						cout << "写入文件失败！3秒后退出程序！" << endl;
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
				cout << "  输入错误！没有这种器材！退出归还模块！\n";
				break;
			}
		}
		cout << "3秒后返回主界面...\n";
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
			cout << "打开文件失败！3秒后退出程序。" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&classes), sizeof(classroom));
		is.close();
		//readfile(3);
		cout << "-----------------------------------------\n";
		cout << "             输入你的名字:";
		for (i = 0; i < 30; i++)
		{
			cin >> Name[i];
		}
		//scanf_s("%s", Name, 30);
		cout << "-----------------------------------------\n";
		cout << "          输入你需要归还的教室:";
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
						cout << "写入文件失败！3秒后退出程序！" << endl;
						Sleep(3000);
						exit(0);
					}
					os.write(reinterpret_cast<char *>(&classes), sizeof(book));
					os.close();
					//writefile(3);
					cout << "-----------------------------------------\n";
					//printf("楼层：%d\t序号：%s\t状态：%d\n", p->floor, p->name, p->statu);
					//printf("              %s归还%s成功！\n", Name, ClassName);
					cout << "楼层: " << p->floor << "\t序号：" << p->name << "\t状态：" << p->statu << endl;
					cout << "              " << Name << "归还" << ClassName << "成功!" << endl;
					//以下写入部分是为了写入历史记录文件的代码
					string s1 = Name;
					string s2 = ClassName;
					string s = s1 + s2;
					ofstream os1("RecordClassroom", ios_base::in);
					if (!os1)
					{
						cout << "写入文件失败！3秒后退出程序！" << endl;
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
				cout << "  输入错误！没有这间教室！退出归还模块！\n";
				break;
			}
		}
		cout << "3秒后返回主界面...\n";
		Sleep(3000);
		login();
	}
	}
}//归还函数

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
		<< "            1 书籍             \n\n"
		<< "            2 体育器材         \n\n"
		<< "            3 教室             \n\n"
		<< "            0 退出系统         \n\n"
		<< "            请输入你的选择：";
	cin >> choice;
	switch (choice)
	{
	case 1:
		if ((err = fopen_s(&fp, "books.txt", "r")) != 0)
		{
			printf("无法打开此文件\n\n");
		}
		fread(book, sizeof(struct books), 15, fp);

		cout << "-----------------------------------------\n";
		cout << "  输入想要查找的书籍(请输入书籍名称)：";
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
				cout << "  书名：" << book[i].book_name << "  库存：" << book[i].num << "本" << endl;
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
			cout << "无法打开此文件\n\n";
		}
		fread(ncupe, sizeof(struct object), 6, fp);
		cout << "-----------------------------------------\n";
		cout << "          输入您想要找的器材类型：";
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
				cout << "已找到该器材： " << ncupe[i].type << ", 库存数：" << ncupe[i].num << endl;
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
			cout << "无法打开此文件\n\n";
		}
		fread(classes, sizeof(struct classroom), 15, fp);
		cout << "-----------------------------------------\n";
		cout << "        输入要查找的教室名（如106）：\n\n";
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
				cout << "         楼层\t教室名\t状态\n\n";
				cout << "房间信息：" << classes[i].floor << "\t" << classes[i].name << "\t";
				if (classes[i].statu == 1)
					cout << "可借用\n\n";
				else cout << "不可借用\n\n";
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
		cout << "                谢谢使用";
		exit(0);
	}
	cout << "-----------------------------------------\n";
	cout << "           返回主界面";
	system("pause");
	system("cls");
}//搜索函数

void user::Borrow()
{
	int op;
	int i;

	cout << "-----------------------------------------\n";
	cout << "------------------菜单-------------------\n";
	cout << "              (1)借书\n\n";
	cout << "              (2)借体育器材\n\n";
	cout << "              (3)借教室\n\n";
	cout << "              请输入你的选择：";
	cin >> op;
	//scanf_s("%d", &op);
	while (op != 1 && op != 2 && op != 3)
	{
		cout << "输入错误！请重新输入！\n\n";
		cout << "-----------------------------------------\n";
		cout << "------------------菜单-------------------\n";
		cout << "              (1)借书\n\n";
		cout << "              (2)借体育器材\n\n";
		cout << "              (3)借教室\n\n";
		cout << "              请输入你的选择：";
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
			cout << "打开文件失败！3秒后退出程序。" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&book), sizeof(book));
		is.close();
		//readfile(1);
		cout << "-----------------------------------------\n";
		cout << "             输入你的名字:";
		//scanf_s("%s", Name, 30);
		for (i = 0; i < 30; i++)
		{
			cin >> Name[i];
		}
		cout << "-----------------------------------------\n";
		cout << "          输入你需要借阅的书籍:";
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
						cout << "              此书无库存！\n";
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
							cout << "写入文件失败！3秒后退出程序！" << endl;
							Sleep(3000);
							exit(0);
						}
						os.write(reinterpret_cast<char *>(&book), sizeof(book));
						os.close();
						//writefile(1);
						cout << "-----------------------------------------\n";
						cout << "书名:" << p->book_name << "\t作者：" << p->author << "\t数量:" << p->num << endl;
						//printf("书名：%s\t作者：%s\t数量：%d\n", p->name, p->author, p->num);
						cout << "             " << Name << "借阅" << BookName << "成功！" << endl;
						//printf("             %s借阅%s成功！\n", Name, BookName);
						//以下写入部分是为了写入历史记录文件的代码
						string s1 = Name;
						string s2 = BookName;
						string s = s1 + s2;
						ofstream os1("RecordBooks", ios_base::in);
						if (!os1)
						{
							cout << "写入文件失败！3秒后退出程序！" << endl;
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
				cout << "    输入错误！没有这本书！退出借用模块！\n";
				break;
			}
		}
		cout << "-----------------------------------------\n";
		cout << "         3秒后返回主界面...\n";
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
			cout << "打开文件失败！3秒后退出程序。" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&ncupe), sizeof(object));
		is.close();
		//readfile(2);
		cout << "-----------------------------------------\n";
		cout << "               输入你的名字:";
		//scanf_s("%s", Name, 30);
		for (i = 0; i < 30; i++)
		{
			cin >> Name[i];
		}
		cout << "-----------------------------------------\n";
		cout << "        输入你需要借用的体育器材:";
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
						cout << "            此器材无库存！\n";
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
							cout << "写入文件失败！3秒后退出程序！" << endl;
							Sleep(3000);
							exit(0);
						}
						os.write(reinterpret_cast<char *>(&ncupe), sizeof(object));
						os.close();
						//writefile(2);
						cout << "-----------------------------------------\n";
						//cout << "种类：%s\t数量：%d\n", p->type, p->num);
						//cout << "             %s借用%s成功！\n", Name, ObjectName);
						cout << "种类:" << p->type << "\t数量:" << p->num << endl;
						cout << "             " << Name << "借用" << ObjectName << "成功！" << endl;
						//以下写入部分是为了写入历史记录文件的代码
						string s1 = Name;
						string s2 = ObjectName;
						string s = s1 + s2;
						ofstream os1("RecordObject", ios_base::in);
						if (!os1)
						{
							cout << "写入文件失败！3秒后退出程序！" << endl;
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
				cout << "   输入错误！没有这种器材！退出借用模块！\n";
				break;
			}
		}
		cout << "-----------------------------------------\n";
		cout << "           3秒后返回主界面...\n";
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
			cout << "打开文件失败！3秒后退出程序。" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&classes), sizeof(classroom));
		is.close();
		//readfile(3);
		cout << "-----------------------------------------\n";
		cout << "              输入你的名字:";
		for (i = 0; i < 30; i++)
		{
			cin >> Name[i];
		}
		//scanf_s("%s", Name, 30);
		cout << "-----------------------------------------\n";
		cout << "         输入你需要借用的教室序号:";
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
						cout << "            此教室不可借用！\n\n";
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
							cout << "写入文件失败！3秒后退出程序！" << endl;
							Sleep(3000);
							exit(0);
						}
						os.write(reinterpret_cast<char *>(&classes), sizeof(book));
						os.close();
						//writefile(3);
						cout << "-----------------------------------------\n";
						//printf("楼层：%d\t序号：%s\t状态：%d\n", p->floor, p->name, p->statu);
						//printf("             %s借用%s成功！\n", Name, ClassName);
						cout << "楼层:" << p->floor << "\t序号：" << p->name << "\t状态：" << p->statu << endl;
						cout << "             " << Name << "借用" << ClassName << "成功！" << endl;
						//以下写入部分是为了写入历史记录文件的代码
						string s1 = Name;
						string s2 = ClassName;
						string s = s1 + s2;
						ofstream os1("RecordClassroom", ios_base::in);
						if (!os1)
						{
							cout << "写入文件失败！3秒后退出程序！" << endl;
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
				cout << "  输入错误！没有这间教室！退出借用模块！\n";
				break;
			}
		}
		cout << "3秒后返回主界面...\n";
		Sleep(3000);
		login();
	}
	}
}//借用函数