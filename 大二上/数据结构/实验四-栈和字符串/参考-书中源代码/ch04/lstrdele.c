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
void strdelete(linkstring*S,int i,int len)
 {
    int k ;
    linkstring p,q,r;
    p=*S, q=null; k=1;
    while (p && k<i)
      {q=p; p=p->next ; k++;}
    if (!p) printf("error1\n");
    else
     { k=1;
       while(k<len && p )
          { p=p->next ;k++;}
       if(!p)  printf("error2\n");
       else
        {  if (!q) { r=*S; *S=p->next; }
           else 
            {
              r=q->next; q->next= p->next;}
           p->next=null;
           while (r !=null)
             {p=r; r=r->next; free(p);}
        }
     }
 } 
main()
{ int i,len;
  linkstring head1;
  strcreate(&head1);
  scanf("%d%d",&i,&len);
  strdelete(&head1,i,len);
  outlinkstring(head1);
}
