#include<iostream>
#include"Assist.h"
#include"ADMIN.h"
#include"STUDENT.h"
#include"Course.h"
#include<fstream>
#include<istream>
#include<ostream>
#include"BaseCourse.h"
using namespace std;

STUDENT STU[10];
char ADMIN::ADPS[9] = "ILoveNCU";
ADMIN ADmin[10];
Create Cre[5];
Literate lit[5];
Engineering Eng[5];
int n;
char b = 'a';
int j;

//�ļ��������
void WriteB(int a)//1ѧ����2��ʦ��3�����࣬4�Ŀ��࣬5������
{
	switch (a)
	{
	case 1:
	{
		ofstream OS("Students", ios_base::out);
		if (OS.bad())
		{
			cout << "д���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		OS.write(reinterpret_cast<char *>(&STU), sizeof(STUDENT));
		OS.close();
		break;
	}
	case 2:
	{
		ofstream OS("Admins", ios_base::out);
		if (OS.bad())
		{
			cout << "д���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		OS.write(reinterpret_cast<char *>(&ADmin), sizeof(ADMIN));
		OS.close();
		break;
	}
	case 3:
	{
		ofstream OS("Creates", ios_base::out);
		if (OS.bad())
		{
			cout << "д���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		OS.write(reinterpret_cast<char *>(&Cre), sizeof(Create));
		OS.close();
		break;
	}
	case 4:
	{
		ofstream OS("Literates", ios_base::out);
		if (OS.bad())
		{
			cout << "д���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		OS.write(reinterpret_cast<char *>(&lit), sizeof(Literate));
		OS.close();
		break;
	}
	case 5:
	{
		ofstream OS("Engineerings", ios_base::out);
		if (OS.bad())
		{
			cout << "д���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		OS.write(reinterpret_cast<char *>(&Eng), sizeof(Engineering));
		OS.close();
		break;
	}
	}
}

//���뺯��
void ReadB(int n)//1ѧ��,2��ʦ��3�����࣬4�Ŀ��࣬5������
{
	switch (n)
	{
	case 1:
	{
		ifstream is("Students", ios_base::in);
		if (is.bad())
		{
			cout << "���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&STU), sizeof(STU));
		is.close();
		break;
	}
	case 2:
	{
		ifstream is("Admins", ios_base::in);
		if (is.bad())
		{
			cout << "���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&ADmin), sizeof(ADmin));
		is.close();
		break;
	}
	case 3:
	{
		ifstream is("Creates", ios_base::in);
		if (is.bad())
		{
			cout << "���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&Cre), sizeof(Cre));
		is.close();
		break;
	}
	case 4:
	{
		ifstream is("Literates", ios_base::in);
		if (is.bad())
		{
			cout << "���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&lit), sizeof(lit));
		is.close();
		break;
	}
	case 5:
		ifstream is("Engineerings", ios_base::in);
		if (is.bad())
		{
			cout << "���ļ�ʧ�ܣ�3����˳�����" << endl;
			Sleep(3000);
			exit(0);
		}
		is.read(reinterpret_cast<char *>(&Eng), sizeof(Eng));
		is.close();
		break;
	}
}

//��������-ѧ���˺�,�����������±�ֵ�����򷵻�-1
int Search(char * Crea)//��������-ѧ���˺�,�����������±�ֵ�����򷵻�-1
{
	int i;
	
	for (i = 0; i < 10; i++)
	{
		if (strncmp(STU[i].SNumber, Crea, 10) == 0)
		{
			return i;
		}
	}
	return -1;
}

//��������-��ʦ�˺�,�����������±꣬���򷵻�-1
int Search(char * Crea, int b)//��������-��ʦ�˺�,�����������±꣬���򷵻�-1
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if (strncmp(ADmin[i].Admin, Crea, 11) == 0)
		{
			return i;
		}
	}

	return -1;
}

//���ݿγ̱�Ų����±꣬�ڶ�������Ƿ������м��,1�����࣬2�Ŀ��࣬3�����࣬�����������±꣬���򷵻�-1
int Search(char * c, int a, int b)//�жϿγ̱�ţ�1�����࣬2�Ŀ��࣬3�����࣬�����������±꣬���򷵻�-1
{
	switch (a)
	{
	case 1:
	{
		int i;
		for (i = 0; i < 5; i++)
		{
			if (strncmp(c, Cre[i].CNumber, 11) == 0)
			{
				return i;
			}
			else
			{
				continue;
			}
		}
		return -1;
	}
	case 2:
	{
		int i;
		for (i = 0; i < 5; i++)
		{
			if (strncmp(c, lit[i].CNumber, 11)  == 0)
			{
				return i;
			}
			else
			{
				continue;
			}
		}
		return -1;
	}
	case 3:
	{
		int i;
		for (i = 0; i < 5; i++)
		{
			if (strncmp(c, Eng[i].CNumber, 11) == 0)
			{
				return i;
			}
			else
			{
				continue;
			}
		}
		return -1;
	}
	}
}

//���ݿγ��������±꣬�ڶ�������Ƿ������м��,1�����࣬2�Ŀ��࣬3�����࣬�����������±꣬���򷵻�-1
int Search(char * c, int a, char b)
{
	switch (a)
	{
	case 1:
	{
		int i;
		for (i = 0; i < 5; i++)
		{
			if (strncmp(c, Cre[i].CName, 11) == 0)
			{
				return i;
			}
			else
			{
				continue;
			}
		}
		return -1;
	}
	case 2:
	{
		int i;
		for (i = 0; i < 5; i++)
		{
			if (strncmp(c, lit[i].CName, 11) == 0)
			{
				return i;
			}
			else
			{
				continue;
			}
		}
		return -1;
	}
	case 3:
	{
		int i;
		for (i = 0; i < 5; i++)
		{
			if (strncmp(c, Eng[i].CName, 11) == 0)
			{
				return i;
			}
			else
			{
				continue;
			}
		}
		return -1;
	}
	}

	return 0;
}

//���ݿγ̱�Ų��ҿγ����ʣ�����Ǵ����࣬����1���Ŀ��෵��2�������෵��3�����򷵻�-1
int Search(char * c, int a, double b)//���ݿγ̱�Ų��ҿγ����ʣ�����Ǵ����࣬����1���Ŀ��෵��2�������෵��3�����򷵻�-1
{
		int i;
		for (i = 0; i < 5; i++)
		{
			if (strncmp(c, Cre[i].CNumber, 1) == 0)
			{
				return 1;
			}
			if (strncmp(c, lit[i].CNumber, 1) == 0)
			{
				return 2;
			}
			if (strncmp(c, Eng[i].CNumber, 1) == 0)
			{
				return 3;
			}
		}

		return -1;
}

//���ݿγ������ҿγ��࣬����1�����࣬2�Ŀ��࣬3�����࣬���򷵻�-1
int Search(char * c, char b)//���ݿγ������ҿγ��࣬����1�����࣬2�Ŀ��࣬3�����࣬���򷵻�-1
{
	int i;
	for (i = 0; i < 5; i++)
	{
		if (strncmp(Cre[i].CName, c, 11) == 0)
		{
			return 1;
		}
		if (strncmp(lit[i].CName, c, 11) == 0)
		{
			return 2;
		}
		if (strncmp(Eng[i].CName, c, 11) == 0)
		{
			return 3;
		}
	}

	return -1;
}

//���ѧ���˺����룬�˺�����ƥ�䣬�����±�ֵ������˺����벻ƥ�䣬����-2����û���ҵ�����-1
int CheckPAPAS(char * Crea, char * c1)//���ѧ���˺����룬�˺�����ƥ�䣬�����±�ֵ������˺����벻ƥ�䣬����-2����û���ҵ�����-1
{
	int n = Search(Crea);
	if (n != -1)
	{
		if (strncmp(c1, STU[n].STPa, 10) == 0)
		{
			return n;
		}
		else
		{
			return -2;
		}
	}
	else
	{
		return n;
	}
}

//�����ʦ�˺����룬�˺�����ƥ�䣬�����±�ֵ������˺����벻ƥ�䣬����-2����û���ҵ�����-1
int CheckPAPAS(char * Crea, char * c1, int a)
{
	int n = Search(Crea, 1);
	if (n != -1)
	{
		if (strncmp(c1, ADmin[n].ADP, 11) == 0)
		{
			return n;
		}
		else
		{
			return -2;
		}
	}
	else
	{
		return n;
	}
}

//���ݿγ̱�ţ��ڶ�������ʾ���1�����࣬2�Ŀ��࣬3������
//����Ӧ�γ������������򷵻��±�ֵ�����򷵻�-2�����Ҳ����γ̷���-1
int CheckCo(char * Crea, int a)
{
	switch (a)
	{
	case 1:
	{
		int n = Search(Crea, a, 1);
		if (n != -1)
		{
			if(Cre[n].Person < Cre[n].Max)
			{
				return n;
			}
			else return -2;
		}
		else
		{
			return n;
		}
	}
	case 2:
	{
		int n = Search(Crea, a, 1);
		if (n != -1)
		{
			if (lit[n].Person < lit[n].Max)
			{
				return n;
			}
			else return -2;
		}
		else
		{
			return n;
		}
	}
	case 3:
	{
		int n = Search(Crea, a, 1);
		if (n != -1)
		{
			if (Eng[n].Person < Eng[n].Max)
			{
				return n;
			}
			else return -2;
		}
		else
		{
			return n;
		}
	}
	}
}

//���ݿγ������룬����Ӧ�γ����Ŀγ������Ƿ���������������-1����������1
int CheckCo(char * Crea, double q)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		if (strncmp(Crea, Cre[i].CName, 11) == 0)
		{
			if (Cre[i].Person < Cre[i].Max)
			{
				return 1;
			}
			else return -1;
		}
		if (strncmp(Crea, lit[i].CName, 11) == 0)
		{
			if (lit[i].Person < lit[i].Max)
			{
				return 1;
			}
			else return -1;
		}
		if (strncmp(Crea, Eng[i].CName, 11) == 0)
		{
			if (Eng[i].Person < Eng[i].Max)
			{
				return 1;
			}
			else return -1;
		}
	}
	
	return 0;
}
 
//���ݿγ��������γ��Ƿ���ڣ�������ڷ��ؿγ���ָ�룬��������ڷ����ض��ַ�'a'
char* CheckCo(char* c)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		if (strncmp(c, Cre[i].CName, 11)  == 0)
		{
			return c;
		}
		else if (strncmp(c, lit[i].CName, 11) == 0)
		{
			return c;
		}
		else if (strncmp(c, Eng[i].CName, 11) == 0)
		{
			return c;
		}
	}

	return &b;
}

//��鵱ǰ����γ����Ƿ�����,�����������-1�����û������1��
int CheckCo(char b)
{

	int j = 0;

	switch (b)
	{
	case '1':
		{
			for (int i = 0; i < 5; i++)
			{
				if (strncmp(Cre[i].ExHour, "0", 2) == 0)
				{
					j++;
				}
			}
			if (j == 0) return -1;
			return 1;
		}
	case '2':
	{
		for (int i = 0; i < 5; i++)
		{
			if (strncmp(lit[i].ExHour, "0", 2) == 0)
			{
				j++;
			}
		}
		if (j == 0) return -1;
		return 1;
	}
	case '3':
	{
		for (int i = 0; i < 5; i++)
		{
			if (strncmp(Eng[i].PrHour, "0", 2) == 0)
			{
				j++;
			}
		}
		if (j == 0) return -1;
		return 1;
	}
	}

	return 0;
}

//�������a��ֵȷ�������һ��γ̣�1�����࣬2�Ŀ��࣬3���࣬�ҵ�������ŵĿγ����±꣬Ȼ�󷵻أ����򷵻�-1
int CheckCo(int a)//�������a��ֵȷ�������һ��γ̣�1�����࣬2�Ŀ��࣬3���࣬�ҵ�������ŵĿγ����±꣬Ȼ�󷵻�
{
	int k = 0;

	switch (a)
	{
	case 1:
	{
		for (int i = 0; i < 5; i++)
		{
			if (strncmp("0", Cre[i].ExHour, 1) == 0) k++;
		}
		return (5 - k);
	}
	case 2:
	{
		for (int i = 0; i < 5; i++)
		{
			if (strncmp("0", lit[i].ExHour, 1) == 0) k++;
		}
		return (5 - k);
	}
	case 3:
	{
		for (int i = 0; i < 5; i++)
		{
			if (strncmp("0", Eng[i].PrHour, 1) == 0) k++;
		}
		return (5 - k);
	}
	}

	return 0;
}

//ϵͳ���˵�
void Menu()
{
	int op;  //������
	int j = 0;  //���Ʋ���������������

	ReadB(1);
	ReadB(2);
	ReadB(3);
	ReadB(4);
	ReadB(5);
	system("cls");
	cout << "                              ����������������������������������������������������" << endl << endl;
	cout << "                              ********************ѧ��ѡ��ϵͳ********************" << endl << endl;
	cout << "                              (1) ��¼" << endl << endl;
	cout << "                              (2) ע��" << endl << endl;
	cout << "                              (3) ����" << endl << endl;
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���������(1, 2, 3):";
	Mouse(50, 11);
	while (1)
	{
		cin.width(1);
		cin >> op;
		j++;
		Check();
		if (j > 3)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ����������������Σ���⵽����ʹ�ñ�ϵͳ�������˳�ϵͳ��" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(1000);
			exit(0);
		}
		if (op == 1 || op == 2 || op == 3)
		{
			break;
		}
		else
		{
			system("cls");
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              �������������������1/2/3,�������룡�����������Σ�" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              (1) ��¼" << endl << endl;
			cout << "                              (2) ע��" << endl << endl;
			cout << "                              (3) ����" << endl << endl;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ���������(1, 2, 3)��";
			Mouse(50, 10);
		}
	}
	try
	{
		switch (op)
		{
		case 1:
			Login();
			break;
		case 2:
			Register();
			break;
		case 3:
			Help();
			break;
		default:
			throw 3.33;
		}
	}
	catch (double Eng)
	{
		if (Eng == 3.33)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              δ֪������������ϵ������Ա�޸���ӦBug!������˳�ϵͳ!" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(3000);
			exit(0);
		}
	}
}

void Help()
{
	system("cls");
	cout << "����������������������������������������������������������������������������������" << endl;
	cout << "ʹ�������:" << endl;
	cout << "����������������������������������������������������������������������������������" << endl;
	cout << "������Ա(����-�绰-QQ): ���Ϻ�-19979405286-964327216" << endl;
	cout << "����������������������������������������������������������������������������������" << endl;
	cout << "ϵͳ��Ϣ��" << endl;
	cout << "����������������������������������������������������������������������������������" << endl;
	cout << "ѧ��ѡ��ϵͳ,��ϵͳ��ʼ��¼������Բο�ϵͳ�Ŀ�����Ϣ��" << endl;
	cout << "����������������������������������������������������������������������������������" << endl;
	cout << "���Ե�¼/ע��ϵͳ�˻�����Ե�һ��ʹ�ñ�ϵͳ��ѧ����" << endl;
	cout << "����������������������������������������������������������������������������������" << endl;
	cout << "��Ҫ��ע���˺ţ�����֤��ݺ��������룬֮�󷽿ɵ�¼ϵͳʹ�ã�" << endl;
	cout << "����������������������������������������������������������������������������������" << endl;
	cout << "��̨��ʦ��ע�����ѧ��ֱ�ӵ�¼ϵͳ���ɡ�" << endl;
	cout << "����������������������������������������������������������������������������������" << endl;
	cout << "��ʦ���Զ����ݿ����ݽ�����ӣ�ɾ������Ϣ�޸ģ�������ݿ�Ȳ�����" << endl;
	cout << "����������������������������������������������������������������������������������" << endl;
	cout << "ѧ���������ѡ�޿γ���Ϣ��ѡ��ѡ�޿γ̣����������Ϣ�����Խ�����ѡ��ѡ�γ̵Ĳ�����" << endl;
	cout << "����������������������������������������������������������������������������������" << endl;
	cout << "�����Բ�ѯ�γ̣���ѯĳ�ſγ�ѧ����ѡ�������������ſ�ѡ�������ȵȹ�����Ϣ��" << endl;
	cout << "����������������������������������������������������������������������������������" << endl;
	cout << "����֮�⣬��Ҫע��ľ��ǿγ�ѡ��ѧ���������ޣ�ѧԺҪ��Ϊ8ѧ�ֻ�������ѡ�޿Σ���" << endl;
	cout << "����������������������������������������������������������������������������������" << endl;
	cout << "ע�����" << endl;
	cout << "����������������������������������������������������������������������������������" << endl;
	cout << "��1�����������û���Ҫ���в�����ѡ���������ݶ�Ӧ�Ĺ����������벻ͬ����������ʹ��ϵͳ��" << endl;
	cout << "����������������������������������������������������������������������������������" << endl;
	cout << "��2����ϵͳ���ս���Ȩ�鿪�������У�δ��������˽���޸ı�ϵͳ��" << endl;
	cout << "����������������������������������������������������������������������������������" << endl;
	Sleep(5000);

	char op[3];
	cout << "                              �Ƿ����ʹ�ñ�ϵͳ������/��:" << endl;
	Mouse(60, 29);
	cin.width(3);
	cin >> op;
	Check();
	if (strcmp(op, "��") == 0)
	{
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              2��󷵻�������!" << endl;
		cout << "                              ����������������������������������������������������" << endl;
		Sleep(2000);
		Menu();
	}
	else if (strcmp(op, "��") == 0)
	{
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              2����˳�ϵͳ!" << endl;
		cout << "                              ����������������������������������������������������" << endl;
		Sleep(2000);
		exit(0);
	}
	else
	{
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              ��������˳�ϵͳ��" << endl;
		cout << "                              ����������������������������������������������������" << endl;
		Sleep(1000);
		exit(0);
	}
}

//ע��ģ��
void Register()
{
	int op;
	int j = 0;

	system("cls");
	cout << "                              ����������������������������������������������������" << endl << endl;
	cout << "                              **********************ע��ģ��**********************" << endl << endl;
	cout << "                              (1) ѧ��ע��" << endl << endl;
	cout << "                              (2) ��ʦע��" << endl << endl;
	cout << "                              (3) �˳�ϵͳ" << endl << endl;
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���������(1, 2, 3):";
	Mouse(30, 12);
	while (1)
	{
		cin.width(1);
		cin >> op;
		j++;
		Check();
		if (j > 3)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ����������������Σ���⵽����ʹ�ñ�ϵͳ�������˳�ϵͳ��" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(1000);
			exit(0);
		}
		if (op == 1 || op == 2 || op == 3)
		{
			break;
		}
		else
		{
			system("cls");
			cout << "                              ����������������������������������������������������" << endl << endl;
			cout << "                              **********************ע��ģ��**********************" << endl << endl;
			cout << "                              (1) ѧ��ע��" << endl << endl;
			cout << "                              (2) ��ʦע��" << endl << endl;
			cout << "                              (3) �˳�ϵͳ" << endl << endl;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ���������(1, 2, 3):";
			Mouse(30, 12);
		}
	}
	try
	{
		switch (op)
		{
		case 1:
		{
			int k;

			if ((k = STU[9].CheckSTU()) == -1)
			{
				cout << "                              ����������������������������������������������������" << endl;
				cout << "                              ϵͳ�������ޣ�ע�������Ѵ����ޣ������ĵȴ�ϵͳ�Ż���" << endl;
				cout << "                              ����������������������������������������������������" << endl;
				cout << "                              2����˳�ϵͳ��" << endl;
				cout << "                              ����������������������������������������������������" << endl;
				Sleep(2000);
				exit(0);
			}
			STUDENT* Stu = new STUDENT;
			Stu->SetSTU();
			STU[k] = *Stu;
			WriteB(1);
			STU[k].STMenu();
			break;
		}
		case 2:
		{
			char ML[9];
			int k;

			if ((k = ADmin[9].CheckAD()) == -1)
			{
				cout << "                              ����������������������������������������������������" << endl;
				cout << "                              ϵͳ�������ޣ�ע�������Ѵ����ޣ������ĵȴ�ϵͳ�Ż���" << endl;
				cout << "                              ����������������������������������������������������" << endl;
				cout << "                              2����˳�ϵͳ��" << endl;
				cout << "                              ����������������������������������������������������" << endl;
				Sleep(2000);
				exit(0);
			}
			system("cls");
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ����ע������:" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			cin.width(9);
			Mouse(30, 3);
			cin >> ML;
			if (ADmin[0].CheckADPS(ML) == 1)
			{
				ADMIN* admin = new ADMIN;
				admin->SetAD();
				ADmin[k] = *admin;
				WriteB(2);
				ADmin[k].ADMenu();
				break;
			}
			else
			{
				cout << "                              ����������������������������������������������������" << endl;
				cout << "                              ����������󣡼�鵽����ʦ��Աע����ʦ�˻����˳�ϵͳ��" << endl;
				Sleep(2000);
				exit(0);
			}
			break;
		}
		case 3:
			exit(0);
		default:
			throw 3.33;
		}
	}
	catch (double Eng)
	{
		if (Eng == 3.33)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              δ֪������������ϵ������Ա�޸���ӦBug!������˳�ϵͳ!" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(3000);
			exit(0);
		}
	}
}

