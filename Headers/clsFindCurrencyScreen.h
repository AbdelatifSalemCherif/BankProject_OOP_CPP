#pragma once

#include <iostream>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{

private:

	enum enFindCurrencyOptions{ optCountry = 1, optCurrencyCode = 2};

	void _PrintCurrencyCard(const clsCurrency& Currency)
{

	cout << "\n\nCurrency Info :" << endl;

	cout << "------------------------------------------" << endl;

	cout << "Country       :" << Currency.GetCountry() << endl;
	cout << "Currency Name :" << Currency.GetCurrencyName() << endl;
	cout << "Currency Code :" << Currency.GetCurrencyCode() << endl;
	cout << "Rate (1$)     :" << Currency.Rate << endl;

	cout << "------------------------------------------" << endl;
}



public:




};
