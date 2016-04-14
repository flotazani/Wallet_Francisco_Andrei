#include <iostream>
#include "Currency.h"
#include <string.h>
#include <iomanip>
#include "Wallet.h"
using namespace std;

enum money
{
	Dollar, Euro, Franc, Hryvnia, Ruble
};

void addFunds(Wallet* & hermes)
{
	int selec;
	bool mainLoop = 0, subLoop = 0;
	double value = 0;


	while (!mainLoop)
	{
		cout <<endl<<
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
			break;
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
		hermes->ptr[selec]->setDouble(value);
	
	}
	cout << endl;
}

void checkFunds(Wallet* &hermes)
	{
	//cout << hermes;
	for (int i = 0; i < 4; i++){
		cout << hermes->ptr[i]->getWholeName() << " " << hermes->ptr[i]->getWhole() << " " << hermes->ptr[i]->getFracName() << " " << hermes->ptr[i]->getFrac() << endl;
	}
	cout << endl;
}

int main(){
	char selec;
	bool mainLoop = 0;
	//Currency wall;
	//wall.setDouble(14.2);
	//Wallet mainWallet;
	Wallet *hermes = new Wallet;

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
			system("cls");
			 addFunds(hermes);
			 system("cls");
			break;
		case '2':
			system("cls");
			checkFunds(hermes);
			system("cls");
			break;
		case '3':
			checkFunds(hermes);
			cout << "Goodbye!";
			delete hermes;
			mainLoop = true;
			break;
		}
	}
	system("pause>nul");
	return 0;
}
