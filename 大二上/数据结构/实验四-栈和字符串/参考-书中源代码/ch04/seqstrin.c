#define NULL 0
# define MAXSIZE 100
    typedef struct{
         char str[MAXSIZE];
         int length ; 
     } seqstring;

void strinsert(seqstring *S, int i , seqstring T)
{
  int k;
  if (i<1 || i>S->length+1 || S->length + T.length>MAXSIZE-1)
  printf("connot insert\n");
else
   {
      for(k=S->length-1;k>=i-1;k--)
        S->str[T.length+k]=S->str[k];
      for (k=0;k<T.length;k++) 
        S->str[i+k-1]=T.str[k];
      S->length= S->length + T.length;
      S->str[S->length]='\0';
    }
}
main()
{ seqstring S,T;
  int i;  
  scanf("%s",S.str);
  scanf("%s",T.str);
  S.length=strlen(S.str); 
  T.length=strlen(T.str);
  scanf("%d",&i);
  strinsert(&S,i,T);
  printf("the result1 is:");
  printf("%s",S.str);
}

