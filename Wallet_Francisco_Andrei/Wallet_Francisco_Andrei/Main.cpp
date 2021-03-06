#include <iostream>
#include <string.h>
#include <iomanip>
#include "Wallet.h"
#include<stdlib.h>
#include <time.h>
using namespace std;
/*
Made by Francisco and Andrei. 
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

void addFunds(Wallet* hermes)
{
	int selec = 0;
	bool mainLoop = 0, subLoop = 0; //for whole loops
	double value = 0; //for input


	while (!mainLoop)
	{
		system("cls");
		cout << 
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
		hermes->ptr[selec]->addDouble(value);
		cout << "Added!";
	}
	cout << endl;
}

void RemoveFunds(Wallet*  hermes)
{
	int selec = 0;
	int w, f;
	bool mainLoop = 0, subLoop = 0; //for whole loops
	double value = 0,temp; //for input


	while (!mainLoop)
	{
		system("cls");
		cout <<
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
		w = value;
		f = value * 100 - w * 100;

		w = hermes->ptr[selec]->getWhole() - w;
		f = hermes->ptr[selec]->getFrac() - f;

		if (f < 0){ f = 100 + f; w--; }
		if (w < 0){ cout << "invalid operation. Not enough money in the wallet." << endl; }
		else{
			hermes->ptr[selec]->setWhole(w);
			hermes->ptr[selec]->setFrac(f);
		}


		cout << "Substracted!";
	}
	cout << endl;
}

void checkFunds(Wallet* hermes)
{
	cout << setprecision(2) << fixed << hermes << endl;
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
		hermes->ptr[i]->addDouble(atr1);
	}

	while (!mainLoop)
	{
		cout <<
			"Welcome to your Wallet" << endl <<
			"1: Add funds" << endl <<
			"2: Remove funds" << endl <<
			"3: Check Funds" << endl <<
			"4: Exit" << endl << endl <<
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
			RemoveFunds(hermes);
			break;
		case '3':
			system("cls");
			checkFunds(hermes);
			break;
		case '4':
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
