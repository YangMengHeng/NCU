/*
试编写一个递归函数bintree buildbintree(char *pre, char *mid, int length)，
根据二叉树的前序序列pre、中序序列mid和前序序列长度length，构造二叉树的存储结构，
函数返回二叉树的树根地址。

*/

#include "bintree.h"
char *a="";
/*请将本函数补充完整，并进行测试*/
bintree buildbintree(char *pre, char *mid,int length)
{
    bintree t;
    int len;
    char *p;
    if (length<=0) return NULL;
    else
    {
        t=(bintree)malloc(sizeof(binnode));
        t->data=*pre;
        t->lchild=t->rchild=NULL;

        p=mid;
        while ( p<mid+length && *p!=*pre)
            p++;

        len=p-mid;                              /*左子树前序序列长度*/
        t->lchild=buildbintree(pre+1,mid,len);  /*递归建左子树*/
        t->rchild=buildbintree(pre+len+1,p+1,length-1-len);  /*递归建右子树*/
        return t;
    }
}
int main()
{   bintree root;
    char pre[100],mid[100];
    puts("请输入前序序列：");
    gets(pre);
    puts("请输入中序序列：");
    gets(mid);
    root=buildbintree(pre,mid,strlen(pre));
    puts("后序序列是：");
    postorder(root);
}

