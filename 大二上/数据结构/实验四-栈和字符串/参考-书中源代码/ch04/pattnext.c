# define maxsize 100
typedef struct{
     char str[maxsize];
      int length ; 
} seqstring;
void getnext(seqstring p,int next[])
{int i,j;
 next[0]=-1;
 i=0;j=-1;
 while(i<p.length)
 {
  if(j==-1||p.str[i]==p.str[j])
  {++i;++j;next[i]=j;}
  else
   j=next[j];
  }
  for(i=0;i<p.length;i++)
  printf("%d",next[i]);
}
void main()
{seqstring p;
 int next[50];
 scanf("%s",p.str);
 p.length=strlen(p.str);
 getnext(p,next);
}