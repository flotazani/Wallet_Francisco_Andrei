#pragma once
#include <string>
class Currency
{
private:
	int whole, frac;
	std::string name, fracName;
public:
	//sets
	void setWhole();
	void setFrac();
	void setName();
	void setFracName();
	//gets
	int getWhole();
	int getFrac();
	std::string getName;
	std::string getFracName();

	//virtual something, add later
};

