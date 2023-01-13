/*
   试编写一个函数，将一棵给定二叉树中所有结点的左、右子女互换。
*/
#include "bintree.h"
char *a="ABC##D##EF#G###";  		/*扩充二叉树序树t的前序序列*/
/*请将本函数补充完整，并进行测试*/
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
