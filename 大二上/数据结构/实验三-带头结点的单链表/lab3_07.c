/*
设计一个算法linklist interSection(linklist L1,linklist L2)，
求两个单链表表示的集合L1和L2的交集，并将结果用一个新的带头
结点的单链表保存并返回表头地址。
*/
/**********************************/
/*文件名称：lab3_07.c                 */
/**********************************/
#include "slnklist.h"
/*请将本函数补充完整，并进行测试*/
linklist   interSection(linklist L1, linklist L2)
{
    linklist L3 = (linklist)malloc(sizeof(node));
    linklist r, s;
    linklist temp = L1->next;
    linklist temp1 = L2->next;
    int j = 1;  //记录L1链表有几个结点
    int i = 1;  //记录L2链表有几个结点
    int k = 0;  //循环变量
    int* data = NULL;
    int length = 0;  //临时交集数组的长度

    while(temp->next)
    {
        temp = temp->next;
        i++;
    }
    while(temp1->next)
    {
        temp1 = temp1->next;
        j++;
    }
    //哪个链表元素多，就让哪个链表做基准数组
    temp = L1->next;
    temp1 = L2->next;
    if(i > j)
    {
        data = (int *)malloc(j * sizeof(datatype));
        for(;i > 0; i--)
        {
            temp1 = L2->next;
            for(k = 0;k < j;k++)
            {
                if(temp->info == temp1->info)
                {
                    data[length++] = temp->info;
					break;
                }
                temp1 = temp1->next;
            }
            temp = temp->next;
        }
    }
    else
    {
        data = (int *)malloc((i + 1) * sizeof(datatype));
        for(;j > 0; j--)
        {
            temp = L1->next;
            for(k = 0;k < i;k++)
            {
                if(temp->info == temp1->info)
                {
                    data[length++] = temp->info;
					break;
                }
                temp = temp->next;
            }
            temp1 = temp1->next;
        }
    }
    data[length] = 0;
    s = L3;
    L3->info = 0;
    for(k = 0; data[k] != 0; k++)
    {
        r = (linklist)malloc(sizeof(node));
        r->info = data[k];
        r->next = NULL;
        s->next = r;
        s = r;
    }

    return L3;
}
int main()
{
 linklist h1,h2,h3;
 h1=creatbyqueue();           /*尾插法建立单链表,输入时请勿输入重复数据*/
 h2=creatbyqueue();
 print(h1);                   /*输出单链表h1*/
 print(h2);
 h3=interSection(h1,h2);      /* 求h1和h2的交集*/
 print(h3);
 delList(h1);
 delList(h2);
 delList(h3);
 return 0;
}
