/*
  编写快速模式匹配KMP算法，请将相关函数补充完整。
*/
#define maxsize 100
typedef struct{
      char str[maxsize];
      int length ;
} seqstring;
/*求模式p的next[]值，请将函数补充完整*/
void getnext(seqstring p,int next[])
{
  int i = 0,j = -1;
  next[0] = -1;

  while(i < p.length)
  {
    if(j == -1  || p.str[i] == p.str[j])
    {
      ++i,++j;
      next[i] = j;
    }
    else j = next[j];
  }
}
/*快速模式匹配算法，请将函数补充完整*/
int kmp(seqstring t,seqstring p,int next[])
{
  int i = 0, j = 0;

  while(i < t.length && j < p.length)
  {
    if(j == -1 || t.str[i] == p.str[j])
    {
      i++, j++;
    }
    else j = next[j];
  }
  if(j == p.length) return (i - p.length);
  else return -1;
}
int  main()
 {   seqstring t, p;
     int next[maxsize],pos;
     printf("请输入主串：\n");
     gets(t.str);
     t.length=strlen(t.str);
     printf("请输入模式串：\n");
     gets(p.str);
     p.length=strlen(p.str);
     getnext(p,next);
     pos=kmp(t,p,next);
     printf("\n");
     printf("%d",pos);
     return 0;
}

