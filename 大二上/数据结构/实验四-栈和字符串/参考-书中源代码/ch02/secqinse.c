/*****************************************************/
/*  �������ܣ�ѭ�����У�˳��洢���Ĳ������         */
/*  ����������ָ��sequence_queue���ͱ�����ָ�����sq */
/*            datatype���͵ı���x                    */
/*  ��������ֵ����                                   */
/*  �ļ�����secqinse.c����������insert_sequence_cqueue()   */
/******************************************************/
void insert_sequence_cqueue(sequence_queue *sq,datatype x)
 {
   if((sq->rear+1)%MAXSIZE==sq->front)
     {printf("\n˳��ѭ�����������ģ��޷����в��������");exit(1);}
   sq->a[sq->rear]=x;
   sq->rear=(sq->rear+1)%MAXSIZE;
 }

