#include"Course.h"
#include<iostream>
#include<string>
using namespace std;

Create::Create() :ExHour("0") {}

Literate::Literate() : ExHour("0") {}

Engineering::Engineering() : PrHour("0") {}

void Create::SetC()
{
	system("cls");
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ��ʼ��������γ�:" << endl;
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ̱�ţ����10���ַ�����" << endl;
	Mouse(30, 4);
	cin.width(11);
	cin >> this->CNumber;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ���(���10���ַ�)��" << endl;
	Mouse(30, 7);
	cin.width(11);
	cin >> this->CName;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ����ʣ����10���ַ��� ���´�ҵ�࣬��ѧ�Ŀ��࣬����ѧ�ࣩ��" << endl;
	Mouse(30, 10);
	cin.width(11);
	cin >> this->CKind;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ̴�٣����20���ַ���" << endl;
	Mouse(30, 13);
	cin.width(21);
	cin >> this->CHeadline;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ�ѧʱ�����֣�:" << endl;
	Mouse(30, 16);
	cin.width(2);
	cin >> this->ClassHour;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ̿���ѧ�ڣ����10���ַ���:" << endl;
	Mouse(30, 19);
	cin.width(11);
	cin >> this->Opentime;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ�ѧ�֣����֣�:" << endl;
	Mouse(30, 22);
	cin.width(2);
	cin >> this->ClassScore;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ��������ޣ����֣�:" << endl;
	Mouse(30, 25);
	cin.width(2);
	cin >> this->Max;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ����ʵ��ѧʱ�����9���ַ�����" << endl;
	Mouse(30, 28);
	cin.width(10);
	cin >> this->ExHour;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              �����ϻ�ѧʱ�����9���ַ���:" << endl;
	Mouse(30, 31);
	cin.width(10);
	cin >> this->PrHour;
	Check();
	this->Person = 0;
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ��ʼ���ɹ���" << endl;
	cout << "                              ����������������������������������������������������" << endl;
}

void Literate::SetL()
{
	system("cls");
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ��ʼ���Ŀ���γ�:" << endl;
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ̱�ţ����10���ַ�����" << endl;
	Mouse(30, 4);
	cin.width(11);
	cin >> this->CNumber;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ���(���10���ַ�)��" << endl;
	Mouse(30, 7);
	cin.width(11);
	cin >> this->CName;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ����ʣ����10���ַ��� ���´�ҵ�࣬��ѧ�Ŀ��࣬����ѧ�ࣩ��" << endl;
	Mouse(30, 10);
	cin.width(11);
	cin >> this->CKind;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ̴�٣����20���ַ���" << endl;
	Mouse(30, 13);
	cin.width(21);
	cin >> this->CHeadline;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ�ѧʱ�����֣�:" << endl;
	Mouse(30, 16);
	cin.width(2);
	cin >> this->ClassHour;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ̿���ѧ�ڣ����10���ַ���:" << endl;
	Mouse(30, 19);
	cin.width(11);
	cin >> this->Opentime;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ�ѧ�֣����֣�:" << endl;
	Mouse(30, 22);
	cin.width(2);
	cin >> this->ClassScore;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ��������ޣ����֣�:" << endl;
	Mouse(30, 25);
	cin.width(2);
	cin >> this->Max;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ����ʵ��ѧʱ�����9���ַ�����" << endl;
	Mouse(30, 28);
	cin.width(10);
	cin >> this->ExHour;
	Check();
	this->Person = 0;
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ��ʼ���ɹ���" << endl;
	cout << "                              ����������������������������������������������������" << endl;
}

void Engineering::SetE()
{
	system("cls");
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ��ʼ���Ŀ���γ�:" << endl;
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ̱�ţ����10���ַ�����" << endl;
	Mouse(30, 4);
	cin.width(1);
	cin >> this->CNumber;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ���(���10���ַ�)��" << endl;
	Mouse(30, 7);
	cin.width(11);
	cin >> this->CName;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ����ʣ����10���ַ��� ���´�ҵ�࣬��ѧ�Ŀ��࣬����ѧ�ࣩ��" << endl;
	Mouse(30, 10);
	cin.width(11);
	cin >> this->CKind;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ̴�٣����20���ַ���" << endl;
	Mouse(30, 13);
	cin.width(21);
	cin >> this->CHeadline;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ�ѧʱ�����֣�:" << endl;
	Mouse(30, 16);
	cin.width(2);
	cin >> this->ClassHour;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ̿���ѧ�ڣ����10���ַ���:" << endl;
	Mouse(30, 19);
	cin.width(11);
	cin >> this->Opentime;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ�ѧ�֣����֣�:" << endl;
	Mouse(30, 22);
	cin.width(2);
	cin >> this->ClassScore;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ÿγ��������ޣ����֣�:" << endl;
	Mouse(30, 25);
	cin.width(2);
	cin >> this->Max;
	Check();
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              �����ϻ�ѧʱ�����9���ַ�����" << endl;
	Mouse(30, 28);
	cin.width(10);
	cin >> this->PrHour;
	Check();
	this->Person = 0;
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ��ʼ���ɹ���" << endl;
	cout << "                              ����������������������������������������������������" << endl;
}
