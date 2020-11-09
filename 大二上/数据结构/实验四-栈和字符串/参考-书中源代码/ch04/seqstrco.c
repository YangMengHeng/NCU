#define NULL 0
# define MAXSIZE 100
    typedef struct{
         char str[MAXSIZE];
         int length ; 
     } seqstring;
seqstring * strconcat(seqstring S1,seqstring S2)
    {
      int i;
      seqstring *r;
      if(S1.length+S2.length>MAXSIZE-1) {printf("cannot concate");
                                       return(NULL);}
      else
        {
           r=(seqstring*)malloc (sizeof(seqstring));           
           for (i=0; i<S1.length;i++) r->str[i]= S1.str[i];
           for (i=0; i<S2.length;i++) r->str[ S1.length+i]= S2.str[i];
           r->length= S1.length+ S2.length;
           r->str[r->length]='\0';
        }
      return (r);
}
main()
{ seqstring S,T,*p;
  scanf("%s",S.str);
  scanf("%s",T.str);
  S.length=strlen(S.str); 
  T.length=strlen(T.str); 
  p=strconcat(S,T);
  printf("the result is:");
  printf("%s",p->str);
}
