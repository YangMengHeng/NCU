 #include <stdio.h>
 #include <stdlib.h>

 #define MAXSIZE 200

 typedef int datatype;

 typedef struct{
   datatype a[MAXSIZE];
   int size;
 }int_list;

 void Initiate(int_list *d);
 int Empty(int_list *d);
 void Display(int_list *d);
 int Find(int_list d, datatype D);
 void Insert(int_list *d, datatype x, int position);
 void Delete(int_list *d, int position);
 int_list* Assemble(int_list *d);
 void Seperate(int_list *d);

//初始化函数，用于初始化列表
void Initiate(int_list *d)
{
	d->size = 0;
}

//顺序表尾部插入元素，比如数组增加size，尾部插入新的元素
void Input(int_list *d, int D)
{
	if(d->size == MAXSIZE)
	{
		printf("顺序表已满！");
		exit(-2);
	}
	d->size++;
	d->a[d->size - 1] = D;
}

//判断顺序表是否为空，若为空返回-1，否则返回当前顺序表的size值
int Empty(int_list *d)
{
	return (d->size == 0?-1:d->size);
}

//显示函数，用于显示列表所有元素值
void Display(int_list *d)
{
	if(!d->size)
	{
		printf("顺序表为空！");
	}
	else
	{
		for(int i = 0 ; i < d->size; i++)
		{
			printf("%d ", d->a[i]);
		}
	}
	printf("\n");
}

//查找函数，查找顺序表中的某个元素,若没有找到返回-3，若找到返回下标值
int Find(int_list d, datatype D)
{
	int i = 0;

	while(i < d.size && d.a[i] != D)i++;

	return (i < d.size?i:-1);
}

//线性表的插入操作，在顺序表的某个position插入某个元素
void Insert(int_list *d, datatype x, int position)
{
	if (d->size == MAXSIZE)
	{
		printf("\n顺序表已满！无法插入！");
		exit(-3);
	}
	if (position < 0 || position > d->size)
	{
		printf("\n指定的插入位置不存在！");
		exit(-3);
	}
	for (int i = d->size; i > position; i--)
	{
		d->a[i] = d->a[i - 1];
	}
	d->a[position] = x;
	d->size++;
}

//线性表的删除操作,在顺序表的某个position删除某个元素
void Delete(int_list *d, int position)
{
	if (d->size == 0)
	{
		printf("\n顺序表为空！无法删除！");
		exit(-4);
	}
	if (position < 0 || position > d->size)
	{
		printf("\n指定的删除位置不存在！");
		exit(-4);
	}
	for (int i = position; i < d->size - 1; i++)
	{
		d->a[i] = d->a[i + 1];
	}
	d->size--;
}

//线性表的分离操作，将参数顺序表划分为两个独立的顺序表（奇数，偶数），再合并为一个顺序表
void Seperate(int_list *d)
{
	int* temp[2];
	int i = 0;
	int j = 0;
	int k = 0;

	Initiate(d);
	printf("请输入需要分离的线性表数据（以0结束）：");
	while (1)
	{
		scanf("%d", &d->a[i]);
		if (d->a[i] == 0)
		{
			break;
		}
		i++;
		d->size++;
	}

	temp[0] = (int*)malloc(sizeof(d));
	temp[1] = (int*)malloc(sizeof(d));
	for (int i = 0; i < d->size && d->a[i] != 0; i++)
	{
		if (d->a[i] % 2 == 0)
		{
			temp[0][j] = d->a[i];
			j++;
		}
		else
		{
			temp[1][k] = d->a[i];
			k++;
		}
	}

	printf("分立前的顺序表:");
	Display(d);
	printf("分离后的顺序表1：");
	for (int i = 0; i < j; i++)
	{
		printf("%d ", temp[0][i]);
	}
	printf("\n分离后的顺序表2：");
	for (int i = 0; i < k; i++)
	{
		printf("%d ", temp[1][i]);
	}
}

/*快速排序
算法思想：将数据划分区间处理，采取分治的思想，首先根据入参数据左右边界确认中间元素的下标，
采用中间元素作为标杆元素,先从数据左边界开始比较，若找到或没有找到（与数据本身比较）用循环变量i标记下标，
再从数据右边界开始比较，若找到或没有找到（与数据本身比较）用循坏变量j标记下标。
若i < j，说明标杆元素左侧有大于等于它的元素，右侧有小于等于它的元素，所以交换i，j两者下标的元素。
若i >= j，说明标杆元素左侧已经没有大于等于它的元素了，右侧也没有小于等于它的元素，所以这时break退出循环，
退出循环后，根据i，j值，划分区间，再进行后面的排序，直到最终区间里只有一个元素，这样就排好了。
关于快速排序是升序还是降序，就看循环找标杆元素左右侧的元素的判断条件，
若是左侧找大于等于，右侧小于等于，那么是升序，反之降序
*/
void QuickSort(int_list *d, int left, int right)
{
	int temp;

	if (left < right)
	{
		int i = left - 1, j = right + 1;
		int mid = d->a[(left + right) / 2];
		while (true)
		{
			while (d->a[++i] < mid);
			while (d->a[--j] > mid);
			if (i >= j)
			{
				break;
			}
			temp = d->a[j];
			d->a[j] = d->a[i];
			d->a[i] = temp;
		}
		QuickSort(d, left, i - 1);
		QuickSort(d, j + 1, right);
	}
}

//线性表的合并操作，将参数顺序表数据中的两个数据按升序排序重新生成一个新数据,将这个新数据快速排序后，返回这个新数据的首地址
int_list* Assemble(int_list *d)
{
	int_list* temp = (int_list*)malloc(sizeof(int_list));
	int loop = d[0].size + d[1].size;

	Initiate(temp);
	if (d[0].a[d[0].size - 1] < d[1].a[0])
	{
		for (int i = 0; i < loop; i++)
		{
			if (i < d[0].size)
			{
				Input(temp, d[0].a[i]);
			}
			else Input(temp, d[1].a[i - d[0].size]);
		}
		d = temp;
		free(temp);
		return d;
	}

	if (d[1].a[d[1].size - 1] < d[0].a[0])
	{
		for (int i = 0; i < loop; i++)
		{
			if (i < d[1].size)
			{
				Input(temp, d[1].a[i]);
			}
			else Input(temp, d[0].a[i - d[1].size]);
		}
		d = temp;
		free(temp);
		return d;
	}

	for (int i = 0; i < loop; i++)
	{
		if (i < d[0].size)
		{
			Input(temp, d[0].a[i]);
		}
		else Input(temp, d[1].a[i - d[0].size]);
	}
	d = temp;
	QuickSort(d, 0, d->size - 1);

	return d;
}