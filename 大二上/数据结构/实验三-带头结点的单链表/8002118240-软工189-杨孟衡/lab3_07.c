/*
���һ���㷨linklist interSection(linklist L1,linklist L2)��
�������������ʾ�ļ���L1��L2�Ľ��������������һ���µĴ�ͷ
���ĵ������沢���ر�ͷ��ַ��
*/
/**********************************/
/*�ļ����ƣ�lab3_07.c                 */
/**********************************/
#include "slnklist.h"
/*�뽫���������������������в���*/
linklist   interSection(linklist L1, linklist L2)
{
    linklist L3 = (linklist)malloc(sizeof(node));
    linklist r, s;
    linklist temp = L1->next;
    linklist temp1 = L2->next;
    int j = 1;  //��¼L1�����м������
    int i = 1;  //��¼L2�����м������
    int k = 0;  //ѭ������
    int* data = NULL;
    int length = 0;  //��ʱ��������ĳ���

    while(temp->next)
    {
        temp = temp->next;
        i++;
    }
    while(temp1->next)
    {
        temp1 = temp1->next;
        j++;
    }
    //�ĸ�����Ԫ�ض࣬�����ĸ���������׼����
    temp = L1->next;
    temp1 = L2->next;
    if(i > j)
    {
        data = (int *)malloc(j * sizeof(datatype));
        for(;i > 0; i--)
        {
            temp1 = L2->next;
            for(k = 0;k < j;k++)
            {
                if(temp->info == temp1->info)
                {
                    data[length++] = temp->info;
					break;
                }
                temp1 = temp1->next;
            }
            temp = temp->next;
        }
    }
    else
    {
        data = (int *)malloc((i + 1) * sizeof(datatype));
        for(;j > 0; j--)
        {
            temp = L1->next;
            for(k = 0;k < i;k++)
            {
                if(temp->info == temp1->info)
                {
                    data[length++] = temp->info;
					break;
                }
                temp = temp->next;
            }
            temp1 = temp1->next;
        }
    }
    data[length] = 0;
    s = L3;
    L3->info = 0;
    for(k = 0; data[k] != 0; k++)
    {
        r = (linklist)malloc(sizeof(node));
        r->info = data[k];
        r->next = NULL;
        s->next = r;
        s = r;
    }

    return L3;
}
int main()
{
 linklist h1,h2,h3;
 h1=creatbyqueue();           /*β�巨����������,����ʱ���������ظ�����*/
 h2=creatbyqueue();
 print(h1);                   /*���������h1*/
 print(h2);
 h3=interSection(h1,h2);      /* ��h1��h2�Ľ���*/
 print(h3);
 delList(h1);
 delList(h2);
 delList(h3);
 return 0;
}
