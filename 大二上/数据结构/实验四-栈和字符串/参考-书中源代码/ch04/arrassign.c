#include<array.h>
int assign( array *A, datatype e, int i1, int i2, int i3)
 {  
   int off;
   if (i1<0 || i1>=A->index[0] || i2< 0 || i2>=A->index[1] || i3<0 || i3>=A->index[2])
       return (0 );   /*�����±�Ƿ������*/
   off= i1��A->c[0]+ i2��A->c[1]+ i3��A->c[2];  /*��������Ԫ�ص�λ��*/
   *(A->base + off)=e;    /*��ֵ*/
   return(1);
   }
