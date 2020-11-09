/*
试编写一个函数，返回一棵给定二叉树在前序遍历下的最后一个结点。
*/

#include "bintree.h"
char *a="ABC##D##EF#G###";  /*扩充二叉树序树t的前序序列*/
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
    t=creatbintree();   	/*建立二叉树t的存储结构*/
    p=prelast(t);
	q=postfirst(t);
	if (p) 	{   printf("前序遍历最后一个结点为：%c\n",p->data);
			    printf("后序遍历第一个结点为：%c\n",q->data);
            }
	 else	printf("二叉树为空！");
    return 0;
}


