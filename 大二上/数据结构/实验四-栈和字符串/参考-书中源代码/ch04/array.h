typedef int datatype;  /*假设数组元素的值为整型*/
typedef  struct {
      datatype *base;  /* 数组存储区的首地址指针*/
      int   index[3];  /* 存放三维数组各维的长度*/
      int   c[3]      /* 存放三维数组各维的ci值*/
} array；
