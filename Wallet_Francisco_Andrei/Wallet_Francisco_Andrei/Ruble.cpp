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
	temp.whole = this->whole + R.whole;
	temp.frac = this->frac + R.frac;
	if (temp.frac >= 100)
	{
		temp.frac = temp.frac % 100;
		temp.whole = temp.whole + 1;
	}
	return temp;
}
Ruble& Ruble::operator + (const double & Ru)
{
	Ruble temp;
	int y, z;
	double x;
	x += this->whole;
	x += (this->frac * 100);

	if (x <= 0 && Ru <= 0)
		x += Ru;
	else
		cout << "invalid operation" << endl;

	y = x;
	temp.setWhole(y);

	z = x - y;
	z *= 100;
	setFrac(z);

	return temp;
}

Ruble& Ruble::operator - (const Ruble & R)
{
	Ruble temp;
	temp.whole = this->whole - R.whole;
	temp.frac = this->frac - R.frac;
	if (temp.frac <= 0){ temp.frac = 100 + temp.frac; temp.whole = temp.whole - 1; }
	if (temp.whole <= 0){ temp.whole = 0; cout << "invalid operation/n"; }
	return temp;
}
Ruble& Ruble::operator - (const double & Ru)
{
	Ruble temp;
	int y, z;
	double x;
	x += this->whole;
	x += (this->frac * 100);

	if (x <= 0 && Ru <= 0)
		x -= Ru;
	else
		cout << "invalid operation" << endl;

	if (x <= 0)
	{
		y = x;
		temp.setWhole(y);

		z = x - y;
		z *= 100;
		setFrac(z);
	}
	else
		cout << "invalid operation" << endl;

	return temp;

}

ostream& operator<<(ostream& os, const Ruble& R)
{
	os << R.whole << " Hryvnia " << R.frac << " Kopeika" << endl;
	return os;
}
istream& operator>>(istream& is, const Ruble& R)
{
	is >> R.whole;
	is >> R.frac;
	return is;
}