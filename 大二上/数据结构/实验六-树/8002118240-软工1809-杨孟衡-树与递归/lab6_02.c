/*
����������ָ�뷽ʽ�ĺ��ӱ�ʾ����ʾ���Ա�дһ���ǵݹ麯��void PreOrder1(tree root)��ʵ������ǰ������㷨��
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
		printf("ǰ�������ǣ�\n");
		PreOrder1(root);
		return 0;
}
