/**************************************************************/
/*  函数功能：将一个中缀表达式e转换为与它等价的后缀表达式f   */
/*  函数参数：char类型数组变量e和f                           */
/*  函数返回值：空                                            */
/*  文件名：postfix.c，函数名：postfix()                          */
/****************************************************** ********/
void postfix(char e[],char f[])
 { int i=0,j=0;
   char opst[100];
   int top,t;
   top=0;
   opst[top]='#';top++;
   while(e[i]!='#')
   {
     if ((e[i]>='0'&&e[i]<='9')||e[i]=='.')
       f[j++]=e[i];                  /*遇到数字和小数点直接写入后缀表达式*/
     else if (e[i]=='(')                /*遇到左括号进入操作符栈*/
           { opst[top]=e[i];top++;}
          else if (e[i]==')')
            /*遇到右括号将其对应的左括号后的操作符全部写入后缀表达式*/
            { 
              t=top-1;
              while (opst[t]!='(') {f[j++]=opst[--top];t=top-1;}
              top--;            /*'('出栈*/
            }
            else if (is_operation(e[i]))         /* '+ ,-, *, /' */
                  {
                    f[j++]=' ';           /*用空格分开两个操作数*/
                    while (priority(opst[top-1])>=priority(e[i]))
                    f[j++]=opst[--top];
                    opst[top]=e[i];top++;     /*当前元素进栈*/
                  }
       i++;  /*处理下一个元素*/
    }
    while (top) f[j++]=opst[--top];
  }

