#include "Ruble.h"


Ruble::Ruble() : Currency("Ruble", "Kopeika", 0, 0)
{
	//sets default name and values as 0

}

Ruble::Ruble(int w, int f):Currency("Ruble", "Kopeika", w, f)
{
	//sets passed values and default name

}
Ruble::Ruble(double x) : Currency("Ruble", "Cent", 0, 0)
{
	//separates double and sets it to frac and whole along with name

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
{	//takes frac and whole from right side and adds it to the frac and whole from the left side

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
{//takes frac and whole from right side, turns it into a double, adds it to the left side, and writes it to the temp class, which it returns
	Ruble temp;
	int y, z;
	double x = 0;
	x += this->whole;
	x += (this->frac * 100);

	if (x <= 0 && Ru <= 0)
		x += Ru;
	else
		cout << "invalid operation" << endl;

	y = x;
	temp.setWhole(y);

	z = 100 * x - 100 * y;
	setFrac(z);

	return temp;
}

Ruble& Ruble::operator - (const Ruble & R)
{	//takes frac and whole from right side and subtracts it from the frac and whole from the left side

	Ruble temp;
	temp.whole = this->whole - R.whole;
	temp.frac = this->frac - R.frac;
	if (temp.frac <= 0){ temp.frac = 100 + temp.frac; temp.whole = temp.whole - 1; }
	if (temp.whole <= 0){ temp.whole = 0; cout << "invalid operation/n"; }
	return temp;
}
Ruble& Ruble::operator - (const double & Ru)
{
	//takes frac and whole from right side, turns it into a double, subtracts the left side from it, and adds it to the temp class, which it returns

	Ruble temp;
	int y, z;
	double x = 0;
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

		z = 100 * x - 100 * y;
		setFrac(z);
	}
	else
		cout << "invalid operation" << endl;

	return temp;

}
Ruble& Ruble::operator = (const Ruble & R)
{	//sets whatever is on the right to the left by respective value

	this->whole = R.whole;
	this->frac = R.frac;
	return *this;
}

ostream& operator<<(ostream& os, const Ruble& R)
{//outputs whole and frac
	os << R.whole << " Hryvnia " << R.frac << " Kopeika" << endl;
	return os;
}
istream& operator>>(istream& is, const Ruble& R)
{//sets whole and frac
	is >> R.whole;
	is >> R.frac;
	return is;
}