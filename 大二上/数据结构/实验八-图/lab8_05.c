/***************************************************/
/*          Dijkstra��Դ���·���㷨               */
/***************************************************/
#include "ljjz.h"   /*�����ڽӾ��󴴽�����*/
typedef enum{FALSE,TRUE} boolean;/*falseΪ0,trueΪ1*/
typedef int dist[M];  /* ������������*/
typedef int path[M];  /* ·������*/

/*�������ܣ�Dijkstra�㷨��ⵥԴ���·��
����������ͼ���ڽӾ���g;Դ��v0;·������p����������d
*/
void dijkstra(Mgraph g,int v0,path p,dist d)
 { boolean final[M]; /*��ʾ��ǰԪ���Ƿ���������·��*/
   int i,k,j,v,min,x;

   /*  ��1��  ��ʼ������S���������d */
    for (v=0;v<g.n;v++)
    {
        final[v]=FALSE;
        d[v]=g.edges[v0][v];
        if (d[v]<FINITY &&d[v]!=0)
                p[v]=v0; else p[v]=-1;
    }
    final[v0]=TRUE;
    d[v0]=0;
   /* ��2��  �����ҳ�n-1��������S��   */
    for (i=1;i<g.n;i++)
    {
        min=FINITY;
        for (k=0;k<g.n;k++)
            if (!final[k] && d[k]<min)
            {
                v=k;
                min=d[k];
            }
            if (min==FINITY)     return ;
            final[v]=TRUE;
    /*��3�� �޸�S��V-S�и����ľ���*/
    for (k=0;k<g.n;++k)
            if (!final[k] && (min+g.edges[v][k]<d[k]))
            {
                d[k]=min+g.edges[v][k];
                p[k]=v;
            }
    }
}
/*�������ܣ��������ͼ�����·��
�����������ڽӾ���g��·������p����������d
*/
void print_gpd(Mgraph g,path p,dist d)
 {
   int st[M],i,pre,top=-1;
   for (i=0;i<g.n;i++)
    { printf("\nDistancd: %7d , path:" ,d[i]);
      st[++top]=i;
      pre=p[i];
      while (pre!=-1)   /*�ӵ�i�����㿪ʼ��ǰ�������·���ϵĶ���*/
        { st[++top]=pre;
          pre=p[pre];
         }
      while (top>0)
     printf("%2d",st[top--]);
    }
 }
/*---------- ������ ------------*/
int main()
 { Mgraph g;   /* ����ͼ */
   path p;     /* ·������ */
   dist d;     /* ���·������ */
   int v0;
   creat(&g,"g21.txt",1); /*����ͼ8.21��ʾ��������G21�������ļ�Ϊg21.txt */
   print(g);        /*���ͼ���ڽӾ���*/
   printf("\n");
   printf("������Դ���ţ�");
   scanf("%d",&v0);       /*����Դ��*/
   dijkstra(g,v0,p,d);   /*��v0�������������̾���*/
   /*���V0�����������·����Ϣ������*/
   print_gpd(g,p,d);

    return 0;
  }
