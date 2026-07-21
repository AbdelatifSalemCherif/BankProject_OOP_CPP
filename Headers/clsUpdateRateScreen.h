#pragma once

#include <iostream>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;


class clsUpdateRateScreen : protected clsScreen
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



public:

	static void ShowUpdateRateScreen()
	{

		_DrawScreenHeader("Update Rate Screen");


		clsCurrency Currency = clsCurrency::FindByCode(clsInputSettings::ReadString("\n\nPlease Enter Currency Cond : "));

		if (Currency.IsEmpty())
		{
			cout << "\n\nCurrency Does Not Exist ! Try Again !\n\n";

		}
		else
		{

			_PrintCurrencyCard(Currency);


			Currency.Rate = clsInputSettings::ReadPositiveFloat(
				"\n\nUpdate Rate :\n------------------------------------\n\nNew Rate : ", "\n\nRate Should Be a Positive Number : ");


			cout << "\n\nRate Updated Successfully :-)\n";

			_PrintCurrencyCard(Currency);


		}



	}



};
