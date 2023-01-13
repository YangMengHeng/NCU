/*
��֪������ͷ���ĵ�����L1��L2�еĽ��ֵ���Ѱ�������������㷨����
linklist mergeAscend (linklist L1,linklist L2)��L1��L2�ϲ���һ�������
��ͷ�ᵥ������Ϊ�����ķ��ؽ����
����㷨����linklist mergeDescend (linklist L1,linklist L2)
��L1��L2�ϲ���һ������Ĵ�ͷ�ᵥ������Ϊ�����ķ��ؽ����
�����main()�������в��ԡ�
*/
/**********************************/
/*�ļ����ƣ�lab3_06.c                 */
/**********************************/
#include "slnklist.h"
/*�뽫���������������������в���*/
linklist mergeAscend(linklist L1,linklist L2)
{
	linklist min, cp, all, pos, p, q;
	datatype data;
	int flag = -1;
	
	p = L1;
	q = L2;
	if(q->next->info < p->next->info)
	{
		flag = 2;
	}
	else flag = 1;
	while(q->next != NULL)
	{
		q = q->next;
	}
	while(p->next != NULL)
	{
		p = p->next;
	}
	switch(flag)
	{
		case 1:
			{
				while(p->next != NULL)
				{
					p = p->next;
				}
				p->next = L2->next;
				p = L1;
				free(L2);
				
				all = p->next;
				min = p->next;
				pos = p->next->next;
				while(all->next != NULL)
				{
					cp = pos;
					while(cp->next != NULL)
					{
						if(cp->info < min->info)
						{
							data = cp->info;
							cp->info = min->info;
							min->info = data;
						}
						cp = cp->next;
					}
					if(cp->info < min->info)
					{
						data = cp->info;
						cp->info = min->info;
						min->info = data;
					} 
					min = min->next;
					all = all->next;
					pos = pos->next;
				}
				
				return L1;
			}
		case 2:
			{
				while(q->next != NULL)	
				{
					q = q->next;
				}
				q->next = L1->next;
				q = L2;
				free(L1);
				
				all = q->next;
				min = q->next;
				pos = q->next->next;
				while(all->next != NULL)
				{
					cp = pos;
					while(cp->next != NULL)
					{
						if(cp->info < min->info)
						{
							data = cp->info;
							cp->info = min->info;
							min->info = data;
						}
						cp = cp->next;
					}
					if(cp->info < min->info)
					{
						data = cp->info;
						cp->info = min->info;
						min->info = data;
					} 
					min = min->next;
					all = all->next;
					pos = pos->next;
				}
				
				return L2;
			}	
 }
}
linklist mergeDescend(linklist L1,linklist L2)
{
linklist max, cp, all, pos, p, q;
	datatype data;
	int flag = -1;
	
	p = L1;
	q = L2;
	if(q->next->info > p->next->info)
	{
		flag = 2;
	}
	else flag = 1;
	while(q->next != NULL)
	{
		q = q->next;
	}
	while(p->next != NULL)
	{
		p = p->next;
	}
	switch(flag)
	{
		case 1:
			{
				while(p->next != NULL)
				{
					p = p->next;
				}
				p->next = L2->next;
				p = L1;
				free(L2);
				
				all = p->next;
				max = p->next;
				pos = p->next->next;
				while(all->next != NULL)
				{
					cp = pos;
					while(cp->next != NULL)
					{
						if(cp->info > max->info)
						{
							data = cp->info;
							cp->info = max->info;
							max->info = data;
						}
						cp = cp->next;
					}
					if(cp->info > max->info)
					{
						data = cp->info;
						cp->info = max->info;
						max->info = data;
					} 
					max = max->next;
					all = all->next;
					pos = pos->next;
				}
				
				return L1;
			}
		case 2:
			{
				while(q->next != NULL)	
				{
					q = q->next;
				}
				q->next = L1->next;
				q = L2;
				free(L1);
				
				all = q->next;
				max = q->next;
				pos = q->next->next;
				while(all->next != NULL)
				{
					cp = pos;
					while(cp->next != NULL)
					{
						if(cp->info > max->info)
						{
							data = cp->info;
							cp->info = max->info;
							max->info = data;
						}
						cp = cp->next;
					}
					if(cp->info > max->info)
					{
						data = cp->info;
						cp->info = max->info;
						max->info = data;
					} 
					max = max->next;
					all = all->next;
					pos = pos->next;
				}
				
				return L2;
			}	
 }
}
int main()
{       linklist h1,h2,h3;
         h1=creatbyqueue();     /*β�巨����������,��������������*/
         h2=creatbyqueue();
         print(h1);
         print(h2);
         h3=mergeDescend(h1,h2);/*����ϲ���h3*/
            /*����ϲ������h3=mergeDescend(h1,h2); */
         print(h3);
         delList(h3);
         return 0;
}
