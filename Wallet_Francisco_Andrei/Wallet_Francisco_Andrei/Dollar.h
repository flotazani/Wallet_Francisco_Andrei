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
};

