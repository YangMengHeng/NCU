#include <stdio.h>
#include <stdlib.h>
/**************************************/
/* ����ʵ�ֵ�ͷ�ļ����ļ���slnklist.h */
/**************************************/
 typedef int datatype;
 typedef struct link_node{
   datatype info;
   struct link_node *next;
 }node;

