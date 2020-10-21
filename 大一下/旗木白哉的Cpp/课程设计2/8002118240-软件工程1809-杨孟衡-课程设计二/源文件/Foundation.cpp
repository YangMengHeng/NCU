#include<iostream>
#include"Assist.h"
#include"ADMIN.h"
#include"STUDENT.h"
#include"Course.h"
#include<fstream>
#include<istream>
#include<ostream>
#include"BaseCourse.h"
using namespace std;

STUDENT STU[10];
char ADMIN::ADPS[9] = "ILoveNCU";
ADMIN ADmin[10];
Create Cre[5];
Literate lit[5];
Engineering Eng[5];
int n;
char b = 'a';
int j;

//文件输出函数
void WriteB(int a)//1学生，2老师，3创新类，4文科类，5理工科类
{
	switch (a)
	{
	case 1:
	{
		ofstream OS("Students", ios_base::out);
		if (OS.bad())
		{
			cout << "写入文件失败！3秒后退出程序！" << endl;
			Sleep(3000);
			exit(0);
		}
		OS.write(reinterpret_cast<char *>(&STU), sizeof(STUDENT));
		OS.close();
		break;
	}
	case 2:
	{
		ofstream OS("Admins", ios_base::out);
		if (OS.bad())
		{
			cout << "写入文件失败！3秒后退出程序！" << endl;
			Sleep(3000);
			exit(0);
		}
		OS.write(reinterpret_cast<char *>(&ADmin), sizeof(ADMIN));
		OS.close();
		break;
	}
	case 3:
	{
		ofstream OS("Creates", ios_base::out);
		if (OS.bad())
		{
			cout << "写入文件失败！3秒后退出程序！" << endl;
			Sleep(3000);
			exit(0);
		}
		OS.write(reinterpret_cast<char *>(&Cre), sizeof(Create));
		OS.close();
		break;
	}
	case 4:
	{
		ofstream OS("Literates", ios_base::out);
		if (OS.bad())
		{
			cout << "写入文件失败！3秒后退出程序！" << endl;
			Sleep(3000);
			exit(0);
		}
		OS.write(reinterpret_cast<char *>(&lit), sizeof(Literate));
		OS.close();
		break;
	}
	case 5:
	{
		ofstream OS("Engineerings", ios_base::out);
		if (OS.bad())
		{
			cout << "写入文件失败！3秒后退出程序！" << endl;
			Sleep(3000);
			exit(0);
		}
		OS.write(reinterpret_cast<char *>(&Eng), sizeof(Engineering));
		OS.close();
		break;
	}
	}
}

//输入函数
void ReadB(int n)//1学生,2老师，3创新类，4文科类，5理工科类
{
	switch (n)
	{
	case 1:
	{
		ifstream is("Students", ios_base::in);
		if (is.bad())
		{
			cout << "打开文件失败！3秒后退出程序。" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&STU), sizeof(STU));
		is.close();
		break;
	}
	case 2:
	{
		ifstream is("Admins", ios_base::in);
		if (is.bad())
		{
			cout << "打开文件失败！3秒后退出程序。" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&ADmin), sizeof(ADmin));
		is.close();
		break;
	}
	case 3:
	{
		ifstream is("Creates", ios_base::in);
		if (is.bad())
		{
			cout << "打开文件失败！3秒后退出程序。" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&Cre), sizeof(Cre));
		is.close();
		break;
	}
	case 4:
	{
		ifstream is("Literates", ios_base::in);
		if (is.bad())
		{
			cout << "打开文件失败！3秒后退出程序。" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&lit), sizeof(lit));
		is.close();
		break;
	}
	case 5:
		ifstream is("Engineerings", ios_base::in);
		if (is.bad())
		{
			cout << "打开文件失败！3秒后退出程序。" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&Eng), sizeof(Eng));
		is.close();
		break;
	}
}

//搜索函数-学生账号,搜索到返回下标值，否则返回-1
int Search(char * Crea)//搜索函数-学生账号,搜索到返回下标值，否则返回-1
{
	int i;
	
	for (i = 0; i < 10; i++)
	{
		if (strncmp(STU[i].SNumber, Crea, 10) == 0)
		{
			return i;
		}
	}
	return -1;
}

//搜索函数-老师账号,搜索到返回下标，否则返回-1
int Search(char * Crea, int b)//搜索函数-老师账号,搜索到返回下标，否则返回-1
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if (strncmp(ADmin[i].Admin, Crea, 11) == 0)
		{
			return i;
		}
	}

	return -1;
}

//根据课程编号查找下标，第二个入参是分类别进行检查,1创新类，2文科类，3理工科类，搜索到返回下标，否则返回-1
int Search(char * c, int a, int b)//判断课程编号，1创新类，2文科类，3理工科类，搜索到返回下标，否则返回-1
{
	switch (a)
	{
	case 1:
	{
		int i;
		for (i = 0; i < 5; i++)
		{
			if (strncmp(c, Cre[i].CNumber, 11) == 0)
			{
				return i;
			}
			else
			{
				continue;
			}
		}
		return -1;
	}
	case 2:
	{
		int i;
		for (i = 0; i < 5; i++)
		{
			if (strncmp(c, lit[i].CNumber, 11)  == 0)
			{
				return i;
			}
			else
			{
				continue;
			}
		}
		return -1;
	}
	case 3:
	{
		int i;
		for (i = 0; i < 5; i++)
		{
			if (strncmp(c, Eng[i].CNumber, 11) == 0)
			{
				return i;
			}
			else
			{
				continue;
			}
		}
		return -1;
	}
	}
}

//根据课程名查找下标，第二个入参是分类别进行检查,1创新类，2文科类，3理工科类，搜索到返回下标，否则返回-1
int Search(char * c, int a, char b)
{
	switch (a)
	{
	case 1:
	{
		int i;
		for (i = 0; i < 5; i++)
		{
			if (strncmp(c, Cre[i].CName, 11) == 0)
			{
				return i;
			}
			else
			{
				continue;
			}
		}
		return -1;
	}
	case 2:
	{
		int i;
		for (i = 0; i < 5; i++)
		{
			if (strncmp(c, lit[i].CName, 11) == 0)
			{
				return i;
			}
			else
			{
				continue;
			}
		}
		return -1;
	}
	case 3:
	{
		int i;
		for (i = 0; i < 5; i++)
		{
			if (strncmp(c, Eng[i].CName, 11) == 0)
			{
				return i;
			}
			else
			{
				continue;
			}
		}
		return -1;
	}
	}

	return 0;
}

