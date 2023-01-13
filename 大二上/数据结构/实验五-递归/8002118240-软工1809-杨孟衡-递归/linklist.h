#include <stdlib.h>
#include <stdio.h>
typedef int datatype;				/*数据域为整型*/
typedef struct node
{
    datatype data;
    struct node *next;
}linknode;
typedef linknode *linklist;
/******************************************/
/*函数名称：creatbystack() 		       	  */
/*函数功能：头插法建立带头结点的单链表    */
/******************************************/
linklist creatbystack()
{

    linklist  head,s;
    datatype x;
    head=(linklist)malloc(sizeof(linknode));
    head->next=NULL;

    printf("请输入整数序列（空格分开，以0结束）:\n");
    scanf("%d",&x);
    while (x!=0)
    {
        s=(linklist)malloc(sizeof(linknode));
        s->data=x;

        s->next=head->next;
        head->next=s;

        scanf("%d",&x);
    }
    return head;
}
/***************************************/
/*函数名称：creatbyqueue() 			   */
/*函数功能：尾插法建立带头结点的单链表 */
/***************************************/
linklist creatbyqueue()
{
    linklist head,r,s;
    datatype x;
    head=r=(linklist)malloc(sizeof(linknode));
    head->next=NULL;
    printf("请输入整数序列（空格分开，以0结束）:\n");
    scanf("%d",&x);
    while (x!=0)
    {
         s=(linklist)malloc(sizeof(linknode));
         s->data=x;
         r->next=s;
         r=s;
         scanf("%d",&x);
   }
    r->next=NULL;
    return head;
}
/**********************************/
/*函数名称：print()		 			 */
/*函数功能：输出带头结点的单链表      */
/**********************************/
void print(linklist head)
{
    linklist p;
    p=head->next;
    printf("List is:\n");
    while(p)
    {
        printf("%5d",p->data);
        p=p->next;
    }
    printf("\n");

}
/**********************************/
/*函数名称：delList()		 		 */
/*函数功能：释放带头结点的单链表      */
/**********************************/
void delList(linklist head)
{ linklist p=head;
  while (p)
  { head=p->next;
    free(p);
    p=head;
  }
}
