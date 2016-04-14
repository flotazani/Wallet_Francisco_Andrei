#include "Euro.h"


Euro::Euro() : Currency("Euro", "Cent", 0, 0)
{
	//sets default name and values as 0

}

Euro::Euro(int w, int f) : Currency("Euro", "Cent", w, f)
{
	//sets passed values and default name

}
Euro::Euro(double x) : Currency("Euro", "Cent", 0, 0)
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

Euro::~Euro()
{
}

Euro& Euro::operator + (const Euro & E)
{	//takes frac and whole from right side and adds it to the frac and whole from the left side

	Euro temp;
	temp.whole = this->whole + E.whole;
	temp.frac = this->frac + E.frac;
	if (temp.frac >= 100)
	{
		temp.frac = temp.frac % 100;
		temp.whole = temp.whole + 1;
	}
	return temp;
}
Euro& Euro::operator + (const double & Eu)
{//takes frac and whole from right side, turns it into a double, adds it to the left side, and writes it to the temp class, which it returns
	Euro temp;
	int y, z;
	double x = 0;
	x += this->whole;
	x += (this->frac * 100);

	if (x <= 0 && Eu <= 0)
		x += Eu;
	else
		cout << "invalid operation" << endl;

	y = x;
	temp.setWhole(y);

	z = 100 * x - 100 * y;
	setFrac(z);

	return temp;
}

Euro& Euro::operator - (const Euro & E)
{	//takes frac and whole from right side and subtracts it from the frac and whole from the left side

	Euro temp;
	temp.whole = this->whole - E.whole;
	temp.frac = this->frac - E.frac;
	if (temp.frac <= 0){ temp.frac = 100 + temp.frac; temp.whole = temp.whole - 1; }
	if (temp.whole <= 0){ temp.whole = 0; cout << "invalid operation/n"; }
	return temp;
}
Euro& Euro::operator - (const double & Eu)
{
	//takes frac and whole from right side, turns it into a double, subtracts the left side from it, and adds it to the temp class, which it returns

	Euro temp;
	int y, z;
	double x = 0;
	x += this->whole;
	x += (this->frac * 100);

	if (x <= 0 && Eu <= 0)
		x -= Eu;
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

Euro& Euro::operator = (const Euro & E)
{	//sets whatever is on the right to the left by respective value

	this->whole = E.whole;
	this->frac = E.frac;
	return *this;
}

ostream& operator<<(ostream& os, const Euro& E)
{//outputs whole and frac
	os << E.whole << " Euro " << E.frac << " Cents" << endl;
	return os;
}
istream& operator>>(istream& is, const Euro& E)
{//sets whole and frac
	is >> E.whole;
	is >> E.frac;
	return is;
}