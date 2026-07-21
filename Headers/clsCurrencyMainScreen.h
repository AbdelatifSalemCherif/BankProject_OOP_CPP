#pragma once

#include <iostream>
#include <iomanip>

#include "clsScreen.h"


using namespace std;

class clsCurrencyMainScreen : protected clsScreen
{

private:

	enum enCurrencyMainMenuOptions {
		eCurrenciesList = 1, eFindCurrency = 2, eUpdateCurrency = 3, eCurencyCalculator = 4, eExit = 5
	};

	static void _GoBackToCurrencyMainMenu() //************************
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Main Menue...\n";

		system("pause>0");

		//ShowCurrencyMainMenu();
	}









public:



};