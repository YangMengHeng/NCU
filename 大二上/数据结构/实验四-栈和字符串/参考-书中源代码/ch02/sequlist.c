/**************************************************/
/*  函数功能：顺序表的初始化-置空表            */
/*  函数参数：指向sequence_list型变量的指针变量slt  */
/*  函数返回值：空                                */
/*  文件名：sequlist.c, 函数名：init()                  */
/***************************************************/
 void init(sequence_list *slt)
 {
   slt->size=0;
 }


/***************************************************/
/*  函数功能：在顺序表后部进行插入操作             */
/*  函数参数：指向sequence_list型变量的指针变量slt   */
/*            datatype类型的变量x                  */
/*  函数返回值：空                                 */
/*  文件名：seqlappe.c, 函数名：append()               */
/***************************************************/
 void append(sequence_list *slt,datatype x)
 {
   if(slt->size==MAXSIZE)
     {printf("顺序表是满的!");exit(1);}
   slt->a[slt->size]=x;
   slt->size=slt->size+1;
 }


/***************************************************/
/*  函数功能：打印顺序表的各结点值                 */
/*  函数参数：sequence_list型变量slt                 */
/*  函数返回值：空                                 */
/*  文件名：sequlist.c,  函数名：display()             */
/***************************************************/
 void display(sequence_list slt)
 {
   int i;
   if(!slt.size) printf("\n顺序表是空的!");
   else
   for(i=0;i<slt.size;i++)  printf("%5d",slt.a[i]);
 }


/***************************************************/
/*  函数功能：判断顺序表是否为空                   */
/*  函数参数：sequence_list型变量slt                 */
/*  函数返回值：int类型。1表示空，0表示非空       */
/*  文件名：sequlist.c，函数名：empty()              */
/***************************************************/
 int empty(sequence_list slt)
 {
   return(slt.size==0 ? 1:0);
 }



/****************************************************/
/*  函数功能：查找顺序表中值为x的结点位置          */
/*  函数参数：sequence_list型变量slt，datatype型变量x  */
/*  函数返回值：int类型。返回x的位置值，-1表示没找到*/
/*  文件名：sequlist.c，函数名：find()                   */
/*****************************************************/
 int find(sequence_list slt,datatype x)
 {
   int i=0;
   while(i<slt.size&&slt.a[i]!=x) i++;
   return(i<slt.size? i:-1);
 }


/*****************************************************/
/*  函数功能：取得顺序表中第i个结点的值             */
/*  函数参数：sequence_list型变量slt，int型变量i       */
/*  函数返回值：datatype类型。返回第i个结点的值      */
/*  文件名：sequlist.c，函数名：get()                    */
/*****************************************************/
 datatype get(sequence_list slt,int i)
 {
   if(i<0||i>=slt.size)
     {printf("\n指定位置的结点不存在!");exit(1);}
   else
     return slt.a[i];
 }


/*****************************************************/
/*  函数功能：在顺序表的position位置插入值为x的结点 */
/*  函数参数：指向sequence_list型变量的指针变量slt    */
/*            datatype型变量，xint型变量 position      */
/*  函数返回值：空                                   */
/*  文件名：sequlist.c，函数名：insert()                 */
/*****************************************************/
 void insert(sequence_list *slt,datatype x,int position)
 {
   int i;
   if(slt->size==MAXSIZE)
     {printf("\n顺序表是满的!没法插入!");exit(1);}
   if(position<0||position>slt->size)
   {printf("\n指定的插入位置不存在!");exit(1);}
   for(i=slt->size;i>position;i--) slt->a[i]=slt->a[i-1];
   slt->a[position]=x;
   slt->size++;
 }


/*****************************************************/
/*  函数功能：删除顺序表中第position位置的结点       */
/*  函数参数：指向sequence_list型变量的指针变量slt    */
/*            int型变量 position                       */
/*  函数返回值：空                                   */
/*  文件名：sequlist.c，函数名：dele()                  */
/*****************************************************/
 void dele(sequence_list *slt,int position)
 {
   int i;
   if(slt->size==0)
     {printf("\n顺序表是空的!");exit(1);}
   if(position<0||position>=slt->size)
     {printf("\n指定的删除位置不存在!");exit(1);}
   for(i=position;i<slt->size-1;i++) slt->a[i]=slt->a[i+1];
   slt->size--;
 }

