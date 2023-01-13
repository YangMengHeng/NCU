/**************************************************/
/*  函数功能：求运算符的优先级                   */
/*  函数参数：char类型变量op                     */
/*  函数返回值：int类型。返回各中运算符的优先级。 */
/*  文件名：priority.c，函数名：priority()             */
/**************************************************/
 int priority(char op)
 {
   switch(op)
   {
     case '#':return ?1;
     case '(':return 0;
     case '+':
     case '-':return 1;
     case '*':
     case '/':return 2;
     default: return ?1;
   }
 }