//��¼ģ��
void Login()
{
	int op;
	int j = 0;

	system("cls");
	cout << "                              ����������������������������������������������������" << endl << endl;
	cout << "                              **********************��¼ģ��**********************" << endl << endl;
	cout << "                              (1) ��ʦ" << endl << endl;
	cout << "                              (2) ѧ��" << endl << endl;
	cout << "                              (3) �˳�ϵͳ" << endl << endl;
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���������(1, 2, 3):";
	Mouse(30, 12);
	while (1)
	{
		cin.width(1);
		cin >> op;
		j++;
		Check();
		if (j > 3)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ����������������Σ���⵽����ʹ�ñ�ϵͳ�������˳�ϵͳ��" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(1000);
			exit(0);
		}
		if (op == 1 || op == 2 || op == 3)
		{
			break;
		}
		else
		{
			system("cls");
			cout << "                              ����������������������������������������������������" << endl << endl;
			cout << "                              **********************��¼ģ��**********************" << endl << endl;
			cout << "                              (1) ��ʦ" << endl << endl;
			cout << "                              (2) ѧ��" << endl << endl;
			cout << "                              (3) �˳�ϵͳ" << endl << endl;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ���������(1, 2, 3):";
			Mouse(30, 12);
			cin.width(1);
			cin >> op;
			j++;
			Check();
		}
	}
	switch (op)
	{
	case 1:
		char PAS[11];
		char PA[11];

	first:
		system("cls");
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              �˺�:" << endl;
		Mouse(30, 2);
		cin.width(11);
		cin >> PA;
		Check();
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              ����:" << endl;
		Mouse(30, 5);
		cin.width(11);
		cin >> PAS;
		Check();
		n = CheckPAPAS(PA, PAS, 1);
		if(n == -1)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              û������˺ţ�����ע�ᣡ" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              2���תע��ģ�飡" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(2000);
			Register();
			break;
		}
		else if (n == -2)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ����������أ�" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(2000);
			goto first;
		}
		else
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ��¼�ɹ�����ӭʹ�ñ�ϵͳ��" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              2���ת���˵�!" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(2000);
			ADmin[n].ADMenu();
			break;
		}
	case 2:
	{
		char PAS[11];
		char PA[11];
		
		second:
		system("cls");
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              �˺�:" << endl;
		Mouse(30, 2);
		cin.width(11);
		cin >> PA;
		Check();
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              ����:" << endl;
		Mouse(30, 5);
		cin.width(11);
		cin >> PAS;
		Check();
		n = CheckPAPAS(PA, PAS);
		if (n == -1)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              û������˺ţ�����ע�ᣡ" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              2���תע��ģ�飡" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(2000);
			Register();
			break;
		}
		else if(n == -2)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ����������أ�" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(2000);
			goto second;
		}
		else
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ��¼�ɹ�����ӭʹ�ñ�ϵͳ��" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              2���ת���˵�!" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(2000);
			STU[n].STMenu();
			break;
		}
	}
	default:
	{
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              2����˳�ϵͳ" << endl;
		Sleep(2000);
		exit(0);
	}
	}
}

