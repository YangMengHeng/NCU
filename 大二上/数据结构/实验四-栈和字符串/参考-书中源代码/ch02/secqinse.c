/*****************************************************/
/*  函数功能：循环队列（顺序存储）的插入操作         */
/*  函数参数：指向sequence_queue类型变量的指针变量sq */
/*            datatype类型的变量x                    */
/*  函数返回值：空                                   */
/*  文件名：secqinse.c，函数名：insert_sequence_cqueue()   */
/******************************************************/
void insert_sequence_cqueue(sequence_queue *sq,datatype x)
 {
   if((sq->rear+1)%MAXSIZE==sq->front)
     {printf("\n顺序循环队列是满的！无法进行插入操作！");exit(1);}
   sq->a[sq->rear]=x;
   sq->rear=(sq->rear+1)%MAXSIZE;
 }

