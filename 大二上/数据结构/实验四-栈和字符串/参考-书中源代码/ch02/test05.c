/*************************************/
/* �������ܣ�˳�������������Գ���  */
/* ������������                      */
/* ��������ֵ����                    */
/* �ļ�����test05   ��������main()   */
/*************************************/
#include "stdio.h"
#include "conio.h"
#include "sequlist.h"
#include "sequlist.c"


void main()
{
  int x;
  sequence_list mytable;
  init(&mytable);
  display(mytable);
  if(empty(mytable))printf("\n���ǿյģ�\n");else printf("\n���ǿյģ�\n");
  append(&mytable,22);
  append(&mytable,33);
  append(&mytable,44);
  append(&mytable,55);
  append(&mytable,66);
  printf("\n\n��������5������Ϊ��\n");
  display(mytable);
  if(empty(mytable))printf("\n���ǿյģ�\n");else printf("\n���ǿյģ�\n");
  printf("\n44�ڱ��е�λ��Ϊ��%d\n",find(mytable,44));
  printf("\n99�ڱ��е�λ��Ϊ��%d\n",find(mytable,99));
  printf("\n������һ��Ҫ���ҵ�ֵ��\n");
  scanf("%d",&x);
  if(find(mytable,x)==-1)printf("\n%d�ڱ��в����ڣ�\n",x);
  else printf("\n%d�ڱ��е�λ��Ϊ��%d\n",x,find(mytable,x));
  getch();


 }

