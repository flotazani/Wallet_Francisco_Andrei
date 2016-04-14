#include "Dollar.h"


Dollar::Dollar() : Currency("Dollar","Cent",0 , 0)
{
}

Dollar::Dollar(int w, int f ) : Currency("Dollar", "Cent", w, f)
{
	
}

Dollar::Dollar(double x) : Currency("Dollar", "Cent", 0, 0)
{
	int y;
	double z;
	y = x;
	setWhole(y);

	z = x - y;
	z *= 100;
	setFrac(z);

}

Dollar::~Dollar()
{
}

Dollar& Dollar::operator+(const Dollar &D) 
{
	Dollar temp;
	temp.whole = this->whole + D.whole;
	temp.frac = this->frac + D.frac;
	if (temp.frac >= 100)
	{
		temp.frac = temp.frac % 100;
		temp.whole = temp.whole + 1;
	}
	return temp;
}
Dollar& Dollar::operator + (const double & Do)
{
	Dollar temp;
	int y, z;
	double x = 0;
	x += this->whole;
	x += (this->frac * 100);

	if (x <= 0 && Do <= 0)
		x += Do;
	else
		cout << "invalid operation" << endl;

	y = x;
	temp.setWhole(y);

	z = 100 * x - 100 * y;
	setFrac(z);

	return temp;
}

Dollar& Dollar::operator - (const Dollar & D)
{
	Dollar temp;
	temp.whole = this->whole - D.whole;
	temp.frac = this->frac - D.frac;
	if (temp.frac <= 0){ temp.frac = 100 + temp.frac; temp.whole = temp.whole - 1; }
	if (temp.whole <= 0){ temp.whole = 0; cout << "invalid operation/n"; }
	
	return temp;
}
Dollar& Dollar::operator - (const double & Do)
{
	Dollar temp;
	int y, z;
	double x = 0;
	x += this->whole;
	x += (this->frac * 100);

	if (x <= 0 && Do <= 0)
		x -= Do;
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
Dollar& Dollar::operator = (const Dollar & D)
{
	this->whole = D.whole;
	this->frac = D.frac;
	return *this;
}

ostream& operator<<(ostream& os, const Dollar& D)
{
	os << D.whole << " Dollar " << D.frac << " Cents" << endl;
	return os;
}

istream& operator>>(istream& is, const Dollar& D)
{
	is >> D.whole;
	is >> D.frac;
	return is;
}