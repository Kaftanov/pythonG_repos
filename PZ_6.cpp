// PZ_6.cpp: ���������� ����� ����� ��� ����������� ����������.
//��������� �������� ������ ������ ������� �������� �����

#include "stdafx.h"

const int LnNmb = 5;//����� ���� � ������� �����
union u_dgbt {//����������� ��� �������� � ������� 
	unsigned short dgt;//����������� �����
	unsigned char  hdgt[2];//������� (hdgt[0]) � ������� �������� �����
	unsigned char add(unsigned char n) {//�������� � ������
		if (hdgt[1]) {//���� ���� �������,
			hdgt[1] = 0;//�� ���������� ��� �
			dgt++;    //����������� ����������� ����� 
		}
		dgt = dgt + n;     //�������� ����� � �������
		return hdgt[0];//����� ����������
	}
	unsigned char sbb(unsigned char n) {//��������� �����
		if (hdgt[1]) {//���� ���� ����,
			hdgt[1] = 0;//�� ��������� ��� �
			dgt--;    //��������� ����������� �����
		}
		dgt = dgt - n;     //�������� �������� � ����
		return hdgt[0];//���������� ��������
	}
};


class Cl_Nmb 
{
	unsigned char Nmb_Dg[LnNmb];
	void clr() 
	{
		for (int i = 0; i<LnNmb; i++) Nmb_Dg[i] = 0;
	}
public:
	Cl_Nmb() 
	{
		clr();
	}
	Cl_Nmb(unsigned char* Nmb) 
	{
		for (int i = 0; i < LnNmb; i++)
			 Nmb_Dg[i] = Nmb[i];
	}

	void inc() 
	{
		u_dgbt smm;
		smm.hdgt[1] = 1;
		int i = 0;
		while ((smm.hdgt[1]) && i<LnNmb) 
		{
			smm.hdgt[1] = 0;
			smm.hdgt[0] = Nmb_Dg[i];
			smm.dgt++;
			Nmb_Dg[i] = smm.hdgt[0];
			i++;
		}
	}

	void dec() 
	{
		u_dgbt sub;								   
		sub.hdgt[1] = 1;							   	   
		int c = 0;                                           
		while ((sub.hdgt[1] != 0) && c < LnNmb);
		{                               
			sub.hdgt[1] = 0;                             
			sub.hdgt[0] = Nmb_Dg[c];                           
			sub.dgt--;                         
			Nmb_Dg[c] = sub.hdgt[0];                       
			c++;                       
		}
	}
Cl_Nmb add(Cl_Nmb Nmb)
{
	Cl_Nmb Tmp;
	u_dgbt smm; 
	int i = 0;
	smm.hdgt[1] = 0; //���������� � ��� ����


	while (i < LnNmb)
	{
		//��� ���� ���� �����
		smm.hdgt[0] = Nmb_Dg[i];   //�������� � �������� ����� ������� ����������
		Tmp = smm.add(Nmb[i]);
		if (smm.hdgt[1] == 1)
			smm.dgt++;// = smm.hdgt[0] + s1[i];//������ � rz ����� ��������� � ������ ������� ����������
		i++;
	}
	return Tmp;
}


Cl_Nmb sbb(Cl_Nmb Nmb) 
{
	Cl_Nmb Tmp;
	u_dgbt smm; //������� �������� �� ���� �����������
	int i = 0;
	smm.hdgt[1] = 0;
	while (i < LnNmb)
	{
		smm.hdgt[0] = Nmb_Dg[i];
		Tmp = smm.sbb(Nmb);
		if (smm.hdgt[1] == 0xFF)
			smm.dgt--;

		i++;
	}
	return Tmp;
}

};

int _tmain(int argc, _TCHAR* argv[]) {
	unsigned char nmb1[5] = { 0xFF,0xFF,1,0,0 };
	unsigned char nmb2[5] = { 1,1,1,0,0 };
	Cl_Nmb Nb1(nmb1);//����������� �������������� ������� ������� ����� Nb1 
	Nb1.inc();//��������� ������ ������� ���������� �
	Nb1.dec();//���������� �� 1. 
	Cl_Nmb Nb2(nmb2);//������� ����� Nb2
	Cl_Nmb Nb3;//����������� �� ��������� ������� ����� Nb3
	Nb3 = Nb2;//���������� ����������� ����������� �������� ����� Nb3
	Nb3 = Nb1.add(Nb2);//�������� �������� �
	Nb3 = Nb3.sbb(Nb2);//���������.
	return 0;
}
