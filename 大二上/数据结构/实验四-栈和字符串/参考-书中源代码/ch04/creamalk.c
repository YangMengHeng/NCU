/*ע��ϡ�������±��1��ʼʹ��*/
typedef struct matrixnode  /*ʮ�������н��Ľṹ*/ 
   {
     int  row,  col;
     struct matrixnode  *right, * down;
     union{ int  val;
           struct matrixnode *next;
          } tag;
   } matrixnode;
typedef matrixnode *spmatrix;
typedef spmatrix headspmatrix[100];  /*ָ�����飬ÿ��Ԫ��ָ��һ����ͷ���*/
void Createspmatrix (headspmatrix h) /*����ϡ������ʮ�������ʾ*/
{ int m,n,t,s,i,r,c,v;
  spmatrix p,q;
  printf("����������������ͷ���Ԫ�صĸ�����");
  scanf("%d%d%d",&m,&n,&t);
  p=(spmatrix) malloc (sizeof(matrixnode));
  h[0]=p;                            /* h[0]Ϊ��ͷ��������ı�ͷ���*/
  p->row=m;p->col=n; 
  s=m>n?m:n;
  for (i=1;i<=s;++i)                 /*��ʼ�����У��У��Ļ�������*/
    { p=(spmatrix) malloc (sizeof(matrixnode));
      h[i]=p;
      h[i-1]->tag.next=p;
      p->row=p->col=0;
      p->down=p->right=p;
     }
   h[s]->tag.next=h[0];
   for (i=1;i<=t;++i)               /*���ζ������Ԫ�ؼ���ʮ��������*/
     { printf("�������Ԫ�ص��кš��кź�ֵ��");
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
void printspmatrix(headspmatrix h)  /*����˳���������ʮ�������еķ���Ԫ��*/
{ spmatrix p,q;
  printf("\nϡ�����Ϊ��\n");
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
main()                         /*������*/
{  headspmatrix h;
   Createspmatrix(h);          /*����һ��ʮ������*/
   printspmatrix(h);           /*���һ��ʮ�������ֵ*/
  
}