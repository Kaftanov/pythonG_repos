// PZ_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <locale>
#include <windows.h>
using namespace std;

const int s_end = VK_TAB;//Код конца ввода

void prt_rus(char* str)
{
	setlocale(LC_ALL, "rus");
	printf(str);
	setlocale(LC_ALL, "rus_rus.866");
}

int _tmain(int argc, _TCHAR* argv[])
{
	prt_rus("Для получения кодов нажимайте кнопки до Enter\n");
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
	prt_rus("\nЗавершаем печать кодов нажатых кнопок\n");
	printf("maximum =%c-%X%c  \n", j, j, ' ');
	return 0;
}

