#pragma once
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 200

typedef char datatype;

typedef struct {
	datatype a[MAXSIZE];
	int top;
}char_stack;

void Initiate(char_stack* c);
bool Empty(char_stack c);
datatype returnTop(char_stack c); 
void Push(char_stack* c, datatype data);
void Pop(char_stack* c);
bool IsPlalindrome();
bool IsOp(char op);
int Priority(char op);
double readNumber(char in[], int* i);
void CalPostFix(char_stack* c);

//初始化字符栈函数，top表示下一个将要插入的节点的存储位置
void Initiate(char_stack* c)
{
	c->top = 0;
}

//根据top值判断是否为空，若top为0则为空，若不为0则不是空栈
bool Empty(char_stack c)
{
	return (c.top ? 0 : 1);
}

//取得当前栈顶值，若不为空则返回栈顶值，若为空输出错误信息，返回NULL值代表出错
datatype returnTop(char_stack c)
{
	if (Empty(c))
	{
		printf("\n这是一个空栈！读取失败！\n");
		return NULL;
	}
	return c.a[c.top - 1];
}

//进栈操作，若栈还未满则根据top值直接插入，若已满输出错误提示信息
void Push(char_stack* c, datatype data)
{
	if (c->top == MAXSIZE)
	{
		printf("\n字符栈已满！插入失败！\n");
		exit(-1);
	}
	c->a[c->top] = data;
	c->top++;
}

//出栈操作，若栈不为空则top值减一即可，若为空栈输出错误提示信息
void Pop(char_stack* c)
{
	if (c->top == 0)
	{
		printf("\n字符栈还是空的！弹出元素失败！\n");
		exit(-2);
	}
	c->top--;
}

/*判断回文函数，采用两个栈分别正序和反序插入字符串数据,首先提示输入字符串数据，
输入以后，用一个临时申请内存的字符数组存放字符串。接着按照正序先给栈1(temp[0])插入字符串数据，
再按照倒序给栈2（temp[1]）插入字符串数据。算法核心是通过循环判断两个栈是否为空，每次循环首先
判断栈顶值是否相等（字符相同值相等），若不相等则说明不是回文，返回false，若相等则弹出栈顶元素，
继续下一轮栈顶值判断，直到两个栈弹出所有元素为空栈，那么就说明这个字符串正序读和倒序读都一样，
这是一个回文字符串，返回true
*/
bool IsPlalindrome()
{
	char_stack temp[2];
	char* incs = (char*)malloc(sizeof(temp[0].a));
	int j = 0;

	Initiate(&temp[0]);
	Initiate(&temp[1]);
	if (!incs)
	{
		printf("\n存储空间不足！无法读入字符串！\n");
		exit(-3);
	}
	printf("输入字符串：\n");
	scanf("%s", incs);
	for (int i = 0; incs[i] != '\0'; i++, j++)
	{
		Push(&temp[0], incs[i]);
	}
	for (j -= 1; j >= 0; j--)
	{
		Push(&temp[1], incs[j]);
	}
	while (!Empty(temp[0]) && !Empty(temp[1]))
	{
		if (returnTop(temp[0]) == returnTop(temp[1]))
		{
			Pop(&temp[0]);
			Pop(&temp[1]);
		}
		else return false;
	}

	return true;
}

//判断当前字符是否为操作符，若是返回true，若不是返回false
bool IsOp(char op)
{
	switch (op)
	{
	case '+':
	case '-':
	case '*':
	case '/':return true;
	default:return false;
	}
}

//优先级函数，判断当前入参op的操作符优先级
int Priority(char op)
{
	switch (op)
	{
	case '#':return -1;
	case '(':return 0;
	case '+':
	case '-':return 1;
	case '*':
	case '/':return 2;
	default:return -2;
	}
}

//数值转换函数，对于一个字符数组中的数字字符，一个一个读入
double readNumber(char in[], int* i)
{
	double x = 0.0;
	int k = 0;

	while (in[*i] >= '0' && in[*i] <= '9')
	{
		x = x * 10 + (in[*i] - '0');
		(*i)++;
	}
	if (in[*i] == '.')
	{
		(*i)++;
		while (in[*i] >= '0' && in[*i] <= '9')
		{
			x = x * 10 + (in[*i] - '0');
			(*i)++;
			k++;
		}
	}
	while (k != 0)
	{
		x /= 10.0;
		k--;
	}

	return x;
}

//利用栈处理中缀表达式，最终转换为后缀表达式，计算出结果输出结果
void CalPostFix(char_stack* c)
{
	int i = 0;
	int j = 0;
	int t;
	char temp[MAXSIZE];
	char after[MAXSIZE];
	double x1, x2;
	double result[MAXSIZE];
	int top = 0;

	//输入中缀表达式
	Initiate(c);
	Push(c, '#');
	printf("请输入中缀表达式(以#结束):\n");
	do {
		scanf("%c", &temp[i]);
		i++;
	} while (temp[i - 1] != '#');
	i = 0;
	//转换中缀表达式为后缀表达式
	while (temp[i] != '#')
	{
		if ((temp[i] >= '0' && temp[i] <= '9') || temp[i] == '.')
		{
			after[j++] = temp[i];
		}
		else if (temp[i] == '(')
		{
			Push(c, temp[i]);
		}
		else if (temp[i] == ')')
		{
			t = c->top - 1;
			while (c->a[t] != '(')
			{
				after[j++] = c->a[--c->top];
				t = c->top - 1;
			}
			Pop(c);
		}
		else if (IsOp(temp[i]))
		{
			after[j++] = ' ';
			while (Priority(c->a[c->top - 1]) >= Priority(temp[i]))
			{
				after[j++] = c->a[--c->top];
			}
			Push(c, temp[i]);
		}
		i++;
	}
	while (c->top) after[j++] = c->a[--c->top];
	printf("经过转换后的后缀表达式为:");
	for (int k = 0; after[k] != '#'; k++)
	{
		printf("%c", after[k]);
	}

	//计算后缀表达式
	i = 0;
	Initiate(c);
	while (after[i] != '#')
	{
		if (after[i] >= '0' && after[i] <= '9')
		{
			result[top] = readNumber(after, &i);
			top++;
		}
		else if (after[i] == ' ') i++;
		else if (after[i] == '+')
		{
			x2 = result[--top];
			x1 = result[--top];
			result[top] = x1 + x2;
			top++;
			i++;
		}
		else if (after[i] == '-')
		{
			x2 = result[--top];
			x1 = result[--top];
			result[top] = x1 - x2;
			top++;
			i++;
		}
		else if (after[i] == '*')
		{
			x2 = result[--top];
			x1 = result[--top];
			result[top] = x1 * x2;
			top++;
			i++;
		}
		else if (after[i] == '/')
		{
			x2 = result[--top];
			x1 = result[--top];
			result[top] = x1 / x2;
			top++;
			i++;
		}
	}

	//打印后缀表达式计算值
	printf("\n经过计算后，这个中缀表达式的值为: %.3lf\n", result[0]);
}