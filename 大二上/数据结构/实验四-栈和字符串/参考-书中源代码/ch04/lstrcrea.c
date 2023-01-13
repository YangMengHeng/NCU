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
main()
{ 
  linkstring head1;
  strcreate(&head1);
  outlinkstring(head1);
}