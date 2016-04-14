#include <iostream>
#include <string.h>
#include <iomanip>
#include "Wallet.h"
using namespace std;

enum money
{
	Dollar, Euro, Franc, Hryvnia, Ruble
};

void addFunds(Wallet & hermes)
{
	char selec;
	bool mainLoop = 0, subLoop = 0;
	double value = 0;


	while (!mainLoop)
	{
		cout <<
			"Select your currency:" << endl <<
			"1. Dollar" << endl <<
			"2. Euro" << endl <<
			"3. Franc" << endl <<
			"4. Hryvnia" << endl <<
			"5. Ruble" << endl <<
			"6. Exit" << endl << endl <<
			"Your choice: ";
		cin >> selec;

		if (selec == 6)
		{
			mainLoop = 1;
			subLoop = 1;
		}

		if (selec >= 0 && selec <= 6)
			mainLoop = 1;

		while (!subLoop)
		{
			cout << endl;
			cout << "Input a value: ";

			do
			{
				if (value < 0)
					cout << "Please enter a value of 0 or higher!";
				while (!(cin >> value)) //will loop only if value fails
				{
					cout << "Please enter a valid value!";
					cin.clear();
					cin.ignore();
				}

			} while (value < 0);

			subLoop = 1;
		}

		selec--;
		hermes.addMoney(selec, value);
	}
}

void checkFunds(Wallet &hermes)
{
	hermes.ptr
}

int main(){
	char selec;
	bool mainLoop = 0;
	//Wallet mainWallet;
	Wallet hermes;

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
			 addFunds(hermes);
			break;
		case '2':
			checkFunds(hermes);
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
