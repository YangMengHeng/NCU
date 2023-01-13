/*****************************************************/
/*  函数功能：循环队列（顺序存储）的删除操作         */
/*  函数参数：指向sequence_queue类型变量的指针变量sq */
/*  函数返回值：空                                   */
/*  文件名secqdele.c, 函数名dele_sequence_cqueue()     */
/*****************************************************/
 void dele_sequence_cqueue(sequence_queue *sq)
 {
   if(sq->front==sq->rear)
     {
       printf("\n循环队列是空的！无法进行删除操作！");
       exit(1);
     }
   sq->front=(sq->front+1)%MAXSIZE;
 }

