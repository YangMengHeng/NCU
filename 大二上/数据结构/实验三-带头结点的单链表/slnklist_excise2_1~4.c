#include <stdlib.h>
#include <stdio.h>
#include "slnklist1.h"


/******************************************************/
/*  函数功能：在不带头结点的单链表中删除一个值为x的结点 */
/*  函数参数：指向node类型变量的指针head               */
/*            datatype类型变量x                       */
/*  函数返回值：指向node类型变量的指针                 */
/*  文件名：slnklist_excise_1~4.c，函数名：delex()    */
/*****************************************************/
linklist delx(linklist head,datatype x)
{
   linklist pre=NULL, p; /*首先pre指向头结点*/
   p=head;               /*ｐ从第一个结点开始找值为x的结点*/
   while(p&&p->info!=x)  /*没有查找完并且还没有找到*/
   {pre=p;p=p->next;}    /*继续查找，pre指向p的前驱*/
   if (p) 
	{  
		if  (!pre)  head=head->next;  /*要删除的是第一个结点*/
        	else  pre->next=p->next;
	        free(p);
	}
   return head;
}




/******************************************************/
/*  函数功能：倒置不带头结点的单链表                    */
/*  函数参数：指向node类型变量的指针head                */
/*  函数返回值：指向node类型变量的指针                  */
/*  文件名：slnklist_excise_1~4.c，函数名：reverse1()     */
/*****************************************************/

linklist reverse1(linklist head)
{
	linklist ph;
	if( !head || !(head->next) )
		return head;
	ph = reverse1( head->next );//递归
	head->next->next = head;
	head->next = NULL;
	return ph;

}


/******************************************************/
/*  函数功能：倒置不带头结点的单链表                  */
/*  函数参数：linklist * head                         */
/*  函数返回值：void                                  */
/*  文件名：slnklist_excise_1~4.c，函数名：reverse2() */
/******************************************************/
void reverse2(linklist * head)
{
	linklist h_1,h_2;

	if(!*head||!((*head)->next)) return ;

	h_1=NULL;
	h_2=*head;
	while( *head )
	{
		h_2 = (*head)->next;   
		(*head)->next = h_1;  //指针指向原表结点前驱，而非后续
		h_1 = *head;          //h指向前面的结点
		*head = h_2;          //头指针移动
	}
	*head = h_1;

}

/******************************************************/
/*  函数功能：倒置不带头结点的单链表                    */
/*  函数参数：指向node类型变量的指针head                */
/*  函数返回值：指向node类型变量的指针                  */
/*  文件名：slnklist_excise_1~4.c，函数名：reverse3()   */
/******************************************************/
linklist reverse3(linklist head)
{
	linklist h_1,h_2;

	if(!head||!(head->next)) return head;

	h_1=NULL;
	h_2=head;
	while( head )
	{
		h_2 = head->next;   
		head->next = h_1;    //指针指向原表结点前驱，而非后续
		h_1 = head;          //h指向前面的结点
		head = h_2;          //头指针移动
	}
	return h_1;
}

/******************************************************/
/*  函数功能：单链表数据插入                           */
/*  函数参数：指向node类型变量的指针head                */
/*            datatype类型变量x                       */
/*  函数返回值：指向node类型变量的指针                  */
/*  文件名：slnklist_excise_1~4.c，函数名：insert()   */
/******************************************************/
linklist insert(linklist head, datatype x)
{
	linklist s, p, q;
	if (!head)
	{
		printf("链表无内容\n");
		return head;
	}

	s=(linklist )malloc(sizeof(node)); //为s申请分配空间
 	s->info=x;                              //结点s的数据是x
 	q=head;                                 //q初始值为第一个结点
	p=q->next;                              //p初始值为第二个节点(q的下一个结点)

    if (q->info>=s->info)//如果插入的值比最小值（也就是第一个值）小，则插入在最前面
	{
	  s->next=q;         //s的下一结点是q,即s放在第一位
	  head = s;
	  return head;
	}
	

	while(p)
	{
		if(x>=q->info&&x<p->info) //当x满足条件时终止循环（条件是：x小于后一个节点大于前一个结点）
		{
		   q->next=s;     //在q和P中插入结点
		   s->next=p;     //
		   break;
		}
		q=p;
		p=p->next;
		
	}

	if(!p && s->info>=q->info)//如果插入的值比最大值（也是最后一个值）大，则插入在最后面
	{
	  q->next=s;
	  s->next=NULL;
	}

	return head;
}

/******************************************************/
/*  函数功能：单链表数据删除                            */
/*  函数参数：指向node类型变量的指针head                */
/*            datatype类型变量x                        */
/*  函数返回值：指向node类型变量的指针                  */
/*  文件名：slnklist_excise_1~4.c，函数名：delallx()   */
/******************************************************/
linklist delallx(linklist head, datatype x)
{
   linklist pre=NULL, p;
   if(!head) {printf("单链表是空的！");return head;}

   p=head;
   while (p)
   {
	if (p->info==x)    //找到
		if (!pre)  //第一个结点 
		{
			head=p->next;
			free(p);
			p=head;
		}
		else
		{
			pre->next = p->next;
			free(p);
			p=pre->next;	
		}
	else    //没找到
	{
		pre=p;
		p=p->next;

	}
   }
   
   return head;

}


int main()
{
	datatype x;
	linklist head;
	/*--------实验2.1 删除
	head=creatbyqueue();    //尾插法建立单链表
	print(head);		
	printf("请输入要删除的值：");
	scanf("%d", &x);
	head = delx(head,x);
	print(head);
	delList(head);
	*/

	/*--------实验2.2 倒置
	head=creatbystack();    //头插法建立单链表
	print(head);			
	head = reverse1(head);
	print(head);
	head=reverse3(head);
	print(head);
	printf("reverse2\n");
	reverse2(&head);
	print(head);
	*/
	
	/*--------实验2.3 插入升序表
	printf("请输入一组升序排列的整数\n");
	head=creatbyqueue();    //头插法建立单链表
	print(head);			
	printf("请输入待插入的整数\n");
	scanf("%d", &x);
	head = insert(head, x);
	print(head);
	*/

	/*--------实验2.4 删除所有x*/
	head=creatbyqueue();    //头插法建立单链表
	print(head);			
	printf("请输入待删除的整数\n");
	scanf("%d", &x);
	head = delallx(head, x);
	print(head);
	//*/

	delList(head);	

	return 0;
}
