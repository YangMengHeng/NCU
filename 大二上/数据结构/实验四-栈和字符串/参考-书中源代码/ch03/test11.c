/*************************************/
/* 函数功能：循环单链表基本操作测试程序  */
/* 函数参数：无                      */
/* 函数返回值：空                    */
/* 文件名：test11   函数名：main()   */
/*************************************/

#include "stdio.h"
#include "conio.h"
#include "slnklist.h"
#include "clnklist.c"


void main()
{
   node *myhead;
   myhead=init();
   display(myhead);
   getch();
}

