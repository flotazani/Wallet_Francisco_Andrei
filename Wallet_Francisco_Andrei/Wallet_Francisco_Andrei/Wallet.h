#pragma once
#include <stdlib.h>
#include <time.h>
#include "Dollar.h"
#include "Euro.h"
#include "Franc.h"
#include "Hryvnia.h"
#include "Ruble.h"

enum money
{
	Dollar, Euro, Franc, Hryvnia, Ruble
};
class Wallet
{
private:
	bool isEmpty, theresDollar, theresEuro, theresFranc, theresHryvnia, theresRuble;
	int randNum;

public:
	Wallet()
	{
		srand(time(NULL));
		
	}
	~Wallet();
};
