#include "Hryvnia.h"


Hryvnia::Hryvnia() : Currency("Hryvnia", "Kopeika", 0, 0)
{
}
Hryvnia::Hryvnia(int w, int f) : Currency("Hryvnia", "Kopeika", w, f)
{
}

Hryvnia::Hryvnia(double x) : Currency("Hryvnia", "Cent", 0, 0)
{
	int y;
	double z;
	y = x;
	setWhole(y);

	z = x - y;
	z *= 100;
	setFrac(z);

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

Hryvnia& Hryvnia::operator + (const double & Hr)
{
	Hryvnia temp;
	int y, z;
	double x;
	x += whole;
	x += (frac * 100);

	if (x <= 0 && Hr <= 0)
		x += Hr;
	else
		cout << "invalid operation" << endl;

	y = x;
	temp.setWhole(y);

	z = x - y;
	z *= 100;
	setFrac(z);

	return temp;
}

Hryvnia& Hryvnia::operator - (const Hryvnia & H)
{
	Hryvnia temp;
	temp.whole = temp.whole - H.whole;
	temp.frac = temp.frac - H.frac;
	if (temp.frac <= 0){ temp.frac = 100 + temp.frac; temp.whole = temp.whole - 1; }
	if (temp.whole <= 0){ temp.whole = 0; cout << "invalid operation/n"; }
	return temp;
}

Hryvnia& Hryvnia::operator - (const double & Hr)
{
	Hryvnia temp;
	int y, z;
	double x;
	x += whole;
	x += (frac * 100);

	if (x <= 0 && Hr <= 0)
		x -= Hr;
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