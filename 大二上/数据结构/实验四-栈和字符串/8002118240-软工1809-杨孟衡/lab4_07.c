/*
��������ģʽƥ���㷨����ģʽt������s�����г��ֵ�λ�ô洢�ڴ�ͷ���ĵ������С�
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}linknode;
typedef linknode *linklist;
/*����ģʽƥ���㷨,����t��s�е�һ�γ��ֵ�λ�ã�û�ҵ��򷵻�-1���뽫���򲹳�����*/
int index(char *s, char *t)
{
	int i = 0, j = 0, succ = 0;
	int tlength = 0;
	int slength = 0;

	while (t[i] != '\0' && t[i] != EOF)
	{
		tlength++;
		i++;
	}
	while (s[j] != '\0' && s[j] != EOF)
	{
		slength++;
		j++;
	}
	i = j = 0;
	while ((i <= slength - tlength) && (!succ))
	{
		j = 0;
		succ = 1;
		while ((j <= tlength - 1) && succ)
		{
			if (t[j] == s[i + j])
			{
				j++;
			}
			else succ = 0;
		}
		i++;
	}
	if (succ) return (i - 1);
	else return -1;
}
/*��������ģʽƥ���㷨����ģʽt��s�����г��ֵ�λ�ô洢�ڴ�ͷ���ĵ�������,�뽫������������*/
linklist indexall(char *s, char *t)
{
	linklist p = (linklist)malloc(sizeof(linknode));
	linklist head = p;
	linklist q;
	int tlength = 0;
	int slength = 0;
	int i = 0;
	int k = 0;
	int j = 0;
	char* temp;

	p->next = NULL;
	p->data = 0;
	while (t[i] != '\0' && t[i] != EOF)
	{
		tlength++;
		i++;
	}
	i = 0;
	while (s[i] != '\0' && s[i] != EOF)
	{
		slength++;
		i++;
	}
	i = 0;
	temp = (char*)malloc(sizeof(char) * (slength + 1));
	for (k = 0,j = 0; k < slength; k++, j++)
	{
		temp[k] = s[j];
	}
	temp[slength] = '\0';
	while (i < slength)
	{
		k = index(temp, t);
		if (k == -1)
		{
			break;
		}
		else
		{
			q = (linklist)malloc(sizeof(linknode));
			q->data = k + i;
			i = q->data + 1;
			q->next = NULL;
			p->next = q;
			p = p->next;
			for (k = i, j = 0; j < slength - i; j++, k++)
			{
				temp[j] = s[k];
			}
			temp[j] = '\0';
		}
	}

	return head;
}
/*�����ͷ���ĵ�����*/
void print(linklist head)
{
	linklist p;
	p = head->next;
	while (p)
	{
		printf("%5d", p->data);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	char s[80], t[80];
	linklist head;
	printf("����������:\n");
	gets(s);
	printf("������ģʽ��:\n");
	gets(t);
	int k = index(s, t);
	printf("k=%d", k);
	head = indexall(s, t);
	printf("\n[ %s ]��[ %s ]�е�λ���У�\n", t, s);
	print(head);
	return 0;
}