void STUDENT::Option()  //ѡ��
{
	char CName[11];
	int flag;
	int U;
	int y = 0;

	system("cls");
	if (this->CNum == 4 || this->OS >= 8)
	{
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              ���Ѿ��ﵽѧԺҪ���ѡ�޿�Ҫ���ˣ�2��󷵻����˵���" << endl;
		Sleep(2000);
		this->STMenu();
	}
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ѡ��ģ�飺" << endl;
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ��ѡ������γ���Ϣһ����" << endl;
	for (int i = 0; i < 5; i++)
	{
		if (strncmp(Cre[i].ExHour, "0", 2) != 0)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                           |  �γ̱��  |  �γ���  |  �γ����  |  �γ�ѧʱ  |  �γ�ѧ��  |" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                           |  ����ѧ��  |  �γ�ѡ������  |  ʵ��ѧʱ  |  �ϻ�ѧʱ  |" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                           |  " << Cre[i].CNumber << "  |  " << Cre[i].CName << "  |  " << Cre[i].CKind << "  |  " << Cre[i].ClassHour
				<< "  |  " << Cre[i].ClassScore << "  |" << endl;
			cout << "                           |  " << Cre[i].Opentime << "  |  " << Cre[i].Person << "/" << Cre[i].Max << "  |  " << Cre[i].ExHour
				<< "  |  " << Cre[i].PrHour << "  |" << endl;
			y++;
		}
	}
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ��ѡ�Ŀ���γ���Ϣһ����" << endl;
	for (int i = 0; i < 5; i++)
	{
		if (strncmp(lit[i].ExHour, "0", 2) != 0)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                           |  �γ̱��  |  �γ���  |  �γ����  |  �γ�ѧʱ  |  �γ�ѧ��  |" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                           |  ����ѧ��  |  �γ�ѡ������  |  ʵ��ѧʱ  |" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                           |  " << lit[i].CNumber << "  |  " << lit[i].CName << "  |  " << lit[i].CKind << "  |  " << lit[i].ClassHour
				<< "  |  " << lit[i].ClassScore << "  |" << endl;
			cout << "                           |  " << lit[i].Opentime << "  |  " << lit[i].Person << "/" << lit[i].Max << "  |  " << lit[i].ExHour
				<< "  |" << endl;
			y++;
		}
	}
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ��ѡ������γ���Ϣһ����" << endl;
	for (int i = 0; i < 5; i++)
	{
		if (strncmp(Eng[i].PrHour, "0", 2) != 0)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                           |  �γ̱��  |  �γ���  |  �γ����  |  �γ�ѧʱ  |  �γ�ѧ��  |" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                           |  ����ѧ��  |  �γ�ѡ������   |  �ϻ�ѧʱ  |" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                           |  " << Eng[i].CNumber << "  |  " << Eng[i].CName << "  |  " << Eng[i].CKind << "  |  " << Eng[i].ClassHour
				<< "  |  " << Eng[i].ClassScore << "  |" << endl;
			cout << "                           |  " << Eng[i].Opentime << "  |  " << Eng[i].Person << "/" << Eng[i].Max << "  |  " << Eng[i].PrHour << "  |" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			y++;
		}
	}
	Sleep(10000);
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ��������Ҫѡ�޵Ŀγ���:" << endl;
	cout << "                              ����������������������������������������������������" << endl;
	Mouse(30, 8 * y + 10);
	cin.width(11);
	cin >> CName;
	Check();
	if (*(CheckCo(CName)) != 'a' && (CheckCo(CName, 2.0) != -1))
	{
		flag = Search(CName, 'i');
		switch (flag)
		{
		case 1:
		{
			U = Search(CName, 1, 't');
			for (int i = 0; i < 4; i++)
			{
				if (strncmp(this->AC[i], Cre[U].CName, 11) == 0)
				{
					cout << "                              ����������������������������������������������������" << endl;
					cout << "                              ���Ѿ�ѡ�޹��ÿγ��ˣ�2��󷵻����˵�!" << endl;
					Sleep(2000);
					this->STMenu();
				}
			}
			this->CNum++;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ѡ�޳ɹ����㻹����ѡ�����" << (4 - this->CNum) << "��ѡ�޿�!" << endl;
			Cre[U].Person++;
			this->OS += (Cre[U].ClassScore);
			switch (CNum - 1)
			{
			case 0:strncpy(this->AC[0], CName, 11); break;
			case 1:strncpy(this->AC[1], CName, 11); break;
			case 2:strncpy(this->AC[2], CName, 11); break;
			case 3:strncpy(this->AC[3], CName, 11); break;
			}
			WriteB(1);
			WriteB(3);
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              2��󷵻����˵�!" << endl;
			Sleep(2000);
			this->STMenu();
			break;
		}
		case 2:
		{
			U = Search(CName, 2, 't');
			for (int i = 0; i < 4; i++)
			{
				if (strncmp(this->AC[i], lit[U].CName, 11) == 0)
				{
					cout << "                              ����������������������������������������������������" << endl;
					cout << "                              ���Ѿ�ѡ�޹��ÿγ��ˣ�2��󷵻����˵�!" << endl;
					Sleep(2000);
					this->STMenu();
				}
			}
			this->CNum++;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ѡ�޳ɹ����㻹����ѡ�����" << (4 - this->CNum) << "��ѡ�޿�!" << endl;
			lit[U].Person++;
			this->OS += (lit[U].ClassScore);
			switch (CNum - 1)
			{
			case 0:strncpy(this->AC[0], CName, 11); break;
			case 1:strncpy(this->AC[1], CName, 11); break;
			case 2:strncpy(this->AC[2], CName, 11); break;
			case 3:strncpy(this->AC[3], CName, 11); break;
			}
			WriteB(1);
			WriteB(4);
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              2��󷵻����˵�!" << endl;
			Sleep(2000);
			this->STMenu();
			break;
		}
		case 3:
		{
			U = Search(CName, 3, 't');
			for (int i = 0; i < 4; i++)
			{
				if (strncmp(this->AC[i], Eng[U].CName, 11) == 0)
				{
					cout << "                              ����������������������������������������������������" << endl;
					cout << "                              ���Ѿ�ѡ�޹��ÿγ��ˣ�2��󷵻����˵�!" << endl;
					Sleep(2000);
					this->STMenu();
				}
			}
			this->CNum++;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ѡ�޳ɹ����㻹����ѡ�����" << (4 - this->CNum) << "��ѡ�޿�!" << endl;
			Eng[U].Person++;
			this->OS += (Eng[U].ClassScore);
			switch (CNum - 1)
			{
			case 0:strncpy(this->AC[0], CName, 11); break;
			case 1:strncpy(this->AC[1], CName, 11); break;
			case 2:strncpy(this->AC[2], CName, 11); break;
			case 3:strncpy(this->AC[3], CName, 11); break;
			}
			WriteB(1);
			WriteB(5);
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              2��󷵻����˵�!" << endl;
			Sleep(2000);
			this->STMenu();
			break;
		}
		}
	}
	else
	{
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              û�����ſγ̣�2��󷵻����˵�!" << endl;
		Sleep(2000);
		this->STMenu();
	}
}

