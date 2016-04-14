#include <iostream>
#include <string.h>
#include <iomanip>
#include "Wallet.h"
using namespace std;

int main(){
	char selec;
	bool mainLoop = 0;

	while (!mainLoop)
	{
		cout <<
			"Welcome to your Wallet" << endl <<
			"1: Add funds" << endl <<
			"2: Check Funds" << endl <<
			"3: Exit" << endl << endl <<
			"Your choice: ";

		cin >> selec;

		switch (selec)
		{
		default:
			cout << "Please enter a valid selection!";
			break;
		case '1':

			break;
		case '2':
			break;
		case '3':
			cout << "Goodbye!";
			mainLoop = true;
			break;
		}
	}
	system("pause>nul");
	return 0;
}

void addFunds()
{

}

void checkFunds()
{

}