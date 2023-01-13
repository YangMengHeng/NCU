/*
�Ա�дһ���ݹ麯��bintree buildbintree(char *pre, char *mid, int length)��
���ݶ�������ǰ������pre����������mid��ǰ�����г���length������������Ĵ洢�ṹ��
�������ض�������������ַ��

*/

#include "bintree.h"
char *a="";
/*�뽫���������������������в���*/
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

        len=p-mid;                              /*������ǰ�����г���*/
        t->lchild=buildbintree(pre+1,mid,len);  /*�ݹ齨������*/
        t->rchild=buildbintree(pre+len+1,p+1,length-1-len);  /*�ݹ齨������*/
        return t;
    }
}
int main()
{   bintree root;
    char pre[100],mid[100];
    puts("������ǰ�����У�");
    gets(pre);
    puts("�������������У�");
    gets(mid);
    root=buildbintree(pre,mid,strlen(pre));
    puts("���������ǣ�");
    postorder(root);
}

