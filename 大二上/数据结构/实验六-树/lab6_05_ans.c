/*
����������ָ�뷽ʽ�ĺ��ӱ�ʾ���洢�ṹ���Ա�дһ������tree Ct(char s[])��
����������������ű�ʾ�ַ���s���������Ĵ洢�ṹ�����磬��Ҫ�����̲�ͼ6.4��ʾ������
Ӧ����A��B��E��F��,C,D��G��I��J��K��,H��������˵����tree.h�ж���ĳ���m��ʾ������
��ȣ�����ݽ�������Ҫ�����޸�m��ֵ��

*/

#include "tree.h"
/*�뽫���������������������в���*/
tree Ct(char s[MAXLEN])
{
    int length;
	tree root;
	int i,j,top;
	tree stack[MAXLEN],temp = NULL,p;
	int childSeq[MAXLEN];	/*��ڼ�������*/
	top = -1;
	length = strlen (s);
    for (i = 0;i < length;i++)
	{
		if (s[i] == ',')
		{
			continue;
		}
		else if (s[i] == '(')
		{
			stack[++top] = temp;
			childSeq[top] = 0;
		}
		else if (s[i] == ')')
		{
			top--;
		}
		else if (top != -1)
		{
			p = (tree)malloc (sizeof (node));
			p->data= s[i];
			for (j = 0;j < m;j++)
			{
				p->child[j] = NULL;
			}
             temp = p;
			 stack[top]->child[childSeq[top]++] = temp;
		}
		else
		{
			root = (tree)malloc (sizeof (node));
			root->data= s[i];
			for (j = 0;j < m;j++)
			{
				root->child[j] = NULL;
			}
			temp = root;
		}
	}
	return root;
}

int main ()
{
    char s[MAXLEN];
	tree root = NULL;
	printf ("�����������ű�ʾ������һ����:\n");
	scanf ("%s",s);
	root = Ct(s);
	preorder(root);  /*ǰ�������*/
	return 0;
}
