/*************************************/
/* 函数功能：顺序表基本操作测试程序  */
/* 函数参数：无                      */
/* 函数返回值：空                    */
/* 文件名：test06   函数名：main()   */
/*************************************/
#include "stdio.h"
#include "conio.h"
#include "sequlist.h"
#include "sequlist.c"


void main()
{
  int k;
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
  printf("\n44在表中的位置为：%d\n",find(mytable,44));
  printf("\n99在表中的位置为：%d\n",find(mytable,99));
  printf("\n请输入一个要查找第几个结点的值：\n");
  scanf("%d",&k);
  printf("\n表中的第%d位置的值为：%d\n",k,get(mytable,k));
  getch();


 }

