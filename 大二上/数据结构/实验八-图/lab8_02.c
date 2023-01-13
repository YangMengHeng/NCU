/*
ͼ�����ڽӱ�洢�ṹ����̶�ͼ���й�����ȱ�����
*/
/**********************************/
/*�ļ����ƣ�lab8_02.c                 */
/**********************************/
#include "ljb.h"
int visited[M];  				/*ȫ�ֱ�־����*/
/*�뽫���������������������в���*/
void bfs(LinkedGraph g, int i)
{ /*�Ӷ���i����������ȱ���ͼg����ͨ����*/
  int j;
  EdgeNode* p;
  int queue[M], front, rear;

  front = rear = 0;
  printf("%c ", g.adjlist[i].vertex);
  visited[i] = 1;
  queue[rear++] = i;
  while(rear > front)
  {
    j = queue[front++];
    p = g.adjlist[j].FirstEdge;
    while(p)
    {
      if(visited[p->adjvex] == 0)
      {
        printf("%c ", g.adjlist[p->adjvex].vertex);
        queue[rear++] = p->adjvex;
        visited[p->adjvex] = 1;
      }
      p = p->next;
    }
  }
}


/*�������ܣ�������ȱ���ͼg
  �����������ڽӱ�g
*/
int BfsTraverse(LinkedGraph g)
{  int i,count=0;
   for (i=0;i<g.n;i++)
       visited[i]=0;     /*��ʼ����־����*/

   for (i=0;i<g.n;i++)
       if (!visited[i])  /*viδ���ʹ�*/
       {printf("\n");
        count++;            /*��ͨ����������1*/
        bfs(g,i);
       }
   return count;
 }

int main()
{ 	  LinkedGraph g;
      int count;
      creat(&g,"g11.txt",0);  		/*����ͼ���ڽӱ�*/
      printf("\n The graph is:\n");
      print(g);
      printf("������ȱ�������Ϊ��\n");
      count=BfsTraverse(g);     	/*�Ӷ���0����������ȱ���ͼg*/
      printf("\n��ͼ����%d����ͨ������\n",count);
      return 0;
}


