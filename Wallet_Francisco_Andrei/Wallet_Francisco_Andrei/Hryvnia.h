#pragma once
#include "Currency.h"
class Hryvnia :
	public Currency
{
public:
	Hryvnia();
	Hryvnia(double);
	Hryvnia(int,int);
	~Hryvnia();
};

