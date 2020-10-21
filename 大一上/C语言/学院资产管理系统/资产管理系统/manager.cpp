#include "basic.h"
#include "manager.h"
#include <cmath>
#include <iostream>
#include<fstream>
#include<Windows.h>
using namespace std;

//从basic.h那里共用结构体
extern struct books book[15];
extern struct object ncupe[6];
extern struct classroom classes[15];

manager::manager(const string Name, string Password):user(Name)
{
	password = Password;
}

void manager::Reference()
{
	int i;    //供给循环使用
	int OSN;    //操作数，选择浏览模块后，输入1则显示教室信息，输入2则显示体育器材信息，输入3则显示书籍信息

	cout << "-----------------------------------------\n";
	cout << "            1书籍信息\n\n";
	cout << "            2体育器材信息\n\n";
	cout << "            3教室信息\n\n";
	cout << "         请选择你想要浏览的信息:";
	cin >> OSN;
	//scanf_s("%d", &OSN);

	while (OSN != 1 && OSN != 2 && OSN != 3)
	{
		cout << "-----------------------------------------\n";
		cout << "              输入错误！\n";
		cout << "          请选择你想要浏览的信息：";
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
			cout << "打开文件失败！3秒后退出程序。" << endl;
			Sleep(3000);
			exit(0);
		}
		if (!is1)
		{
			cout << "打开文件失败！3秒后退出程序。" << endl;
			Sleep(3000);
			exit(0);
		}
		is1.read(reinterpret_cast<char *>(&s), sizeof(s));
		is.read(reinterpret_cast<char *>(&book), sizeof(book));
		is.close();
		is1.close();
		cout << "-----------------------------------------\n";
		cout << "            读取文件信息\n\n";
		cout << "-----------------------------------------\n";
		cout << "          书名：作者\t数量\n\n";
		for (i = 0; i < 15; i++)
		{
			/*if (book[i].book_name == "0")
			{
				break;
			}*/
			cout << "          " << book[i].book_name << "\t" << book[i].author << "\t" << book[i].num << endl << endl;
		}
		cout << "          历史记录：\n" << s << endl;

		break;
	}
	case 2:
	{
		string s;

		ifstream is("object", ios_base::in);
		ifstream is1("RecordObject", ios_base::in);
		if (!is)
		{
			cout << "打开文件失败！3秒后退出程序。" << endl;
			Sleep(3000);
			exit(0);
		}
		if (!is1)
		{
			cout << "打开文件失败！3秒后退出程序。" << endl;
			Sleep(3000);
			exit(0);
		}
		is1.read(reinterpret_cast<char *>(&s), sizeof(s));
		is.read(reinterpret_cast<char *>(&ncupe), sizeof(object));
		is.close();
		is1.close();
		cout << "-----------------------------------------\n";
		cout << "            读取文件信息\n\n";
		cout << "-----------------------------------------\n";
		cout << "          器材信息：器材种类\t数量\n\n";
		for (i = 0; i < 6; i++)
		{
			cout << "          " << ncupe[i].type << "\t\t" << ncupe[i].num << endl << endl;
		}
		cout << "          历史记录：\n" << s << endl;

		break;
	}
	case 3:
	{
		string s;

		ifstream is("classroom", ios_base::in);
		ifstream is1("RecordClassroom", ios_base::in);
		if (!is)
		{
			cout << "打开文件失败！3秒后退出程序。" << endl;
			Sleep(3000);
			exit(0);
		}
		if (!is1)
		{
			cout << "打开文件失败！3秒后退出程序。" << endl;
			Sleep(3000);
			exit(0);
		}
		is1.read(reinterpret_cast<char *>(&s), sizeof(s));
		is.read(reinterpret_cast<char *>(&classes), sizeof(classroom));
		is.close();
		is1.close();
		cout << "-----------------------------------------\n";
		cout << "            读取文件信息\n\n";
		cout << "-----------------------------------------\n";
		cout << "教室信息: 楼层\t教室名\t状态（1代表可借用，0代表不可借用）\n\n";
		for (i = 0; i < 15; i++)
		{
			cout << "         " << classes[i].floor << "\t" << classes[i].name << "\t" << classes[i].statu << endl << endl;
		}
		cout << "          历史记录：\n" << s << endl;

		break;
	}
	}
}

