#pragma once
#include<string.h>
using namespace std;

class ADMIN
{
private:
	char Admin[11];  //老师账号
	char ADP[11];  //密码
public:
	static char ADPS[9];  //注册密令
	ADMIN();
	~ADMIN();
	void ADMenu();
	bool CheckADPS(char * c);  //检查注册密令
	friend int CheckPAPAS(char * Crea, char * c1, int a); 
	friend int Search(char * Crea, int b);
	void SetAD();  //初始化老师类成员
	void Modify();  //修改数据
	void Add(); //添加数据
	void Delete(); //删除数据
	void Reference(int a);  //浏览课程信息,a=1表示课程信息,a=2表示个人信息
	static int CheckAD(); //检查老师数组是否已满
};