#pragma once
#include "Currency.h"
class Euro :
	public Currency
{
public:
	Euro();
	Euro(double);
	Euro(int,int);
	~Euro();
};

