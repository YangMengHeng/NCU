/*
   假设树采用指针方式的孩子表示法表示，试编写一个非递归函数void PostOrder1(tree t)，实现树的后序遍历算法。
*/

#include "tree.h"
int PostOrder1(tree root)
{
	tree treeStack[MAXLEN];				
	int top = -1;
	tree printStack[MAXLEN];			
	int topp = -1;
	int i;
	if( root ) treeStack[++top] = root;	
	while( top != -1 )
	{
		root = treeStack[top--];		
		for(i=0;i<m;i++)				
		{
			if( root->child[i] ) treeStack[++top] = root->child[i];
		}
		printStack[++topp] = root;		
	}
	while( topp != -1 ) printf("%c",printStack[topp--]->data);
}
int main ()
{
    tree root;
    printf("please input the preorder sequence of the tree:\n");
	root =createtree();
	printf("后序序列是：\n");
	PostOrder1(root);
	return 0;
}

