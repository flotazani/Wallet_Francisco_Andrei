#include "Hryvnia.h"


Hryvnia::Hryvnia() : Currency("Hryvnia", "Kopeika", 0, 0)
{
}
Hryvnia::Hryvnia(int w, int f) : Currency("Hryvnia", "Kopeika", w, f)
{
}

Hryvnia::~Hryvnia()
{
}

Hryvnia& Hryvnia::operator + (const Hryvnia & H)
{
	Hryvnia temp;
	temp.whole = whole + H.whole;
	temp.frac = frac + H.frac;
	if (temp.frac >= 100)
	{
		temp.frac = temp.frac % 100;
		temp.whole = temp.whole + 1;
	}
	return temp;
}

Hryvnia& Hryvnia::operator + (const double & Hr){}

Hryvnia& Hryvnia::operator - (const Hryvnia & H)
{
	Hryvnia temp;
	temp.whole = temp.whole - H.whole;
	temp.frac = temp.frac - H.frac;
	if (temp.frac <= 0){ temp.frac = 100 + temp.frac; temp.whole = temp.whole - 1; }
	if (temp.whole <= 0){ temp.whole = 0; cout << "invalid operation/n"; }
	return temp;
}

Hryvnia& Hryvnia::operator - (const double & Hr){}
ostream& operator<<(ostream& os, const Hryvnia& H)
{
	os << H.whole << " Hryvnia " << H.frac << " Kopeika" << endl;
	return os;
}
istream& operator>>(istream& is, const Hryvnia& H)
{
	is >> H.whole;
	is >> H.frac;
}