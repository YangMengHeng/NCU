#pragma once
#include<iostream>
#include"Assist.h"
using namespace std;

struct BaseCourse
{
	char CNumber[11];  //�γ̱��
	char CName[11];  //�γ���
	char CKind[11];  //�γ�����
	char CHeadline[21];  //�γ̴��
	unsigned int ClassHour;  //�γ�ѧʱ
	double ClassScore;  //�γ�ѧ��
	char Opentime[11];  //����ѧ��
	unsigned int Person;  //��ѡ����
	unsigned int Max;  //��������
	virtual void Show() = 0;  //��ʾ�麯��
};