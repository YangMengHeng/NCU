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
	cout << "                              ！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl;
	cout << "                              兜兵晒析弗嬲薩��" << endl;
	cout << "                              ！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl;
	cout << "                              譜崔低議嬲催(恷謹10倖忖憲):" << endl;
	Mouse(30, 4);
	cin.width(11);
	cin >> this->Admin;
	Check();
	cout << "                              ！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl;
	cout << "                              譜崔低議畜鷹��恷謹10倖忖憲����" << endl;
	Mouse(30, 7);
	cin.width(11);
	cin >> this->ADP;
	Check();
	cout << "                              ！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl;
	cout << "                              兜兵晒撹孔��2昼朔卦指麼暇汽��" << endl;
	cout << "                              ！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl;
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
	cout << "                              ！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl << endl;
	cout << "                              ********************析弗孔嬬庁翠********************" << endl << endl;
	cout << "                              (1) 箝誓仁殻佚連" << endl << endl;
	cout << "                              (2) 箝誓倖繁佚連" << endl << endl;
	cout << "                              (3) 俐個仁殻佚連" << endl << endl;
	cout << "                              (4) 耶紗方象" << endl << endl;
	cout << "                              (5) 評茅方象" << endl << endl;
	cout << "                              (6) 曜竃狼由" << endl << endl;
	cout << "                              ！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl;
	cout << "                              補秘荷恬方(1, 2, 3, 4, 5, 6):";
	Mouse(30, 18);
	while (1)
	{
		cin.width(1);
		cin >> op;
		j++;
		Check();
		if (j > 3)
		{
			cout << "                              ！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl;
			cout << "                              補秘荷恬方階狛眉肝�ー豌盖酋駲睚荒単章詰械ー棺�曜竃狼由��" << endl;
			cout << "                              ！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl;
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
			cout << "                              ！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl << endl;
			cout << "                              ********************僥伏孔嬬庁翠********************" << endl << endl;
			cout << "                              (1) 箝誓仁殻佚連" << endl << endl;
			cout << "                              (2) 箝誓倖繁佚連" << endl << endl;
			cout << "                              (3) 俐個仁殻佚連" << endl << endl;
			cout << "                              (4) 耶紗方象" << endl << endl;
			cout << "                              (5) 評茅方象" << endl << endl;
			cout << "                              (6) 曜竃狼由" << endl << endl;
			cout << "                              ！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl;
			cout << "                              補秘荷恬方(1, 2, 3, 4, 5, 6):";
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
		cout << "                              ！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl;
		cout << "                              頁倦写偬聞喘云狼由�殖�頁/倦��:" << endl;
		Mouse(30, 7);
		cin.width(3);
		cin >> op;
		Check();
		if (strcmp(op, "頁") == 0)
		{
			cout << "                              ！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl;
			cout << "                              2昼朔卦指麼順中!" << endl;
			cout << "                              ！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
		else if (strcmp(op, "倦") == 0)
		{
			cout << "                              ！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl;
			cout << "                              2昼朔曜竃狼由!" << endl;
			cout << "                              ！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl;
			Sleep(2000);
			exit(0);
		}
		else
		{
			cout << "                              ！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl;
			cout << "                              補秘危列�〕乏�狼由��" << endl;
			cout << "                              ！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl;
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
		cout << "                              ！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl;
		cout << "                              2昼朔曜竃狼由��" << endl;
		Sleep(2000);
		exit(0);
	}
	}
}
