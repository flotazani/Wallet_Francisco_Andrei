#include "Franc.h"


Franc::Franc() : Currency("Franc", "Cent", 0, 0)// cent???
{
}
Franc::Franc(int w, int f) : Currency("Franc", "Cent", w, f)
{
}
Franc::Franc(double x)
{
	int y;
	double z;
	y = x;
	setWhole(y);

	z = x - y;

	z *=100;
	setFrac(z);

}

Franc::~Franc()
{
}

Franc& Franc::operator + (const Franc & F)
{
	Franc temp;
	temp.whole = whole + F.whole;
	temp.frac = frac + F.frac;
	if (temp.frac >= 100)
	{
		temp.frac = temp.frac % 100;
		temp.whole = temp.whole + 1;
	}
	return temp;
}

Franc& Franc::operator + (const double & Fr){}

Franc& Franc::operator - (const Franc & F)
{
	Franc temp;
	temp.whole = temp.whole - F.whole;
	temp.frac = temp.frac - F.frac;
	if (temp.frac <= 0){ temp.frac = 100 + temp.frac; temp.whole = temp.whole - 1; }
	if (temp.whole <= 0){ temp.whole = 0; cout << "invalid operation/n"; }
	return temp;
}

Franc& Franc::operator - (const double & Fr){}

ostream& operator<<(ostream& os, const Franc& F)
{
	os << F.whole << " Franc " << F.frac << " Rappen" << endl;
	return os;
}
istream& operator>>(istream& is, const Franc& F)
{
	is >> F.whole;
	is >> F.frac;
}