/*
�ַ������ô�ͷ��������洢������㷨����void delstring(linkstring s, int i,int len)
���ַ���s��ɾ���ӵ�i��λ�ÿ�ʼ������Ϊlen���Ӵ���
*/
/**********************************/
/*�ļ����ƣ�lab4_05.c                 */
/**********************************/
#include "linkstring.h"
/*�뽫���������������������в���*/
void delstring(linkstring  s, int i, int len)
{
    linkstring p = s->next;
    linkstring q = s;
    linkstring temp = q;
    int k = 0;

    if(i < 0)
    {
        printf("û�����λ�õĽ�㣡���������룡\n");
        exit(-1); 
    }
    for(k = 1; k < i; k++)
    {
        if(p->next == NULL && (k + 1) < i)
        {
            printf("û�����λ�õĽ�㣡���������룡\n");
			exit(-1);
        }
        temp = temp->next;
        p = p->next;
    }
    k = 0;
    while(p && k < len)
    {
        q = p;
        p = p->next;
        temp->next = p;
        free(q);
        k++;
    }
    if(!p && k != len)
    {   
        free(p);
        temp->next = NULL;
    }
}
int main()
{   linkstring str;
    str=creat();            /*���ַ�������*/
    print(str);
    delstring(str,3,5);     /*���ԣ��ӵ�2��λ��ɾ������Ϊ3���Ӵ�,�����й��첻ͬ�Ĳ�������  */
    print(str);               /*���*/
    delList(str);
    return 0;
}
