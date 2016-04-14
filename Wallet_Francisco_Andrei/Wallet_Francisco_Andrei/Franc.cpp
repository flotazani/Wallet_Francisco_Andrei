#include "Franc.h"


Franc::Franc() : Currency("Franc", "Cent", 0, 0)// cent???
{
}
Franc::Franc(int w, int f) : Currency("Franc", "Cent", w, f)
{
}
Franc::Franc(double x)
{
	int y;
	double z;
	y = x;
	setWhole(y);

	z = x - y;

	z *=100;
	setFrac(z);

}


Franc::~Franc()
{
}
