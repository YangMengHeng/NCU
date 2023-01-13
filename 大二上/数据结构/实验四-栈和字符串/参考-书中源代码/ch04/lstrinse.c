#include <stdio.h>
#define null 0
typedef struct node
   {
      char data;
      struct node *next;
    } linkstrnode;
typedef linkstrnode *linkstring;

/*-----------------------------*/
/*     β�巨����������        */
/*-----------------------------*/
void strcreate(linkstring *S)
{ char ch;
  linkstrnode *p,*r;
  *S=NULL; r=NULL;
  while ((ch=getchar())!='\n')
   { p=(linkstrnode *)malloc(sizeof(linkstrnode));
     p->data=ch;     /*�����½��*/
     if (*S==NULL) /*�½�����ձ�*/
         *S=p;
     else r->next=p;
     r=p;
   } /*�����β���ָ����*/
   if (r!=NULL)  r->next=NULL;
 }
/*-------------------------------*/
/*     ��������������          */
/*-------------------------------*/

void outlinkstring(linkstring head)
{
 linkstrnode *p;
 p=head;
 while (p)
  {printf("%c-->",p->data);
   p=p->next;
  }
  printf("\n");
 }
void strinsert(linkstring *S,int i,linkstring T)
/*����T���뵽��S�е�i���ַ�֮ǰ*/
{
  int k ;
  linkstring p,q;
  p=*S, k=1;
  while (p && k<i-1)
     {
       p=p->next ; k++;
      }
  if (!p) printf("error\n");
  else
    {
      q=T;
      while(q->next)  q=q->next;
      q->next=p->next;
      p->next=T;
    }
 }
main()
{ int i;
  linkstring head1,head2;
  strcreate(&head1);
  strcreate(&head2);
  scanf("%d",&i);
  strinsert(&head1,i,head2);
  outlinkstring(head1);
}