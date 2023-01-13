/*
编写算法函数void levelorder(tree t)实现树的层次遍历。
*/

#include "tree.h"

void levelorder(tree t)    /* t为指向树根结点的指针*/
    {
       tree queue[100];        /*存放等待访问的结点队列*/
       int f,r,i;            /*f、r分别为队头、队尾指针*/
       tree p;
       f=0; r=1; queue[0]=t;
       while (f<r)      /*队列不为空*/
        {
          p=queue[f]; f++; printf("%c",p->data);  /*访问队头元素*/
          for (i=0;i<m;++i)   /*将刚被访问的元素的所有子女结点依次进队*/
            if (p->child[i])
            {
               queue[r]=p->child[i];  ++r;
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
