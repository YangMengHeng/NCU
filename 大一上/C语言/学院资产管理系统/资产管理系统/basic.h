#pragma once

struct books//书籍的结构体
{
	char book_name[30];
	char author[20];
	int num;
};//默认定义15个成员

struct object//体育器材的结构体
{
	char type[10];//体育器材种类
	int num;
};//默认定义6个成员

struct classroom//教室的结构体
{
	int floor;//教室的楼层
	char name[256];//教室名字
	int statu;//教室状态
};//默认定义15间教室