/****************************************************/
/*  函数功能：求一个后缀表达式的值                  */
/*  函数参数：char类型数组f                         */
/*  函数返回值：double类型。返回后缀表达式的值      */
/*  文件名：evalpost.c，函数名：evalpost()              */
/****************************************************/
double evalpost(char f[])
 { double obst[100]; /*操作数栈*/
   int top=0;
   int i=0;
   double x1,x2;
   while (f[i]!='#')
       { if (f[i]>='0' && f[i]<='9')
       { obst[top]=readnumber(f,&i);top++;}
        else if (f[i]==' ')  i++;
          else if (f[i]=='+')
            { x2=obst[--top];
              x1=obst[--top];
              obst[top]=x1+x2;top++;
              i++;
                    }
              else if (f[i]=='-')
            {
              x2=obst[--top];
              x1=obst[--top];
              obst[top]=x1-x2;top++;
                      i++;
                    }
              else if (f[i]=='*')
            { x2=obst[--top];
              x1=obst[--top];
              obst[top]=x1*x2;top++;
              i++;
                    }
              else if (f[i]=='/')
            { x2=obst[--top];
              x1=obst[--top];
              obst[top]=x1/x2;top++;
              i++;
                    }
          }
    return obst[0];
  }

