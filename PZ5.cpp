// PZ_5.cpp: ���������� ����� ����� ��� ����������� ����������.
//

// PZ5.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include <iostream>
using namespace std;

union u_dgbt {//����������� ��� �������� � ������� 
	unsigned short dgt;//����������� �����
	unsigned char  hdgt[2];//������� (hdgt[0]) � ������� �������� �����

	unsigned char add(unsigned char n) {//�������� � ������ n
		if (hdgt[1])
		{//���� ���� �������,��
			hdgt[1] = 0; //���������� ��� �
			dgt++;//����������� ����� ������� ����������
		}
		dgt = dgt + n;//��������� ����� � ��������
		return hdgt[0];//���������� ����� �����
	}

	unsigned char sbb(const unsigned char n) {//��������� ����� n
		if (hdgt[1]) {//���� ���� ����,��
			hdgt[1] = 0;//���������� ��� �
			dgt--;//��������� �� 1 �����������.
		}
		dgt = dgt - n;//�������� ���������� �
		return hdgt[0];//���������� ����� ��������
	}
};

void inc(unsigned char* nmb, int ln) {//���������� ����� nmb �� 1
	u_dgbt smm;//������� �������� �� ���� �����������
	smm.hdgt[1] = 1;//������������� � ��� �������
	int i = 0;//����� �������� ����
	while ((smm.hdgt[1] == 1) && i<ln) {//��� ���� ���� ����� ���� ���� ������� � ���������
		smm.hdgt[1] = 0;//���������� ������� � ���������
		smm.hdgt[0] = nmb[i];//���������� � �������� �����
		smm.dgt++;//����������� �����
		nmb[i] = smm.hdgt[0];//��������� ����������� �����
		i++;//���������� ��������� �����
	}
}

void dec(unsigned char* nmb, int ln)
{                                        //���������� ����� nmb �� 1
	u_dgbt sub;								    //������� �������� �� ���� ����������� (subtraction)
	sub.hdgt[1] = 1;							   	   //������������� � ��� ����
	int c = 0;                                           //����� �������� ����
	while ((sub.hdgt[1] != 0) && c < ln)
	{                                //��� ���� ���� ����� ���� ���� ���� � ���������
		sub.hdgt[1] = 0;                               //���������� ���� � ���������
		sub.hdgt[0] = nmb[c];                           //���������� � �������� �����
		sub.dgt--;                          //��������� ����������� ����� �� 1
		nmb[c] = sub.hdgt[0];                         //��������� ���������� �����
		c++;                        //���������� ��������� �����
	}
}

void add_n(unsigned char* s1, unsigned char* s2, unsigned char* rz, int ln)
{
	u_dgbt smm;	  //������� �������� �� ���� �����������
	int i = 0;
	smm.hdgt[1] = 0; //���������� � ��� ����


	while (i < ln)
	{
		//��� ���� ���� �����
		smm.hdgt[0] = s1[i];   //�������� � �������� ����� ������� ����������
		rz[i] = smm.add(s2[i]);
		if (smm.hdgt[1] == 1)
			smm.dgt++;// = smm.hdgt[0] + s1[i];//������ � rz ����� ��������� � ������ ������� ����������
		i++;
	}
}

void sbb_n(unsigned char* s1, unsigned char* s2, unsigned char* rz, int ln)
{
	u_dgbt smm; //������� �������� �� ���� �����������
	int i = 0;
	int j = 0;
	smm.hdgt[1] = 0;
	while (i < ln)
	{
		smm.hdgt[0] = s1[i];
		rz[i] = smm.sbb(s2[i]);
		if (smm.hdgt[1] == 0xFF)
			smm.dgt--;

		i++;
	}
}

int _tmain(int argc, _TCHAR* argv[]) {
	u_dgbt d1;//���������� ������ �����
	d1.dgt = 5;//����������� �������� ������ �����
	cout << "d1=" << d1.dgt << endl;//������ �������� d1
	d1.add(251);//��������� � d2=d1+255 ����� d1 � ������ 255
	cout << "d1+255=" << d1.dgt << endl;//������ ����������� ����������
	d1.sbb(251);//������� �� d1 255
	cout << "d1-255=" << d1.dgt << endl;//������ ����������� ����������
										//�������� � �������� ������� ���������� �������� ����� �� 1
	unsigned char nmb1[5] = { 0xFF,0xFF,1,0,0 };
	inc(nmb1, 5);
	dec(nmb1, 5);
	unsigned char nmb2[5] = { 1,1,1,0,0 };
	unsigned char rez[5];
	add_n(nmb2, nmb1, rez, 5);
	sbb_n(rez, nmb2, rez, 5);
	return 0;
}
