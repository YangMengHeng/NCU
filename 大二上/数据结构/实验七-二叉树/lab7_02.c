/*
编写算法函数void levelbintree(bintree t)，实现二叉树的层次遍历。
*/

#include "bintree.h"
char *a="ABC##D#E##F##";  			/*扩充二叉树序树t的前序序列*/
void levelbintree(bintree t)
{
    seqstack s;

    s.top = 0;
    while(t || (s.top != 0))
    {
        if(t)
        {
            push(&s, t);
            t =t->lchild;
        }
        else
        {
            t = pop(&s);
            printf("%c", t->data);
            t =t ->rchild;
        }
        
    }
}
int main()
{   bintree t;
    t=creatbintree();   	/*建立二叉树t的存储结构*/
    printf("二叉树的层次序列为：\n");
    levelbintree(t);       /*层次遍历二叉树*/
    return 0;
}
