/*
��֪��ͷ���ĵ�����ṹ����ͬʵ��3���������������н��ֵ������ͬ��
���дһ���ݹ麯��linklist max(linklist head)�����ر�����������ڵĽ���ַ��������Ϊ�գ�����NULL��
*/


#include "linklist.h"
/*�뽫���������������������в���*/
linklist maxe(linklist head)
{
    linklist p;
    if (head->next==NULL)
        return NULL;
    else
        if (head->next->next==NULL)
            return head->next;
    else
        {
            p=maxe(head->next);
            return head->next->data>p->data? head->next:p;
        }
}
int main()
{   
    linklist head,p;
    head=creatbyqueue();
    print(head);
    p=maxe(head);
    if (p)
        printf("max=%d\n",p->data);
    else
        printf("����Ϊ��\n");
    return 0;
}
