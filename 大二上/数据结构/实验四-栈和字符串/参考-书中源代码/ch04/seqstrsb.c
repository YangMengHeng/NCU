#define NULL 0
# define MAXSIZE 100
    typedef struct{
         char str[MAXSIZE];
         int length ; 
     } seqstring;
seqstring *substring(seqstring S,int i, int len)
{
   int k;
   seqstring *r;
   if (i<1 || i>S.length || i+len-1>S.length) 
          {printf("error\n");
           return(NULL);}
   else
        {
             r=(seqstring*) malloc (sizeof(seqstring));
             for(k=0;k<len;k++) 
               r->str[k]= S.str[i+k-1];
               r->length=len;
               r->str[r->length]='\0';
         }
    return(r);
}
main()
{ seqstring S,*q;
  int i,len;  
  scanf("%s",S.str);
  S.length=strlen(S.str);  
  scanf("%d%d",&i,&len);
  q=substring(S,i,len);
  printf("the result is:");
  printf("%s",q->str);
}
