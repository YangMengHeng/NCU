/**********************************/
/* ˫�����ͷ�ļ����ļ���dlnklist.h */
/**********************************/
 typedef int datatype;
 typedef struct dlink_node{
   datatype info;
   struct dlink_node *llink,*rlink;
 }dnode;

