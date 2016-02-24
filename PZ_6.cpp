// PZ_6.cpp: определяет точку входа для консольного приложения.
//Программа проверки работы класса длинное байтовое число

#include "stdafx.h"

const int LnNmb = 5;//Число цифр в длинном числе
union u_dgbt {//Объединение для операций с байтами 
	unsigned short dgt;//Расширенная цифра
	unsigned char  hdgt[2];//Младшая (hdgt[0]) и старшая половины цифры
	unsigned char add(unsigned char n) {//Сложение с цифрой
		if (hdgt[1]) {//Если есть перенос,
			hdgt[1] = 0;//то сбрасываем его и
			dgt++;    //увеличиваем расширенную цифру 
		}
		dgt = dgt + n;     //Получаем сумму и перенос
		return hdgt[0];//Сумму возвращаем
	}
	unsigned char sbb(unsigned char n) {//Вычитание цифры
		if (hdgt[1]) {//Если есть заем,
			hdgt[1] = 0;//то сбрасыаем его и
			dgt--;    //уменьшаем расширенную цифру
		}
		dgt = dgt - n;     //Получаем разность и заем
		return hdgt[0];//Возвращаем разность
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
	smm.hdgt[1] = 0; //Сбрасываем в нем заем


	while (i < LnNmb)
	{
		//Для всех цифр числа
		smm.hdgt[0] = Nmb_Dg[i];   //Помещаем в сумматор цифру первого слагаемого
		Tmp = smm.add(Nmb[i]);
		if (smm.hdgt[1] == 1)
			smm.dgt++;// = smm.hdgt[0] + s1[i];//Запись в rz суммы сумматора с цифрой второго слагаемого
		i++;
	}
	return Tmp;
}


Cl_Nmb sbb(Cl_Nmb Nmb) 
{
	Cl_Nmb Tmp;
	u_dgbt smm; //Создаем сумматор на базе объединения
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
	Cl_Nmb Nb1(nmb1);//Конструктор преобразования создает длинное число Nb1 
	Nb1.inc();//Проверяем работу методов увеличения и
	Nb1.dec();//уменьшения на 1. 
	Cl_Nmb Nb2(nmb2);//Создаем число Nb2
	Cl_Nmb Nb3;//Конструктор по умолчанию создает число Nb3
	Nb3 = Nb2;//Встроенный конструктор копирования изменяет число Nb3
	Nb3 = Nb1.add(Nb2);//Проверка сложения и
	Nb3 = Nb3.sbb(Nb2);//вычитания.
	return 0;
}
