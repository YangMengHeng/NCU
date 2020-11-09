typedef struct {
int  data[100][100];
int  m,n;  /*分别存放稀疏矩阵的行数、列数和非零元素的个数*/
 } matrix;
typedef  int  spmatrix[100][3];
void  compressmatrix(matrix A , spmatrix B) 
 {/*将稀疏矩阵A转换成其三元组表示B*/
    int i, j, k=1;
    for ( i=0; i<A.m; i++)
      for (j=0; j<A.n; j++)
         if (A.data[i][j] !=0)
           {  B[k][0]=i;
              B[k][1]=j;
              B[k][2]=A.data[i][j];
              k++;
            }
     B[0][0]=A.m;
     B[0][1]=A.n;
     B[0][2]=k-1;
}

void transpmatrix (spmatrix B, spmatrix C)
 {/*实现稀疏矩阵的转置*/
    int i, j, t, m, n;
    int x[100];
    int y[100];
    m=B[0][0]; n=B[0][1]; t=B[0][2];
    C[0][0]=n; C[0][1]=m; C[0][2]=t;
    if (t>0)
     {
       for (i=0; i<n; i++) x[i]=0;
       for (i=1; i<=t; i++) x[B[i][1]]=x[B[i][1]]+1;
       y[0]=1;
       for (i=1; i<n; i++) y[i]=y[i-1]+x[i-1];
       for (i=1; i<=t; i++)
         {
           j=y[B[i][1]];
           C[j][0]= B[i][1];
           C[j][1]= B[i][0];
           C[j][2]= B[i][2];
           y[B[i][1]]=j+1;
         }
    }
 }

main()
{ int i,j,m,n;
  matrix A;
  spmatrix B,C;
  scanf("%d%d",&m,&n);
  A.m=m; A.n=n;
  for ( i=0; i<m; i++)
      for (j=0; j<n; j++)
         scanf("%d",&A.data[i][j]);
  compressmatrix(A,B);
  for ( i=0; i<=B[0][2]; i++)
      { printf("\n");
        for (j=0; j<3; j++)
           printf("%d",B[i][j]);
       }
  printf("-------");
  transpmatrix(B,C);
  for ( i=0; i<=C[0][2]; i++)
      { printf("\n");
        for (j=0; j<3; j++)
           printf("%d",C[i][j]);
       }
}
