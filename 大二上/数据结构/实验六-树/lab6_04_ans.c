/*
����������ָ�뷽ʽ�ĺ��ӱ�ʾ����ʾ���Ա�дһ������int equal(tree t1, tree t2)��
�ж����ø��������Ƿ�ȼۣ��������ȼ۵��ҽ����������ֵ��������Ӧ���������໥�ȼۣ���
*/
#include "tree.h"
#define TRUE  1
#define FALSE 0

int equal(tree t1,tree t2)
{	int i;
	if (t1 == NULL && t2 == NULL)
	{
		return TRUE;
	}
	else if (t1 == NULL && t2 != NULL  || 	t1 != NULL && t2 == NULL)
	{
		return FALSE;
	}
	else
	{
		if (t1->data != t2->data)
		{
			return FALSE;
		}
		for (i = 0;i < m;i++)
		{
			if ( equal(t1->child[i],t2->child[i]) == FALSE)
			{
				return FALSE;
			}
		}
		return TRUE;
	}
}

int main ()
{
	tree t1,t2;
    printf("please input the preorder sequence of the tree:\n");
	t1=createtree();
	getchar();
	printf("please input the preorder sequence of the tree:\n");
	t2=createtree();
    if (equal(t1,t2) == TRUE)
	{
		printf ("�������\n");
	}
	else
	{
		printf ("���������\n");
	}

	return 0;
}
