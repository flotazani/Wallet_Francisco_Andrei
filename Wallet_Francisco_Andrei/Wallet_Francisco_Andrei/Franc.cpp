#include "Franc.h"


Franc::Franc() : Currency("Franc", "Rappen", 0, 0)// cent???
{
	//sets default name and values as 0
}
Franc::Franc(int w, int f) : Currency("Franc", "Rappen", w, f)
{
	//sets passed values and default name
}
Franc::Franc(double x) : Currency("Franc", "Rappen", 0, 0)
{
	//separates double and sets it to frac and whole along with name
	int y;
	double z;
	y = x;
	setWhole(y);

	z = 100 * (x - y);
	setFrac(z);

}

Franc::~Franc()
{
}

Franc& Franc::operator + (const Franc & F)
{
	//takes frac and whole from right side and adds it to the frac and whole from the left side
	Franc temp;
	temp.whole = this->whole + F.whole;
	temp.frac = this->frac + F.frac;
	if (temp.frac >= 100)
	{
		temp.frac = temp.frac % 100;
		temp.whole = temp.whole + 1;
	}
	return temp;
}
Franc& Franc::operator + (const double & Fr)
{	//takes frac and whole from right side, turns it into a double, adds it to the left side, and writes it to the temp class, which it returns

	Franc temp; //currency class
	int y, z; //temp holders
	double x = 0;
	x += this->whole; //add the whole numb to x
	x += (this->frac * 100); //multiply the decimal by 100 and add it to x

	if (x <= 0 && Fr <= 0)
		x += Fr; //if both doubles are equal or bigger to 0, add them to x
	else
		cout << "invalid operation" << endl;

	y = x; //will cut off and only leave the whole
	temp.setWhole(y); //send it

	z = x - y; //subtract whole and leave only decimal
	z *= 100; //mulitply decimal by 100 to make it whole
	setFrac(z); // send it
	z = 100 * x - 100 * y;
	setFrac(z);

	return temp;//return temp currency class
}

Franc& Franc::operator - (const Franc & F)
{	//takes frac and whole from right side and subtracts it from the frac and whole from the left side

	Franc temp;
	temp.whole = this->whole - F.whole;
	temp.frac = this->frac - F.frac;
	if (temp.frac <= 0){ temp.frac = 100 + temp.frac; temp.whole = temp.whole - 1; }
	if (temp.whole <= 0){ temp.whole = 0; cout << "invalid operation/n"; }
	return temp;
}
Franc& Franc::operator - (const double & Fr)
{
	//takes frac and whole from right side, turns it into a double, subtracts the left side from it, and adds it to the temp class, which it returns

	Franc temp;
	int y, z;
	double x = 0;
	x += this->whole;
	x += (this->frac * 100);

	if (x <= 0 && Fr <= 0)
		x -= Fr;
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

Franc& Franc::operator = (const Franc & F)
{
	//sets whatever is on the right to the left by respective value
	this->whole = F.whole;
	this->frac = F.frac;
	return *this;
}

ostream& operator<<(ostream& os, const Franc& F)
{//outputs whole and frac
	os << F.whole << " Franc " << F.frac << " Rappen" << endl;
	return os;
}
istream& operator>>(istream& is, const Franc& F)
{//sets whole and frac
	is >> F.whole;
	is >> F.frac;
	return is;
}
