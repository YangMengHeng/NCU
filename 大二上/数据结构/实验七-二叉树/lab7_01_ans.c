/*

��д�㷨����void preorder1(bintree t)ʵ�ֶ�����t�ķǵݹ�ǰ�������

*/

#include "bintree.h"
char *a="ABC##D#E##F##";  /*�������������t��ǰ������*/

/*����preorder1()�Ĺ����Ƿǵݹ�ǰ�����������t���뽫����������������������*/
void preorder1(bintree t)
{
    seqstack s;  /*˳��ջ*/
    init(&s);    /*��ʼ����ջ*/
    /*���ڴ˴�����������������*/
    while (t || s.top>-1)
    {
        if (t)
        {
            printf("%c",t->data);
            push(&s,t);
            t=t->lchild;
        }
        else
        {
           t=pop(&s);
           t=t->rchild;
        }
    }

}
int main()
{   bintree t;
    t=creatbintree();   /*����������t�Ĵ洢�ṹ*/
    printf("��������ǰ������Ϊ��\n");
    preorder1(t);       /*ǰ��ݹ����������*/
    return 0;
}
