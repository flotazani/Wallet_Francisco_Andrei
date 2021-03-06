#include "Currency.h"
#include <string>
using namespace std;


Currency::Currency()
{
	//default constructor sets everything to 0
	wholeName = fracName = "Generic";
	whole = frac = 0;
}

Currency::Currency(string wn, string fn, int w, int f)
{
	//sets everything to passed values
	wholeName = wn;
	fracName = fn;
	whole = w;
	frac = f;
}

void Currency::setWhole(int w)
{
	//sets passed value
	whole = w;
}

void Currency::setFrac(int f)
{

	frac = f;
}

void Currency::addDouble(double x)
{
	//separates double into frac and whole
	int y;
	double z;
	y = x;
	whole += y;
	
	z = 100*x - 100*y;
	frac += z;
	if (frac > 100)
	{
		frac = frac - 100;
		whole++;
	}
}

void Currency::setWholeName(string wn)
{
	wholeName = wn;
}

void Currency::setFracName(string fn)
{
	fracName = fn;
}

//gets

int Currency::getWhole()
{
	//gets respective value
	return whole;
}

int Currency::getFrac()
{
	return frac;
}

double Currency::getDouble()
{
	//turns frac and whole into one double
	double x;
	x = frac / 100;
	cout << x;
	return x + whole;
}

string Currency::getWholeName()
{
	return wholeName;
}

string Currency::getFracName()
{
	return fracName;
}

Currency::~Currency()
{
}


