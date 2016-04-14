#pragma once
#include <string>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

class Currency
{
protected:
	int whole, frac;
	std::string wholeName, fracName;
public:
	//sets
	void setWhole(int);
	void setFrac(int);
	void addDouble(double);
	void setWholeName(string);
	void setFracName(string);
	//gets
	int getWhole();
	int getFrac();
	double getDouble();
	string getWholeName();
	string getFracName();
	//constructors
	Currency();
	Currency(std::string, std::string, int, int);
	~Currency();

};

