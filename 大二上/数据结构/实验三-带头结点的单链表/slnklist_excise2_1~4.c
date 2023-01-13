#include <stdlib.h>
#include <stdio.h>
#include "slnklist1.h"


/******************************************************/
/*  �������ܣ��ڲ���ͷ���ĵ�������ɾ��һ��ֵΪx�Ľ�� */
/*  ����������ָ��node���ͱ�����ָ��head               */
/*            datatype���ͱ���x                       */
/*  ��������ֵ��ָ��node���ͱ�����ָ��                 */
/*  �ļ�����slnklist_excise_1~4.c����������delex()    */
/*****************************************************/
linklist delx(linklist head,datatype x)
{
   linklist pre=NULL, p; /*����preָ��ͷ���*/
   p=head;               /*��ӵ�һ����㿪ʼ��ֵΪx�Ľ��*/
   while(p&&p->info!=x)  /*û�в����겢�һ�û���ҵ�*/
   {pre=p;p=p->next;}    /*�������ң�preָ��p��ǰ��*/
   if (p) 
	{  
		if  (!pre)  head=head->next;  /*Ҫɾ�����ǵ�һ�����*/
        	else  pre->next=p->next;
	        free(p);
	}
   return head;
}




/******************************************************/
/*  �������ܣ����ò���ͷ���ĵ�����                    */
/*  ����������ָ��node���ͱ�����ָ��head                */
/*  ��������ֵ��ָ��node���ͱ�����ָ��                  */
/*  �ļ�����slnklist_excise_1~4.c����������reverse1()     */
/*****************************************************/

linklist reverse1(linklist head)
{
	linklist ph;
	if( !head || !(head->next) )
		return head;
	ph = reverse1( head->next );//�ݹ�
	head->next->next = head;
	head->next = NULL;
	return ph;

}


/******************************************************/
/*  �������ܣ����ò���ͷ���ĵ�����                  */
/*  ����������linklist * head                         */
/*  ��������ֵ��void                                  */
/*  �ļ�����slnklist_excise_1~4.c����������reverse2() */
/******************************************************/
void reverse2(linklist * head)
{
	linklist h_1,h_2;

	if(!*head||!((*head)->next)) return ;

	h_1=NULL;
	h_2=*head;
	while( *head )
	{
		h_2 = (*head)->next;   
		(*head)->next = h_1;  //ָ��ָ��ԭ����ǰ�������Ǻ���
		h_1 = *head;          //hָ��ǰ��Ľ��
		*head = h_2;          //ͷָ���ƶ�
	}
	*head = h_1;

}

/******************************************************/
/*  �������ܣ����ò���ͷ���ĵ�����                    */
/*  ����������ָ��node���ͱ�����ָ��head                */
/*  ��������ֵ��ָ��node���ͱ�����ָ��                  */
/*  �ļ�����slnklist_excise_1~4.c����������reverse3()   */
/******************************************************/
linklist reverse3(linklist head)
{
	linklist h_1,h_2;

	if(!head||!(head->next)) return head;

	h_1=NULL;
	h_2=head;
	while( head )
	{
		h_2 = head->next;   
		head->next = h_1;    //ָ��ָ��ԭ����ǰ�������Ǻ���
		h_1 = head;          //hָ��ǰ��Ľ��
		head = h_2;          //ͷָ���ƶ�
	}
	return h_1;
}

/******************************************************/
/*  �������ܣ����������ݲ���                           */
/*  ����������ָ��node���ͱ�����ָ��head                */
/*            datatype���ͱ���x                       */
/*  ��������ֵ��ָ��node���ͱ�����ָ��                  */
/*  �ļ�����slnklist_excise_1~4.c����������insert()   */
/******************************************************/
linklist insert(linklist head, datatype x)
{
	linklist s, p, q;
	if (!head)
	{
		printf("����������\n");
		return head;
	}

	s=(linklist )malloc(sizeof(node)); //Ϊs�������ռ�
 	s->info=x;                              //���s��������x
 	q=head;                                 //q��ʼֵΪ��һ�����
	p=q->next;                              //p��ʼֵΪ�ڶ����ڵ�(q����һ�����)

    if (q->info>=s->info)//��������ֵ����Сֵ��Ҳ���ǵ�һ��ֵ��С�����������ǰ��
	{
	  s->next=q;         //s����һ�����q,��s���ڵ�һλ
	  head = s;
	  return head;
	}
	

	while(p)
	{
		if(x>=q->info&&x<p->info) //��x��������ʱ��ֹѭ���������ǣ�xС�ں�һ���ڵ����ǰһ����㣩
		{
		   q->next=s;     //��q��P�в�����
		   s->next=p;     //
		   break;
		}
		q=p;
		p=p->next;
		
	}

	if(!p && s->info>=q->info)//��������ֵ�����ֵ��Ҳ�����һ��ֵ����������������
	{
	  q->next=s;
	  s->next=NULL;
	}

	return head;
}

/******************************************************/
/*  �������ܣ�����������ɾ��                            */
/*  ����������ָ��node���ͱ�����ָ��head                */
/*            datatype���ͱ���x                        */
/*  ��������ֵ��ָ��node���ͱ�����ָ��                  */
/*  �ļ�����slnklist_excise_1~4.c����������delallx()   */
/******************************************************/
linklist delallx(linklist head, datatype x)
{
   linklist pre=NULL, p;
   if(!head) {printf("�������ǿյģ�");return head;}

   p=head;
   while (p)
   {
	if (p->info==x)    //�ҵ�
		if (!pre)  //��һ����� 
		{
			head=p->next;
			free(p);
			p=head;
		}
		else
		{
			pre->next = p->next;
			free(p);
			p=pre->next;	
		}
	else    //û�ҵ�
	{
		pre=p;
		p=p->next;

	}
   }
   
   return head;

}


int main()
{
	datatype x;
	linklist head;
	/*--------ʵ��2.1 ɾ��
	head=creatbyqueue();    //β�巨����������
	print(head);		
	printf("������Ҫɾ����ֵ��");
	scanf("%d", &x);
	head = delx(head,x);
	print(head);
	delList(head);
	*/

	/*--------ʵ��2.2 ����
	head=creatbystack();    //ͷ�巨����������
	print(head);			
	head = reverse1(head);
	print(head);
	head=reverse3(head);
	print(head);
	printf("reverse2\n");
	reverse2(&head);
	print(head);
	*/
	
	/*--------ʵ��2.3 ���������
	printf("������һ���������е�����\n");
	head=creatbyqueue();    //ͷ�巨����������
	print(head);			
	printf("����������������\n");
	scanf("%d", &x);
	head = insert(head, x);
	print(head);
	*/

	/*--------ʵ��2.4 ɾ������x*/
	head=creatbyqueue();    //ͷ�巨����������
	print(head);			
	printf("�������ɾ��������\n");
	scanf("%d", &x);
	head = delallx(head, x);
	print(head);
	//*/

	delList(head);	

	return 0;
}
