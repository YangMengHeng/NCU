#pragma once
#include<iostream>
#include"Assist.h"
using namespace std;

struct BaseCourse
{
	char CNumber[11];  //课程编号
	char CName[11];  //课程名
	char CKind[11];  //课程性质
	char CHeadline[21];  //课程大纲
	unsigned int ClassHour;  //课程学时
	double ClassScore;  //课程学分
	char Opentime[11];  //开课学期
	unsigned int Person;  //已选人数
	unsigned int Max;  //人数上限
	virtual void Show() = 0;  //显示虚函数
};