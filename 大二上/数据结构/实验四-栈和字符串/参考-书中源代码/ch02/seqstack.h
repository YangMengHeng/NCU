/*****************************/
/*   栈（顺序存储）的头文件  */
/*       文件名seqstack.h     */
/*****************************/
 #define MAXSIZE 100
 typedef int datatype;
 typedef struct{
   datatype a[MAXSIZE];
   int top;
 }sequence_stack;

