/*************************************/
/* 函数功能：单链表删除操作测试程序  */
/* 函数参数：无                      */
/* 函数返回值：空                    */
/* 文件名：test05   函数名：main()   */
/*************************************/

#include "stdio.h"
#include "conio.h"
#include "slnklist.h"
#include "slnklist.c"



void main()
{
   node *myhead;
   myhead=init();
   display(myhead);
   myhead=insert(myhead,33,0);
   display(myhead);
   myhead=insert(myhead,55,1);
   display(myhead);
   myhead=insert(myhead,22,0);
   display(myhead);
   myhead=insert(myhead,77,3);
   display(myhead);
   myhead=dele(myhead,22);
   display(myhead);
   myhead=dele(myhead,23);
   display(myhead);
   getch();
}

