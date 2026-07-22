#pragma once

#include <iostream>

#include "clsInputSettings.h"
#include "clsOutputSettings.h"
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{

private:

	static void _PrintCurrencyCard(const clsCurrency& Currency)
	{

		cout << "\n\nCurrency Info :" << endl;

		cout << "------------------------------------------" << endl;

		cout << "Country       :" << Currency.GetCountry() << endl;
		cout << "Currency Name :" << Currency.GetCurrencyName() << endl;
		cout << "Currency Code :" << Currency.GetCurrencyCode() << endl;
		cout << "Rate (1$)     :" << Currency.Rate << endl;

		cout << "------------------------------------------" << endl;
	}

	static clsCurrency _ReadCurrencyByCode(const string& MessageToUser, const string& ErrorMessage)
	{
		clsCurrency Currency = clsCurrency::FindByCode(clsInputSettings::ReadString(MessageToUser));

		while (Currency.IsEmpty())
		{

			Currency = clsCurrency::FindByCode(clsInputSettings::ReadString(ErrorMessage));

		}

		return Currency;

	}

public:

	



};