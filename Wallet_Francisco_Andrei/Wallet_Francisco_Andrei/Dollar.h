#pragma once
#include "Currency.h"
class Dollar :
	public Currency 
{
public:
	Dollar();
	Dollar(double);
	Dollar(int, int);
	~Dollar();
	Dollar& operator + (const Dollar & D);
	Dollar& operator + (const double & Do);
	Dollar& operator - (const Dollar & D);
	Dollar& operator - (const double & Do);
	Dollar& operator = (const Dollar & D);
	friend ostream& operator<<(ostream& os, const Dollar& D);
	friend istream& operator>>(istream& is, const Dollar& D);
};

