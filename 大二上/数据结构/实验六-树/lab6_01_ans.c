/*
��д�㷨����void levelorder(tree t)ʵ�����Ĳ�α�����
*/

#include "tree.h"

void levelorder(tree t)    /* tΪָ����������ָ��*/
    {
       tree queue[100];        /*��ŵȴ����ʵĽ�����*/
       int f,r,i;            /*f��r�ֱ�Ϊ��ͷ����βָ��*/
       tree p;
       f=0; r=1; queue[0]=t;
       while (f<r)      /*���в�Ϊ��*/
        {
          p=queue[f]; f++; printf("%c",p->data);  /*���ʶ�ͷԪ��*/
          for (i=0;i<m;++i)   /*���ձ����ʵ�Ԫ�ص�������Ů������ν���*/
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
