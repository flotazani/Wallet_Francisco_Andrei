#include "Ruble.h"


Ruble::Ruble() : Currency("Ruble", "Kopeika", 0, 0)
{
}
Ruble::Ruble(int w, int f):Currency("Ruble", "Kopeika", w, f)
{
}

Ruble::Ruble(double x) : Currency("Ruble", "Cent", 0, 0)
{
	int y;
	double z;
	y = x;
	setWhole(y);

	z = x - y;
	z *= 100;
	setFrac(z);

}

Ruble::~Ruble()
{
}

Ruble& Ruble::operator + (const Ruble & R)
{
	Ruble temp;
	temp.whole = whole + R.whole;
	temp.frac = frac + R.frac;
	if (temp.frac >= 100)
	{
		temp.frac = temp.frac % 100;
		temp.whole = temp.whole + 1;
	}
	return temp;
}

Ruble& Ruble::operator + (const double & Ru){}

Ruble& Ruble::operator - (const Ruble & R)
{
	Ruble temp;
	temp.whole = temp.whole - R.whole;
	temp.frac = temp.frac - R.frac;
	if (temp.frac <= 0){ temp.frac = 100 + temp.frac; temp.whole = temp.whole - 1; }
	if (temp.whole <= 0){ temp.whole = 0; cout << "invalid operation/n"; }
	return temp;
}
Ruble& Ruble::operator - (const double & Ru){}