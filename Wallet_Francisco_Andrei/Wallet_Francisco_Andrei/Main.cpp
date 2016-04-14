#include <iostream>
#include <iomanip>
#include "Franc.h";
using namespace std;

int main(){
	Franc jakoor(4.13);

	cout << jakoor.getWhole() << " " << jakoor.getFrac();

	system("pause>nul");
	return 0;
}