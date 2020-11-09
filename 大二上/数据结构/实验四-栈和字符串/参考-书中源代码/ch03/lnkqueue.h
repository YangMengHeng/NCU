/************************************/
/* 链式队列的头文件，文件名lnkqueue.h*/
/************************************/
 typedef int datatype;
 typedef struct link_node{
   datatype info;
   struct link_node *next;
 }node;
typedef struct{
   node *front,*rear;  /*定义队首与队尾指针*/
 }queue;

