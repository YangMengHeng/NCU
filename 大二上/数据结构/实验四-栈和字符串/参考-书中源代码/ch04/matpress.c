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
main()
{ int i,j,m,n;
  matrix A;
  spmatrix B;
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
}