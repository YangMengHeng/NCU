/*
������ʽջ�ṹ����д�㷨����void Dto16(unsigned int m)ʵ��ʮ�����޷�������m��ʮ����������ת�����ܡ�
*/
/**********************************/
/*�ļ����ƣ�lab4_02.c                 */
/**********************************/
#include "linkstack.h"
/*�뽫���������������������в���*/
void Dto16(unsigned int m)
{
    linkstack s;
    s=init();
    printf("ʮ������%u��Ӧ��ʮ���������ǣ�",m);
    while (m)
    {
        s = push(s, m % 16);
        m = m << 4;
    }
    while (!empty(s))
               {
                   printf("%c", read(s) < 10? read(s) + 48:read(s) + 55);
                   s = pop(s);
               }
    printf("\n");
}


int main()
{
        unsigned int m;
        printf("�������ת����ʮ��������\n");
        scanf("%u",&m);
        Dto16(m);
        return 0;
}

