/*************************************/
/* 函数功能：顺序队列基本操作测试程序  */
/* 函数参数：无                      */
/* 函数返回值：空                    */
/* 文件名：test20   函数名：main()   */
/*   test20-test25基本相同           */
/*************************************/
#include "stdio.h"
#include "conio.h"
#include "seqqueue.h"
#include "seqqueue.c"


void main()
{
  int k;
  sequence_queue myqueue;
  init(&myqueue);
  if(empty(myqueue))printf("\n队列是空的！\n");else printf("\n队列不是空的！\n");
  insert(&myqueue,22);
  insert(&myqueue,33);
  insert(&myqueue,44);
  insert(&myqueue,55);
  insert(&myqueue,66);
  if(empty(myqueue))printf("\n队列是空的！\n");else printf("\n队列不是空的！\n");
  printf("\n\n上述5个结点进队列后队首元素值为：%d\n",get(myqueue));
  printf("\n下面执行2次出队列操作\n");
  dele(&myqueue);
  dele(&myqueue);
  printf("\n\n执行2次出栈操作后栈顶元素值为：%d\n",get(myqueue));

  getch();


 }

