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

	void _ShowFindByCountry()
	{


		clsCurrency Currency = clsCurrency::FindByCountry(clsInputSettings::ReadString("\n\nPlease Enter Country Name : "));

		if (Currency.IsEmpty())
		{
			cout << "\n\nThis Country Is Incorrect ! Try Again !";
		}
		else
		{

			cout << "\n\nCurrency Found Successfully :-) ";

			_PrintCurrencyCard(Currency);
		}


	}

	void _ShowFindByCode()
	{

		clsCurrency Currency = clsCurrency::FindByCode(clsInputSettings::ReadString("\n\nPlease Enter Currency Code : "));

		if (Currency.IsEmpty())
		{
			cout << "\n\nThis Code Is Incorrect ! Try Again !";
		}
		else
		{

			cout << "\n\nCurrency Found Successfully :-) ";

			_PrintCurrencyCard(Currency);
		}


	}

	void _PerformFindCurrencyOption(enFindCurrencyOptions Option)
	{

		switch (Option)
		{

		case optCountry:
		{

			_ShowFindByCountry();

			break;
		}

		case optCurrencyCode:
		{

			_ShowFindByCode();

			break;
		}


		}


	}


public:

	void ShowFindCurrencyScreen()
	{

		_DrawScreenHeader("Find Currency Screen");

		
		_PerformFindCurrencyOption((enFindCurrencyOptions)
			clsInputSettings::ReadShortInRange(1, 2, "\n\nFind By : [1] Country or [2] Code ? "));


	}


};
