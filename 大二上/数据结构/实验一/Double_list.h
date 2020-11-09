 #include <stdio.h>
 #include <stdlib.h>

 #define MAXSIZE 200

 typedef double datatype;

 typedef struct{
   datatype a[MAXSIZE];
   int size;
 }Double_list;

 void Initiate(Double_list *d);
 void Reverse(Double_list *d);
 void Input(Double_list *d, double D);
 int Empty(Double_list *d);
 void Display(Double_list *d);
 int Find(Double_list d, datatype D);
 void InputFile(Double_list *d, char * f);
 void Delete(Double_list *d, int position);
 void Insert(Double_list *d, datatype x, int position);
 void OutputFile(Double_list *d, char * f);


//初始化函数，用于初始化列表
void Initiate(Double_list *d)
{
	d->size = 0;
}

//逆转置函数，用于将列表逆置，即顺序逆反
void Reverse(Double_list *d)
{
	double temp;
	int i = 0;
	int op = 0;

	Initiate(d);
	printf("选择菜单：\n");
	printf("（1）静态数据线性表;\n");
	printf("（2）文件数据线性表;\n");
	scanf("%d", &op);
	switch (op)
	{
	case 1:
	{
		printf("请输入需要逆置的线性表数据（以0结束）：");
		while (1)
		{
			scanf("%5lf", &d->a[i]);
			if (d->a[i] == 0)
			{
				break;
			}
			i++;
			d->size++;
		}

		break;
	}
	case 2:
	{
		char S[20];

		printf("输入文件名:\n");
		scanf("%s", &S);
		InputFile(d, S);

		break;
	}
	default:
	{
		printf("请根据菜单提示正确输入操作数！");
		exit(-1);
	}
	}

	for (int i = 0; i < (d->size / 2); i++)
	{
		temp = d->a[i];
		d->a[i] = d->a[d->size - i - 1];
		d->a[d->size - i - 1] = temp;
	}
	printf("\n逆转置后的顺序表：");
	Display(d);
}

//顺序表尾部插入元素，比如数组增加size，尾部插入新的元素
void Input(Double_list *d, double D)
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
int Empty(Double_list *d)
{
	return (d->size == 0?-1:d->size);
}

//显示函数，用于显示列表所有元素值
void Display(Double_list *d)
{
	if(!d->size)
	{
		printf("顺序表为空！");
	}
	else
	{
		for(int i = 0 ; i < d->size; i++)
		{
			printf("%5.2lf ", d->a[i]);
		}
	}
}

//查找函数，查找顺序表中的某个元素,若没有找到返回-3，若找到返回下标值
int Find(Double_list d, datatype D)
{
	int i = 0;

	while(i < d.size && d.a[i] != D)i++;

	return (i < d.size?i:-1);
}

//随机访问顺序表中的某个元素，如数组可以随机访问任意一个元素，返回-1表示没找到，程序异常
datatype Get(Double_list d, int i)
{
	if(i < 0 ||  i >= d.size)
	{
		printf("该位置不存在元素！非法访问其他内存！");
	}
	else
	{
		return d.a[i];
	}

	return -1; 
}

//从文件读取浮点型数据
void InputFile(Double_list *d, char * f)
{
	
    FILE * fp=fopen(f, "r");

	Initiate(d);

	if (fp)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%lf", &d->a[d->size++]);
		}
		fclose(fp);
	}
}

//数据写入文件，将线性表数据保存
void OutputFile(Double_list *d, char * f)
{
	FILE * fp = fopen(f, "w");

	if (fp)
	{
		for (int i = 0; i < d->size; i++)
		{
			fprintf(fp, "%lf", &d->a[i]);
		}
		fclose(fp);
	}
}

//线性表的插入操作，在顺序表的某个position插入某个元素
void Insert(Double_list *d, datatype x, int position)
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
void Delete(Double_list *d, int position)
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