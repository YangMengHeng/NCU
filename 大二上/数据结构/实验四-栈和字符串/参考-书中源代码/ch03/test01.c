/*************************************/
/* �������ܣ�����������������Գ���  */
/* ������������                      */
/* ��������ֵ����                    */
/* �ļ�����test01   ��������main()   */
/*         test01~test04��ͬ         */
/*************************************/

#include "stdio.h"
#include "conio.h"
#include "slnklist.h"
#include "slnklist.c"


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
   display(myhead);
   myhead=insert(myhead,77,3);
   display(myhead);
   myhead=insert(myhead,99,5);
   display(myhead);
   getch();
}

