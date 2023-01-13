#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 200 
typedef int datatype;

typedef struct{
   datatype a[MAXSIZE];
   int size;
}sequence_list;

void Initiate(sequence_list *li);
void Input(sequence_list *li);
int deleteAllX(sequence_list *li, datatype x);
void Inputfromfile(sequence_list *li, char * f);
void Print(sequence_list *li);
int Find(sequence_list *li, datatype x);
void Inter(sequence_list * li1, sequence_list * li2, sequence_list * li3);

//初始化顺序列表
void Initiate(sequence_list *li)
{
	li->size = 0;
}

//列表插入元素
void Input(sequence_list *li)
{
	datatype x;

	Initiate(li);
	printf("\n输入插入列表的元素（以0结束）：\n");
	scanf("%d", &x);
	while (x)
	{
		li->a[li->size++] = x;
		scanf("%d", &x);
	}
}

//从文件中读入数据,第一个入参是存放数据的容器，第二个入参是需要打开的文件名
void Inputfromfile(sequence_list *li, char * f)
{
    FILE * fp=fopen(f, "r");
	Initiate(li);

	if (fp)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d", &li->a[li->size++]);
		}
		fclose(fp);
	}
}

//打印顺序列表中的所有元素值
void Print(sequence_list *li)
{
	printf("\n");
	for (int i = 0; i < li->size; i++)
	{
		printf("%d ", li->a[i]);
		//每打印10个元素后，输出一个换行符，整理格式
		if ((i+1)%10==0) printf("\n");
	}
	printf("\n");
}

//查找顺序列表中的某个元素
int Find(sequence_list *li, datatype x)
 {
   int i = 0;

   while(i < li->size && li->a[i] != x) i++;

   return (i < li->size? i: -1);
 }

//删除顺序列表中的某个元素
int deleteAllX(sequence_list *li, datatype x)
 {
   int i = 0, j = 0;
   
   for (i=0; i < li->size; i++)
   {
	   if (li->a[i] != x)
		   li->a[j++] = li->a[i];
   }

   li->size = j;
   return 0;
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
void QuickSort(sequence_list *d, int left, int right)
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

/*折半查找（二分查找），用给定值k先与中间结点的关键字比较，中间结点把线形表分成两个子表，
若相等则查找成功；若不相等，再根据k与该中间结点关键字的比较结果确定下一步查找哪个子表，
这样循环进行，直到查找到或查找结束发现表中没有这样的结点。
*/
int BinarySearch(int a[], int value, int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] == value)
			return mid;
		if (a[mid] > value)
			high = mid - 1;
		if (a[mid] < value)
			low = mid + 1;
	}
	return -1;
}

//顺序表的交集，实现两个顺序列表(li1, li2)之间求交集，之后将交集存放在li3中
void Inter(sequence_list * li1, sequence_list * li2, sequence_list * li3)
{
	int flag = 0;

	Initiate(li3);
	//先利用快速排序将两个顺序列表升序排序
	QuickSort(li1, 0, li1->size - 1);
	QuickSort(li2, 0, li2->size - 1);

	//利用折半查找的方法，对两个顺序列表查找相同的元素,若相同则存储于li3中
	for (int i = 0; i < li1->size; i++)
	{
		flag = BinarySearch(li2->a, li1->a[i], li2->size);
		if (flag != -1)
		{
			li3->a[li3->size++] = li1->a[i];
		}
	}

	//打印求交集前的各顺序列表元素，以及求交集后的顺序列表元素
	printf("求交集之前的两个顺序列表元素:");
	Print(li1);
	Print(li2);
	printf("求交集之后的顺序列表元素:");
	Print(li3);
}

//顺序表的调整，将顺序表*li中的所有奇数调整到表的左边，所有偶数调整到表的右边
void Partion(sequence_list* li)
{
	sequence_list temp;
	int j = 199;

	Initiate(&temp);
	for (int i = 0; i < li->size; i++)
	{
		switch (li->a[i] % 2)
		{
		case 1:
		{
			temp.a[temp.size++] = li->a[i];
			break;
		}
		case 0:
		{
			temp.a[j--] = li->a[i];
			break;
		}
		default: printf("算法出错！"); exit(-1);
		}
	}

	printf("顺序表调整之前的元素:");
	Print(li);
	printf("顺序表调整之后的左侧元素:");
	Print(&temp);
	printf("顺序表调整之后的右侧元素:\n");
	for (int i = 199; i > j; i--)
	{
		printf("%d ", temp.a[i]);
		if ((i - 1) % 10 == 0) printf("\n");
	}
	printf("\n");
}