#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

enum Types
{
	string = 1, charr, intt, floatt, doublee, booll
};



class Variant
{
	Types var;
	std::string str;

	void FindType(std::string str);
	template <typename T>
	std::string toString(T val);
	template<typename T>
	T fromString(const std::string& s);

public:
	Variant(std::string str);
	Variant(char ch);
	Variant(int num);
	Variant(float num);
	Variant(double num);
	Variant(bool bo);
	void PrintType();
	std::string ToString();
	char ToChar();
	int ToInt();
	float ToFloat();
	double ToDouble();
	bool ToBool();
	void Converse(Types type);

};

