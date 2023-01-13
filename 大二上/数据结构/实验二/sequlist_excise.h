 #include <stdio.h>
 #include <stdlib.h>

 #define MAXSIZE 200
 typedef int datatype;

 typedef struct{
   datatype a[MAXSIZE];
   int size;
 }sequence_list;

//初始化顺序列表
void Initiate(sequence_list *L)
{
	L->size =0;
}

/********************************/
/*�������ƣ�input()             */
/*�������ܣ�����˳���          */
/********************************/
void input(sequence_list *L)
{
	datatype x;
	initseqlist(L);
	printf("������һ�����ݣ���0��Ϊ������\n");
	scanf("%d", &x);
	while (x)
	{
		L->a[L->size++]=x;
		scanf("%d", &x);
	}
}

/********************************/
/*�������ƣ�inputfromfile()     */
/*�������ܣ����ļ�����˳���    */
/********************************/
void inputfromfile(sequence_list *L, char * f)
{
	
    FILE * fp=fopen(f, "r");
	L->size=0;

	if (fp)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d", &L->a[L->size++]);
		}
		fclose(fp);
	}
}

/********************************/
/*�������ƣ�prinf()             */
/*�������ܣ����˳���          */
/********************************/
void print(sequence_list *L)
{
	int i;
	for (i=0; i<L->size; i++)
	{
		printf("%d ", L->a[i]);
		//printf("\n");
		if ((i+1)%10==0) printf("\n");
	}
	printf("\n");
}

/*****************************************************/
/*  ��������:����˳�����ֵΪx�Ľ��λ��               */
/*  ��������:sequence_list�ͱ���slt,datatype�ͱ���x	     */
/*  ��������ֵ:int���͡�����x��λ��ֵ,-1��ʾû�ҵ�	     */
/*  �ļ���:sequlist.c,������:find()                   */
/*****************************************************/
 int Find(sequence_list *L,datatype x)
 {
   int i=0;
   while(i<L->size && L->a[i]!=x ) i++;
   return(i<L->size?i:-1);
 }



/******************************************************/
/*  ��������:ɾ��˳�����ֵΪx�Ľ��λ��              */
/*  ��������:sequence_list�ͱ���slt, datatype�ͱ���x  */
/*  ��������ֵ: int���͡�0��ʾ��ɣ�-1��ʾû�����    */
/*  �ļ���:sequlist.c,������:deleteAllX()                   */
/******************************************************/
 int deleteAllX(sequence_list *L, datatype x)
 {
   int i=0, j =0;
   
   /*
   while(i<L->size  ) 
   {
	   if (L->a[i]!=x)
			L->a[j++]=L->a[i++];
	   else
			i++;
   }
   */
   
   for (i=0; i<L->size; i++)
   {
	   if (L->a[i]!=x)
		   L->a[j++] = L->a[i];
   }

   L->size = j;
   return 0;
 }

float readnumber(char f[],int *i)
{
	float x=0.0;
	int k=0;
   
	while(f[*i]>='0'&&f[*i]<='9') 
	{
		x=x*10+(f[*i]-'0');     
		(*i)++;   
	}
    if (f[*i]=='.')    
	{
		(*i)++;
		while(f[*i]>='0'&& f[*i]<='9')  
		{
			x=x*10+(f[*i]-'0'); 
			(*i)++;    
			k++;    
		}  
	}  
	while (k!=0)    
	{ 
		x=x/10.0; 
		k=k-1; 
	}  
	printf("\n*%f*",x);  
	return(x);
}