//根据课程编号查找课程性质，如果是创新类，返回1，文科类返回2，理工科类返回3，否则返回-1
int Search(char * c, int a, double b)//根据课程编号查找课程性质，如果是创新类，返回1，文科类返回2，理工科类返回3，否则返回-1
{
		int i;
		for (i = 0; i < 5; i++)
		{
			if (strncmp(c, Cre[i].CNumber, 1) == 0)
			{
				return 1;
			}
			if (strncmp(c, lit[i].CNumber, 1) == 0)
			{
				return 2;
			}
			if (strncmp(c, Eng[i].CNumber, 1) == 0)
			{
				return 3;
			}
		}

		return -1;
}

//根据课程名查找课程类，返回1创新类，2文科类，3理工科类，否则返回-1
int Search(char * c, char b)//根据课程名查找课程类，返回1创新类，2文科类，3理工科类，否则返回-1
{
	int i;
	for (i = 0; i < 5; i++)
	{
		if (strncmp(Cre[i].CName, c, 11) == 0)
		{
			return 1;
		}
		if (strncmp(lit[i].CName, c, 11) == 0)
		{
			return 2;
		}
		if (strncmp(Eng[i].CName, c, 11) == 0)
		{
			return 3;
		}
	}

	return -1;
}

//检查学生账号密码，账号密码匹配，返回下标值，如果账号密码不匹配，返回-2，若没有找到返回-1
int CheckPAPAS(char * Crea, char * c1)//检查学生账号密码，账号密码匹配，返回下标值，如果账号密码不匹配，返回-2，若没有找到返回-1
{
	int n = Search(Crea);
	if (n != -1)
	{
		if (strncmp(c1, STU[n].STPa, 10) == 0)
		{
			return n;
		}
		else
		{
			return -2;
		}
	}
	else
	{
		return n;
	}
}

//检查老师账号密码，账号密码匹配，返回下标值，如果账号密码不匹配，返回-2，若没有找到返回-1
int CheckPAPAS(char * Crea, char * c1, int a)
{
	int n = Search(Crea, 1);
	if (n != -1)
	{
		if (strncmp(c1, ADmin[n].ADP, 11) == 0)
		{
			return n;
		}
		else
		{
			return -2;
		}
	}
	else
	{
		return n;
	}
}

//根据课程编号，第二参数表示类别，1创新类，2文科类，3理工科类
//若对应课程人数不满，则返回下标值，否则返回-2，若找不到课程返回-1
int CheckCo(char * Crea, int a)
{
	switch (a)
	{
	case 1:
	{
		int n = Search(Crea, a, 1);
		if (n != -1)
		{
			if(Cre[n].Person < Cre[n].Max)
			{
				return n;
			}
			else return -2;
		}
		else
		{
			return n;
		}
	}
	case 2:
	{
		int n = Search(Crea, a, 1);
		if (n != -1)
		{
			if (lit[n].Person < lit[n].Max)
			{
				return n;
			}
			else return -2;
		}
		else
		{
			return n;
		}
	}
	case 3:
	{
		int n = Search(Crea, a, 1);
		if (n != -1)
		{
			if (Eng[n].Person < Eng[n].Max)
			{
				return n;
			}
			else return -2;
		}
		else
		{
			return n;
		}
	}
	}
}

//根据课程名输入，检查对应课程名的课程人数是否已满，已满返回-1，不满返回1
int CheckCo(char * Crea, double q)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		if (strncmp(Crea, Cre[i].CName, 11) == 0)
		{
			if (Cre[i].Person < Cre[i].Max)
			{
				return 1;
			}
			else return -1;
		}
		if (strncmp(Crea, lit[i].CName, 11) == 0)
		{
			if (lit[i].Person < lit[i].Max)
			{
				return 1;
			}
			else return -1;
		}
		if (strncmp(Crea, Eng[i].CName, 11) == 0)
		{
			if (Eng[i].Person < Eng[i].Max)
			{
				return 1;
			}
			else return -1;
		}
	}
	
	return 0;
}
 
//根据课程名，检查课程是否存在，如果存在返回课程名指针，如果不存在返回特定字符'a'
char* CheckCo(char* c)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		if (strncmp(c, Cre[i].CName, 11)  == 0)
		{
			return c;
		}
		else if (strncmp(c, lit[i].CName, 11) == 0)
		{
			return c;
		}
		else if (strncmp(c, Eng[i].CName, 11) == 0)
		{
			return c;
		}
	}

	return &b;
}

//检查当前定义课程数是否已满,如果已满返回-1，如果没满返回1；
int CheckCo(char b)
{

	int j = 0;

	switch (b)
	{
	case '1':
		{
			for (int i = 0; i < 5; i++)
			{
				if (strncmp(Cre[i].ExHour, "0", 2) == 0)
				{
					j++;
				}
			}
			if (j == 0) return -1;
			return 1;
		}
	case '2':
	{
		for (int i = 0; i < 5; i++)
		{
			if (strncmp(lit[i].ExHour, "0", 2) == 0)
			{
				j++;
			}
		}
		if (j == 0) return -1;
		return 1;
	}
	case '3':
	{
		for (int i = 0; i < 5; i++)
		{
			if (strncmp(Eng[i].PrHour, "0", 2) == 0)
			{
				j++;
			}
		}
		if (j == 0) return -1;
		return 1;
	}
	}

	return 0;
}

//根据入参a的值确定检查哪一类课程，1创新类，2文科类，3理工类，找到该类空着的课程项下标，然后返回，否则返回-1
int CheckCo(int a)//根据入参a的值确定检查哪一类课程，1创新类，2文科类，3理工类，找到该类空着的课程项下标，然后返回
{
	int k = 0;

	switch (a)
	{
	case 1:
	{
		for (int i = 0; i < 5; i++)
		{
			if (strncmp("0", Cre[i].ExHour, 1) == 0) k++;
		}
		return (5 - k);
	}
	case 2:
	{
		for (int i = 0; i < 5; i++)
		{
			if (strncmp("0", lit[i].ExHour, 1) == 0) k++;
		}
		return (5 - k);
	}
	case 3:
	{
		for (int i = 0; i < 5; i++)
		{
			if (strncmp("0", Eng[i].PrHour, 1) == 0) k++;
		}
		return (5 - k);
	}
	}

	return 0;
}

