/*
���дһ���ݹ��㷨����void partion(int a[], int left, int right)��
������a[left..right]�е��������������������ߣ�����ż������������ұߡ�
*/
#include "ArrayIo.h"
#define N 10
/*�뽫���������������������в���*/
void partion(int a[], int left,int right)
{
int x;
   if (left<right)
   {
       while (left<right && a[left]%2==1)
            left++;
       while (left<right && a[right]%2==0)
            right--;
       if (left<right)
       {
            x=a[left];
            a[left]=a[right];
            a[right]=x;
            partion(a,left+1,right-1);
       }
   }
}
int main()
{   int a[N];
    init(a,N);				/*�������N����*/
    print(a,N);
    partion(a,0,N-1);
    print(a,N);
    return 0;
}
