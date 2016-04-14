#include <iostream>
//#include "Currency.h"
#include <string.h>
#include <iomanip>
#include "Wallet.h"
#include<stdlib.h>
#include <time.h>
using namespace std;
/*
addFunds:
main loop
	list options
	input verify using loop that will be triggered on an error
	if selection is 6, exit menu

	sub-loop for value input (double)
		input verify using loop that will be triggered on an error

	send all to hermes (main wallet)

checkFunds:
for loop running 5 times
	call name and value functions from pointer array

main:
create main wallet hermes as dynamic memory
main loop for options
	switch statement for options
		case 1: call add funds
		case 2: call checkFunds
		case 3:
			call checkFunds
			delete memory (hermes)
			set mainLoop trigger as true


*/


void addFunds(Wallet* & hermes)
{
	int selec = 0;
	bool mainLoop = 0, subLoop = 0; //for whole loops
	double value = 0; //for input


	while (!mainLoop)
	{
		cout << endl << 
			"Select your currency:" << endl <<
			"1. Dollar" << endl <<
			"2. Euro" << endl <<
			"3. Franc" << endl <<
			"4. Hryvnia" << endl <<
			"5. Ruble" << endl <<
			"6. Exit" << endl << endl <<
			"Your choice: ";
		do
		{

			while (!(cin >> selec)) //will loop only if value fails
			{
				cout << "Please enter a valid value!: ";
				cin.clear();
				cin.ignore();
			}
			
			if (selec < 0 || selec > 6)
			{
				cout << "Please enter a valid value!: ";
				selec = -1;
			}
		} while (selec < 0); //input verify

		if (selec == 6) //exit
		{
			break;
		}

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
	for (int i = 0; i <= 4; i++){
		cout << hermes->ptr[i]->getWholeName() << " " << hermes->ptr[i]->getWhole() << " " << hermes->ptr[i]->getFracName() << " " << hermes->ptr[i]->getFrac() << endl;
	}
	cout << endl;
}

int main(){
	char selec;
	double atr1;
	bool mainLoop = 0;
	//Currency wall;
	//wall.setDouble(14.2);
	//Wallet mainWallet;
	Wallet *hermes = new Wallet;
	 srand(time(0)); //set random seed
	 double atr = rand() / (double)RAND_MAX; //set rand cent generator
	 atr1 = rand(); //set rand num generator
	for (int i = 0; i <= 4; i++)
	{
		atr1 += atr; //merge numbers
		hermes->ptr[i]->setDouble(atr1);
	}

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
			cout << "Please enter a valid selection!" << endl;
			break;
		case '1':
			system("cls");
			 addFunds(hermes);
			 system("cls");
			break;
		case '2':
			system("cls");
			checkFunds(hermes);
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
