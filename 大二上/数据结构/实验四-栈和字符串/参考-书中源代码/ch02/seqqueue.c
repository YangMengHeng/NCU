/*******************************************************/
/*  函数功能：队列（顺序存储）初始化                   */
/*  函数参数：指向sequence_queue类型变量的指针变量sq  */
/*  函数返回值：空                                     */
/*  文件名：seqqueue.c，函数名：init()                     */
/*******************************************************/
 void init(sequence_queue *sq)
 {
   sq->front=sq->rear=0;
 }


/***************************************************/
/*  函数功能：判断队列（顺序存储）是否为空         */
/*  函数参数：sequence_queue类型变量sq             */
/*  函数返回值：int类型。返回1表示空，0表示非空   */
/*  文件名：seqqueue.c，函数名：empty()              */
/***************************************************/
int empty(sequence_queue sq)
 {
   return (sq.front==sq.rear? 1:0);
 }


/***************************************************/
/*  函数功能：打印队列（顺序存储）的结点值         */
/*  函数参数：sequence_queue类型变量sq             */
/*  函数返回值：空                                 */
/*  文件名：seqqueue.c，函数名：display()              */
/***************************************************/
void display(sequence_queue sq)
 {
   int i;
   if(empty(sq))
   {
     printf("\n顺序队列是空的!");
   }
   else
   for(i=sq.front;i<sq.rear;i++)  printf("%5d",sq.a[i]);
 }


/***************************************************/
/*  函数功能：取得队列（顺序存储）的队首结点值     */
/*  函数参数：sequence_queue类型变量sq             */
/*  函数返回值：datatype类型。返回队首结点值        */
/*  文件名：seqqueue.c，函数名：get()                 */
/***************************************************/
datatype get(sequence_queue sq)
 {
   if(empty(sq))
   {
     printf("\n顺序队列是空的！无法获得队首结点值！");
     exit(1);
   }
   return sq.a[sq.front];
 }


/*****************************************************/
/*  函数功能：队列（顺序存储）的插入（进队）操作     */
/*  函数参数：指向sequence_queue类型变量的指针变量sq */
/*            datatype类型的变量x                    */
/*  函数返回值：空                                   */
/*  文件名：seqqueue.c，函数名：insert()                 */
/*****************************************************/
void insert(sequence_queue *sq,datatype x)
 {
   int i;
   if(sq->rear==MAXSIZE)
     {printf("\n顺序队列是满的!");exit(1);}
   sq->a[sq->rear]=x;
   sq->rear=sq->rear+1;
 }



/*****************************************************/
/*  函数功能：队列（顺序存储）的删除（出队）操作     */
/*  函数参数：指向sequence_queue类型变量的指针变量sq */
/*  函数返回值：空                                   */
/*  文件名：seqqueue.c，函数名：dele()                 */
/******************************************************/
 void dele(sequence_queue *sq)
 {
   if(sq->front==sq->rear)
     {
       printf("\n顺序队列是空的！不能做删除操作！");
       exit(1);
     }
   sq->front++;
 }




