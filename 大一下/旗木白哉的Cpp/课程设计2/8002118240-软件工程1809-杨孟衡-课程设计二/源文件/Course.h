#pragma once
#include"BaseCourse.h"
#include<string.h>

struct Create :public BaseCourse
{
	char ExHour[10];  //实验学时
	char PrHour[10];  //上机学时
	Create();
	void SetC();
	void Show()override final;
};

struct Literate :public BaseCourse
{
	char ExHour[10];  //实验学时
	Literate();
	void SetL();
	void Show() override final;
};

struct Engineering :public BaseCourse
{
	char PrHour[10];  //上机学时
	Engineering();
	void SetE();
	void Show() override final;
};