#include "Currency.h"
#include <string>
using namespace std;


Currency::Currency()
{
	wholeName = fracName = "Generic";
	whole = frac = 0;
}

Currency::Currency(string wn, string fn, int w, int f)
{
	wholeName = wn;
	fracName = fn;
	whole = w;
	frac = f;
}

void Currency::setWhole(int w)
{
	whole = w;
}

void Currency::setFrac(int f)
{
	frac = f;
}

void Currency::setDouble(double x)
{
	int y;
	double z;
	y = x;
	whole = y;
	
	z = x - y;
	z *= 100;
	frac = z;
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
	return whole;
}

int Currency::getFrac()
{
	return frac;
}

double Currency::getDouble()
{
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


