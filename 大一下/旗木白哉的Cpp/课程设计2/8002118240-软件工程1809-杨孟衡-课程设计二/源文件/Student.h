#pragma once
#include<string.h>
using namespace std;

class STUDENT
{
private:
	char SNumber[11];  //ѧ���˺�
	char SName[11];  //ѧ������
	char STPa[11];  //����
	char SP[12];  //ѧ���绰
	int CNum;  //ѡ�޿γ���
	double OS;  //ѡ�޿γ̵�ѧ��
	char AC[4][11];  //��ѡ�γ̶�ά����
public:
	STUDENT();
	~STUDENT();
	void STMenu(); //ѧ�����˵�
	void SetSTU();  //��ʼ��ѧ�����Ա
	friend int CheckPAPAS(char * Crea, char * c1);  
	friend int Search(char * Crea);
	void Option();  //ѡ��
	void Reference(int a);  //������ݣ�a=1��ʾ��ѡ�γ���Ϣ��a=2��ʾ������Ϣ
	void Drop();  //�˿�
	void Sear();  //��ѯ��Ϣ
	static int CheckSTU(); //���ѧ���˺������Ƿ�����,û�����򷵻ض�Ӧ����
};