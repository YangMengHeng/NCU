/*************************************/
/* 函数功能：双链表基本操作测试程序  */
/* 函数参数：无                      */
/* 函数返回值：空                    */
/* 文件名：test18   函数名：main()   */
/*************************************/

#include "stdio.h"
#include "conio.h"
#include "dlnklist.h"
#include "dlnklist.c"


void main()
{
   dnode *myhead,*tail;
   myhead=init();
   display(myhead);
   getch();
}

