/*************************************/
/* �������ܣ�˳����л����������Գ���  */
/* ������������                      */
/* ��������ֵ����                    */
/* �ļ�����test20   ��������main()   */
/*   test20-test25������ͬ           */
/*************************************/
#include "stdio.h"
#include "conio.h"
#include "seqqueue.h"
#include "seqqueue.c"


void main()
{
  int k;
  sequence_queue myqueue;
  init(&myqueue);
  if(empty(myqueue))printf("\n�����ǿյģ�\n");else printf("\n���в��ǿյģ�\n");
  insert(&myqueue,22);
  insert(&myqueue,33);
  insert(&myqueue,44);
  insert(&myqueue,55);
  insert(&myqueue,66);
  if(empty(myqueue))printf("\n�����ǿյģ�\n");else printf("\n���в��ǿյģ�\n");
  printf("\n\n����5���������к����Ԫ��ֵΪ��%d\n",get(myqueue));
  printf("\n����ִ��2�γ����в���\n");
  dele(&myqueue);
  dele(&myqueue);
  printf("\n\nִ��2�γ�ջ������ջ��Ԫ��ֵΪ��%d\n",get(myqueue));

  getch();


 }

