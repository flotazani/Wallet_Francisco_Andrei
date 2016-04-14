#include "Wallet.h"


Wallet::Wallet()
{
	ptr[0] = new Dollar;
	ptr[1] = new Euro;
	ptr[2] = new Franc;
	ptr[3] = new Hryvnia;
	ptr[4] = new Ruble;

}

Wallet::Wallet(int Curr, double num)
{
	if (Curr == 0){
		ptr[0] = new Dollar(num);
		ptr[1] = new Euro;
		ptr[2] = new Franc;
		ptr[3] = new Hryvnia;
		ptr[4] = new Ruble;
	}
	else if (Curr == 1)
	{
		ptr[0] = new Dollar;
		ptr[1] = new Euro(num);
		ptr[2] = new Franc;
		ptr[3] = new Hryvnia;
		ptr[4] = new Ruble;
	}
	else if (Curr == 2)
	{
		ptr[0] = new Dollar;
		ptr[1] = new Euro;
		ptr[2] = new Franc(num);
		ptr[3] = new Hryvnia;
		ptr[4] = new Ruble;
	}
	else if (Curr == 3)
	{
		ptr[0] = new Dollar;
		ptr[1] = new Euro;
		ptr[2] = new Franc;
		ptr[3] = new Hryvnia(num);
		ptr[4] = new Ruble;
	}
	else if (Curr == 4)
	{
		ptr[0] = new Dollar;
		ptr[1] = new Euro;
		ptr[2] = new Franc;
		ptr[3] = new Hryvnia;
		ptr[4] = new Ruble(num);
	}
}
Wallet::Wallet(int Curr, int wh, int fr)
{
	if (Curr == 0){
		ptr[0] = new Dollar(wh,fr);
		ptr[1] = new Euro;
		ptr[2] = new Franc;
		ptr[3] = new Hryvnia;
		ptr[4] = new Ruble;
	}
	else if (Curr == 1)
	{
		ptr[0] = new Dollar;
		ptr[1] = new Euro(wh, fr);
		ptr[2] = new Franc;
		ptr[3] = new Hryvnia;
		ptr[4] = new Ruble;
	}
	else if (Curr == 2)
	{
		ptr[0] = new Dollar;
		ptr[1] = new Euro;
		ptr[2] = new Franc(wh, fr);
		ptr[3] = new Hryvnia;
		ptr[4] = new Ruble;
	}
	else if (Curr == 3)
	{
		ptr[0] = new Dollar;
		ptr[1] = new Euro;
		ptr[2] = new Franc;
		ptr[3] = new Hryvnia(wh, fr);
		ptr[4] = new Ruble;
	}
	else if (Curr == 4)
	{
		ptr[0] = new Dollar;
		ptr[1] = new Euro;
		ptr[2] = new Franc;
		ptr[3] = new Hryvnia;
		ptr[4] = new Ruble(wh, fr);
	}

}

Wallet::~Wallet()
{
	for (int i = 0; i < 4; i++)
	{
		delete ptr[i];
	}
}
