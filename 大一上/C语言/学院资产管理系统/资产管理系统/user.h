#pragma once
#include <string>

using namespace std;

class user
{
public:
	string name;
	void Return();//归还函数
	void search();//搜索函数
	void Borrow();//借用函数
	user(const string Name);
};