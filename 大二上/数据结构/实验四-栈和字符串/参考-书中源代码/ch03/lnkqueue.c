/******************************************************/
/*    函数功能：建立一个空的链式队列                  */
/*    函数参数：无                                    */
/*    函数返回值：指向queue类型变量的指针            */
/*    文件名：lnkqueue.c，函数名：init()                  */
/******************************************************/
 queue *init() /*建立一个空的链式队列*/
 {
   queue *qu;
   qu=(queue*)malloc(sizeof(queue));  /*分配空间*/
   qu->front=NULL;    /*队首指针设置为空*/
   qu->rear=NULL;     /*队尾指针设置为空*/
   return qu;
 }



/*****************************************************/
/*    函数功能：判断链式队列是否为空                 */
/*    函数参数：queue类型的变量qu                   */
/*    函数返回值：int类型                            */
/*    文件名：lnkqueue.c，函数名：empty()              */
/*****************************************************/
 int empty(queue qu)
 {
   return (qu.front ? 0:1);
 }


/*****************************************************/
/*    函数功能：输出链式队列中各个结点的值           */
/*    函数参数：指向queue类型的指针变量qu           */
/*    函数返回值：空                                 */
/*    文件名：lnkqueue.c，函数名：display()              */
/*****************************************************/
 void display(queue *qu)
 {
   node *p;
   printf("\n");
   p=qu->front;
   if(!p) printf("\nThe link queue is empty!\n");
   while(p) { printf("%5d",p->info);p=p->next;}
 }


/*****************************************************/
/*    函数功能：取得链式队列的队首结点值             */
/*    函数参数：queue类型的变量qu                   */
/*    函数返回值：datatype类型                        */
/*    文件名：lnkqueue.c，函数名：read()                */
/*****************************************************/
 datatype read(queue qu)
 {
   if(!qu.front) {printf("\n链式队列是空的!");exit(1);}
   return(qu.front->info);
 }

/*****************************************************/
/*    函数功能：向链式队列中插入一个值为x的结点     */
/*    函数参数：指向queue类型变量的指针变量qu       */
/*              datatype类型的变量x                  */
/*    函数返回值：指向queue类型变量的指针           */
/*    文件名：lnkqueue.c，函数名：insert()               */
/*****************************************************/
 queue *insert(queue *qu,datatype x)
 {
/*向链式队列中插入一个值为x的结点*/
   node *p;
   p=(node*)malloc(sizeof(node)); /*分配空间*/
   p->info=x;                     /*设置新结点的值*/
   p->next=NULL;
   if (qu->front==NULL)       /*当前队列为空，新插入的结点为队列中惟一一个结点*/
      qu->front=qu->rear=p;
   else
      {  qu->rear->next=p;    /*队尾插入*/
    qu->rear=p;
      }
   return qu;
 }

/******************************************************/
/*    函数功能：删除链式队列中的队首结点              */
/*    函数参数：指向queue类型变量的指针变量qu        */
/*    函数返回值：指向queue类型变量的指针            */
/*    文件名：lnkqueue.c，函数名：dele()                */
/******************************************************/
 queue *dele(queue *qu)/*删除队首结点*/
 {
   node *q;
   if(!qu->front) {printf("队列为空，无法删除！");return qu;}
   q=qu->front;   /*q指向队首结点（1）*/
   qu->front=q->next; /*队首指针指向下一个结点（2）*/
   free(q);       /*释放原队首结点空间*/
   if (qu->front==NULL)  qu->rear=NULL;    /*队列中的惟一结点被删除后，队列变空（3）*/
   return qu;
 }

