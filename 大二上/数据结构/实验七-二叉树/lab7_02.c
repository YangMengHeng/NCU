/*
��д�㷨����void levelbintree(bintree t)��ʵ�ֶ������Ĳ�α�����
*/

#include "bintree.h"
char *a="ABC##D#E##F##";  			/*�������������t��ǰ������*/
void levelbintree(bintree t)
{
    seqstack s;

    s.top = 0;
    while(t || (s.top != 0))
    {
        if(t)
        {
            push(&s, t);
            t =t->lchild;
        }
        else
        {
            t = pop(&s);
            printf("%c", t->data);
            t =t ->rchild;
        }
        
    }
}
int main()
{   bintree t;
    t=creatbintree();   	/*����������t�Ĵ洢�ṹ*/
    printf("�������Ĳ������Ϊ��\n");
    levelbintree(t);       /*��α���������*/
    return 0;
}
