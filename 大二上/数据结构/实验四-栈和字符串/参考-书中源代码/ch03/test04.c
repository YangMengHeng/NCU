/*************************************/
/* 函数功能：单链表基本操作测试程序  */
/* 函数参数：无                      */
/* 函数返回值：空                    */
/* 文件名：test01   函数名：main()   */
/*         test01~test04相同         */
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
   myhead=insert(myhead,99,5);
   display(myhead);
   getch();
}

