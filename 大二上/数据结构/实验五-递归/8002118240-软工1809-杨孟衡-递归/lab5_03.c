/*
  ���д�ݹ麯��void bubbleSort(int a[],int n)��
  �Գ���Ϊn���������ð�ݷ�������������
  ���д�ݹ麯��int binSearch(int a[], int left, int right,int key)��
  ���ö��ֲ��ҷ�������a[left..right]�в���ֵΪkey��Ԫ�����ڵ�λ�ã�
  ������ʧ�ܺ�������-1��
  */

#include "ArrayIo.h"
#define N 10
/*�뽫���������������������в���*/
void bubbleSort(int a[],int n)
{
  int temp;
  int i;
  int j;

  for(i = 0; i < n - 1; i++)
  {
    for(j = 0; j < n - i - 1; j++)
    {
      if(a[j] > a[j+1])
      {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
}
int binSearch(int a[], int left,int right,int key)
{
  int mid;
  if(left > right)
  {
    return NULL;
  }
  mid = (left + right) / 2;
  if(a[mid] == key)
  {
    return mid;
  }
  if(key < a[mid])
  {
    binSearch(a, left, mid - 1, key);
  }
  else binSearch(a, mid + 1, right, key);
}
int main()
{   int x,pos,a[N];
    init(a,N);
   	bubbleSort(a,N);
    print(a,N);
    printf("������Ҫ���ҵ�����\n");
    scanf("%d",&x);
    pos=binSearch(a,0,N-1,x);
    if (pos!=-1) printf("a[%d]=%d\n",pos,x);
    else printf("Not found!\n");
    return 0;
}
