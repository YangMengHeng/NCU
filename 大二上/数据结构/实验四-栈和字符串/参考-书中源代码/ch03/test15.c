/*************************************/
/* �������ܣ�ѭ�����������������Գ���  */
/* ������������                      */
/* ��������ֵ����                    */
/* �ļ�����test15   ��������main()   */
/*************************************/

#include "stdio.h"
#include "conio.h"
#include "slnklist.h"
#include "clnklist.c"


void main()
{
   node *myhead,*tail;
   myhead=init();
   display(myhead);
   myhead=insert(myhead,33,0);
   display(myhead);
   myhead=insert(myhead,55,1);
   display(myhead);
   myhead=insert(myhead,22,0);
   printf("\n\n��ѭ����������ǰ�����22��Ľ��Ϊ��\n");
   /*���߿�������Ӧ�ĵط����������䣬�����ʵ�����ʾ*/
   display(myhead);
   myhead=insert(myhead,77,3);
   display(myhead);
   tail=rear(myhead);
   printf("\n\n\nʹ��β������ָ���򣬴�ӡѭ��������Ľ��Ϊ��\n");
   display(tail->next);
   getch();
}

