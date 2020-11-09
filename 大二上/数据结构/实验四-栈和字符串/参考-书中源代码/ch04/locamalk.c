typedef struct matrixnode  /*十字链表中结点的结构*/ 
   {
     int  row,  col;
     struct matrixnode  *right, * down;
     union{ int  val;
           struct matrixnode *next;
          } tag;
   } matrixnode;
typedef matrixnode *spmatrix;
typedef spmatrix headspmatrix[100];  /*指针数组，每个元素指向一个表头结点*/
void Createspmatrix (headspmatrix h) /*创建稀疏矩阵的十字链表表示*/
{ int m,n,t,s,i,r,c,v;
  spmatrix p,q;
  printf("矩阵的行数、列数和非零元素的个数：");
  scanf("%d%d%d",&m,&n,&t);
  p=(spmatrix) malloc (sizeof(matrixnode));
  h[0]=p;                            /* h[0]为表头环形链表的表头结点*/
  p->row=m;p->col=n; 
  s=m>n?m:n;
  for (i=1;i<=s;++i)                 /*初始化各行（列）的环形链表*/
    { p=(spmatrix) malloc (sizeof(matrixnode));
      h[i]=p;
      h[i-1]->tag.next=p;
      p->row=p->col=0;
      p->down=p->right=p;
     }
   h[s]->tag.next=h[0];
   for (i=1;i<=t;++i)               /*依次读入非零元素加入十字链表中*/
     { printf("输入非零元素的行号、列号和值：");
       scanf("%d%d%d",&r,&c,&v);
       p=(spmatrix) malloc (sizeof(matrixnode));
       p->row=r; p->col=c; p->tag.val=v;
       q=h[r];
       while (q->right!=h[r] && q->right->col<c)
           q=q->right;
       p->right=q->right;
       q->right=p;
       q=h[c];
       while (q->down!=h[c] && q->down->row<r)
           q=q->down;
       p->down=q->down;
       q->down=p;
     }
 } 
void printspmatrix(headspmatrix h)  /*按行顺序依次输出十字链表中的非零元素*/
{ spmatrix p,q;
  printf("\n稀疏矩阵为：\n");
  printf("%d%d\n",h[0]->row,h[0]->col);
  p=h[0]->tag.next;
  while (p!=h[0])
   { q=p->right;
     while (p!=q)
      { printf("%d%d%d\n",q->row,q->col,q->tag.val);
        q=q->right;
       }
     p=p->tag.next;
    }
}
int locatespmatrix(headspmatrix h,int x,int *rowx,int *colx)  /*在十字链表中查找值为x的结点*/
{  spmatrix p,q;
   p=h[0]->tag.next;      /*p指向第一行（列）的表头结点*/
   while (p!=h[0])        /*按顺序在每行中查找值为x的结点*/
   { q=p->right;
     while (p!=q)
      { if (q->tag.val==x)   /*找到x后将其行号和列号返回*/
          { *rowx=q->row; *colx=q->col;
            return(1);
           }
        q=q->right;
       }
      p=p->tag.next;       /*准备进入下一行查找*/
    }
   return(0);
} 
main()                         /*主程序*/
{  headspmatrix h;
   int rowx,colx,x;
   Createspmatrix(h);          /*创建一个十字链表*/
   printspmatrix(h);           /*输出一个十字链表的值*/
   printf("\n输入x的值：");
   scanf("%d",&x);
   if (locatespmatrix(h,x,&rowx,&colx)) 
     printf("\n%d在第%d行第%d列",x,rowx,colx);
   else
     printf("没找到!");
}
