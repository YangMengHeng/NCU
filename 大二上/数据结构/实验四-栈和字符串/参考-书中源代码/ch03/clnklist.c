/*****************************************************/
/*  函数功能：建立一个空的循环单链表                 */
/*  函数参数：无                                     */
/*  函数返回值：指向node类型变量的指针              */
/*  文件名：clnkinit.c，函数名init()                     */
/*****************************************************/
 node *init() /*建立一个空的循环单链表*/
 {
   return NULL;
 }


/******************************************************/
/*  函数功能：获得循环单链表的最后一个结点的存储地址  */
/*  函数参数：指向node类型变量的指针变量head         */
/*  函数返回值：指向node类型变量的指针               */
/*  文件名：clnklist.c，函数名：rear()                    */
/*******************************************************/
 node *rear(node *head)
 {
   node *p;
   if(!head)/*循环单链表为空*/
     p=NULL;
   else
     {
       p=head;/*从第一个结点开始*/
       while(p->next!=head)/*没有到达最后一个结点*/
         p=p->next;/*继续向后*/
     }
   return p;
 }


/*****************************************************/
/*  函数功能：输出循环单链表中各个结点的值           */
/*  函数参数：指向node类型变量的指针变量head        */
/*  函数返回值：空                                   */
/*  文件名：clnklist.c，函数名：display()                */
/*****************************************************/
 void display(node *head)
 {
   node *p;
   if(!head) printf("\n循环单链表是空的！\n");
   else
     {
       printf("\n循环单链表各个结点的值分别为:\n");
       printf("%5d",head->info);/*输出非空表中第一个结点的值*/
       p=head->next;/*p指向第一个结点的下一个结点*/
       while(p!=head)/*没有回到第一个结点*/
       {
         printf("%5d",p->info);
         p=p->next;
       }
     }
 }


/*****************************************************/
/*  函数功能：循环单链表中查找值为x的结点的存储地址 */
/*  函数参数：指向node类型变量的指针变量head        */
/*            datatype类型的变量x                    */
/*  函数返回值：指向node类型变量的指针              */
/*  文件名：clnklist.c，函数名：find()                  */
/*****************************************************/
 node *find(node *head,datatype x)
 {
   /*查找一个值为x的结点*/
   node *q;
   if(!head)  /*循环单链表是空的*/
     {
       printf("\n循环单链表是空的！无法找指定结点！");
       return NULL;
     }
   q=head;/* q指向循环单链表的第一个结点，准备查找*/
   while(q->next!=head&&q->info!=x)/*没有查找到并且没有查找完整个表*/
     q=q->next;/*继续查找*/
   if(q->info==x) return q;
     else
    return NULL;
 }


/*****************************************************/
/*  函数功能：循环单链表第i个结点后插入值为x的新结点*/
/*  函数参数：指向node类型变量的指针变量head        */
/*            datatype类型的变量x，int类型的变量i    */
/*  函数返回值：指向node类型变量的指针              */
/*  文件名：clnklist.c，函数名：insert()                 */
/*****************************************************/
 node *insert(node *head,datatype x,int i)
 {/*i为0时表示将值为x的结点插入作为循环单链表的第一个结点*/
   node *p,*q,*myrear;
   int j;
   p=(node*)malloc(sizeof(node));/*分配空间*/
   p->info=x;/*设置新结点的值*/
   if(i<0)/*如果i小于0，则输出出错信息*/
     {printf("\n无法找到指定的插入位置！"); free(p);return head;}
   if(i==0&&!head) /*插入前循环单链表如果是空的，则新结点的指针域应指向它自己*/
    { p->next=p;head=p;return head;}
   if(i==0&&head) /*在非空的循环单链表最前面插入*/
   {
              myrear=rear(head);/*找到循环单链表的最后一个结点*/
              p->next=head;   /*插入(1)*/              head=p; /*插入(2)*/
              myrear->next=p;/*插入(3)最后一个结点的指针域指向新插入的表中第一个结点*/
              return head;
    }
   if(i>0&&!head) {printf("\n无法找到指定的插入位置！"); free(p);return head;}
   if(i>0&&head)
   {/*在非空的循环单链表中插入值为x的结点，并且插入的结点不是第一个结点*/
          q=head;/*准备从表中第一个结点开始查找*/
          j=1;/*计数开始*/
          while(i!=j&&q->next!=head)/*没有找到并且没有找遍整个表*/
                {
                 q=q->next;j++;/*继续查找，计数器加1*/
                }
                if(i!=j)/* 找不到指定插入位置，即i的值超过表中结点的个数，则不进行插入*/
               {
                 printf("\n表中不存在第%d个结点，无法进行插入!\n",i);free(p);
                 return head;
               }
               else
               { /*找到了第i个结点，插入x*/
                p->next=q->next;/*插入，修改指针(1)*/
                q->next=p;/*插入，修改指针(2)*/
                return head;
               } 
            }   
 }

/*****************************************************/
/*  函数功能：在循环单链表中删除一个值为x的结点     */
/*  函数参数：指向node类型变量的指针变量head        */
/*            datatype类型的变量x                    */
/*  函数返回值：指向node类型变量的指针              */
/*  文件名：clnklist.c，函数名：dele()                 */
/*****************************************************/
 node *dele(node *head,datatype x)
 {
   node *pre=NULL,*q;/*q用于查找值为x的结点，pre指向q的前驱结点*/
   if(!head)/*表为空，则无法做删除操作*/
     {
       printf("\n循环单链表为空，无法做删除操作！");
       return head;
     }
   q=head;/*从第1个结点开始准备查找*/
   while(q->next!=head&&q->info!=x)/*没有找遍整个表并且没有找到*/
     {
       pre=q;
       q=q->next;/*pre为q的前驱，继续查找*/
     }/*循环结束后，pre为q的前驱*/
    if(q->info!=x)/*没找到*/
      {
        printf("没有找到值为%d的结点！",x);
      }
     else   /*找到了，下面要删除q*/
      {
      if(q!=head){pre->next=q->next;free(q);}
        else
      if(head->next==head){free(q);head=NULL;}
      else
      {pre=head->next;
      while(pre->next!=q) pre=pre->next; /*找q的前驱结点位置*/
      head=head->next;
      pre->next=head;
      free(q);
      }
      }
   return head;
 }








