#pragma once
#include <string>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
template <class T>
class Currency
{
protected:
	int whole, frac;
	std::string wholeName, fracName;
public:             // ???? ????????? ???????!! ONLY POSITIVE NUMBERS
	//sets
	void setWhole(int);
	void setFrac(int);
	void setWholeName(string);
	void setFracName(string);
	//gets
	int getWhole();
	int getFrac();
	string getWholeName();
	string getFracName();
	//constructors
	Currency();
	Currency(std::string, std::string, int, int);
	~Currency();
	//virtual overloaded operators
	virtual T& operator + (const T & D);
	virtual T& operator + (const double & Do);
	virtual T& operator - (const T & D);
	virtual T& operator - (const double & Do);
	virtual friend ostream& operator<<(ostream& os, const T& D);
	virtual friend ostream& operator>>(ostream& os, const T& D);
	Currency &Currency<T>::operator = (const Currency & C1)
	//Currency& operator = (const Currency & C1);
};