//系统主菜单
void Menu()
{
	int op;  //操作数
	int j = 0;  //控制操作数输入错误次数

	ReadB(1);
	ReadB(2);
	ReadB(3);
	ReadB(4);
	ReadB(5);
	system("cls");
	cout << "                              ——————————————————————————" << endl << endl;
	cout << "                              ********************学生选课系统********************" << endl << endl;
	cout << "                              (1) 登录" << endl << endl;
	cout << "                              (2) 注册" << endl << endl;
	cout << "                              (3) 帮助" << endl << endl;
	cout << "                              ——————————————————————————" << endl;
	cout << "                              输入操作数(1, 2, 3):";
	Mouse(50, 11);
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
		if (op == 1 || op == 2 || op == 3)
		{
			break;
		}
		else
		{
			system("cls");
			cout << "                              ——————————————————————————" << endl;
			cout << "                              操作数输入错误！请输入1/2/3,重新输入！最多可输入三次！" << endl;
			cout << "                              ——————————————————————————" << endl;
			cout << "                              (1) 登录" << endl << endl;
			cout << "                              (2) 注册" << endl << endl;
			cout << "                              (3) 帮助" << endl << endl;
			cout << "                              ——————————————————————————" << endl;
			cout << "                              输入操作数(1, 2, 3)：";
			Mouse(50, 10);
		}
	}
	try
	{
		switch (op)
		{
		case 1:
			Login();
			break;
		case 2:
			Register();
			break;
		case 3:
			Help();
			break;
		default:
			throw 3.33;
		}
	}
	catch (double Eng)
	{
		if (Eng == 3.33)
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              未知错误发生！请联系开发人员修改相应Bug!三秒后退出系统!" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(3000);
			exit(0);
		}
	}
}

void Help()
{
	system("cls");
	cout << "—————————————————————————————————————————" << endl;
	cout << "使用与帮助:" << endl;
	cout << "—————————————————————————————————————————" << endl;
	cout << "开发人员(姓名-电话-QQ): 杨孟衡-19979405286-964327216" << endl;
	cout << "—————————————————————————————————————————" << endl;
	cout << "系统信息：" << endl;
	cout << "—————————————————————————————————————————" << endl;
	cout << "学生选课系统,在系统初始登录界面可以参看系统的开发信息，" << endl;
	cout << "—————————————————————————————————————————" << endl;
	cout << "可以登录/注册系统账户，针对第一次使用本系统的学生，" << endl;
	cout << "—————————————————————————————————————————" << endl;
	cout << "需要先注册账号，即验证身份和设置密码，之后方可登录系统使用，" << endl;
	cout << "—————————————————————————————————————————" << endl;
	cout << "后台老师和注册过的学生直接登录系统即可。" << endl;
	cout << "—————————————————————————————————————————" << endl;
	cout << "老师可以对数据库数据进行添加，删除，信息修改，浏览数据库等操作。" << endl;
	cout << "—————————————————————————————————————————" << endl;
	cout << "学生可以浏览选修课程信息，选择选修课程，浏览个人信息，可以进行退选已选课程的操作，" << endl;
	cout << "—————————————————————————————————————————" << endl;
	cout << "还可以查询课程，查询某门课程学生的选修情况（比如该门课选修人数等等公共信息）" << endl;
	cout << "—————————————————————————————————————————" << endl;
	cout << "除此之外，需要注意的就是课程选修学分有所上限（学院要求为8学分或者四门选修课），" << endl;
	cout << "—————————————————————————————————————————" << endl;
	cout << "注意事项：" << endl;
	cout << "—————————————————————————————————————————" << endl;
	cout << "（1）操作数是用户需要进行操作的选项数，根据对应的功能需求输入不同操作数即可使用系统。" << endl;
	cout << "—————————————————————————————————————————" << endl;
	cout << "（2）本系统最终解释权归开发者所有，未经允许不得私自修改本系统。" << endl;
	cout << "—————————————————————————————————————————" << endl;
	Sleep(5000);

	char op[3];
	cout << "                              是否继续使用本系统？（是/否）:" << endl;
	Mouse(60, 29);
	cin.width(3);
	cin >> op;
	Check();
	if (strcmp(op, "是") == 0)
	{
		cout << "                              ——————————————————————————" << endl;
		cout << "                              2秒后返回主界面!" << endl;
		cout << "                              ——————————————————————————" << endl;
		Sleep(2000);
		Menu();
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
}

//注册模块
void Register()
{
	int op;
	int j = 0;

	system("cls");
	cout << "                              ——————————————————————————" << endl << endl;
	cout << "                              **********************注册模块**********************" << endl << endl;
	cout << "                              (1) 学生注册" << endl << endl;
	cout << "                              (2) 老师注册" << endl << endl;
	cout << "                              (3) 退出系统" << endl << endl;
	cout << "                              ——————————————————————————" << endl;
	cout << "                              输入操作数(1, 2, 3):";
	Mouse(30, 12);
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
		if (op == 1 || op == 2 || op == 3)
		{
			break;
		}
		else
		{
			system("cls");
			cout << "                              ——————————————————————————" << endl << endl;
			cout << "                              **********************注册模块**********************" << endl << endl;
			cout << "                              (1) 学生注册" << endl << endl;
			cout << "                              (2) 老师注册" << endl << endl;
			cout << "                              (3) 退出系统" << endl << endl;
			cout << "                              ——————————————————————————" << endl;
			cout << "                              输入操作数(1, 2, 3):";
			Mouse(30, 12);
		}
	}
	try
	{
		switch (op)
		{
		case 1:
		{
			int k;

			if ((k = STU[9].CheckSTU()) == -1)
			{
				cout << "                              ——————————————————————————" << endl;
				cout << "                              系统性能有限！注册名额已达上限！请耐心等待系统优化！" << endl;
				cout << "                              ——————————————————————————" << endl;
				cout << "                              2秒后退出系统！" << endl;
				cout << "                              ——————————————————————————" << endl;
				Sleep(2000);
				exit(0);
			}
			STUDENT* Stu = new STUDENT;
			Stu->SetSTU();
			STU[k] = *Stu;
			WriteB(1);
			STU[k].STMenu();
			break;
		}
		case 2:
		{
			char ML[9];
			int k;

			if ((k = ADmin[9].CheckAD()) == -1)
			{
				cout << "                              ——————————————————————————" << endl;
				cout << "                              系统性能有限！注册名额已达上限！请耐心等待系统优化！" << endl;
				cout << "                              ——————————————————————————" << endl;
				cout << "                              2秒后退出系统！" << endl;
				cout << "                              ——————————————————————————" << endl;
				Sleep(2000);
				exit(0);
			}
			system("cls");
			cout << "                              ——————————————————————————" << endl;
			cout << "                              输入注册密令:" << endl;
			cout << "                              ——————————————————————————" << endl;
			cin.width(9);
			Mouse(30, 3);
			cin >> ML;
			if (ADmin[0].CheckADPS(ML) == 1)
			{
				ADMIN* admin = new ADMIN;
				admin->SetAD();
				ADmin[k] = *admin;
				WriteB(2);
				ADmin[k].ADMenu();
				break;
			}
			else
			{
				cout << "                              ——————————————————————————" << endl;
				cout << "                              密令输入错误！检查到非老师人员注册老师账户！退出系统！" << endl;
				Sleep(2000);
				exit(0);
			}
			break;
		}
		case 3:
			exit(0);
		default:
			throw 3.33;
		}
	}
	catch (double Eng)
	{
		if (Eng == 3.33)
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              未知错误发生！请联系开发人员修改相应Bug!三秒后退出系统!" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(3000);
			exit(0);
		}
	}
}

