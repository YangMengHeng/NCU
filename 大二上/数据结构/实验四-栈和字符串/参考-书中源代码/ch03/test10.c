/*************************************/
/* �������ܣ���ͷ��㵥����ɾ���������Գ��� */
/* ������������                      */
/* ��������ֵ����                    */
/* �ļ�����test10   ��������main()   */
/*************************************/

#include "stdio.h"
#include "conio.h"
#include "slnklist.h"
#include "hlnklist.c"



void main()
{
   node *myhead;
   myhead=init();
   display(myhead);
   myhead=insert(myhead,33,0);
   display(myhead);
   myhead=insert(myhead,55,1);
   display(myhead);
   myhead=insert(myhead,22,0);
   printf("\n�ڴ�ͷ���ĵ�������ǰ�����22��Ľ��Ϊ��\n");
   /*���߿�������Ӧ�ĵط����������䣬�����ʵ�����ʾ*/
   display(myhead);
   myhead=insert(myhead,77,3);
   display(myhead);
   myhead=dele(myhead,77);
   display(myhead);
   myhead=dele(myhead,22);
   display(myhead);
   myhead=dele(myhead,55);
   myhead=dele(myhead,33);
   display(myhead);
   getch();
}

