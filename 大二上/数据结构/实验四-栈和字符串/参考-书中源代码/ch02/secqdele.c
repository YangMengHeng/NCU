/*****************************************************/
/*  �������ܣ�ѭ�����У�˳��洢����ɾ������         */
/*  ����������ָ��sequence_queue���ͱ�����ָ�����sq */
/*  ��������ֵ����                                   */
/*  �ļ���secqdele.c, ������dele_sequence_cqueue()     */
/*****************************************************/
 void dele_sequence_cqueue(sequence_queue *sq)
 {
   if(sq->front==sq->rear)
     {
       printf("\nѭ�������ǿյģ��޷�����ɾ��������");
       exit(1);
     }
   sq->front=(sq->front+1)%MAXSIZE;
 }