//登录模块
void Login()
{
	int op;
	int j = 0;

	system("cls");
	cout << "                              ——————————————————————————" << endl << endl;
	cout << "                              **********************登录模块**********************" << endl << endl;
	cout << "                              (1) 老师" << endl << endl;
	cout << "                              (2) 学生" << endl << endl;
	cout << "                              (3) 退出系统" << endl << endl;
	cout << "                              ——————————————————————————" << endl;
	cout << "                              输入操作数(1, 2, 3):";
	Mouse(30, 12);
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
		if (op == 1 || op == 2 || op == 3)
		{
			break;
		}
		else
		{
			system("cls");
			cout << "                              ——————————————————————————" << endl << endl;
			cout << "                              **********************登录模块**********************" << endl << endl;
			cout << "                              (1) 老师" << endl << endl;
			cout << "                              (2) 学生" << endl << endl;
			cout << "                              (3) 退出系统" << endl << endl;
			cout << "                              ——————————————————————————" << endl;
			cout << "                              输入操作数(1, 2, 3):";
			Mouse(30, 12);
			cin.width(1);
			cin >> op;
			j++;
			Check();
		}
	}
	switch (op)
	{
	case 1:
		char PAS[11];
		char PA[11];

	first:
		system("cls");
		cout << "                              ——————————————————————————" << endl;
		cout << "                              账号:" << endl;
		Mouse(30, 2);
		cin.width(11);
		cin >> PA;
		Check();
		cout << "                              ——————————————————————————" << endl;
		cout << "                              密码:" << endl;
		Mouse(30, 5);
		cin.width(11);
		cin >> PAS;
		Check();
		n = CheckPAPAS(PA, PAS, 1);
		if(n == -1)
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              没有这个账号！请先注册！" << endl;
			cout << "                              ——————————————————————————" << endl;
			cout << "                              2秒后转注册模块！" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(2000);
			Register();
			break;
		}
		else if (n == -2)
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              密码错误！重载！" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(2000);
			goto first;
		}
		else
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              登录成功！欢迎使用本系统！" << endl;
			cout << "                              ——————————————————————————" << endl;
			cout << "                              2秒后转主菜单!" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(2000);
			ADmin[n].ADMenu();
			break;
		}
	case 2:
	{
		char PAS[11];
		char PA[11];
		
		second:
		system("cls");
		cout << "                              ——————————————————————————" << endl;
		cout << "                              账号:" << endl;
		Mouse(30, 2);
		cin.width(11);
		cin >> PA;
		Check();
		cout << "                              ——————————————————————————" << endl;
		cout << "                              密码:" << endl;
		Mouse(30, 5);
		cin.width(11);
		cin >> PAS;
		Check();
		n = CheckPAPAS(PA, PAS);
		if (n == -1)
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              没有这个账号！请先注册！" << endl;
			cout << "                              ——————————————————————————" << endl;
			cout << "                              2秒后转注册模块！" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(2000);
			Register();
			break;
		}
		else if(n == -2)
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              密码错误！重载！" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(2000);
			goto second;
		}
		else
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              登录成功！欢迎使用本系统！" << endl;
			cout << "                              ——————————————————————————" << endl;
			cout << "                              2秒后转主菜单!" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(2000);
			STU[n].STMenu();
			break;
		}
	}
	default:
	{
		cout << "                              ——————————————————————————" << endl;
		cout << "                              2秒后退出系统" << endl;
		Sleep(2000);
		exit(0);
	}
	}
}

