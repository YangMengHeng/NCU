/*
假设树采用指针方式的孩子表示法表示，试编写一个非递归函数void PreOrder1(tree root)，实现树的前序遍历算法。
*/
#include "tree.h"
void  PreOrder1(tree root)
{
	tree stack[100];
    int top=-1;
	int i;

    while (root || top!=-1)
    {
    	if (root)
    	{	printf("%c",root->data);
    		for (i=m-1;i>0;i--)
    			if (root->child[i])
    			 stack[++top]=root->child[i];
		    root=root->child[0];
    	}
		else
		if (top>-1)
		{
			root=stack[top--];
		}
   }
}
int main ()
{
        tree root;
        printf("please input the preorder sequence of the tree:\n");
		root =createtree();
		printf("前序序列是：\n");
		PreOrder1(root);
		return 0;
}
