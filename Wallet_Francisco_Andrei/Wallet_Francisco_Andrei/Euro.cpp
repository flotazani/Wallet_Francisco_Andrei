#include "Euro.h"


Euro::Euro() : Currency("Euro", "Cent", 0, 0)
{
}
Euro::Euro(int w, int f) : Currency("Euro", "Cent", w, f)
{
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
Euro& Euro::operator + (const double & Eu){}

Euro& Euro::operator - (const Euro & E)
{
	Euro temp;
	temp.whole = temp.whole - E.whole;
	temp.frac = temp.frac - E.frac;
	if (temp.frac <= 0){ temp.frac = 100 + temp.frac; temp.whole = temp.whole - 1; }
	if (temp.whole <= 0){ temp.whole = 0; cout << "invalid operation/n"; }
	return temp;
}

Euro& Euro::operator - (const double & Eu){}