/*
   ����������ָ�뷽ʽ�ĺ��ӱ�ʾ����ʾ���Ա�дһ���ǵݹ麯��void PostOrder1(tree t)��ʵ�����ĺ�������㷨��
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
	printf("���������ǣ�\n");
	PostOrder1(root);
	return 0;
}

