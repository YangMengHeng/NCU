/*************************************/
/* �������ܣ�˫�������������Գ���  */
/* ������������                      */
/* ��������ֵ����                    */
/* �ļ�����test20   ��������main()   */
/*************************************/

#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "dlnklist.h"
#include "dlnklist.c"



void main()
{
   dnode *myhead;
   myhead=init();
   display(myhead);
   myhead=insert(myhead,33,0);
   display(myhead);
   myhead=insert(myhead,55,1);
   display(myhead);
   myhead=insert(myhead,22,0);
   printf("\n\n��˫������ǰ�����22��Ľ��Ϊ��\n");
   /*���߿�������Ӧ�ĵط����������䣬�����ʵ�����ʾ*/
   display(myhead);
   myhead=insert(myhead,77,3);
   display(myhead);

    printf("\n\n@@@@@@@@@@@@\n");
   getch();
}

