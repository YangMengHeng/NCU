/*************************************/
/* 函数功能：双链表插入操作测试程序  */
/* 函数参数：无                      */
/* 函数返回值：空                    */
/* 文件名：test20   函数名：main()   */
/*************************************/

#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "dlnklist.h"
#include "dlnklist.c"



void main()
{
   dnode *myhead;
   myhead=init();
   display(myhead);
   myhead=insert(myhead,33,0);
   display(myhead);
   myhead=insert(myhead,55,1);
   display(myhead);
   myhead=insert(myhead,22,0);
   printf("\n\n在双链表最前面插入22后的结果为：\n");
   /*读者可以在相应的地方加上输出语句，给予适当的提示*/
   display(myhead);
   myhead=insert(myhead,77,3);
   display(myhead);

    printf("\n\n@@@@@@@@@@@@\n");
   getch();
}

