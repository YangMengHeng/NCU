/*
�Ա�дһ������������һ�ø�����������ǰ������µ����һ����㡣
*/

#include "bintree.h"
char *a="ABC##D##EF#G###";  /*�������������t��ǰ������*/
bintree prelast(bintree t)
{
    if (t==NULL)  return NULL;
    else
        {
            if (t->lchild==NULL && t->rchild==NULL)  return t;
            else
                {
                    if (t->rchild )  return prelast(t->rchild);
                    else  return prelast(t->lchild);
                }
        }
}

bintree postfirst(bintree t)
{
    bintree p;
	if (t)
	{
		p=t;
		while (p && p->lchild || p->rchild)
        {
		    if (p->lchild)
		    	p=p->lchild;
	    	else
	    	   p=p->rchild;
        }
	}
	return p;
}

int main()
{   bintree t,p,q;
    t=creatbintree();   	/*����������t�Ĵ洢�ṹ*/
    p=prelast(t);
	q=postfirst(t);
	if (p) 	{   printf("ǰ��������һ�����Ϊ��%c\n",p->data);
			    printf("���������һ�����Ϊ��%c\n",q->data);
            }
	 else	printf("������Ϊ�գ�");
    return 0;
}


