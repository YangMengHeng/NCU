/**************************************************/
/*  函数功能：栈（顺序存储）初始化                */
/*  函数参数：指向sequence_stack型变量的指针变量st */
/*  函数返回值：空                                */
/*  文件名：seqstack.c，函数名：init()                */
/**************************************************/ 
 void init(sequence_stack *st)
 {
   st->top=0;
 }

/***************************************************/
/*  函数功能：判断栈（顺序存储）是否为空           */
/*  函数参数：sequence_stack型变量st                */
/*  函数返回值：int类型。1表示空，0表示非空       */
/*  文件名：seqstack.c，函数名：empty()              */
/***************************************************/
 int empty(sequence_stack st)
 {
   return(st.top? 0:1);
 }


/***************************************************/
/*  函数功能：读栈顶（顺序存储）结点值             */
/*  函数参数：sequence_stack型变量st                */
/*  函数返回值：datatype类型。返回栈顶结点值        */
/*  文件名：seqstack.c，函数名：read()                */
/***************************************************/
 datatype read(sequence_stack st)
 {
   if (empty(st))
     {printf("\n栈是空的!");exit(1);}
   else
     return st.a[st.top-1];
 }


/***************************************************/
/*  函数功能：栈（顺序存储）的插入（进栈）操作     */
/*  函数参数：指向sequence_stack型变量的指针变量st  */
/*            datatype型变量x                       */
/*  函数返回值：空                                 */
/*  文件名：seqstack.c，函数名：push()               */
/***************************************************/
 void push(sequence_stack *st,datatype x)
 {
   if(st->top==MAXSIZE)
     {printf("\nThe sequence stack is full!");exit(1);}
   st->a[st->top]=x;
   st->top++;
 }


/***************************************************/
/*  函数功能：栈（顺序存储）的删除（出栈）操作     */
/*  函数参数：指向sequence_stack型变量的指针变量st  */
/*  函数返回值：空                                 */
/*  文件名：seqstack.c，函数名pop()                  */
/***************************************************/
 void pop(sequence_stack *st)
 {
   if(st->top==0)
     {printf("\nThe sequence stack is empty!");exit(1);}
   st->top--;
 }