void STUDENT::Option()  //选课
{
	char CName[11];
	int flag;
	int U;
	int y = 0;

	system("cls");
	if (this->CNum == 4 || this->OS >= 8)
	{
		cout << "                              ——————————————————————————" << endl;
		cout << "                              你已经达到学院要求的选修课要求了！2秒后返回主菜单！" << endl;
		Sleep(2000);
		this->STMenu();
	}
	cout << "                              ——————————————————————————" << endl;
	cout << "                              选修模块：" << endl;
	cout << "                              ——————————————————————————" << endl;
	cout << "                              可选创新类课程信息一览：" << endl;
	for (int i = 0; i < 5; i++)
	{
		if (strncmp(Cre[i].ExHour, "0", 2) != 0)
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                           |  课程编号  |  课程名  |  课程类别  |  课程学时  |  课程学分  |" << endl;
			cout << "                              ——————————————————————————" << endl;
			cout << "                           |  开课学期  |  课程选修人数  |  实验学时  |  上机学时  |" << endl;
			cout << "                              ——————————————————————————" << endl;
			cout << "                           |  " << Cre[i].CNumber << "  |  " << Cre[i].CName << "  |  " << Cre[i].CKind << "  |  " << Cre[i].ClassHour
				<< "  |  " << Cre[i].ClassScore << "  |" << endl;
			cout << "                           |  " << Cre[i].Opentime << "  |  " << Cre[i].Person << "/" << Cre[i].Max << "  |  " << Cre[i].ExHour
				<< "  |  " << Cre[i].PrHour << "  |" << endl;
			y++;
		}
	}
	cout << "                              ——————————————————————————" << endl;
	cout << "                              可选文科类课程信息一览：" << endl;
	for (int i = 0; i < 5; i++)
	{
		if (strncmp(lit[i].ExHour, "0", 2) != 0)
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                           |  课程编号  |  课程名  |  课程类别  |  课程学时  |  课程学分  |" << endl;
			cout << "                              ——————————————————————————" << endl;
			cout << "                           |  开课学期  |  课程选修人数  |  实验学时  |" << endl;
			cout << "                              ——————————————————————————" << endl;
			cout << "                           |  " << lit[i].CNumber << "  |  " << lit[i].CName << "  |  " << lit[i].CKind << "  |  " << lit[i].ClassHour
				<< "  |  " << lit[i].ClassScore << "  |" << endl;
			cout << "                           |  " << lit[i].Opentime << "  |  " << lit[i].Person << "/" << lit[i].Max << "  |  " << lit[i].ExHour
				<< "  |" << endl;
			y++;
		}
	}
	cout << "                              ——————————————————————————" << endl;
	cout << "                              可选理工科类课程信息一览：" << endl;
	for (int i = 0; i < 5; i++)
	{
		if (strncmp(Eng[i].PrHour, "0", 2) != 0)
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                           |  课程编号  |  课程名  |  课程类别  |  课程学时  |  课程学分  |" << endl;
			cout << "                              ——————————————————————————" << endl;
			cout << "                           |  开课学期  |  课程选修人数   |  上机学时  |" << endl;
			cout << "                              ——————————————————————————" << endl;
			cout << "                           |  " << Eng[i].CNumber << "  |  " << Eng[i].CName << "  |  " << Eng[i].CKind << "  |  " << Eng[i].ClassHour
				<< "  |  " << Eng[i].ClassScore << "  |" << endl;
			cout << "                           |  " << Eng[i].Opentime << "  |  " << Eng[i].Person << "/" << Eng[i].Max << "  |  " << Eng[i].PrHour << "  |" << endl;
			cout << "                              ——————————————————————————" << endl;
			y++;
		}
	}
	Sleep(10000);
	cout << "                              ——————————————————————————" << endl;
	cout << "                              输入你想要选修的课程名:" << endl;
	cout << "                              ——————————————————————————" << endl;
	Mouse(30, 8 * y + 10);
	cin.width(11);
	cin >> CName;
	Check();
	if (*(CheckCo(CName)) != 'a' && (CheckCo(CName, 2.0) != -1))
	{
		flag = Search(CName, 'i');
		switch (flag)
		{
		case 1:
		{
			U = Search(CName, 1, 't');
			for (int i = 0; i < 4; i++)
			{
				if (strncmp(this->AC[i], Cre[U].CName, 11) == 0)
				{
					cout << "                              ——————————————————————————" << endl;
					cout << "                              你已经选修过该课程了！2秒后返回主菜单!" << endl;
					Sleep(2000);
					this->STMenu();
				}
			}
			this->CNum++;
			cout << "                              ——————————————————————————" << endl;
			cout << "                              选修成功！你还可以选修最多" << (4 - this->CNum) << "门选修课!" << endl;
			Cre[U].Person++;
			this->OS += (Cre[U].ClassScore);
			switch (CNum - 1)
			{
			case 0:strncpy(this->AC[0], CName, 11); break;
			case 1:strncpy(this->AC[1], CName, 11); break;
			case 2:strncpy(this->AC[2], CName, 11); break;
			case 3:strncpy(this->AC[3], CName, 11); break;
			}
			WriteB(1);
			WriteB(3);
			cout << "                              ——————————————————————————" << endl;
			cout << "                              2秒后返回主菜单!" << endl;
			Sleep(2000);
			this->STMenu();
			break;
		}
		case 2:
		{
			U = Search(CName, 2, 't');
			for (int i = 0; i < 4; i++)
			{
				if (strncmp(this->AC[i], lit[U].CName, 11) == 0)
				{
					cout << "                              ——————————————————————————" << endl;
					cout << "                              你已经选修过该课程了！2秒后返回主菜单!" << endl;
					Sleep(2000);
					this->STMenu();
				}
			}
			this->CNum++;
			cout << "                              ——————————————————————————" << endl;
			cout << "                              选修成功！你还可以选修最多" << (4 - this->CNum) << "门选修课!" << endl;
			lit[U].Person++;
			this->OS += (lit[U].ClassScore);
			switch (CNum - 1)
			{
			case 0:strncpy(this->AC[0], CName, 11); break;
			case 1:strncpy(this->AC[1], CName, 11); break;
			case 2:strncpy(this->AC[2], CName, 11); break;
			case 3:strncpy(this->AC[3], CName, 11); break;
			}
			WriteB(1);
			WriteB(4);
			cout << "                              ——————————————————————————" << endl;
			cout << "                              2秒后返回主菜单!" << endl;
			Sleep(2000);
			this->STMenu();
			break;
		}
		case 3:
		{
			U = Search(CName, 3, 't');
			for (int i = 0; i < 4; i++)
			{
				if (strncmp(this->AC[i], Eng[U].CName, 11) == 0)
				{
					cout << "                              ——————————————————————————" << endl;
					cout << "                              你已经选修过该课程了！2秒后返回主菜单!" << endl;
					Sleep(2000);
					this->STMenu();
				}
			}
			this->CNum++;
			cout << "                              ——————————————————————————" << endl;
			cout << "                              选修成功！你还可以选修最多" << (4 - this->CNum) << "门选修课!" << endl;
			Eng[U].Person++;
			this->OS += (Eng[U].ClassScore);
			switch (CNum - 1)
			{
			case 0:strncpy(this->AC[0], CName, 11); break;
			case 1:strncpy(this->AC[1], CName, 11); break;
			case 2:strncpy(this->AC[2], CName, 11); break;
			case 3:strncpy(this->AC[3], CName, 11); break;
			}
			WriteB(1);
			WriteB(5);
			cout << "                              ——————————————————————————" << endl;
			cout << "                              2秒后返回主菜单!" << endl;
			Sleep(2000);
			this->STMenu();
			break;
		}
		}
	}
	else
	{
		cout << "                              ——————————————————————————" << endl;
		cout << "                              没有这门课程！2秒后返回主菜单!" << endl;
		Sleep(2000);
		this->STMenu();
	}
}

void  STUDENT::Reference(int a)//浏览数据，a=1表示已选课程信息，a=2表示个人信息
{
	switch (a)
	{
	case 1:
	{
		system("cls");
		cout << "                              ——————————————————————————" << endl;
		cout << "                             |已选课程：" << endl;
		cout << "                              ——————————————————————————" << endl;
		for (int i = 0; i < 4; i++)
		{
				cout << "                              ——————————————————————————" << endl;
				cout << "                              || " << this->AC[i] << endl;
				cout << "                              ——————————————————————————" << endl;
		}
		break;
	}
	case 2:
	{
		system("cls");
		cout << "                              ——————————————————————————" << endl;
		cout << "                              个人信息：" << "  ||  姓名：" << this->SName << endl;
		cout << "                              ——————————————————————————" << endl;
		cout << "                              账号：" << this->SNumber << "||  密码：" << this->STPa << endl;
		cout << "                              ——————————————————————————" << endl;
		cout << "                              联系方式:" << this->SP << "  ||  学分:" << this->OS << endl;
		cout << "                              ——————————————————————————" << endl;
		break;
	}
	default:
		exit(0);
	}
}

