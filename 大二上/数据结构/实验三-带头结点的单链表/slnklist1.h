/************************************/
/* 链表实现的头文件，文件名slnklist.h */
/************************************/

#include <stdlib.h>
#include <stdio.h>
typedef int datatype;
typedef struct link_node{
   datatype info;
   struct link_node *next;
}node;
typedef node * linklist;

/************************************/
/* 函数名称：createbystack()         */
/* 头插法建立单链表                  */
/************************************/
linklist creatbystack()
{
	linklist head,s;
	datatype x;
	head=NULL;
	printf("请输入若干整数序列:\n");
	scanf("%d", &x);
	while (x!=0)  //以0结束输入
	{
		s=(linklist)malloc(sizeof(node)); //生成待插入结点
		s->info = x;
		s->next = head;
		head=s;
		scanf("%d", &x);
	}
	return head;
}

/************************************/
/* 函数名称：createbyqueue()         */
/* 尾插法建立单链表                  */
/************************************/
linklist creatbyqueue()
{
	linklist head,r,s;
	datatype x;
	head=r=NULL;

	printf("请输入若干整数序列:\n");
	scanf("%d", &x);
	while (x!=0)  //以0结束输入
	{
		s=(linklist)malloc(sizeof(node)); //生成待插入结点
		s->info = x;
		if (head==NULL)			    //将新结点插入到链表最后
			head=s;
		else 
			r->next = s;
		r=s;                              //r始终指向链表最后一个结点
		scanf("%d", &x);
	}
	if(r) r->next = NULL;
	return head;
}


/************************************/
/* 函数名称：print()                 */
/* 输出不带头结点的单链表             */
/************************************/
void print(linklist head)
{
	linklist p;
      int i =0;
	p= head;

	printf("List is:\n");

	while (p)  //链表未结束
	{
		printf("%d ", p->info);
		p = p->next;
            i++;
            if (i%10==0) printf("\n");
	}
	printf("\n");
}

/************************************/
/* 函数名称：dellist()               */
/* 释放不带头结点的单链表             */
/************************************/
void delList(linklist head)
{
	linklist p=head;
      
	while (p)  //链表未结束
	{
		head =p->next;
		free(p);
		p = head;
	}
}


