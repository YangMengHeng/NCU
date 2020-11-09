#include "sequlist_excise.h"

/********************************/
/*函数名称：reverse()           */
/*函数功能：倒置顺序表          */
/********************************/
/*请将本函数补充完整，并进行测试*/
void reverse(sequence_list *L)
{
    int i,j;
    int temp; //辅助变量，用于交换
    for(i=0,j=L->size-1;i<j;i++,j--) {  //当i与j相遇时循环结束
        temp=L->a[i];
        L->a[i]=L->a[j];
        L->a[j]=temp;
	}
}


/********************************/
/*函数名称：reverse()           */
/*函数功能：倒置顺序表          */
/********************************/
/*请将本函数补充完整，并进行测试*/
void reverse2(sequence_list * L)
{
	int i, j;
	int temp;
	for (i =0, j=L->size-1; i<j; i++, j--)
	{
		temp = L->a[i];
		L->a[i] = L->a[j];
        L->a[j] = temp;   
	}
	
}

/********************************/
/*函数名称：sprit()             */
/*函数功能：分割顺序表，奇数放L2,oushu fang L3*/
/********************************/
/*请将本函数补充完整，并进行测试*/
void sprit(sequence_list *L1, sequence_list *L2, sequence_list *L3 )
{
	int i;
    
	initseqlist(L2);
	initseqlist(L3);

    for(i=0;i<L1->size;i++) 
	{  
        if (L1->a[i]%2==0)  //偶数
			L2->a[L2->size++]=L1->a[i];
		else
			L3->a[L3->size++]=L1->a[i];	
        
	}
}


/********************************/
/*函数名称：merge()             */
/*函数功能：合并顺序表          */
/********************************/
/*请将本函数补充完整，并进行测试*/
void merge(sequence_list *L1, sequence_list *L2, sequence_list *L3 )
{

	int i,j;
	
	i=0;
	j=0;
	
	initseqlist(L3);

	while(!(i==L1->size && j==L2->size))
	{
		if (i<L1->size&&j<L2->size)
		{
			if(L1->a[i]<=L2->a[j])
			{
				L3->a[L3->size++] = L1->a[i];
				i++;
			}
			else
			{
				L3->a[L3->size++] = L2->a[j];
				j++;
			}
		}
		if (i==L1->size)
			for (;j<L2->size;j++)
				L3->a[L3->size++] = L2->a[j];
    	if (j==L2->size)
			for (;i<L1->size;i++)
				L3->a[L3->size++] = L1->a[i];

	}
}


int main()
{

	sequence_list L, L2, L3;                       /*定义顺序表*/
	//input(&L);                             /*输入测试用例*/
	//printf("原始顺序表\n");
	//print(&L);                             /*打印测试用例*/
	//reverse2(&L);                           /*顺序表倒置*/
	//printf("倒置后顺序表\n");
	//print(&L);                             /*输出新表*/

	//deleteAllX(&L, 15);                 	 /*删除*/
	//printf("删除后顺序表\n");
	//print(&L);                             /*输出新表*/
	
	//sprit(&L, &L2, &L3);                   /*顺序表分离*/
	//printf("分离后顺序表\n");
	//print(&L2);                             /*输出新表*/
    //print(&L3);                             /*输出新表*/
	//printf("融合前输入两个顺序表\n");
	//input(&L);                              /*输入测试用例*/
    //input(&L2);                              /*输入测试用例*/
	
	//merge(&L, &L2, &L3 );
	//printf("融合后顺序表\n");
	//print(&L3);                             /*输出新表*/

	char f[50]="AB34.251";
	float x;
	//input(&L);                             /*输入测试用例*/
	int  i =2;
	x = readnumber(f, &i);
	printf("取得数据：\n");
	printf("%8.3f", x);


	return 0;
}
