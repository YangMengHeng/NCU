/*************************************/
/* 函数功能：带头结点单链表插入操作测试程序，同test09 */
/* 函数参数：无                      */
/* 函数返回值：空                    */
/* 文件名：test08   函数名：main()   */
/*************************************/

#include "stdio.h"
#include "conio.h"
#include "slnklist.h"
#include "hlnklist.c"


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
   printf("\n在带头结点的单链表最前面插入22后的结果为：\n");
   /*读者可以在相应的地方加上输出语句，给予适当的提示*/
   display(myhead);
   myhead=insert(myhead,77,3);
   display(myhead);
   getch();
}

