#pragma once
#include "Currency.h"
#include "Dollar.h"
#include "Euro.h"
#include "Franc.h"
#include "Hryvnia.h"
#include "Ruble.h"

using namespace std;
class Wallet
{ // you have to put enums somewhere so we will be able to call elements ptr[Dollar] instead of ptr[2]
private:
	Currency *ptr[5]; 
public:
	Wallet();
	Wallet(int, double);
	Wallet(int, int, int);
	~Wallet();
};

