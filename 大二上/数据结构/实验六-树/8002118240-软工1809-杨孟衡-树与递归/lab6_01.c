/*
��д�㷨����void levelorder(tree t)ʵ�����Ĳ�α�����
*/

#include "tree.h"

void levelorder(tree t)    /* tΪָ����������ָ��*/
{
      tree queue[100];        
      int f,r,i;            
      tree p;

      f=0; 
      r=1; 
      queue[0]=t;
      while (f<r)      
      {
        p=queue[f++];
        printf("%c",p->data);  
        for (i=0;i<m;++i)
        {
          if (p->child[i])
          {
              queue[r++]=p->child[i];
          }
        }
      }
}

 int main()
 {
   tree t;
   printf("please input the preorder sequence of the tree:\n");
   t=createtree();
   printf("\nthe levelorder is:");
   levelorder(t);
   return 0;
 }
