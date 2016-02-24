// PZ_3.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	char fio[100];
	char buf[100];
	int ch = 0;

	cout << "Введите ФИО: " << endl;
	cin.getline(fio, 99, '\n');

	if (argv[1] == NULL)
	{
		cerr << "filename is empty" << endl;
		return 1;
	}
	else
	{
		ofstream file(argv[1]);
		if (!file)
		{
			cout << " can't open the file" << endl;
			return 1;
		}
		file << fio;
		file.close();
	}

	   ifstream file(argv[1]);
	   if (!file)
	   {
			cerr << " can't open the file" << endl;
			return 1;
	   }
	   file.getline(buf, 50);
	   file.close();

	while (ch != '3')
	{
		cout << "1 - Записать в файл" << endl << "2 - Вывести содержимое файла" << endl << "3 - Выход" << endl;
		if (ch == '1')
		{
			cout << "ФИО = " << fio << endl;
		}
		else if (ch == '2')
		{
			cout << "Выводд из файла = " << buf << endl;
		}
		
		ch = getchar();
		cout << endl;
	}
	
	
		
	    
	return 0;
}