void  STUDENT::Drop()  //退课
{
	char CName[11];
	int U;
	int flag;
	int p = 0;

	system("cls");
	if (this->CNum == 0 || this->OS == 0)
	{
		cout << "                              ——————————————————————————" << endl;
		cout << "                              你一门课程都还没有选修！2秒后返回主菜单！" << endl;
		Sleep(2000);
		this->STMenu();
	}
	this->Reference(1);
	cout << "                              ——————————————————————————" << endl;
	cout << "                              输入你需要退选的课程:" << endl;
	Mouse(30, 17);
	cin.width(11);
	cin >> CName;
	Check();
	char* CC = CheckCo(CName);
	if (*CC != 'a')
	{
		flag = Search(CName, 'y');
		switch (flag)
		{
		case 1:
		{
			U = Search(CName, 1, 't');
			for (int i = 0; i < 4; i++)
			{
				if (strncmp(this->AC[i], Cre[U].CName, 11) != 0)
				{
					p++;
				}
			}
			if (p >= 4)
			{
				cout << "                              ——————————————————————————" << endl;
				cout << "                              你还没有选修过该课程！请先选修对应课程！" << endl;
				Sleep(2000);
				this->STMenu();
				break;
			}
			this->CNum--;
			cout << "                              ——————————————————————————" << endl;
			cout << "                              退选成功！还可以选修最多" << (4 - this->CNum) << "门选修课!" << endl;
			Cre[U].Person--;
			this->OS -= Cre[U].ClassScore;
			WriteB(3);
			break;
		}
		case 2:
		{
			U = Search(CName, 2, 't');
			for (int i = 0; i < 4; i++)
			{
				if (strncmp(this->AC[i], lit[U].CName, 11) != 0)
				{
					p++;
				}
			}
			if (p >= 4)
			{
				cout << "                              ——————————————————————————" << endl;
				cout << "                              你还没有选修过该课程！请先选修对应课程！" << endl;
				Sleep(2000);
				this->STMenu();
				break;
			}
			this->CNum--;
			cout << "                              ——————————————————————————" << endl;
			cout << "                              退选成功！还可以选修最多" << (4 - this->CNum) << "门选修课!" << endl;
			lit[U].Person--;
			this->OS -= lit[U].ClassScore;
			WriteB(4);
			break;
		}
		case 3:
		{
			U = Search(CName, 3, 't');
			for (int i = 0; i < 4; i++)
			{
				if (strncmp(this->AC[i], Eng[U].CName, 11) != 0)
				{
					p++;
				}
			}
			if (p >= 4)
			{
				cout << "                              ——————————————————————————" << endl;
				cout << "                              你还没有选修过该课程！请先选修对应课程！" << endl;
				Sleep(2000);
				this->STMenu();
				break;
			}
			this->CNum--;
			cout << "                              ——————————————————————————" << endl;
			cout << "                              退选成功！还可以选修最多" << (4 - this->CNum) << "门选修课!" << endl;
			Eng[U].Person--;
			this->OS -= Eng[U].ClassScore;
			WriteB(5);
			break;
		}
		}
		switch (CNum + 1)
		{
		case 1:strncpy(this->AC[0], "\0", 11); break;
		case 2:strncpy(this->AC[1], "\0", 11); break;
		case 3:strncpy(this->AC[2], "\0", 11); break;
		case 4:strncpy(this->AC[3], "\0", 11); break;
		}
		WriteB(1);
		cout << "                              ——————————————————————————" << endl;
		cout << "                              2秒后返回主菜单!" << endl;
		Sleep(2000);
		this->STMenu();
	}
	else
	{
		cout << "                              ——————————————————————————" << endl;
		cout << "                              没有这门课程！" << "2秒后返回主菜单!" << endl;
		Sleep(2000);
		this->STMenu();
	}
}

void Create::Show()
{
		cout << "                              ——————————————————————————" << endl;
		cout << "                              创新类课程信息一览：" << endl;
		cout << "                              ——————————————————————————" << endl;
		cout << "                           |  课程编号  |  课程名  |  课程类别  |  课程学时  |  课程学分  |" << endl;
		cout << "                              ——————————————————————————" << endl;
		cout << "                           |  开课学期  |  课程选修人数  |  实验学时  |  上机学时  |" << endl;
		cout << "                              ——————————————————————————" << endl;
		cout << "                           |  " << this->CNumber << "  |  " << this->CName << "  |  " << this->CKind << "  |  " << this->ClassHour
			<< "  |  " << this->ClassScore << "  |" << endl;
		cout << "                           |  " << this->Opentime << "  |  " << this->Person << "/" << this->Max << "  |  " << this->ExHour
			<< "  |  " << this->PrHour << "  |" << endl;
		cout << "                              ——————————————————————————" << endl;
}

void Literate::Show()
{
		cout << "                              ——————————————————————————" << endl;
		cout << "                              文科类课程信息一览：" << endl;
		cout << "                              ——————————————————————————" << endl;
		cout << "                           |  课程编号  |  课程名  |  课程类别  |  课程学时  |  课程学分  |" << endl;
		cout << "                              ——————————————————————————" << endl;
		cout << "                           |  开课学期  |  课程选修人数  |  实验学时  |" << endl;
		cout << "                              ——————————————————————————" << endl;
		cout << "                           |  " << this->CNumber << "  |  " << this->CName << "  |  " << this->CKind << "  |  " << this->ClassHour
			<< "  |  " << this->ClassScore << "  |" << endl;
		cout << "                           |  " << this->Opentime << "  |  " << this->Person << "/" << this->Max << "  |  " << this->ExHour
			<< "  |" << endl;
		cout << "                              ——————————————————————————" << endl;
}

