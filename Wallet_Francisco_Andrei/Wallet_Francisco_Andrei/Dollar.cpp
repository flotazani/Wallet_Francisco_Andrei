#include "Dollar.h"


Dollar::Dollar() : Currency("Dollar","Cent",0 , 0)
{
}

Dollar::Dollar(int w, int f ) : Currency("Dollar", "Cent", w, f)
{
}

Dollar::~Dollar()
{
}

Dollar& Dollar::operator+(const Dollar &D) 
{
	Dollar temp;
	temp.whole = whole + D.whole;
	temp.frac = frac + D.frac;
	if (temp.frac >= 100)
	{
		temp.frac = temp.frac % 100;
		temp.whole = temp.whole + 1;
	}
	return temp;
}
Dollar& Dollar::operator + (const double & Do){}

Dollar& Dollar::operator - (const Dollar & D)
{
	Dollar temp;
	temp.whole = temp.whole - D.whole;
	temp.frac = temp.frac - D.frac;
	if (temp.frac <= 0){ temp.frac = 100 + temp.frac; temp.whole = temp.whole - 1; }
	if (temp.whole <= 0){ temp.whole = 0; cout << "invalid operation/n"; }
	
	return temp;
}
Dollar& Dollar::operator - (const double & Do){}

ostream& operator<<(ostream& os, const Dollar& D)
{
	os << D.whole << " Dollar " << D.frac << " Cents" << endl;
	return os;
}

istream& operator>>(istream& is, const Dollar& D)
{
	is >> D.whole;
	is >> D.frac;
}