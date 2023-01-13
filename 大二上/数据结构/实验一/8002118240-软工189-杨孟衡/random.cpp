#include <iostream>
#include<string>
#include<fstream>
#include<map>
#include"Double_list.h"
using namespace std;

int main()
{
	Double_list dlist;

	Reverse(&dlist);
	Insert(&dlist, 99.9, 1);
	printf("\n\n");
	Display(&dlist);
	Delete(&dlist, 1);
	printf("\n\n");
	Display(&dlist);

	system("pause");
	return 0;
}
