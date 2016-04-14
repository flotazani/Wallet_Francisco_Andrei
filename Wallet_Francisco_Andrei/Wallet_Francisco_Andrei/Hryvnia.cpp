#include "Hryvnia.h"


Hryvnia::Hryvnia() : Currency("Hryvnia", "Kopeika", 0, 0)
{
	//sets default name and values as 0
}
Hryvnia::Hryvnia(int w, int f) : Currency("Hryvnia", "Kopeika", w, f)
{
	//sets passed values and default name
}
Hryvnia::Hryvnia(double x) : Currency("Hryvnia", "Cent", 0, 0)
{
	//separates double and sets it to frac and whole along with name

	int y;
	double z;
	y = x;
	setWhole(y);

	z = 100 * x - 100 * y;
	setFrac(z);

}

Hryvnia::~Hryvnia()
{
}

Hryvnia& Hryvnia::operator + (const Hryvnia & H)
{	//takes frac and whole from right side and adds it to the frac and whole from the left side

	Hryvnia temp;
	temp.whole = this->whole + H.whole;
	temp.frac = this->frac + H.frac;
	if (temp.frac >= 100)
	{
		temp.frac = temp.frac % 100;
		temp.whole = temp.whole + 1;
	}
	return temp;
}
Hryvnia& Hryvnia::operator + (const double & Hr)
{//takes frac and whole from right side, turns it into a double, adds it to the left side, and writes it to the temp class, which it returns
	Hryvnia temp;
	int y, z;
	double x = 0;
	x += this->whole;
	x += (this->frac * 100);

	if (x <= 0 && Hr <= 0)
		x += Hr;
	else
		cout << "invalid operation" << endl;

	y = x;
	temp.setWhole(y);

	z = 100 * x - 100 * y;
	setFrac(z);

	return temp;
}

Hryvnia& Hryvnia::operator - (const Hryvnia & H)
{
	//takes frac and whole from right side and subtracts it from the frac and whole from the left side

	Hryvnia temp;
	temp.whole = this->whole - H.whole;
	temp.frac = this->frac - H.frac;
	if (temp.frac <= 0){ temp.frac = 100 + temp.frac; temp.whole = temp.whole - 1; }
	if (temp.whole <= 0){ temp.whole = 0; cout << "invalid operation/n"; }
	return temp;
}
Hryvnia& Hryvnia::operator - (const double & Hr)
{
	//takes frac and whole from right side, turns it into a double, subtracts the left side from it, and adds it to the temp class, which it returns

	Hryvnia temp;
	int y, z;
	double x = 0;
	x += this->whole;
	x += (this->frac * 100);

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
}
Hryvnia& Hryvnia::operator = (const Hryvnia & H)
{	//sets whatever is on the right to the left by respective value

	this->whole = H.whole;
	this->frac = H.frac;
	return *this;
}

ostream& operator<<(ostream& os, const Hryvnia& H)
{//outputs whole and frac
	os << H.whole << " Hryvnia " << H.frac << " Kopeika" << endl;
	return os;
}
istream& operator>>(istream& is, const Hryvnia& H)
{//sets whole and frac
	is >> H.whole;
	is >> H.frac;
	return is;
}