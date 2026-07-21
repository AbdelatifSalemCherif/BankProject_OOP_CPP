#pragma once

#include <iostream>
#include <iomanip>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;

class clsCurrenciesListScreen : protected clsScreen
{

private:

	static void _PrintCurrencyLineOfList(const clsCurrency& Currency)
	{
		cout << setw(8) << left << "";
		cout << "| " << left << setw(40) << Currency.GetCountry();
		cout << "| " << left << setw(40) << Currency.GetCurrencyName();
		cout << "| " << left << setw(14) << Currency.GetCurrencyCode();
		cout << "| " << left << setw(10) << Currency.Rate << endl;
	}

public:

	static void ShowCurrenciesListScreen()
	{
		vector <clsCurrency> vCurrencies = clsCurrency::GetAllCurrenciesList();

		_DrawScreenHeader("Currencies List Screen", "(" + to_string(vCurrencies.size()) + ") Currencies.");


		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"--------------------------- " << endl;

		cout << setw(8) << left << "";
		cout << "| " << left << setw(40) << "Country";
		cout << "| " << left << setw(40) << "Currency Name";
		cout << "| " << left << setw(14) << "Currency Code";
		cout << "| " << left << setw(10) << "Rate (1$)" << endl;

		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"--------------------------- " << endl;

		for (const clsCurrency& Currency : vCurrencies)
		{

			_PrintCurrencyLineOfList(Currency);
		}

		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"--------------------------- " << endl;
	}


};
