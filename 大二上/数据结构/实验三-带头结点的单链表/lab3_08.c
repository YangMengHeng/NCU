/*
���дһ���㷨����void partion(linklist head)��
����ͷ���ĵ�����head�е�����ֵΪ�����Ľ�����
�������ǰ�棬����ֵΪż���Ľ�����������ĺ��档
*/

/**********************************/
/*�ļ����ƣ�lab3_08.c             */
/**********************************/
#include "slnklist.h"
/*�뽫���������������������в���*/
void partion(linklist head)
{
    linklist f = head->next;
    linklist right = head->next;
    linklist r;
    linklist left = head;

    while(right->next)
    {
        right = right->next;
    }
    r = right;
    while(f != r)
    {
        switch(f->info % 2)
        {
            case 1:
            {
                f = f->next;
                left = left->next;
                break;
            }
            case 0:
            {
                left->next = f->next;
                right->next = f;
                f->next = NULL;
                f = left->next;
                right = right->next;
                break;
            }
        }
    }

    return head;
}
int main()
{        linklist head;
         head=creatbyqueue();           /*β�巨������ͷ���ĵ�����*/
         print(head);                   /*���������head*/
         partion(head);
         print(head);
         delList(head);
         return 0;
}
