/*************************************/
/* �������ܣ�˳�������������Գ���  */
/* ������������                      */
/* ��������ֵ����                    */
/* �ļ�����test02   ��������main()   */
/*         test01~test06��ͬ         */
/*************************************/
#include "stdio.h"
#include "conio.h"
#include "sequlist.h"
#include "sequlist.c"


void main()
{
  sequence_list mytable;
  init(&mytable);
  display(mytable);
  append(&mytable,22);
  append(&mytable,33);
  append(&mytable,44);
  append(&mytable,55);
  append(&mytable,66);
  printf("\n\n��������5������Ϊ��\n");
  display(mytable);
  getch();


 }

