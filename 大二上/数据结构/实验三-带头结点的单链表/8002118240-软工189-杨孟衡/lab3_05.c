/*
��֪���Ա�洢�ڴ�ͷ���ĵ�����head�У�������㷨����void sort(linklist head)����head�еĽ�㰴���ֵ�������С�
*/
/**********************************/
/*�ļ����ƣ�lab3_05.c                 */
/**********************************/
#include "slnklist.h"
/*�뽫���������������������в���*/
void  sort(linklist head)
{
	linklist min, cp, all, pos;
	datatype data;
	if (head->next && head->next->next) //����������ʵ�ʽ��
	{
		all = head->next;
		min = head->next;
		pos = head->next->next;
		while(all->next != NULL)
		{
			cp = pos;
			while(cp->next != NULL)
			{
				if(cp->info > min->info)
				{
					data = cp->info;
					cp->info = min->info;
					min->info = data;
				}
				cp = cp->next;
			}
			if(cp->info > min->info)
			{
				data = cp->info;
				cp->info = min->info;
				min->info = data;
			} 
			min = min->next;
			all = all->next;
			pos = pos->next;
		}
	}
	
}
int main()
{        linklist head;
         head=creatbyqueue();   		/*β�巨������ͷ���ĵ�����*/
         print(head);    			    /*���������head*/
         sort(head);     				/*����*/
         print(head);
         delList(head);
         return 0;
}
