#pragma once

struct books//�鼮�Ľṹ��
{
	char book_name[30];
	char author[20];
	int num;
};//Ĭ�϶���15����Ա

struct object//�������ĵĽṹ��
{
	char type[10];//������������
	int num;
};//Ĭ�϶���6����Ա

struct classroom//���ҵĽṹ��
{
	int floor;//���ҵ�¥��
	char name[256];//��������
	int statu;//����״̬
};//Ĭ�϶���15�����