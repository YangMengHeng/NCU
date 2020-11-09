/*************************************/
/* 函数功能：循环单链表删除操作测试程序  */
/* 函数参数：无                      */
/* 函数返回值：空                    */
/* 文件名：test16   函数名：main()   */
/*************************************/

#include "stdio.h"
#include "conio.h"
#include "slnklist.h"
#include "clnklist.c"



void main()
{
   node *myhead,*tail;
   myhead=init();
   display(myhead);
   myhead=insert(myhead,33,0);
   display(myhead);
   myhead=insert(myhead,55,1);
   display(myhead);
   myhead=insert(myhead,22,0);
   printf("\n\n在循环单链表最前面插入22后的结果为：\n");
   /*读者可以在相应的地方加上输出语句，给予适当的提示*/
   display(myhead);
   myhead=insert(myhead,77,3);
   display(myhead);
   tail=rear(myhead);
   printf("\n\n\n使用尾部结点的指针域，打印循环单链表的结果为：\n");
   display(tail->next);
   myhead=dele(myhead,22); display(tail->next);display(myhead);
   myhead=dele(myhead,77); display(tail->next);display(myhead);


   getch();
}

