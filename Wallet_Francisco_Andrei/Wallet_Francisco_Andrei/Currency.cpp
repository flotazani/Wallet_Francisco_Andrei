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
string Currency::getWholeName()
{
	return wholeName;
}
string Currency::getFracName()
{
	return fracName;
}

//Currency operator + (const Currency & C1, const Currency & C2)
//{
//
//}

Currency::~Currency()
{
}


