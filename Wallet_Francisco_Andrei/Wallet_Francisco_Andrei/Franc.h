#pragma once
#include "Currency.h"
class Franc :
	public Currency
{
public:
	Franc();
	Franc(int);
	Franc(int, double);
	~Franc();
};

