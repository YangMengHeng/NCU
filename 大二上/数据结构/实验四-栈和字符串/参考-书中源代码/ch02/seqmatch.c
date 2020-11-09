/****************************************************/
/*  函数功能：判断表达式括号是否匹配                */
/*  函数参数：char类型数组c                         */
/*  函数返回值：int类型。返回1为匹配，返回0为不匹配*/
/*  文件名：seqmatch.c，函数名：match_kouhao()        */
/*****************************************************/
int match_kuohao(char c[])
 {
   int i=0;
   sequence_stack s;
   init(&s);
   while(c[i]!='#')
   {
     switch(c[i])
     {
       case '{':
       case '[':
       case '(':push(&s,c[i]);break;
       case '}':if(!empty(s)&&read(s)=='{'  )
              {pop(&s);break;}
             else return 0;
       case ']':if(!empty(s)&&read(s)=='['  )
              {pop(&s);break;}
             else return 0;
       case ')':if(!empty(s)&&read(s)=='('  )
                  {pop(&s);break;}
             else return 0;
     }
     i++;
   }
   return (empty(s));/*栈为空则匹配，否则不匹配*/
 }

