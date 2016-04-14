#include "Wallet.h"

Wallet::Wallet()
{
	//create a new pointer for all of them with default constructor
	ptr[0] = new Dollar;
	ptr[1] = new Euro;
	ptr[2] = new Franc;
	ptr[3] = new Hryvnia;
	ptr[4] = new Ruble;

} //default

Wallet::Wallet(int Curr, double num)
{
	//depending on curr, call specific currency and use double constructor
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
	//depending on curr, call specific currency and use Whole and Fraction constructor

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
ostream& operator<<(ostream& os, const Wallet* W)
{ 
	// call name and value functions for all currencies
	os << W->ptr[0]->getWholeName() << " " << W->ptr[0]->getWhole() << " " << W->ptr[0]->getFracName() << " " << W->ptr[0]->getFrac() << endl <<
		W->ptr[1]->getWholeName() << " " << W->ptr[1]->getWhole() << " " << W->ptr[1]->getFracName() << " " << W->ptr[1]->getFrac() << endl <<
		W->ptr[2]->getWholeName() << " " << W->ptr[2]->getWhole() << " " << W->ptr[2]->getFracName() << " " << W->ptr[2]->getFrac() << endl <<
		W->ptr[3]->getWholeName() << " " << W->ptr[3]->getWhole() << " " << W->ptr[3]->getFracName() << " " << W->ptr[3]->getFrac() << endl <<
		W->ptr[4]->getWholeName() << " " << W->ptr[4]->getWhole() << " " << W->ptr[4]->getFracName() << " " << W->ptr[4]->getFrac() << endl;
	return os;
}

Wallet::~Wallet()
{
	//delete temp memory
	for (int i = 0; i < 4; i++)
	{
		delete ptr[i];
	}
}
