#pragma once
#include "Currency.h"
class Franc :
	public Currency <Franc>
{
public:
	Franc();
	Franc(double);
	Franc(int,int);
	~Franc();
	Franc& operator + (const Franc & F);
	Franc& operator + (const double & Fr);
	Franc& operator - (const Franc & F);
	Franc& operator - (const double & Fr);
	friend ostream& operator<<(ostream& os, const Franc& F);
	friend ostream& operator>>(ostream& os, const Franc& F);
};												 

