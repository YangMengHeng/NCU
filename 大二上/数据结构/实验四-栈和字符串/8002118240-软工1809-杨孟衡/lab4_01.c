/*
����˳��ջ�ṹ����д�㷨����void Dto16(unsigned int m)ʵ��ʮ�����޷�������m��ʮ����������ת�����ܡ�
*/
/**********************************/
/*�ļ����ƣ�lab4_01.c                 */
/**********************************/
#include "seqstack.h"
/*�뽫���������������������в���*/
void Dto16(int m)
{   seqstack s;			/*����˳��ջ*/
    init(&s);
    printf("ʮ������%u��Ӧ��ʮ���������ǣ�",m);
    while (m)
    {
        push(&s,m % 16);
        m = m >> 4;
    }
    while (!empty(&s))
                putchar(read(&s) < 10 ? pop(&s) + 48: pop(&s) + 55);
    printf("\n");
}
int main()
{    int m;
     printf("�������ת����ʮ��������\n");
     scanf("%u",&m);
     Dto16(m);
     return 0;
}
