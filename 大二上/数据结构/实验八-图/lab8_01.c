/*
��д����������ڽӱ�Ϊ�洢�ṹ������ͼ�ĸ�����Ķȡ�
*/
/**********************************/
/*�ļ����ƣ�lab8_01.c                 */
/**********************************/
#include "ljb.h"
/* ������ڽӱ�Ϊ�洢�ṹ������ͼg�ĸ�����Ķ� */
void degree(LinkedGraph g)
{
    EdgeNode* t;
    int num = g.n;
    int k;
    int i;

    for(i = 0; i < num; i++)
    {
        t = g.adjlist[i].FirstEdge;
        for(k = 1; ;k++)
        {
            if(t->next == NULL)
            {
                break;
            }
            t = t->next;
        }
        printf("��%d�����Ķ���%d\n", i + 1, k);
    }
}
int main()
{ LinkedGraph g;
  creat(&g,"g11.txt",0);  	/*��֪g11.txt�д洢��ͼ����Ϣ*/
  printf("\nThe graph is:\n");
  print(g);
  degree(g);
  return 0;
}