void  STUDENT::Reference(int a)//������ݣ�a=1��ʾ��ѡ�γ���Ϣ��a=2��ʾ������Ϣ
{
	switch (a)
	{
	case 1:
	{
		system("cls");
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                             |��ѡ�γ̣�" << endl;
		cout << "                              ����������������������������������������������������" << endl;
		for (int i = 0; i < 4; i++)
		{
				cout << "                              ����������������������������������������������������" << endl;
				cout << "                              || " << this->AC[i] << endl;
				cout << "                              ����������������������������������������������������" << endl;
		}
		break;
	}
	case 2:
	{
		system("cls");
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              ������Ϣ��" << "  ||  ������" << this->SName << endl;
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              �˺ţ�" << this->SNumber << "||  ���룺" << this->STPa << endl;
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              ��ϵ��ʽ:" << this->SP << "  ||  ѧ��:" << this->OS << endl;
		cout << "                              ����������������������������������������������������" << endl;
		break;
	}
	default:
		exit(0);
	}
}

void  STUDENT::Drop()  //�˿�
{
	char CName[11];
	int U;
	int flag;
	int p = 0;

	system("cls");
	if (this->CNum == 0 || this->OS == 0)
	{
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              ��һ�ſγ̶���û��ѡ�ޣ�2��󷵻����˵���" << endl;
		Sleep(2000);
		this->STMenu();
	}
	this->Reference(1);
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ��������Ҫ��ѡ�Ŀγ�:" << endl;
	Mouse(30, 17);
	cin.width(11);
	cin >> CName;
	Check();
	char* CC = CheckCo(CName);
	if (*CC != 'a')
	{
		flag = Search(CName, 'y');
		switch (flag)
		{
		case 1:
		{
			U = Search(CName, 1, 't');
			for (int i = 0; i < 4; i++)
			{
				if (strncmp(this->AC[i], Cre[U].CName, 11) != 0)
				{
					p++;
				}
			}
			if (p >= 4)
			{
				cout << "                              ����������������������������������������������������" << endl;
				cout << "                              �㻹û��ѡ�޹��ÿγ̣�����ѡ�޶�Ӧ�γ̣�" << endl;
				Sleep(2000);
				this->STMenu();
				break;
			}
			this->CNum--;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ��ѡ�ɹ���������ѡ�����" << (4 - this->CNum) << "��ѡ�޿�!" << endl;
			Cre[U].Person--;
			this->OS -= Cre[U].ClassScore;
			WriteB(3);
			break;
		}
		case 2:
		{
			U = Search(CName, 2, 't');
			for (int i = 0; i < 4; i++)
			{
				if (strncmp(this->AC[i], lit[U].CName, 11) != 0)
				{
					p++;
				}
			}
			if (p >= 4)
			{
				cout << "                              ����������������������������������������������������" << endl;
				cout << "                              �㻹û��ѡ�޹��ÿγ̣�����ѡ�޶�Ӧ�γ̣�" << endl;
				Sleep(2000);
				this->STMenu();
				break;
			}
			this->CNum--;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ��ѡ�ɹ���������ѡ�����" << (4 - this->CNum) << "��ѡ�޿�!" << endl;
			lit[U].Person--;
			this->OS -= lit[U].ClassScore;
			WriteB(4);
			break;
		}
		case 3:
		{
			U = Search(CName, 3, 't');
			for (int i = 0; i < 4; i++)
			{
				if (strncmp(this->AC[i], Eng[U].CName, 11) != 0)
				{
					p++;
				}
			}
			if (p >= 4)
			{
				cout << "                              ����������������������������������������������������" << endl;
				cout << "                              �㻹û��ѡ�޹��ÿγ̣�����ѡ�޶�Ӧ�γ̣�" << endl;
				Sleep(2000);
				this->STMenu();
				break;
			}
			this->CNum--;
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ��ѡ�ɹ���������ѡ�����" << (4 - this->CNum) << "��ѡ�޿�!" << endl;
			Eng[U].Person--;
			this->OS -= Eng[U].ClassScore;
			WriteB(5);
			break;
		}
		}
		switch (CNum + 1)
		{
		case 1:strncpy(this->AC[0], "\0", 11); break;
		case 2:strncpy(this->AC[1], "\0", 11); break;
		case 3:strncpy(this->AC[2], "\0", 11); break;
		case 4:strncpy(this->AC[3], "\0", 11); break;
		}
		WriteB(1);
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              2��󷵻����˵�!" << endl;
		Sleep(2000);
		this->STMenu();
	}
	else
	{
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              û�����ſγ̣�" << "2��󷵻����˵�!" << endl;
		Sleep(2000);
		this->STMenu();
	}
}

