// PZ_4.cpp: ���������� ����� ����� ��� ����������� ����������.
//

//������������� ������ wstring 
#include "stdafx.h"
#include <string>
#include <iostream>
#include <locale>//��� ������������ �������
using namespace std;

void prt_rus(const wchar_t * str_c) {
	setlocale(LC_ALL, "rus");
	wcout << str_c << endl;
	setlocale(LC_ALL, "rus_rus.866");
}

int _tmain(int argc, _TCHAR* argv[]) {
	wstring ���(argv[1]);
	wstring ���(L"����");
	wstring ���;
	wstring ���;
	prt_rus(L"������� ��������");
	wcin >> ���;
	wcout <<L"��������� �������� :" << ��� << endl;
	��� = ��� + ��� + ���;
	wstring sps(L" ");  
	��� = ��� + sps + ��� + sps + ���;	 
	int ln = ���.length();
	wcout << L"������ \"" << ��� << L"\" ����� �����-" << ln << L" ��������." << L"\n";
	wstring ���;
	if ((��� < ���) || (��� < ���))
	{
		��� = ���;
	}
	else if ((��� < ���) || (��� < ���))
	{
		��� = ���;
	}
	else if ((��� < ���) || (��� < ���))
	{
		��� = ���;
	}
	wcout << L"����������� ������: " << ��� << L"\n";
	wstring ���;
	��� = ���[0];
	��� = ��� + ���[0];
	��� = ��� + ���[0];
	        
	wcout << L"���������� ���: " << ��� << L"\n";
	return 0;
}
