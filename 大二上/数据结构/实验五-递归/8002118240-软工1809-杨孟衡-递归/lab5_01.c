/*
  ��д�ݹ��㷨int max(int a[],int left, int right)��������a[left..right]�е��������
*/

#include "ArrayIo.h"
/*�뽫���������������������в���*/
int max(int a[],int left,int right)
{
    int temp;

    if(left == right)
    {
      return a[left];
    }
    if(a[left] > a[right])
    {
      temp = max(a, left,right - 1);
    }
    else temp = max(a, left + 1, right);
}
int main()
{   int a[10];
    input(a,10);
    print(a,10);
    printf("������������:%d\n",max(a,0,9));
    return 0;
}