void Create::Show()
{
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              ������γ���Ϣһ����" << endl;
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                           |  �γ̱��  |  �γ���  |  �γ����  |  �γ�ѧʱ  |  �γ�ѧ��  |" << endl;
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                           |  ����ѧ��  |  �γ�ѡ������  |  ʵ��ѧʱ  |  �ϻ�ѧʱ  |" << endl;
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                           |  " << this->CNumber << "  |  " << this->CName << "  |  " << this->CKind << "  |  " << this->ClassHour
			<< "  |  " << this->ClassScore << "  |" << endl;
		cout << "                           |  " << this->Opentime << "  |  " << this->Person << "/" << this->Max << "  |  " << this->ExHour
			<< "  |  " << this->PrHour << "  |" << endl;
		cout << "                              ����������������������������������������������������" << endl;
}

void Literate::Show()
{
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              �Ŀ���γ���Ϣһ����" << endl;
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                           |  �γ̱��  |  �γ���  |  �γ����  |  �γ�ѧʱ  |  �γ�ѧ��  |" << endl;
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                           |  ����ѧ��  |  �γ�ѡ������  |  ʵ��ѧʱ  |" << endl;
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                           |  " << this->CNumber << "  |  " << this->CName << "  |  " << this->CKind << "  |  " << this->ClassHour
			<< "  |  " << this->ClassScore << "  |" << endl;
		cout << "                           |  " << this->Opentime << "  |  " << this->Person << "/" << this->Max << "  |  " << this->ExHour
			<< "  |" << endl;
		cout << "                              ����������������������������������������������������" << endl;
}

