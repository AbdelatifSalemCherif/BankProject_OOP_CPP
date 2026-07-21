#pragma once

#include <iostream>
#include <iomanip>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "clsScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"


using namespace std;

class clsCurrencyMainScreen : protected clsScreen
{

private:

	enum enCurrencyMainMenuOptions {
		eCurrenciesList = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eExit = 5
	};

	static void _GoBackToCurrencyMainMenu() 
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Main Menue...\n";

		system("pause>0");

		ShowCurrencyMainMenu();
	}

	static void _ShowCurrenciesListScreen()
	{

		clsCurrenciesListScreen::ShowCurrenciesListScreen();

	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		clsUpdateRateScreen::ShowUpdateRateScreen();
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

	static void ShowCurrencyMainMenu()
	{
		clsOutputSettings::RestScreen();

		_DrawScreenHeader("Currency Main Screen");

		cout << endl;

		cout << setw(37) << left << "" << "===================================================================\n\n";
		cout << setw(37) << left << "" << "\t\t\t\tCurrency Main Menu\n\n";
		cout << setw(37) << left << "" << "===================================================================\n\n";

		cout << setw(37) << left << "" << "\t[1] Show Currencies List.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Exit.\n\n";

		cout << setw(37) << left << "" << "===================================================================\n\n";


		cout << setw(37) << left << "";
		_PerformCurrencyMainMenuOption((enCurrencyMainMenuOptions)
			clsInputSettings::ReadShortInRange(1, 5, "Choose What Do You Want To Do ? [1 to 5] ? "));


	}





};