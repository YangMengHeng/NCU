/*
编写程序输出以邻接表为存储结构的无向图的各顶点的度。
*/
/**********************************/
/*文件名称：lab8_01.c                 */
/**********************************/
#include "ljb.h"
/* 输出以邻接表为存储结构的无向图g的各顶点的度 */
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
        printf("第%d个结点的度是%d\n", i + 1, k);
    }
}
int main()
{ LinkedGraph g;
  creat(&g,"g11.txt",0);  	/*已知g11.txt中存储了图的信息*/
  printf("\nThe graph is:\n");
  print(g);
  degree(g);
  return 0;
}
