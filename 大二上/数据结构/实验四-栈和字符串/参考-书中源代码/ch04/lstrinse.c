#include <stdio.h>
#define null 0
typedef struct node
   {
      char data;
      struct node *next;
    } linkstrnode;
typedef linkstrnode *linkstring;

/*-----------------------------*/
/*     尾插法建立单链表        */
/*-----------------------------*/
void strcreate(linkstring *S)
{ char ch;
  linkstrnode *p,*r;
  *S=NULL; r=NULL;
  while ((ch=getchar())!='\n')
   { p=(linkstrnode *)malloc(sizeof(linkstrnode));
     p->data=ch;     /*产生新结点*/
     if (*S==NULL) /*新结点插入空表*/
         *S=p;
     else r->next=p;
     r=p;
   } /*处理表尾结点指针域*/
   if (r!=NULL)  r->next=NULL;
 }
/*-------------------------------*/
/*     输出单链表的内容          */
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
/*将串T插入到串S中第i个字符之前*/
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