#pragma once
#include "Currency.h"
class Euro :
	public Currency
{
public:
	Euro();
	Euro(double);
	Euro(int,int);
	~Euro();
	Euro& operator + (const Euro & E);
	Euro& operator + (const double & Eu);
	Euro& operator - (const Euro & E);
	Euro& operator - (const double & Eu);
	Euro& operator = (const Euro & E);
	friend ostream& operator<<(ostream& os, const Euro& E);
	friend istream& operator>>(istream& is, const Euro& E);
};

