/*
��֪�ַ������ô�������ʽ�洢�ṹ�����linksrting.h�ļ�����
���д����linkstring substring(linkstring s,int i,int len)��
���ַ���s�дӵ�i��λ����ȡ����Ϊlen���Ӵ������������Ӵ�����
*/

#include "linkstring.h"
/*�뽫���������������������в���*/
linkstring substring(linkstring  s, int i, int len)
{
    linkstring p = s->next;
    linkstring q = s;
    linkstring temp = p;
    int k = 0;

    if(i < 0)
    {
        printf("û�����λ�õĽ�㣡���������룡\n");
        return s;
    }
    for(k = 1; k < i; k++)
    {
        if(p->next == NULL && (k + 1) < i)
        {
            printf("û�����λ�õĽ�㣡���������룡\n");
            return s;
        }
        temp = p;
        q->next = p->next;
        p = p->next;
        free(temp);
    }
    temp = p;
    for(k = 1;k < len; k++)
    {
        if(!temp)
        {
            break;
        }
        temp = temp->next;
    }
    temp->next = NULL;
    
    return s;
}
int main()
{   linkstring str1,str2;
    str1=creat();                  /*���ַ�������*/
    print(str1);
    str2=substring(str1,3,5);    /*���ԣ��ӵ�3��λ�ÿ�ʼȡ����Ϊ5���Ӵ�,�����й��첻ͬ��������*/
    print(str2);                   /*����Ӵ�*/
    delList(str1);
    delList(str2);
    return 0;
}