void manager::change()
{
	FILE *fp;//文件指针
	errno_t err;//错误判断
	int a, choice, cho;//cho作为跳出循环的判断
	int i, j = 0;
	struct books bookfile;
	struct object objectfile;
	struct classroom classfile;
	cout << "     请确认你要更改的物品类型：\n\n";
	cout << "            1 书籍             \n\n";
	cout << "            2 体育器材         \n\n";
	cout << "            3 教室             \n\n";
	  cin >>choice;

	switch (choice)
	{
	case 1://书籍类的修改
		cout << "-----------------------------------------\n";
		cout << "            读取文件信息\n\n";
		if ((err = fopen_s(&fp, "books.txt", "r")) != 0)
		{
			cout << "     无法打开此文件\n\n";
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
			cout << "     请输入要改变的数量：\n\n";
			cin>>book[a].num;
			cout << "     修改信息成功！\n\n";
			if ((err = fopen_s(&fp, "books.txt", "w")) != 0)
			{
				cout << "     无法打开此文件\n\n";
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
				cout << "无法打开此文件\n\n";
			}
			else
			{
				cout << "      请输入要添加的信息（书本名字、作者、数量）：\n\n";
				//scanf_s("%s%s%d", &bookfile.book_name, 30, &bookfile.author, 20, &bookfile.num);//先保留看看
				cin >> bookfile.book_name >> bookfile.author >> bookfile.num;//读入书籍信息
				cout << bookfile.book_name << bookfile.author << bookfile.num;
				fwrite(&bookfile, sizeof(struct books), 1, fp);
				fclose(fp);
			}
			//移动到文件尾部；
		}
		break;
	case 2:
		cout << "-----------------------------------------\n";
		cout << "            读取文件信息\n\n";
		if ((err = fopen_s(&fp, "object.txt", "r")) != 0)
		{
			cout << "     无法打开此文件\n\n";
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
			cout << "     请输入要改变的数量：\n\n";//提示
			cin >> ncupe[a].num;//读入要改变的数量
			cout << "     修改信息成功！\n\n";
			if ((err = fopen_s(&fp, "object.txt", "w")) != 0)
			{
				cout << "     无法打开此文件\n\n";
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
				cout << "无法打开此文件\n\n";
			}
			else
			{
				cout << "-----------------------------------------\n";
				cout << "   请输入要添加的信息（器材种类、数量）：\n\n";
				//scanf_s("%s%d", &objectfile.type, 10, &objectfile.num);//先保留防止新的出bug
				cin >> objectfile.type >> objectfile.num;
				fwrite(&objectfile, sizeof(struct object), 1, fp);
				//移动到文件尾部；
				fclose(fp);
			}
		}
		break;
	case 3:
		readfile(3);
		if ((err = fopen_s(&fp, "classroom.txt", "a")) != 0)
		{
			cout << "无法打开此文件\n\n";
		}
		cout << "-------------------------------------------------------------------\n";
		cout << "请输入要添加的信息（楼层、教室名、状态（1代表可借用，0代表不可借用）：\n\n";
		//scanf_s("%d%s%d", &classfile.floor, &classfile.name, 256, &classfile.statu);先保留防止新的语句出问题

		fwrite(&classfile, sizeof(struct classroom), 1, fp);
		//移动到文件尾部；
		fclose(fp);
		break;
	}
	cout << "-----------------------------------------\n";
	cout << "  是否还要继续添加？按0可返回添加\n\n";
	cout << "        按任意数字可返回主界面\n\n";
	cin >> cho;
	  if (0 == cho) change();//对函数自身进行再一次调用，进行多次修改
}

int search_return1()
{
	int i, j, k;
	int flag = 0;
	char str2[20];

	cout << "-----------------------------------------\n";
	cout << "        输入想要添加的书籍名称：";
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
			cout << "书名：" << book[i].book_name << "  库存：" << book[i].num << "本" << endl;
			flag++;
			break;
		}
	}
	if (!flag)
	{
		return -1;
	}
	else return i;
}//用于书籍的添加检测

int search_return2()
{
	int i, j, k;
	int flag = 0;
	char str[20];

	cout << "-----------------------------------------\n";
	cout << "           输入您想添加的器材：";
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
			break;
		}
	}
	if (!flag)
	{
		return -1;
	}
	else return i;
}//用于器材的添加检测

void readfile(int choice)//读入文件函数
{
	FILE *fp;
	errno_t err;

	if (choice == 1)
	{
		if ((err = fopen_s(&fp, "books.txt", "r")) != 0)
		{
			cout << "     无法打开此文件\n\n";
		}
		fread(book, sizeof(struct books), 15, fp);
	}
	else if (choice == 2)
	{
		if ((err = fopen_s(&fp, "object.txt", "r")) != 0)
		{
			cout << "     无法打开此文件\n\n";
		}
		fread(ncupe, sizeof(struct object), 6, fp);
	}
	else if (choice == 3)
	{
		if ((err = fopen_s(&fp, "classroom.txt", "r")) != 0)
		{
			cout << "     无法打开此文件\n\n";
		}
		fread(classes, sizeof(struct classroom), 15, fp);
	}
	else
	{
		cout << "   谢谢使用！  ";
		exit(0);
	}
	fclose(fp);
}

void writefile(int choice)//写入文件函数
{
	FILE *fp;
	errno_t err;

	if (choice == 1)
	{
		if ((err = fopen_s(&fp, "books.txt", "w")) != 0)
		{
			cout << "     无法打开此文件\n\n";
		}
		fwrite(book, sizeof(struct books), 15, fp);
	}
	else if (choice == 2)
	{
		if ((err = fopen_s(&fp, "object.txt", "w")) != 0)
		{
			cout << "     无法打开此文件\n\n";
		}
		fwrite(ncupe, sizeof(struct object), 6, fp);
	}
	else if (choice == 3)
	{
		if ((err = fopen_s(&fp, "classroom.txt", "w")) != 0)
		{
			cout << "     无法打开此文件\n\n";
		}
		fwrite(classes, sizeof(struct classroom), 15, fp);
	}
	else
	{
		cout << "   谢谢使用！  ";
		exit(0);
	}
	fclose(fp);
}
