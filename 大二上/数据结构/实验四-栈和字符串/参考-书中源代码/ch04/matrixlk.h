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