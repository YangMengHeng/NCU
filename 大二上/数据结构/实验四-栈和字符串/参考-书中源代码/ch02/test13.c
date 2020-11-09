/*************************************/
/* 函数功能：顺序栈基本操作测试程序  */
/* 函数参数：无                      */
/* 函数返回值：空                    */
/* 文件名：test13   函数名：main()   */
/*   test09-test13基本相同           */
/*************************************/
#include "stdio.h"
#include "conio.h"
#include "seqstack.h"
#include "seqstack.c"

void main()
{
  int k;
  sequence_stack mystack;
  init(&mystack);
  if(empty(mystack))printf("\n栈是空的！\n");else printf("\n栈不是空的！\n");
  push(&mystack,22);
  push(&mystack,33);
  push(&mystack,44);
  push(&mystack,55);
  push(&mystack,66);
  if(empty(mystack))printf("\n栈是空的！\n");else printf("\n栈不是空的！\n");
  printf("\n\n压入上述5个结点后栈顶元素值为：%d\n",read(mystack));
  printf("\n下面执行2次出栈操作\n");
  pop(&mystack);
  pop(&mystack);
  printf("\n\n执行2次出栈操作后栈顶元素值为：%d\n",read(mystack));

  getch();


 }

