#include "Ruble.h"


Ruble::Ruble() : Currency("Ruble", "Kopeika", 0, 0)
{
}
Ruble::Ruble(int w, int f):Currency("Ruble", "Kopeika", w, f)
{
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

ostream& operator<<(ostream& os, const Ruble& R)
{
	os << R.whole << " Hryvnia " << R.frac << " Kopeika" << endl;
	return os;
}
istream& operator>>(istream& is, const Ruble& R)
{
	is >> R.whole;
	is >> R.frac;
}