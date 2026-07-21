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
		cout << "| " << left << setw(15) << Currency.GetCountry();
		cout << "| " << left << setw(20) << Currency.GetCurrencyName();
		cout << "| " << left << setw(30) << Currency.GetCurrencyCode();
		cout << "| " << left << setw(15) << Currency.Rate << endl;
	}

public:




};
