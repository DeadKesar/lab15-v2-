#pragma once
#include "Variant.h"

int GetNumber(std::string s);

int main()
{
    
	setlocale(LC_ALL, "Russian");
	std::cout << "лабораторная..." << std::endl;
	std::string base;
	std::cout << "Введите значение:" << std::endl;
	std::getline(std::cin, base); // получаем значение
	Variant answ(base);
	std::cout << std::endl;
	std::cout << "Вы ввели:" << std::endl;
	answ.PrintType();
	std::cout << std::endl;
	int conv = 0;
	while (conv < 1 || conv>6)
		conv = GetNumber("к какому типу привести?\n 1 - string, 2 - char, 3 - int, 4 - float, 5 - double, 6 - bool\n");
	answ.Converse((Types)conv);
	std::cout << std::endl << answ.ToString() << std::endl;
	answ.PrintType();
}


int GetNumber(std::string s)
{
	int num;
	while (true)
	{
		std::cout << s;
		std::cin >> num;
		if (std::cin.fail()) //проверяем, не заблокирован ли буфер ввода, если да, значит значения ввода было некоректным.
		{
			std::cin.clear(); //возвращаем буфер в обычный режим
			std::cin.ignore(32767, '\n'); // очищаем буфер ввода
			std::cout << "некоректное значение, попробуйте снова" << std::endl; //просим повторный ввод
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очищаем буфер ввода от лишних символов, если таковые есть
			return num; // выходим из функции.
		}
	}
}