/************************************/
/* ��ʽ���е�ͷ�ļ����ļ���lnkqueue.h*/
/************************************/
 typedef int datatype;
 typedef struct link_node{
   datatype info;
   struct link_node *next;
 }node;
typedef struct{
   node *front,*rear;  /*����������βָ��*/
 }queue;

