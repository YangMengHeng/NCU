/****************************************************/
/*  �������ܣ��жϱ��ʽ�����Ƿ�ƥ��                */
/*  ����������char��������c                         */
/*  ��������ֵ��int���͡�����1Ϊƥ�䣬����0Ϊ��ƥ��*/
/*  �ļ�����seqmatch.c����������match_kouhao()        */
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
   return (empty(s));/*ջΪ����ƥ�䣬����ƥ��*/
 }

