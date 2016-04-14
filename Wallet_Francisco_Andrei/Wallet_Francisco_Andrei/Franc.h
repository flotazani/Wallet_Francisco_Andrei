#pragma once
#include "Currency.h"
class Franc :
	public Currency
{
public:
	Franc();
	Franc(double);
	Franc(int,int);
	~Franc();
};

