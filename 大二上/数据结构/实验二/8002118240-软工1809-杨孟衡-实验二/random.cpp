#include <iostream>
#include "int_list.h"
using namespace std;

int main()
{
	/*字符栈
	bool flag;
	char_stack cs;

	flag = IsPlalindrome();
	if (!flag)
	{
		printf("此字符串不是回文字符串！\n");
	}
	else printf("此字符串是回文字符串！\n");

	CalPostFix(&cs);
	*/

	
	int_list dlist[2];
	int_list* li;

	Initiate(&dlist[0]);
	Initiate(&dlist[1]);
	Input(&dlist[0], 10);
	Input(&dlist[0], 13);
	Input(&dlist[0], 26);
	Input(&dlist[0], 31);
	Input(&dlist[0], 46);
	Input(&dlist[0], 54);
	Input(&dlist[1], 8);
	Input(&dlist[1], 17);
	Input(&dlist[1], 39);
	Input(&dlist[1], 40);
	Input(&dlist[1], 100);
	Input(&dlist[1], 200);
	
	printf("合并前的两个顺序表:");
	Display(&dlist[0]);
	Display(&dlist[1]);
	li = Assemble(dlist);
	printf("合并后的顺序表:");
	Display(li);
	Seperate(li);
	
	/*顺序表
	sequence_list li1;
	/*sequence_list li2;
	sequence_list li3;

	Input(&li1);
	Input(&li2);
	Inter(&li1, &li2, &li3);

	Input(&li1);
	Partion(&li1);*/

	system("pause");
	return 0;
}
