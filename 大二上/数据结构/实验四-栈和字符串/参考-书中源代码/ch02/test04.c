/*************************************/
/* 函数功能：顺序表基本操作测试程序  */
/* 函数参数：无                      */
/* 函数返回值：空                    */
/* 文件名：test04   函数名：main()   */
/*************************************/
#include "stdio.h"
#include "conio.h"
#include "sequlist.h"
#include "sequlist.c"


void main()
{
  sequence_list mytable;
  init(&mytable);
  display(mytable);
  if(empty(mytable))printf("\n表是空的！\n");else printf("\n表不是空的！\n");
  append(&mytable,22);
  append(&mytable,33);
  append(&mytable,44);
  append(&mytable,55);
  append(&mytable,66);
  printf("\n\n插入上述5个结点后为：\n");
  display(mytable);
  if(empty(mytable))printf("\n表是空的！\n");else printf("\n表不是空的！\n");
  getch();


 }

