#pragma once
#include <string>
#include "user.h"
using namespace std;

class manager: public user//�̳�user��ĺ���
{
public:
	 string password;
	 void Reference();//�������
	 void change();//�޸ĺ�����������������޸�
	 manager(const string Name, string Password);
};

int search_return1();//Ϊ�����޸������ṩ����
int search_return2();//Ϊ�����޸������ṩ����
void readfile(int choice);//���ļ����ж�ȡ
void writefile(int choice);//���ļ�����д��