/**********************************/
/*�ļ����ƣ�lab3_02.c                 */
/**********************************/
/*
�������Ա�a1,a2,a3,��an�����ô�ͷ���ĵ�����洢��������㷨����linklist reverse(linklist  head)��
����ͷ���ĵ�����head�͵ص��ã�ʹ���ɣ�an,an-1,��a3.a2,a1��������������������в��ԡ�
*/
#include "slnklist.h"
/*�뽫���������������������в���*/
linklist reverse(linklist head)
{
	linklist last2 = head->next;
	linklist last1 = head->next;
	linklist last = head->next->next;
	
	last1 = last;
	last = last->next;
	last1->next = last2;
	last2->next = NULL;
	last2 = last1;
	while(last->next != NULL)
	{
		last1 = last;
		last = last->next;
		last1->next = last2;
		last2 = last1;
	}
	last->next = last1;
	head->next = last;
	
	return head;
}
int main()
{   datatype x;
    linklist head;
    head=creatbystack();			/*ͷ���뷨������ͷ���ĵ�����*/
    print(head);					/*���ԭ����*/
    head= reverse(head);			/*���õ�����*/
    print(head);					/*������ú������*/
    delList(head);
    return 0;
}
