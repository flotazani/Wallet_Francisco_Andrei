#pragma once
#include "Currency.h"
class Ruble :
	public Currency
{
public:
	Ruble();
	Ruble(double);
	Ruble(int,int);
	~Ruble();
};

