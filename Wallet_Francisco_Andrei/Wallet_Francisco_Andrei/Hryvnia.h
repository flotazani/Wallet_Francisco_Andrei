#pragma once
#include "Currency.h"
class Hryvnia :
	public Currency
{
public:
	Hryvnia();
	Hryvnia(double);
	Hryvnia(int,int);
	~Hryvnia();
	Hryvnia& operator + (const Hryvnia & H);
	Hryvnia& operator + (const double & Hr);
	Hryvnia& operator - (const Hryvnia & H);
	Hryvnia& operator - (const double & Hr);
	friend ostream& operator<<(ostream& os, const Hryvnia& H);
	friend ostream& operator>>(ostream& os, const Hryvnia& H);
};
 

