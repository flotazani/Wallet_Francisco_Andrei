#include <iostream>
#include <iomanip>
using namespace std;

class Currency{
private:
	struct Pounds{
		int Pounds;
		int pence;
	};
	struct Rub{
		int Rub;
		int kopeika;
	};
	struct Euro{
		int Euro;
		int cent;
	};
	struct Dollar{
		int Dollar;
		int centD;
	};
public:
	friend Pounds operator+(const)

};