void Engineering::Show()
{
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              �Ŀ���γ���Ϣһ����" << endl;
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                           |  �γ̱��  |  �γ���  |  �γ����  |  �γ�ѧʱ  |  �γ�ѧ��  |" << endl;
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                           |  ����ѧ��  |  �γ�ѡ������  |  ʵ��ѧʱ  |" << endl;
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                           |  " << this->CNumber << "  |  " << this->CName << "  |  " << this->CKind << "  |  " << this->ClassHour
		<< "  |  " << this->ClassScore << "  |" << endl;
	cout << "                           |  " << this->Opentime << "  |  " << this->Person << "/" << this->Max << "  |  " << this->PrHour
		<< "  |" << endl;
	cout << "                              ����������������������������������������������������" << endl;
}

void ADMIN::Reference(int a) //����γ���Ϣ,a=1��ʾ�γ���Ϣ,a=2��ʾ������Ϣ
{
	switch (a)
	{
	case 1:
	{
		int u = 0;
		system("cls");
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              ����γ���Ϣ:" << endl;
		cout << "                              ����������������������������������������������������" << endl;
		for (int i = 0; i < 5; i++)
		{
			if (strncmp(Cre[i].ExHour, "0", 11) != 0)
			{
				u++;
				Cre[i].Show();
			}
			if (strncmp(lit[i].ExHour, "0", 11) != 0)
			{
				lit[i].Show();
				u++;
			}
			if (strncmp(Eng[i].PrHour, "0", 11) != 0)
			{
				Eng[i].Show();
				u++;
			}
		}
		Sleep(10000);
		char op[3];
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              �Ƿ����ʹ�ñ�ϵͳ������/��:" << endl;
		Mouse(30, 10 * u + 5);
		cin.width(3);
		cin >> op;
		Check();
		if (strcmp(op, "��") == 0)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              2��󷵻�������!" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(2000);
			this->ADMenu();
		}
		else if (strcmp(op, "��") == 0)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              2����˳�ϵͳ!" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(2000);
			exit(0);
		}
		else
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ��������˳�ϵͳ��" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(1000);
			exit(0);
		}
		break;
	}
	case 2:
	{
		system("cls");
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              ������Ϣ��" << endl;
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              �˺ţ�" << this->Admin << "  ||  ���룺" << this->ADP << endl;
		cout << "                              ����������������������������������������������������" << endl;
		break;
	}
	default:
		exit(0);
	}
}

