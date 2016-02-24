// PZ_5.cpp: определяет точку входа для консольного приложения.
//

// PZ5.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
using namespace std;

union u_dgbt {//Объединение для операций с байтами 
	unsigned short dgt;//Расширенная цифра
	unsigned char  hdgt[2];//Младшая (hdgt[0]) и старшая половины цифры

	unsigned char add(unsigned char n) {//Сложение с байтом n
		if (hdgt[1])
		{//Если есть перенос,то
			hdgt[1] = 0; //сбрасываем его и
			dgt++;//увеличиваем цифру первого слагаемого
		}
		dgt = dgt + n;//Получение суммы и переноса
		return hdgt[0];//Возвращаем цифру суммы
	}

	unsigned char sbb(const unsigned char n) {//Вычитание байта n
		if (hdgt[1]) {//Если есть заем,то
			hdgt[1] = 0;//сбрасываем его и
			dgt--;//уменьшаем на 1 уменьшаемое.
		}
		dgt = dgt - n;//Вычитаем вычитаемое и
		return hdgt[0];//возвращаем цифру разности
	}
};

void inc(unsigned char* nmb, int ln) {//Увеличение числа nmb на 1
	u_dgbt smm;//Создаем сумматор на базе объединения
	smm.hdgt[1] = 1;//Устанавливаем в нем перенос
	int i = 0;//Сброс счетчика цифр
	while ((smm.hdgt[1] == 1) && i<ln) {//Для всех цифр числа пока есть перенос в сумматоре
		smm.hdgt[1] = 0;//Сбрасываем перенос в сумматоре
		smm.hdgt[0] = nmb[i];//Записываем в сумматор цифру
		smm.dgt++;//Увеличиваем цифру
		nmb[i] = smm.hdgt[0];//Сохраняем увеличенную цифру
		i++;//Продвигаем указатель цифры
	}
}

void dec(unsigned char* nmb, int ln)
{                                        //Уменьшение числа nmb на 1
	u_dgbt sub;								    //Создаем сумматор на базе объединения (subtraction)
	sub.hdgt[1] = 1;							   	   //Устанавливаем в нем заем
	int c = 0;                                           //Сброс счетчика цифр
	while ((sub.hdgt[1] != 0) && c < ln)
	{                                //Для всех цифр числа пока есть заем в сумматоре
		sub.hdgt[1] = 0;                               //Сбрасываем заем в сумматоре
		sub.hdgt[0] = nmb[c];                           //Записываем в сумматор цифру
		sub.dgt--;                          //Уменьшаем расширенную цифру на 1
		nmb[c] = sub.hdgt[0];                         //Сохраняем полученную цифру
		c++;                        //Продвигаем указатель цифры
	}
}

void add_n(unsigned char* s1, unsigned char* s2, unsigned char* rz, int ln)
{
	u_dgbt smm;	  //Создаем сумматор на базе объединения
	int i = 0;
	smm.hdgt[1] = 0; //Сбрасываем в нем заем


	while (i < ln)
	{
		//Для всех цифр числа
		smm.hdgt[0] = s1[i];   //Помещаем в сумматор цифру первого слагаемого
		rz[i] = smm.add(s2[i]);
		if (smm.hdgt[1] == 1)
			smm.dgt++;// = smm.hdgt[0] + s1[i];//Запись в rz суммы сумматора с цифрой второго слагаемого
		i++;
	}
}

void sbb_n(unsigned char* s1, unsigned char* s2, unsigned char* rz, int ln)
{
	u_dgbt smm; //Создаем сумматор на базе объединения
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
	u_dgbt d1;//Объявление первой цифры
	d1.dgt = 5;//Определение значения первой цифры
	cout << "d1=" << d1.dgt << endl;//Печать значения d1
	d1.add(251);//Получение в d2=d1+255 суммы d1 с цифрой 255
	cout << "d1+255=" << d1.dgt << endl;//Печать полученного результата
	d1.sbb(251);//Вычесть из d1 255
	cout << "d1-255=" << d1.dgt << endl;//Печать полученного результата
										//Написать и отладить функцию уменьшения длинного числа на 1
	unsigned char nmb1[5] = { 0xFF,0xFF,1,0,0 };
	inc(nmb1, 5);
	dec(nmb1, 5);
	unsigned char nmb2[5] = { 1,1,1,0,0 };
	unsigned char rez[5];
	add_n(nmb2, nmb1, rez, 5);
	sbb_n(rez, nmb2, rez, 5);
	return 0;
}
