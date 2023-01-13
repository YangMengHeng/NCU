/*************************************/
/* 函数功能：顺序表删除操作测试程序  */
/* 函数参数：无                      */
/* 函数返回值：空                    */
/* 文件名：test08   函数名：main()   */
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
  printf("\n请输入删除第几个位置元素结点：\n");
  scanf("%d",&k);
  dele(&mytable,k);
  printf("\n表中删除第%d位置的结点后，顺序表为：\n");
  display(mytable);
  getch();


 }

