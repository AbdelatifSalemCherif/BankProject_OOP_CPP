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

	static void _PrintCalculationsResult(const clsCurrency& CurrencyFrom, const clsCurrency& CurrencyTo, float Amount)
	{


		if (CurrencyFrom.GetCurrencyCode() == CurrencyTo.GetCurrencyCode())
		{
			cout << "\n\nIs The Same Currency !\n\nYour Amount Still = " << Amount << " " << CurrencyFrom.GetCurrencyCode();

			return;
		}

		cout << "\n\nConvert From :" << endl;

		_PrintCurrencyCard(CurrencyFrom);

		if (CurrencyTo.GetCurrencyCode() == "USD")
		{

			cout << "\n\n" << Amount << " " << CurrencyFrom.GetCurrencyCode() << " = "
				<< CurrencyFrom.ConvertToUSD(Amount) << " USD" << endl;

		}

		else if (CurrencyFrom.GetCurrencyCode() == "USD")
		{

			cout << "\n\n" << Amount << " USD" << " = "
				<< CurrencyFrom.ConvertToAnotherCurrency(Amount, CurrencyTo) << " " << CurrencyTo.GetCurrencyCode() << endl;


		}

		else
		{

			float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);

			cout << "\n\n" << Amount << " " << CurrencyFrom.GetCurrencyCode() << " = "
				<< AmountInUSD << " USD" << endl;

			cout << "\n\nConverting From USD To :" << endl;

			_PrintCurrencyCard(CurrencyTo);

			cout << "\n\n" << Amount << " " << CurrencyFrom.GetCurrencyCode() << " = "
				<< CurrencyFrom.ConvertToAnotherCurrency(Amount, CurrencyTo) << " " << CurrencyTo.GetCurrencyCode() << endl;

		}

	}

public:

	
	static void ShowCurrencyCalculatorScreen()
	{

		do {

			clsOutputSettings::RestScreen();

			_DrawScreenHeader("Currency Calculator Screen");

			clsCurrency CurrencyFrom = _ReadCurrencyByCode("\n\nPlease Enter Currency 1 Code : "
				, "\n\nInvalid Code ! Please Enter A Valid One : ");

			clsCurrency CurrencyTo = _ReadCurrencyByCode("\n\nPlease Enter Currency 2 Code : "
				, "\n\nInvalid Code ! Please Enter A Valid One : ");


			float Amount = clsInputSettings::ReadPositiveFloat("\n\nPlease Enter Amount To Exchange : "
				, "\n\nAmount Should Be A Possitive Number ! Please Enter Again : ");


			_PrintCalculationsResult(CurrencyFrom, CurrencyTo, Amount);


		} while (clsInputSettings::ReadYesOrNo("\n\nDo You Want To Perform Another Calculation ? y/n ?"));

	}


};