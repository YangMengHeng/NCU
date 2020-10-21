#include"Admin.h"
#include<iostream>
#include"Assist.h"
#include<Windows.h>
using namespace std;

void ADMIN::SetAD()
{
	for (int i = 0; i < 11; i++)
	{
		this->Admin[i] = '\0';
	}
	for (int i = 0; i < 11; i++)
	{
		this->ADP[i] = '\0';
	}
	system("cls");
	cout << "                              ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
	cout << "                              ³õÊ¼»¯ÀÏÊ¦ÕË»§£º" << endl;
	cout << "                              ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
	cout << "                              ÉèÖÃÄãµÄÕËºÅ(×î¶à10¸ö×Ö·û):" << endl;
	Mouse(30, 4);
	cin.width(11);
	cin >> this->Admin;
	Check();
	cout << "                              ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
	cout << "                              ÉèÖÃÄãµÄÃÜÂë£¨×î¶à10¸ö×Ö·û£©£º" << endl;
	Mouse(30, 7);
	cin.width(11);
	cin >> this->ADP;
	Check();
	cout << "                              ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
	cout << "                              ³õÊ¼»¯³É¹¦£¡2Ãëºó·µ»ØÖ÷²Ëµ¥£¡" << endl;
	cout << "                              ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
	Sleep(2000);
}

bool ADMIN::CheckADPS(char * c)
{
	if (strncmp(c, this->ADPS, 9) != 0)
	{
		return false;
	}
	else
		return true;
}

ADMIN::ADMIN() :Admin("0")
{
}

ADMIN::~ADMIN()
{

}

void ADMIN::ADMenu()
{
	int op;
	int j = 0;

	system("cls");
	cout << "                              ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl << endl;
	cout << "                              ********************ÀÏÊ¦¹¦ÄÜÄ£¿é********************" << endl << endl;
	cout << "                              (1) ä¯ÀÀ¿Î³ÌÐÅÏ¢" << endl << endl;
	cout << "                              (2) ä¯ÀÀ¸öÈËÐÅÏ¢" << endl << endl;
	cout << "                              (3) ÐÞ¸Ä¿Î³ÌÐÅÏ¢" << endl << endl;
	cout << "                              (4) Ìí¼ÓÊý¾Ý" << endl << endl;
	cout << "                              (5) É¾³ýÊý¾Ý" << endl << endl;
	cout << "                              (6) ÍË³öÏµÍ³" << endl << endl;
	cout << "                              ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
	cout << "                              ÊäÈë²Ù×÷Êý(1, 2, 3, 4, 5, 6):";
	Mouse(30, 18);
	while (1)
	{
		cin.width(1);
		cin >> op;
		j++;
		Check();
		if (j > 3)
		{
			cout << "                              ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
			cout << "                              ÊäÈë²Ù×÷Êý³¬¹ýÈý´Î£¡¼ì²âµ½¶ñÒâÊ¹ÓÃ±¾ÏµÍ³£¡¼´½«ÍË³öÏµÍ³£¡" << endl;
			cout << "                              ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
			Sleep(1000);
			exit(0);
		}
		if (op == 1 || op == 2 || op == 3 || op == 4 || op == 5 || op == 6)
		{
			break;
		}
		else
		{
			system("cls");
			cout << "                              ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl << endl;
			cout << "                              ********************Ñ§Éú¹¦ÄÜÄ£¿é********************" << endl << endl;
			cout << "                              (1) ä¯ÀÀ¿Î³ÌÐÅÏ¢" << endl << endl;
			cout << "                              (2) ä¯ÀÀ¸öÈËÐÅÏ¢" << endl << endl;
			cout << "                              (3) ÐÞ¸Ä¿Î³ÌÐÅÏ¢" << endl << endl;
			cout << "                              (4) Ìí¼ÓÊý¾Ý" << endl << endl;
			cout << "                              (5) É¾³ýÊý¾Ý" << endl << endl;
			cout << "                              (6) ÍË³öÏµÍ³" << endl << endl;
			cout << "                              ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
			cout << "                              ÊäÈë²Ù×÷Êý(1, 2, 3, 4, 5, 6):";
			Mouse(30, 18);
			cin.width(1);
			cin >> op;
			j++;
			Check();
		}
	}

	switch (op)
	{
	case 1:
	{
		this->Reference(1);
		break;
	}
	case 2:
	{
		this->Reference(2);
		char op[3];
		cout << "                              ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
		cout << "                              ÊÇ·ñ¼ÌÐøÊ¹ÓÃ±¾ÏµÍ³£¿£¨ÊÇ/·ñ£©:" << endl;
		Mouse(30, 7);
		cin.width(3);
		cin >> op;
		Check();
		if (strcmp(op, "ÊÇ") == 0)
		{
			cout << "                              ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
			cout << "                              2Ãëºó·µ»ØÖ÷½çÃæ!" << endl;
			cout << "                              ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
		else if (strcmp(op, "·ñ") == 0)
		{
			cout << "                              ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
			cout << "                              2ÃëºóÍË³öÏµÍ³!" << endl;
			cout << "                              ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
			Sleep(2000);
			exit(0);
		}
		else
		{
			cout << "                              ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
			cout << "                              ÊäÈë´íÎó£¡ÍË³öÏµÍ³£¡" << endl;
			cout << "                              ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
			Sleep(1000);
			exit(0);
		}
		break;
	}
	case 3:
	{
		this->Modify();
		break;
	}
	case 4:
	{
		this->Add();
		break;
	}
	case 5:
	{
		this->Delete();
		break;
	}
	default:
	{
		cout << "                              ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
		cout << "                              2ÃëºóÍË³öÏµÍ³£¡" << endl;
		Sleep(2000);
		exit(0);
	}
	}
}
