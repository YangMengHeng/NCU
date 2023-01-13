#include <stdio.h>
#include <stdlib.h>
/**************************************/
/* 链表实现的头文件，文件名slnklist.h */
/**************************************/
 typedef int datatype;
 typedef struct link_node{
   datatype info;
   struct link_node *next;
 }node;

