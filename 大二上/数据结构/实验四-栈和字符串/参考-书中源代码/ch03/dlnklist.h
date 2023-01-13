/**********************************/
/* 双链表的头文件，文件名dlnklist.h */
/**********************************/
 typedef int datatype;
 typedef struct dlink_node{
   datatype info;
   struct dlink_node *llink,*rlink;
 }dnode;

