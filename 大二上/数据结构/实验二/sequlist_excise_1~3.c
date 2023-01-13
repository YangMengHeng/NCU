#include "sequlist_excise.h"

/********************************/
/*�������ƣ�reverse()           */
/*�������ܣ�����˳���          */
/********************************/
/*�뽫���������������������в���*/
void reverse(sequence_list *L)
{
    int i,j;
    int temp; //�������������ڽ���
    for(i=0,j=L->size-1;i<j;i++,j--) {  //��i��j����ʱѭ������
        temp=L->a[i];
        L->a[i]=L->a[j];
        L->a[j]=temp;
	}
}


/********************************/
/*�������ƣ�reverse()           */
/*�������ܣ�����˳���          */
/********************************/
/*�뽫���������������������в���*/
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
/*�������ƣ�sprit()             */
/*�������ܣ��ָ�˳���������L2,oushu fang L3*/
/********************************/
/*�뽫���������������������в���*/
void sprit(sequence_list *L1, sequence_list *L2, sequence_list *L3 )
{
	int i;
    
	initseqlist(L2);
	initseqlist(L3);

    for(i=0;i<L1->size;i++) 
	{  
        if (L1->a[i]%2==0)  //ż��
			L2->a[L2->size++]=L1->a[i];
		else
			L3->a[L3->size++]=L1->a[i];	
        
	}
}


/********************************/
/*�������ƣ�merge()             */
/*�������ܣ��ϲ�˳���          */
/********************************/
/*�뽫���������������������в���*/
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

	sequence_list L, L2, L3;                       /*����˳���*/
	//input(&L);                             /*�����������*/
	//printf("ԭʼ˳���\n");
	//print(&L);                             /*��ӡ��������*/
	//reverse2(&L);                           /*˳�����*/
	//printf("���ú�˳���\n");
	//print(&L);                             /*����±�*/

	//deleteAllX(&L, 15);                 	 /*ɾ��*/
	//printf("ɾ����˳���\n");
	//print(&L);                             /*����±�*/
	
	//sprit(&L, &L2, &L3);                   /*˳������*/
	//printf("�����˳���\n");
	//print(&L2);                             /*����±�*/
    //print(&L3);                             /*����±�*/
	//printf("�ں�ǰ��������˳���\n");
	//input(&L);                              /*�����������*/
    //input(&L2);                              /*�����������*/
	
	//merge(&L, &L2, &L3 );
	//printf("�ںϺ�˳���\n");
	//print(&L3);                             /*����±�*/

	char f[50]="AB34.251";
	float x;
	//input(&L);                             /*�����������*/
	int  i =2;
	x = readnumber(f, &i);
	printf("ȡ�����ݣ�\n");
	printf("%8.3f", x);


	return 0;
}
