#pragma once
#include "Currency.h"
class Ruble :
	public Currency <Ruble>
{
public:
	Ruble();
	Ruble(double);
	Ruble(int,int);
	~Ruble();
	Ruble& operator + (const Ruble & R);
	Ruble& operator + (const double & Ru);
	Ruble& operator - (const Ruble & R);
	Ruble& operator - (const double & Ru);
	friend ostream& operator<<(ostream& os, const Ruble& R);
	friend ostream& operator>>(ostream& os, const Ruble& R);
};

