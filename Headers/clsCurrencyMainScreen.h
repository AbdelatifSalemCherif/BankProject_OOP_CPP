#pragma once

#include <iostream>
#include <iomanip>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "clsScreen.h"


using namespace std;

class clsCurrencyMainScreen : protected clsScreen
{

private:

	enum enCurrencyMainMenuOptions {
		eCurrenciesList = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eExit = 5
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

	static void _ShowUpdateRateScreen()
	{
		cout << "\n\tUpdate Currency Screen will be here...\n";
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		cout << "\n\tCurrency Calculator Screen will be here...\n";
	}

	static void _PerformCurrencyMainMenuOption(enCurrencyMainMenuOptions Option)
	{
		switch (Option)
		{
		case eCurrenciesList:
		{
			clsOutputSettings::RestScreen();

			_ShowCurrenciesListScreen();

			_GoBackToCurrencyMainMenu();

			break;
		}

		case eFindCurrency:
		{
			clsOutputSettings::RestScreen();

			_ShowFindCurrencyScreen();

			_GoBackToCurrencyMainMenu();

			break;
		}

		case eUpdateRate:
		{
			clsOutputSettings::RestScreen();

			_ShowUpdateRateScreen();

			_GoBackToCurrencyMainMenu();

			break;
		}

		case eCurrencyCalculator:
		{
			clsOutputSettings::RestScreen();

			_ShowCurrencyCalculatorScreen();

			_GoBackToCurrencyMainMenu();

			break;
		}

		case eExit:
		{

			break;
		}

		}
	}




public:

	





};