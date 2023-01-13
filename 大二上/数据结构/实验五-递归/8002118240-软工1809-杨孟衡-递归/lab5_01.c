/*
  编写递归算法int max(int a[],int left, int right)，求数组a[left..right]中的最大数。
*/

#include "ArrayIo.h"
/*请将本函数补充完整，并进行测试*/
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
    printf("数组的最大数是:%d\n",max(a,0,9));
    return 0;
}
