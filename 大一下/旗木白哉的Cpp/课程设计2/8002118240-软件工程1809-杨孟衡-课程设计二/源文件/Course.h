#pragma once
#include"BaseCourse.h"
#include<string.h>

struct Create :public BaseCourse
{
	char ExHour[10];  //ʵ��ѧʱ
	char PrHour[10];  //�ϻ�ѧʱ
	Create();
	void SetC();
	void Show()override final;
};

struct Literate :public BaseCourse
{
	char ExHour[10];  //ʵ��ѧʱ
	Literate();
	void SetL();
	void Show() override final;
};

struct Engineering :public BaseCourse
{
	char PrHour[10];  //�ϻ�ѧʱ
	Engineering();
	void SetE();
	void Show() override final;
};