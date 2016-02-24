// PZ_4.cpp: определяет точку входа для консольного приложения.
//

//Использование класса wstring 
#include "stdafx.h"
#include <string>
#include <iostream>
#include <locale>//Для переключения шрифтов
using namespace std;

void prt_rus(const wchar_t * str_c) {
	setlocale(LC_ALL, "rus");
	wcout << str_c << endl;
	setlocale(LC_ALL, "rus_rus.866");
}

int _tmain(int argc, _TCHAR* argv[]) {
	wstring фмл(argv[1]);
	wstring имя(L"Илья");
	wstring отч;
	wstring фио;
	prt_rus(L"Введите отчество");
	wcin >> отч;
	wcout <<L"Введенное отчество :" << отч << endl;
	фио = фмл + имя + отч;
	wstring sps(L" ");  
	фио = фмл + sps + имя + sps + отч;	 
	int ln = фио.length();
	wcout << L"Строка \"" << фио << L"\" имеет длину-" << ln << L" символов." << L"\n";
	wstring мин;
	if ((фмл < имя) || (фмл < отч))
	{
		мин = фмл;
	}
	else if ((имя < фмл) || (отч < фмл))
	{
		мин = имя;
	}
	else if ((отч < фмл) || (отч < имя))
	{
		мин = отч;
	}
	wcout << L"Минимальная строка: " << мин << L"\n";
	wstring ФИО;
	ФИО = фмл[0];
	ФИО = ФИО + имя[0];
	ФИО = ФИО + отч[0];
	        
	wcout << L"Сокращение ФИО: " << ФИО << L"\n";
	return 0;
}
