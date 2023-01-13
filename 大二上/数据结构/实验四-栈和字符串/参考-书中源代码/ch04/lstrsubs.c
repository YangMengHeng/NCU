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
linkstring substring(linkstring S,int i, int len)
{
    int k;
    linkstring p,q,r,t;
    p=S, k=1;
    while (p && k<i) {p= p->next;k++;}
    if (!p)  {printf("error1\n"); return(null);}
    else
      { 
         r=(linkstring ) malloc (sizeof(linkstrnode));
         r->data=p->data; r->next=null;
         k=1; q=r;
         while (p->next  && k<len)
           { p=p->next ;k++;
             t=(linkstring) malloc (sizeof (linkstrnode));
             t->data=p->data; q->next=t; q=t;
            }
         if (k<len) {printf("error2\n") ; return(null);}
         else
            {q->next=null; return(r);}
       }
}
main()
{ int i,len;
  linkstring head1,p;
  strcreate(&head1);
  scanf("%d%d",&i,&len);
  p=substring(head1,i,len);
  outlinkstring(p);  
}