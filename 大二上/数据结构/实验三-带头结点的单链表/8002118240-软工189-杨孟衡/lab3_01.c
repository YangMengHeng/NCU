/*��д����void delx(linklist head, datatype x)��ɾ����ͷ��㵥����head�е�һ��ֵΪx �Ľ�㡣
����������������в��ԡ�
*/
/**********************************/
/*�ļ����ƣ�lab3_01.c                 */
/**********************************/
#include "slnklist.h"
/*�뽫���������������������в���*/
linklist delx(linklist head,datatype x)
{
	linklist temp = head->next;
	linklist pre = head;
	while(temp && (temp->info != x))
	{
		pre = temp;
		temp = temp->next;
	}
	if(temp)
	{
		pre->next = temp->next;
		free(temp);
	}
	return head;
}

int main()
{   datatype x;
    linklist head;
    head=creatbyqueue();		/*β���뷨������ͷ���ĵ�����*/
    print(head);
    printf("������Ҫɾ����ֵ��");
    scanf("%d",&x);
    head=delx(head,x);			/*ɾ��������ĵ�һ��ֵΪx�Ľ��*/
    print(head);
    delList(head);				/*�ͷŵ�����ռ�*/
    return 0;
}
