/*************************************/
/* �������ܣ�˳��ջ�����������Գ���  */
/* ������������                      */
/* ��������ֵ����                    */
/* �ļ�����test13   ��������main()   */
/*   test09-test13������ͬ           */
/*************************************/
#include "stdio.h"
#include "conio.h"
#include "seqstack.h"
#include "seqstack.c"

void main()
{
  int k;
  sequence_stack mystack;
  init(&mystack);
  if(empty(mystack))printf("\nջ�ǿյģ�\n");else printf("\nջ���ǿյģ�\n");
  push(&mystack,22);
  push(&mystack,33);
  push(&mystack,44);
  push(&mystack,55);
  push(&mystack,66);
  if(empty(mystack))printf("\nջ�ǿյģ�\n");else printf("\nջ���ǿյģ�\n");
  printf("\n\nѹ������5������ջ��Ԫ��ֵΪ��%d\n",read(mystack));
  printf("\n����ִ��2�γ�ջ����\n");
  pop(&mystack);
  pop(&mystack);
  printf("\n\nִ��2�γ�ջ������ջ��Ԫ��ֵΪ��%d\n",read(mystack));

  getch();


 }