void ADMIN::Modify()  //�޸�����
{
	char OP[11];
	int op;
	third:
	system("cls");
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              �޸�ģ�飺" << endl;
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              �����޸�����γ̣�1���´�ҵ�࣬2�Ŀ���ѧ�࣬3����ѧ�ࣩ:" << endl;
	Mouse(30, 4);
	cin.width(1);
	cin >> op;
	Check();
	if (op != 1 && op != 2 && op != 3)
	{
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              ��������������룡" << endl;
		Sleep(2000);
		goto third;
	}
	switch (op)
	{
	case 1:
	{
		system("cls");
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              �����޸ĵĿγ���:" << endl;
		Mouse(30, 2);
		cin.width(11);
		cin >> OP;
		Check();
		j = Search(OP, 1, 't');
		if (j != -1)
		{
			Create cre;
			cre.SetC();
			Cre[j] = cre;
			WriteB(3);
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              �޸ĳɹ����������˵���" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
		else
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              û���ҵ��˿γ̣��������˵�!" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
	}
	case 2:
	{
		system("cls");
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              �����޸ĵĿγ���:" << endl;
		Mouse(30, 2);
		cin.width(11);
		cin >> OP;
		Check();
		j = Search(OP, 2, 't');
		if (j != -1)
		{
			Literate Lit;
			Lit.SetL();
			lit[j] = Lit;
			WriteB(4);
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              �޸ĳɹ����������˵���" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
		else
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              û���ҵ��˿γ̣��������˵�!" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
	}
	case 3:
	{
		system("cls");
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              �����޸ĵĿγ���:" << endl;
		Mouse(30, 2);
		cin.width(11);
		cin >> OP;
		Check();
		j = Search(OP, 3, 't');
		if (j != -1)
		{
			Engineering eng;
			eng.SetE();
			Eng[j] = eng;
			WriteB(5);
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              �޸ĳɹ����������˵���" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
		else
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              û���ҵ��˿γ̣��������˵�!" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
	}
	}
}

void ADMIN::Add() //�������
{
	int op;
forth:
	system("cls");
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ���ģ�飺" << endl;
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              �����������γ̣�1���´�ҵ�࣬2�Ŀ���ѧ�࣬3����ѧ�ࣩ:" << endl;
	Mouse(30, 4);
	cin.width(1);
	cin >> op;
	Check();
	if (op != 1 && op != 2 && op != 3)
	{
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              ��������������룡" << endl;
		Sleep(2000);
		goto forth;
	}
	switch (op)
	{
	case 1:
	{
		int y;
	
		system("cls");
		if (y = CheckCo('1') == -1)
		{
			break;
		}
		else
		{
			j = CheckCo(1);
			Create crea;
			crea.SetC();
			Cre[j] = crea;
			WriteB(3);
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ��ӳɹ���2��󷵻����˵�!" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
	}
	case 2:
	{
		int y;

		system("cls");
		if (y = CheckCo('1') == -1)
		{
			break;
		}
		else
		{
			j = CheckCo(2);
			Literate LIT;
			LIT.SetL();
			lit[j] = LIT;
			WriteB(4);
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ��ӳɹ���2��󷵻����˵�!" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
	}
	case 3:
	{
		int y;

		system("cls");
		if (y = CheckCo('1') == -1)
		{
			break;
		}
		else
		{
			j = CheckCo(3);
			Engineering ENG;
			ENG.SetE();
			Eng[j] = ENG;
			WriteB(5);
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ��ӳɹ���2��󷵻����˵�!" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
	}
	}
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              �ǳ���Ǹ����ǰ�����������������ĵȴ�ϵͳ�Ż���" << endl;
	Sleep(2000);
	this->ADMenu();
}

void ADMIN::Delete() //ɾ������
{
	char OP[11];
	int op;

fifth:
	system("cls");
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ɾ��ģ�飺" << endl;
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ����ɾ������γ̣�1���´�ҵ�࣬2�Ŀ���ѧ�࣬3����ѧ�ࣩ:" << endl;
	Mouse(30, 4);
	cin.width(1);
	cin >> op;
	Check();
	if (op != 1 && op != 2 && op != 3)
	{
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              ��������������룡" << endl;
		Sleep(2000);
		goto fifth;
	}
	switch (op)
	{
	case 1:
	{
		if (strncmp(Cre[0].ExHour, "0", 2) == 0)
		{
			break;
		}
		system("cls");
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              ����ɾ���Ŀγ���:" << endl;
		Mouse(30, 2);
		cin.width(11);
		cin >> OP;
		Check();
		j = Search(OP, 1, 't');
		if (j != -1)
		{
			Create cre;
			Cre[j] = cre;
			WriteB(3);
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ɾ���ɹ����������˵���" << endl;
			Sleep(2000);
			break;
		}
		else
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              û���ҵ��˿γ̣��������˵�!" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
	}
	case 2:
	{
		if (strncmp(lit[4].ExHour, "0", 2) == 0)
		{
			break;
		}
		system("cls");
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              ����ɾ���Ŀγ���:" << endl;
		Mouse(30, 2);
		cin.width(11);
		cin >> OP;
		Check();
		j = Search(OP, 2, 't');
		if (j != -1)
		{
			Literate LIT;
			lit[j] = LIT;
			WriteB(4);
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ɾ���ɹ����������˵���" << endl;
			Sleep(2000);
			break;
		}
		else
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              û���ҵ��˿γ̣��������˵�!" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
	}
	case 3:
	{
		if (strncmp(Eng[4].PrHour, "0", 2) == 0)
		{
			break;
		}
		system("cls");
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              ����ɾ���Ŀγ���:" << endl;
		Mouse(30, 2);
		cin.width(11);
		cin >> OP;
		Check();
		j = Search(OP, 3, 't');
		if(j != -1)
		{
			Engineering ENG;
			Eng[j] = ENG;
			WriteB(5);
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ɾ���ɹ����������˵���" << endl;
			Sleep(2000);
			break;
		}
		else
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              û���ҵ��˿γ̣��������˵�!" << endl;
			Sleep(2000);
			this->ADMenu();
			break;
		}
	}
	}
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              �ǳ���Ǹ����ǰ���ݿ⻹δ��ʼ��������������ݣ�" << endl;
	Sleep(2000);
	this->ADMenu();
}

void  STUDENT::Sear()  //��ѯ��Ϣ
{
	char CName[11];
	int t;
	int flag;

	system("cls");
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              ��ѯģ�飺" << endl;
	cout << "                              ����������������������������������������������������" << endl;
	cout << "                              �����ѯ�Ŀγ�����" << endl;
	Mouse(30, 4);
	cin.width(11);
	cin >> CName;
	Check();
	flag = Search(CName, 'b');
	switch(flag)
	{
	case 1:
	{
		t = Search(CName, 1, 't');
		system("cls");
		Cre[t].Show();
		Sleep(2000);
		fifth:
		char op[3];
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              �Ƿ����ʹ�ñ�ϵͳ������/��:" << endl;
		Mouse(30, 12);
		cin.width(3);
		cin >> op;
		Check();
		if (strcmp(op, "��") == 0)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              2��󷵻�������!" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(2000);
			this->STMenu();
			break;
		}
		else if (strcmp(op, "��") == 0)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              2����˳�ϵͳ!" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(2000);
			exit(0);
		}
		else
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              ��������������������ʾ���룡" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(1000);
			goto fifth;
		}
	}
	case 2:
	{
		t = Search(CName, 2, 't');
		system("cls");
		lit[t].Show();
		Sleep(2000);
		char op[3];
		sixth:
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              �Ƿ����ʹ�ñ�ϵͳ������/��:" << endl;
		Mouse(30, 12);
		cin.width(3);
		cin >> op;
		Check();
		if (strcmp(op, "��") == 0)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              2��󷵻�������!" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(2000);
			this->STMenu();
			break;
		}
		else if (strcmp(op, "��") == 0)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              2����˳�ϵͳ!" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(2000);
			exit(0);
		}
		else
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              �����������������ڵ���ʾ���룡" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(1000);
			goto sixth;
		}
	}
	case 3:
	{
		t = Search(CName, 3, 't');
		system("cls");
		Eng[t].Show();
		Sleep(2000);
		char op[3];
		seventh:
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              �Ƿ����ʹ�ñ�ϵͳ������/��:" << endl;
		Mouse(30, 12);
		cin.width(3);
		cin >> op;
		Check();
		if (strcmp(op, "��") == 0)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              2��󷵻�������!" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(2000);
			this->STMenu();
			break;
		}
		else if (strcmp(op, "��") == 0)
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              2����˳�ϵͳ!" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(2000);
			exit(0);
		}
		else
		{
			cout << "                              ����������������������������������������������������" << endl;
			cout << "                              �����������������ڵ���ʾ���룡" << endl;
			cout << "                              ����������������������������������������������������" << endl;
			Sleep(1000);
			goto seventh;
		}
	}
	default:
	{
		cout << "                              ����������������������������������������������������" << endl;
		cout << "                              �ÿγ̲����ڣ�2��󷵻����˵���" << endl;
		Sleep(2000);
		this->STMenu();
		break;
	}
	}
}

int STUDENT::CheckSTU()
{
	int i;
	int j = 0;

	for (i = 0; i < 10; i++)
	{
		if (strncmp(STU[i].SNumber, "0", 1) == 0)
		{
			j++;
		}
	}
	if (j == 0) return -1;
	else return (10 - j);
}

int ADMIN::CheckAD()
{
	int i;
	int j = 0;

	for (i = 0; i < 10; i++)
	{
		if (strncmp(ADmin[i].Admin, "0", 1) == 0)
		{
			j++;
		}
	}
	if (j == 0) return -1;
	else return (10 - j);
}