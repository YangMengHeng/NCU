/*
�����ͷ���ĵ�����head���������еģ�����㷨����linklist insert(linklist head,datatype x)��
��ֵΪx�Ľ����뵽����head�У����������������ԡ�
�ֱ�����뵽��ͷ�����кͱ�β��������Ĳ����������в��ԡ�
*/
/**********************************/
/*�ļ����ƣ�lab3_03.c                 */
/**********************************/
#include "slnklist.h"
/*�뽫���������������������в���*/
linklist insert(linklist head ,datatype x)
{
    linklist pre = head;
    linklist data = malloc(sizeof(node));
    
    data->info = x;
    while(pre->next != NULL)
    {
    	if(pre->next->info > x)
    	{
    		data->next = pre->next;
    		pre->next = data;
    		break;
		}
		pre = pre->next;
	}
	if(pre->next == NULL)
	{
		pre->next = data;
		data->next = NULL;
	}
	
	return head;
}

int main()
{   datatype x;
    linklist head;
    printf("����һ���������е�������\n");
    head=creatbyqueue();				/*β���뷨������ͷ���ĵ�����*/
    print(head);
    printf("������Ҫ�����ֵ��");
    scanf("%d",&x);
    head=insert(head,x);				/*�������ֵ���뵽��ͷ���ĵ������ʵ�λ��*/
    print(head);
    delList(head);
    return 0;
}
