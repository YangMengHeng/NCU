/*
   �Ա�дһ����������һ�ø��������������н���������Ů������
*/
#include "bintree.h"
char *a="ABC##D##EF#G###";  		/*�������������t��ǰ������*/
/*�뽫���������������������в���*/
void change(bintree t)
{	bintree p;
		if (t)
		{	p=t->lchild;
			t->lchild=t->rchild;
			t->rchild=p;
			change(t->lchild);
			change(t->rchild);
		}
}
int main()
{  bintree root;
   root=creatbintree();
   change(root);
   preorder(root);
}
