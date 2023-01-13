/*
假设二叉树采用链式方式存储，root为其根结点，编写一个函数int Depth(bintree t, char x)，求值为x的结点在二叉树中的层次。
*/
#include "bintree.h"
char *a="ABC##D##EF#G###";  		/*扩充二叉树序树t的前序序列*/

/*
 	函数Depth，功能：求结点x所在的层次
*/
int Depth(bintree t,char x)
{
    seqstack  s;
    int i=0,j;

    s.top=0;
    while(t || s.top!=0)
    {
        while(t)
	  	{
	    	s.data[s.top]=t;
	    	s.tag[s.top]=0;
	    	s.top++;
			t=t->lchild;
	  	}
		while(s.top>0 && s.tag[s.top-1])
	  	{
	    	s.top--;
		 	t=s.data[s.top];
		 	if(t->data==x) return s.top+1;
	  	}
	  	if(s.top>0)
	  	{
	    	t=s.data[s.top-1];
			s.tag[s.top-1]=1;
			t=t->rchild;
	  	}
	  	else  t=NULL;
  }
}

int main()
{  bintree root;
   char x;
   int k=0;
   root=creatbintree();
   printf("请输入树中的1个结点值：\n");
   scanf("%c",&x);
   k=Depth(root,x);
   printf("%c结点的层次为%d\n",x,k);
}
