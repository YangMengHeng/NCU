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
main()
{ 
  linkstring head1;
  strcreate(&head1);
  outlinkstring(head1);
}