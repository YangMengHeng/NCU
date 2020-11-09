# define maxsize 100
typedef struct{
     char str[maxsize];
     int length ; 
} seqstring;
int index(seqstring p, seqstring t) 
{
   int i,j, succ;
   i=0; succ=0;
   while((i<=t.length-p.length) && (!succ))
       { j=0 ; succ=1;
         while ((j<=p.length-1) && succ)
           if (p.str[j]==t.str[i+j] )  j++;
           else succ=0;
         ++i;
        }
   if (succ) return (i-1);
   else return (-1);
}
void main()
{seqstring t, p;
 int pos;
 scanf("%s",t.str);
 t.length=strlen(t.str);
 scanf("%s",p.str);
 p.length=strlen(p.str);
 pos=index(p,t);
 printf("\n");
 if (pos==-1) printf("no found");
 else 
   printf("the position is %d",pos+1);
}
