#pragma once
#include "Currency.h"
using namespace std;
class Wallet
{
private:
	Currency *ptr[5]; 
public:
	Wallet();
	~Wallet();
};

