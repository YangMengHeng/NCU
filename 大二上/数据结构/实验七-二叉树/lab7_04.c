/*
���������������ʽ��ʽ�洢��rootΪ�����㣬��дһ������int Depth(bintree t, char x)����ֵΪx�Ľ���ڶ������еĲ�Ρ�
*/
#include "bintree.h"
char *a="ABC##D##EF#G###";  		/*�������������t��ǰ������*/

/*
 	����Depth�����ܣ�����x���ڵĲ��
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
   printf("���������е�1�����ֵ��\n");
   scanf("%c",&x);
   k=Depth(root,x);
   printf("%c���Ĳ��Ϊ%d\n",x,k);
}
