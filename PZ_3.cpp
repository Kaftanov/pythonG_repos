// PZ_3.cpp: ���������� ����� ����� ��� ����������� ����������.
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

	cout << "������� ���: " << endl;
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
		cout << "1 - �������� � ����" << endl << "2 - ������� ���������� �����" << endl << "3 - �����" << endl;
		if (ch == '1')
		{
			cout << "��� = " << fio << endl;
		}
		else if (ch == '2')
		{
			cout << "������ �� ����� = " << buf << endl;
		}
		
		ch = getchar();
		cout << endl;
	}
	
	
		
	    
	return 0;
}
