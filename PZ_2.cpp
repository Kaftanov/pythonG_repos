// PZ_2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <locale>
#include <windows.h>
using namespace std;

const int s_end = VK_TAB;//��� ����� �����

void prt_rus(char* str)
{
	setlocale(LC_ALL, "rus");
	printf(str);
	setlocale(LC_ALL, "rus_rus.866");
}

int _tmain(int argc, _TCHAR* argv[])
{
	prt_rus("��� ��������� ����� ��������� ������ �� Enter\n");
	int s;
	int i = 0;
	int j = 0;

	while ((s = _getch()) != s_end)
	{ 
		if (s == VK_RETURN)
		{
			printf("\n");
		}
		else
		printf("%c-%X%c ", s, s, ' ');
		
		i = s;
		if (j < i)
		{
			j = i;
			
		}
	}
	prt_rus("\n��������� ������ ����� ������� ������\n");
	printf("maximum =%c-%X%c  \n", j, j, ' ');
	return 0;
}

