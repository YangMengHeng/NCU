/*
��д�㷨����linklist delallx(linklist head, int x)��ɾ����ͷ��㵥����head������ֵΪx�Ľ�㡣
*/
/**********************************/
/*�ļ����ƣ�lab3_04.c                 */
/**********************************/
#include "slnklist.h"
/*�뽫���������������������в���*/
linklist delallx(linklist head,int x)
{
	linklist temp = head->next;
	linklist pre = head;
	linklist del = temp;
	
	while(temp)
	{
		if(temp->info == x)
		{
			pre->next = temp->next;
			del = temp;
			temp = temp->next;
			free(del);
		}
		else 
		{
			temp = temp->next;
			pre = pre->next;
		}
	}
	
	return head;
}
int main()
{   datatype x;
    linklist head;
    head=creatbyqueue();				/*β���뷨������ͷ���ĵ�����*/
    print(head);
    printf("������Ҫɾ����ֵ��");
    scanf("%d",&x);
    head=delallx(head,x);
    print(head);
    delList(head);
    return 0;
}
