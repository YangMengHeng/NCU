#include <stdlib.h>
#include <stdio.h>
typedef int datatype;				/*������Ϊ����*/
typedef struct node
{
    datatype data;
    struct node *next;
}linknode;
typedef linknode *linklist;
/******************************************/
/*�������ƣ�creatbystack() 		       	  */
/*�������ܣ�ͷ�巨������ͷ���ĵ�����    */
/******************************************/
linklist creatbystack()
{

    linklist  head,s;
    datatype x;
    head=(linklist)malloc(sizeof(linknode));
    head->next=NULL;

    printf("�������������У��ո�ֿ�����0������:\n");
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
/*�������ƣ�creatbyqueue() 			   */
/*�������ܣ�β�巨������ͷ���ĵ����� */
/***************************************/
linklist creatbyqueue()
{
    linklist head,r,s;
    datatype x;
    head=r=(linklist)malloc(sizeof(linknode));
    head->next=NULL;
    printf("�������������У��ո�ֿ�����0������:\n");
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
/*�������ƣ�print()		 			 */
/*�������ܣ������ͷ���ĵ�����      */
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
/*�������ƣ�delList()		 		 */
/*�������ܣ��ͷŴ�ͷ���ĵ�����      */
/**********************************/
void delList(linklist head)
{ linklist p=head;
  while (p)
  { head=p->next;
    free(p);
    p=head;
  }
}
