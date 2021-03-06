/*****************************************************/
/*  函数功能：建立一个空的带头结点的单链表           */
/*  函数参数：空                                     */
/*  函数返回值：指向node类型变量的指针             */
/*  文件名：hlnklist.c，函数名：init()                    */
/**************************************************** */
 node *init()
 {
   node *head;
   head=(node*)malloc(sizeof(node));
   head->next=NULL;
   return head;
 }


/*****************************************************/
/*  函数功能：输出带头结点的单链表中各个结点的值     */
/*  函数参数：指向node类型变量的指针head            */
/* 函数返回值：无                          */
/*  文件名：hlnklist.c，函数名：display()               */
  /*****************************************************/
 void display(node *head)
 {
   node *p;
   p=head->next;/*从第一个（实际）结点开始*/
   if(!p) printf("\n带头结点的单链表是空的!");
   else
     {
       printf("\n带头结点的单链表各个结点的值为：\n");
       while(p) { printf("%5d",p->info);p=p->next;}
     }
 }

 /*****************************************************/
/*  函数功能：在带头结点的单链表中查找第i个结点地址 */
/*  函数参数：指向node类型变量的指针head           */
/*             int类型变量i                          */
/*  函数返回值：指向node类型变量的指针head          */
/*  文件名hlnklist.c，函数名find()                     */
/*****************************************************/
 node *find(node *head,int i)
 {
   int j=0;
   node *p=head;
   if(i<0){printf("\n带头结点的单链表中不存在第%d个结点！",i);return NULL;}
   else if(i==0) return p;/*此时p指向的是头结点*/
   while(p&&i!=j)/*没有查找完并且还没有找到*/
   {
     p=p->next;j++;/*继续向后（左）查找，计数器加1*/
   }
   return p;/*返回结果，i=0时，p指示的是头结点*/
 }


/***********************************************************************/
/*  函数功能：在带头结点的单链表中第i个结点后插入一个值为x的新结点 */
/*  函数参数：指向node类型变量的指针head                              */
/*            datatype 类型变量x，int型变量i                            */
 /*  函数返回值：指向node类型变量的指针head                           */
 /* 文件名：hlnklist.c，函数名：insert()                     */
 /***********************************************************************/
 node *insert(node *head,datatype x,int i)
 {
   node *p,*q;
   q=find(head,i);/*查找带头结点的单链表中的第i个结点*/
                           /*i=0，表示新结点插入在头结点之后，此时q指向的是头结点*/
   if(!q)/*没有找到*/
   {printf("\n带头结点的单链表中不存在第%d个结点！不能插入%d！",i,x);return head;}
   p=(node*)malloc(sizeof(node));/*为准备插入的新结点分配空间*/
   p->info=x;/*为新结点设置值x*/
   p->next=q->next;/*插入(1)*/
   q->next=p;/*插入(2)，当i=0时，由于q指向的是头结点，本语句等价于head>next=p */
   return head;
 }


/******************************************************/
/*  函数功能：在带头结点的单链表中删除一个值为x的结点*/
/*  函数参数：指向node类型变量的指针head            */
/*            datatype类型变量x                      */
/*  函数返回值：指向node类型变量的指针              */
/*  文件名：hlnklist.c，函数名：dele()    */
/*****************************************************/
 node *dele(node *head,datatype x)
 {
   node *pre=head,*q;/*首先pre指向头结点*/
   q=head->next;/*q从带头结点的第一个实际结点开始找值为x的结点*/
   while(q&&q->info!=x)/*没有查找完并且还没有找到*/
     {pre=q;q=q->next;}/*继续查找，pre指向q的前驱*/
   pre->next=q->next;/*删除*/
   free(q);/*释放空间*/
   return head;
 }




