/*
字符串采用带头结点的链表存储，设计算法函数void delstring(linkstring s, int i,int len)
在字符串s中删除从第i个位置开始，长度为len的子串。
*/
/**********************************/
/*文件名称：lab4_05.c                 */
/**********************************/
#include "linkstring.h"
/*请将本函数补充完整，并进行测试*/
void delstring(linkstring  s, int i, int len)
{
    linkstring p = s->next;
    linkstring q = s;
    linkstring temp = q;
    int k = 0;

    if(i < 0)
    {
        printf("没有这个位置的结点！请重新输入！\n");
        exit(-1); 
    }
    for(k = 1; k < i; k++)
    {
        if(p->next == NULL && (k + 1) < i)
        {
            printf("没有这个位置的结点！请重新输入！\n");
			exit(-1);
        }
        temp = temp->next;
        p = p->next;
    }
    k = 0;
    while(p && k < len)
    {
        q = p;
        p = p->next;
        temp->next = p;
        free(q);
        k++;
    }
    if(!p && k != len)
    {   
        free(p);
        temp->next = NULL;
    }
}
int main()
{   linkstring str;
    str=creat();            /*建字符串链表*/
    print(str);
    delstring(str,3,5);     /*测试，从第2个位置删除长度为3的子串,请自行构造不同的测试用例  */
    print(str);               /*输出*/
    delList(str);
    return 0;
}
