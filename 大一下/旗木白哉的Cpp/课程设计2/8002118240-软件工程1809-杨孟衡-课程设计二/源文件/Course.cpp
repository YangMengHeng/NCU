#include"Course.h"
#include<iostream>
#include<string>
using namespace std;

Create::Create() :ExHour("0") {}

Literate::Literate() : ExHour("0") {}

Engineering::Engineering() : PrHour("0") {}

void Create::SetC()
{
	system("cls");
	cout << "                              ——————————————————————————" << endl;
	cout << "                              初始化创新类课程:" << endl;
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程编号（最多10个字符）：" << endl;
	Mouse(30, 4);
	cin.width(11);
	cin >> this->CNumber;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程名(最多10个字符)：" << endl;
	Mouse(30, 7);
	cin.width(11);
	cin >> this->CName;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程性质（最多10个字符， 创新创业类，文学文科类，理工科学类）：" << endl;
	Mouse(30, 10);
	cin.width(11);
	cin >> this->CKind;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程大纲（最多20个字符）" << endl;
	Mouse(30, 13);
	cin.width(21);
	cin >> this->CHeadline;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程学时（数字）:" << endl;
	Mouse(30, 16);
	cin.width(2);
	cin >> this->ClassHour;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程开课学期（最多10个字符）:" << endl;
	Mouse(30, 19);
	cin.width(11);
	cin >> this->Opentime;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程学分（数字）:" << endl;
	Mouse(30, 22);
	cin.width(2);
	cin >> this->ClassScore;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程人数上限（数字）:" << endl;
	Mouse(30, 25);
	cin.width(2);
	cin >> this->Max;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置实验学时（最多9个字符）：" << endl;
	Mouse(30, 28);
	cin.width(10);
	cin >> this->ExHour;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置上机学时（最多9个字符）:" << endl;
	Mouse(30, 31);
	cin.width(10);
	cin >> this->PrHour;
	Check();
	this->Person = 0;
	cout << "                              ——————————————————————————" << endl;
	cout << "                              初始化成功！" << endl;
	cout << "                              ——————————————————————————" << endl;
}

void Literate::SetL()
{
	system("cls");
	cout << "                              ——————————————————————————" << endl;
	cout << "                              初始化文科类课程:" << endl;
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程编号（最多10个字符）：" << endl;
	Mouse(30, 4);
	cin.width(11);
	cin >> this->CNumber;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程名(最多10个字符)：" << endl;
	Mouse(30, 7);
	cin.width(11);
	cin >> this->CName;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程性质（最多10个字符， 创新创业类，文学文科类，理工科学类）：" << endl;
	Mouse(30, 10);
	cin.width(11);
	cin >> this->CKind;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程大纲（最多20个字符）" << endl;
	Mouse(30, 13);
	cin.width(21);
	cin >> this->CHeadline;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程学时（数字）:" << endl;
	Mouse(30, 16);
	cin.width(2);
	cin >> this->ClassHour;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程开课学期（最多10个字符）:" << endl;
	Mouse(30, 19);
	cin.width(11);
	cin >> this->Opentime;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程学分（数字）:" << endl;
	Mouse(30, 22);
	cin.width(2);
	cin >> this->ClassScore;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程人数上限（数字）:" << endl;
	Mouse(30, 25);
	cin.width(2);
	cin >> this->Max;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置实验学时（最多9个字符）：" << endl;
	Mouse(30, 28);
	cin.width(10);
	cin >> this->ExHour;
	Check();
	this->Person = 0;
	cout << "                              ——————————————————————————" << endl;
	cout << "                              初始化成功！" << endl;
	cout << "                              ——————————————————————————" << endl;
}

void Engineering::SetE()
{
	system("cls");
	cout << "                              ——————————————————————————" << endl;
	cout << "                              初始化文科类课程:" << endl;
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程编号（最多10个字符）：" << endl;
	Mouse(30, 4);
	cin.width(1);
	cin >> this->CNumber;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程名(最多10个字符)：" << endl;
	Mouse(30, 7);
	cin.width(11);
	cin >> this->CName;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程性质（最多10个字符， 创新创业类，文学文科类，理工科学类）：" << endl;
	Mouse(30, 10);
	cin.width(11);
	cin >> this->CKind;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程大纲（最多20个字符）" << endl;
	Mouse(30, 13);
	cin.width(21);
	cin >> this->CHeadline;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程学时（数字）:" << endl;
	Mouse(30, 16);
	cin.width(2);
	cin >> this->ClassHour;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程开课学期（最多10个字符）:" << endl;
	Mouse(30, 19);
	cin.width(11);
	cin >> this->Opentime;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程学分（数字）:" << endl;
	Mouse(30, 22);
	cin.width(2);
	cin >> this->ClassScore;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置课程人数上限（数字）:" << endl;
	Mouse(30, 25);
	cin.width(2);
	cin >> this->Max;
	Check();
	cout << "                              ——————————————————————————" << endl;
	cout << "                              设置上机学时（最多9个字符）：" << endl;
	Mouse(30, 28);
	cin.width(10);
	cin >> this->PrHour;
	Check();
	this->Person = 0;
	cout << "                              ——————————————————————————" << endl;
	cout << "                              初始化成功！" << endl;
	cout << "                              ——————————————————————————" << endl;
}