void Engineering::Show()
{
	cout << "                              ——————————————————————————" << endl;
	cout << "                              文科类课程信息一览：" << endl;
	cout << "                              ——————————————————————————" << endl;
	cout << "                           |  课程编号  |  课程名  |  课程类别  |  课程学时  |  课程学分  |" << endl;
	cout << "                              ——————————————————————————" << endl;
	cout << "                           |  开课学期  |  课程选修人数  |  实验学时  |" << endl;
	cout << "                              ——————————————————————————" << endl;
	cout << "                           |  " << this->CNumber << "  |  " << this->CName << "  |  " << this->CKind << "  |  " << this->ClassHour
		<< "  |  " << this->ClassScore << "  |" << endl;
	cout << "                           |  " << this->Opentime << "  |  " << this->Person << "/" << this->Max << "  |  " << this->PrHour
		<< "  |" << endl;
	cout << "                              ——————————————————————————" << endl;
}

void ADMIN::Reference(int a) //浏览课程信息,a=1表示课程信息,a=2表示个人信息
{
	switch (a)
	{
	case 1:
	{
		int u = 0;
		system("cls");
		cout << "                              ——————————————————————————" << endl;
		cout << "                              浏览课程信息:" << endl;
		cout << "                              ——————————————————————————" << endl;
		for (int i = 0; i < 5; i++)
		{
			if (strncmp(Cre[i].ExHour, "0", 11) != 0)
			{
				u++;
				Cre[i].Show();
			}
			if (strncmp(lit[i].ExHour, "0", 11) != 0)
			{
				lit[i].Show();
				u++;
			}
			if (strncmp(Eng[i].PrHour, "0", 11) != 0)
			{
				Eng[i].Show();
				u++;
			}
		}
		Sleep(10000);
		char op[3];
		cout << "                              ——————————————————————————" << endl;
		cout << "                              是否继续使用本系统？（是/否）:" << endl;
		Mouse(30, 10 * u + 5);
		cin.width(3);
		cin >> op;
		Check();
		if (strcmp(op, "是") == 0)
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              2秒后返回主界面!" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(2000);
			this->ADMenu();
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
	case 2:
	{
		system("cls");
		cout << "                              ——————————————————————————" << endl;
		cout << "                              个人信息：" << endl;
		cout << "                              ——————————————————————————" << endl;
		cout << "                              账号：" << this->Admin << "  ||  密码：" << this->ADP << endl;
		cout << "                              ——————————————————————————" << endl;
		break;
	}
	default:
		exit(0);
	}
}

void ADMIN::Modify()  //修改数据
{
	char OP[11];
	int op;
	third:
	system("cls");
	cout << "                              ——————————————————————————" << endl;
	cout << "                              修改模块：" << endl;
	cout << "                              ——————————————————————————" << endl;
	cout << "                              输入修改哪类课程（1创新创业类，2文科文学类，3理工科学类）:" << endl;
	Mouse(30, 4);
	cin.width(1);
	cin >> op;
	Check();
	if (op != 1 && op != 2 && op != 3)
	{
		cout << "                              ——————————————————————————" << endl;
		cout << "                              输入错误！重新输入！" << endl;
		Sleep(2000);
		goto third;
	}
	switch (op)
	{
	case 1:
	{
		system("cls");
		cout << "                              ——————————————————————————" << endl;
		cout << "                              输入修改的课程名:" << endl;
		Mouse(30, 2);
		cin.width(11);
		cin >> OP;
		Check();
		j = Search(OP, 1, 't');
		if (j != -1)
		{
			Create cre;
			cre.SetC();
			Cre[j] = cre;
			WriteB(3);
			cout << "                              ——————————————————————————" << endl;
			cout << "                              修改成功！返回主菜单！" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
		else
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              没有找到此课程！返回主菜单!" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
	}
	case 2:
	{
		system("cls");
		cout << "                              ——————————————————————————" << endl;
		cout << "                              输入修改的课程名:" << endl;
		Mouse(30, 2);
		cin.width(11);
		cin >> OP;
		Check();
		j = Search(OP, 2, 't');
		if (j != -1)
		{
			Literate Lit;
			Lit.SetL();
			lit[j] = Lit;
			WriteB(4);
			cout << "                              ——————————————————————————" << endl;
			cout << "                              修改成功！返回主菜单！" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
		else
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              没有找到此课程！返回主菜单!" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
	}
	case 3:
	{
		system("cls");
		cout << "                              ——————————————————————————" << endl;
		cout << "                              输入修改的课程名:" << endl;
		Mouse(30, 2);
		cin.width(11);
		cin >> OP;
		Check();
		j = Search(OP, 3, 't');
		if (j != -1)
		{
			Engineering eng;
			eng.SetE();
			Eng[j] = eng;
			WriteB(5);
			cout << "                              ——————————————————————————" << endl;
			cout << "                              修改成功！返回主菜单！" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
		else
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              没有找到此课程！返回主菜单!" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
	}
	}
}

void ADMIN::Add() //添加数据
{
	int op;
forth:
	system("cls");
	cout << "                              ——————————————————————————" << endl;
	cout << "                              添加模块：" << endl;
	cout << "                              ——————————————————————————" << endl;
	cout << "                              输入添加哪类课程（1创新创业类，2文科文学类，3理工科学类）:" << endl;
	Mouse(30, 4);
	cin.width(1);
	cin >> op;
	Check();
	if (op != 1 && op != 2 && op != 3)
	{
		cout << "                              ——————————————————————————" << endl;
		cout << "                              输入错误！重新输入！" << endl;
		Sleep(2000);
		goto forth;
	}
	switch (op)
	{
	case 1:
	{
		int y;
	
		system("cls");
		if (y = CheckCo('1') == -1)
		{
			break;
		}
		else
		{
			j = CheckCo(1);
			Create crea;
			crea.SetC();
			Cre[j] = crea;
			WriteB(3);
			cout << "                              ——————————————————————————" << endl;
			cout << "                              添加成功！2秒后返回主菜单!" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
	}
	case 2:
	{
		int y;

		system("cls");
		if (y = CheckCo('1') == -1)
		{
			break;
		}
		else
		{
			j = CheckCo(2);
			Literate LIT;
			LIT.SetL();
			lit[j] = LIT;
			WriteB(4);
			cout << "                              ——————————————————————————" << endl;
			cout << "                              添加成功！2秒后返回主菜单!" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
	}
	case 3:
	{
		int y;

		system("cls");
		if (y = CheckCo('1') == -1)
		{
			break;
		}
		else
		{
			j = CheckCo(3);
			Engineering ENG;
			ENG.SetE();
			Eng[j] = ENG;
			WriteB(5);
			cout << "                              ——————————————————————————" << endl;
			cout << "                              添加成功！2秒后返回主菜单!" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
	}
	}
	cout << "                              ——————————————————————————" << endl;
	cout << "                              非常抱歉！当前数据项已满！请耐心等待系统优化！" << endl;
	Sleep(2000);
	this->ADMenu();
}

void ADMIN::Delete() //删除数据
{
	char OP[11];
	int op;

fifth:
	system("cls");
	cout << "                              ——————————————————————————" << endl;
	cout << "                              删除模块：" << endl;
	cout << "                              ——————————————————————————" << endl;
	cout << "                              输入删除哪类课程（1创新创业类，2文科文学类，3理工科学类）:" << endl;
	Mouse(30, 4);
	cin.width(1);
	cin >> op;
	Check();
	if (op != 1 && op != 2 && op != 3)
	{
		cout << "                              ——————————————————————————" << endl;
		cout << "                              输入错误！重新输入！" << endl;
		Sleep(2000);
		goto fifth;
	}
	switch (op)
	{
	case 1:
	{
		if (strncmp(Cre[0].ExHour, "0", 2) == 0)
		{
			break;
		}
		system("cls");
		cout << "                              ——————————————————————————" << endl;
		cout << "                              输入删除的课程名:" << endl;
		Mouse(30, 2);
		cin.width(11);
		cin >> OP;
		Check();
		j = Search(OP, 1, 't');
		if (j != -1)
		{
			Create cre;
			Cre[j] = cre;
			WriteB(3);
			cout << "                              ——————————————————————————" << endl;
			cout << "                              删除成功！返回主菜单！" << endl;
			Sleep(2000);
			break;
		}
		else
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              没有找到此课程！返回主菜单!" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
	}
	case 2:
	{
		if (strncmp(lit[4].ExHour, "0", 2) == 0)
		{
			break;
		}
		system("cls");
		cout << "                              ——————————————————————————" << endl;
		cout << "                              输入删除的课程名:" << endl;
		Mouse(30, 2);
		cin.width(11);
		cin >> OP;
		Check();
		j = Search(OP, 2, 't');
		if (j != -1)
		{
			Literate LIT;
			lit[j] = LIT;
			WriteB(4);
			cout << "                              ——————————————————————————" << endl;
			cout << "                              删除成功！返回主菜单！" << endl;
			Sleep(2000);
			break;
		}
		else
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              没有找到此课程！返回主菜单!" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
	}
	case 3:
	{
		if (strncmp(Eng[4].PrHour, "0", 2) == 0)
		{
			break;
		}
		system("cls");
		cout << "                              ——————————————————————————" << endl;
		cout << "                              输入删除的课程名:" << endl;
		Mouse(30, 2);
		cin.width(11);
		cin >> OP;
		Check();
		j = Search(OP, 3, 't');
		if(j != -1)
		{
			Engineering ENG;
			Eng[j] = ENG;
			WriteB(5);
			cout << "                              ——————————————————————————" << endl;
			cout << "                              删除成功！返回主菜单！" << endl;
			Sleep(2000);
			break;
		}
		else
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              没有找到此课程！返回主菜单!" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
	}
	}
	cout << "                              ——————————————————————————" << endl;
	cout << "                              非常抱歉！当前数据库还未初始化！请先添加数据！" << endl;
	Sleep(2000);
	this->ADMenu();
}

void  STUDENT::Sear()  //查询信息
{
	char CName[11];
	int t;
	int flag;

	system("cls");
	cout << "                              ——————————————————————————" << endl;
	cout << "                              查询模块：" << endl;
	cout << "                              ——————————————————————————" << endl;
	cout << "                              输入查询的课程名：" << endl;
	Mouse(30, 4);
	cin.width(11);
	cin >> CName;
	Check();
	flag = Search(CName, 'b');
	switch(flag)
	{
	case 1:
	{
		t = Search(CName, 1, 't');
		system("cls");
		Cre[t].Show();
		Sleep(2000);
		fifth:
		char op[3];
		cout << "                              ——————————————————————————" << endl;
		cout << "                              是否继续使用本系统？（是/否）:" << endl;
		Mouse(30, 12);
		cin.width(3);
		cin >> op;
		Check();
		if (strcmp(op, "是") == 0)
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              2秒后返回主界面!" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(2000);
			this->STMenu();
			break;
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
			cout << "                              输入错误！请根据括号内提示输入！" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(1000);
			goto fifth;
		}
	}
	case 2:
	{
		t = Search(CName, 2, 't');
		system("cls");
		lit[t].Show();
		Sleep(2000);
		char op[3];
		sixth:
		cout << "                              ——————————————————————————" << endl;
		cout << "                              是否继续使用本系统？（是/否）:" << endl;
		Mouse(30, 12);
		cin.width(3);
		cin >> op;
		Check();
		if (strcmp(op, "是") == 0)
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              2秒后返回主界面!" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(2000);
			this->STMenu();
			break;
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
			cout << "                              输入错误！请根据括号内的提示输入！" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(1000);
			goto sixth;
		}
	}
	case 3:
	{
		t = Search(CName, 3, 't');
		system("cls");
		Eng[t].Show();
		Sleep(2000);
		char op[3];
		seventh:
		cout << "                              ——————————————————————————" << endl;
		cout << "                              是否继续使用本系统？（是/否）:" << endl;
		Mouse(30, 12);
		cin.width(3);
		cin >> op;
		Check();
		if (strcmp(op, "是") == 0)
		{
			cout << "                              ——————————————————————————" << endl;
			cout << "                              2秒后返回主界面!" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(2000);
			this->STMenu();
			break;
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
			cout << "                              输入错误！请根据括号内的提示输入！" << endl;
			cout << "                              ——————————————————————————" << endl;
			Sleep(1000);
			goto seventh;
		}
	}
	default:
	{
		cout << "                              ——————————————————————————" << endl;
		cout << "                              该课程不存在！2秒后返回主菜单！" << endl;
		Sleep(2000);
		this->STMenu();
		break;
	}
	}
}

int STUDENT::CheckSTU()
{
	int i;
	int j = 0;

	for (i = 0; i < 10; i++)
	{
		if (strncmp(STU[i].SNumber, "0", 1) == 0)
		{
			j++;
		}
	}
	if (j == 0) return -1;
	else return (10 - j);
}

int ADMIN::CheckAD()
{
	int i;
	int j = 0;

	for (i = 0; i < 10; i++)
	{
		if (strncmp(ADmin[i].Admin, "0", 1) == 0)
		{
			j++;
		}
	}
	if (j == 0) return -1;
	else return (10 - j);
}