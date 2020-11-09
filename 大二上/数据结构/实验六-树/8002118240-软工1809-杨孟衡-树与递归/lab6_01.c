/*
编写算法函数void levelorder(tree t)实现树的层次遍历。
*/

#include "tree.h"

void levelorder(tree t)    /* t为指向树根结点的指针*/
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
