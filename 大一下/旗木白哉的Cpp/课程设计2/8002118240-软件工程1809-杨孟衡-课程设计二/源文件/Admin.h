#pragma once
#include<string.h>
using namespace std;

class ADMIN
{
private:
	char Admin[11];  //��ʦ�˺�
	char ADP[11];  //����
public:
	static char ADPS[9];  //ע������
	ADMIN();
	~ADMIN();
	void ADMenu();
	bool CheckADPS(char * c);  //���ע������
	friend int CheckPAPAS(char * Crea, char * c1, int a); 
	friend int Search(char * Crea, int b);
	void SetAD();  //��ʼ����ʦ���Ա
	void Modify();  //�޸�����
	void Add(); //�������
	void Delete(); //ɾ������
	void Reference(int a);  //����γ���Ϣ,a=1��ʾ�γ���Ϣ,a=2��ʾ������Ϣ
	static int CheckAD(); //�����ʦ�����Ƿ�����
};