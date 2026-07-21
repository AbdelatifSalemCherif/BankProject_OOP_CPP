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

	static void _ShowCurrenciesListScreen()
	{

		cout << "\n\tCurrencies List Screen will be here...\n";

	}

	static void _ShowFindCurrencyScreen()
	{
		cout << "\n\tFind Currency Screen will be here...\n";
	}

	static void _ShowUpdateCurrencyScreen()
	{
		cout << "\n\tUpdate Currency Screen will be here...\n";
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		cout << "\n\tCurrency Calculator Screen will be here...\n";
	}








public:



};