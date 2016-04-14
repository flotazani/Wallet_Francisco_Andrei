#include "Euro.h"


Euro::Euro() : Currency("Euro", "Cent", 0, 0)
{
}
Euro::Euro(int w, int f) : Currency("Euro", "Cent", w, f)
{
}

Euro::Euro(double x) : Currency("Euro", "Cent", 0, 0)
{
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
{
	Euro temp;
	temp.whole = whole + E.whole;
	temp.frac = frac + E.frac;
	if (temp.frac >= 100)
	{
		temp.frac = temp.frac % 100;
		temp.whole = temp.whole + 1;
	}
	return temp;
}
Euro& Euro::operator + (const double & Eu)
{
	Euro temp;
	int y, z;
	double x;
	x += whole;
	x += (frac * 100);

	if (x <= 0 && Eu <= 0)
		x += Eu;
	else
		cout << "invalid operation" << endl;

	y = x;
	temp.setWhole(y);

	z = x - y;
	z *= 100;
	setFrac(z);

	return temp;
}


Euro& Euro::operator - (const Euro & E)
{
	Euro temp;
	temp.whole = temp.whole - E.whole;
	temp.frac = temp.frac - E.frac;
	if (temp.frac <= 0){ temp.frac = 100 + temp.frac; temp.whole = temp.whole - 1; }
	if (temp.whole <= 0){ temp.whole = 0; cout << "invalid operation/n"; }
	return temp;
}

Euro& Euro::operator - (const double & Eu)
{
	Euro temp;
	int y, z;
	double x;
	x += whole;
	x += (frac * 100);

	if (x <= 0 && Eu <= 0)
		x -= Eu;
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