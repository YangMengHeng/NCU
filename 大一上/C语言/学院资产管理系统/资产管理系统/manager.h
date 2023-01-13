#pragma once
#include <string>
#include "user.h"
using namespace std;

class manager: public user//继承user类的函数
{
public:
	 string password;
	 void Reference();//浏览函数
	 void change();//修改函数，方便进行数据修改
	 manager(const string Name, string Password);
};

int search_return1();//为后续修改数据提供便利
int search_return2();//为后续修改数据提供便利
void readfile(int choice);//对文件进行读取
void writefile(int choice);//对文件进行写入