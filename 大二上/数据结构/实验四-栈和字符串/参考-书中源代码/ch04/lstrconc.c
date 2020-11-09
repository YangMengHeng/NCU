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
void strconcat(linkstring *S1, linkstring S2)
{
  linkstring p;
  if (!(*S1) )  
       {*S1=S2; return;}
  else
    if (S2)  
      {
        p=*S1;
        while(p->next ) p= p->next;
        p->next=S2;
      }
}
main()
{ 
  linkstring head1,head2;
  strcreate(&head1);
  strcreate(&head2);
  strconcat(&head1,head2);
  outlinkstring(head1);
}