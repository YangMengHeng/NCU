#include<array.h>
int initarray (array *A, int b1 , int b2, int b3)  
{         
   int elements;
   if (b1<=0||b2<=0||b3<=0)  return( 0 );  /*����Ƿ����*/
   A->index[0]=b1; A->index[1]=b2; A->index[2]=b3;
   elements = b1 �� b2 �� b3;   /*������Ԫ�صĸ���*/
   A->base=(datatype*) malloc (elements �� sizeof (datatype)); /*Ϊ�������ռ�*/
   if  (! (A->base)) return(0);
   A->c[0]= b2 �� b3;  A->c[1]= b3;  A->c[2]= 1;
   return(1);
  }
