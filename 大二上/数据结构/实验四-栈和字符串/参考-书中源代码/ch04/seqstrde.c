#define NULL 0
# define MAXSIZE 100
    typedef struct{
         char str[MAXSIZE];
         int length ; 
     } seqstring;
void strdelete(seqstring *S,int i,int len)
{
    int k;
    if (i<1 || i>S->length||i+len-1>S->length) printf(" cannot delete\n");
    else
      {
         for(k=i+len-1; k<S->length;k++) S->str[k-len]= S->str[k];
         S->length=S->length-len;
         S->str[S->length]='\0';
      }
}
main()
{ seqstring S;
  int i,len;  
  scanf("%s",S.str);
  S.length=strlen(S.str); 
  scanf("%d%d",&i,&len);
  strdelete(&S,i,len);
  printf("the result is:");
  printf("%s",S.str);
}