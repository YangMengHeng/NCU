#pragma once
#include<string.h>
using namespace std;

class STUDENT
{
private:
	char SNumber[11];  //学生账号
	char SName[11];  //学生姓名
	char STPa[11];  //密码
	char SP[12];  //学生电话
	int CNum;  //选修课程数
	double OS;  //选修课程的学分
	char AC[4][11];  //已选课程二维数组
public:
	STUDENT();
	~STUDENT();
	void STMenu(); //学生主菜单
	void SetSTU();  //初始化学生类成员
	friend int CheckPAPAS(char * Crea, char * c1);  
	friend int Search(char * Crea);
	void Option();  //选课
	void Reference(int a);  //浏览数据，a=1表示已选课程信息，a=2表示个人信息
	void Drop();  //退课
	void Sear();  //查询信息
	static int CheckSTU(); //检查学生账号数组是否已满,没有满则返回对应数量
};