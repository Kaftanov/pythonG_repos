#include "stdafx.h"
#include <iostream>

using namespace std;

void prt_rus(char* str)
{
	setlocale(LC_ALL, "rus");//Установка кодовой таблицы для вывода строк
	cout << str << endl;
	setlocale(LC_ALL, "rus_rus.866");//Установка таблици кодирования для символов
}
int _tmain(int argc, _TCHAR* argv[]) {
	int s = 0;
	int i = 0, j = 0, k = 0;
	prt_rus("Введите строку символов:");
	cout << hex << showbase;               //Установка формата вывода целых чисел
	while (1)
	{
		s = cin.get();
		if (s == 0x0A)
		{
			break;
		}
		else
		j = i + s;
		i = s;
		cout << "int s = " << s << endl << "char s = " << (char)s << endl;
		k++;
	}
	cout << "summa= " << j << endl;
	i = 0;
	i = j / k;
	cout << "middle el = " << i << endl;
	return 0;
}


