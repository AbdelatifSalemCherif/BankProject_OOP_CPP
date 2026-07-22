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

	static float _ExchangeToUSD(float Amount, float Rate)
	{
		return Amount/ Rate;
	}

	static float _ExchangeFromUSD(float Amount, float Rate)
	{
		return Amount * Rate;
	}

public:

	
	static void ShowCurrencyCalculatorScreen()
	{

		do {
			clsOutputSettings::RestScreen();

			_DrawScreenHeader("Currency Calculator Screen");

			clsCurrency Currency1 = _ReadCurrencyByCode("\n\nPlease Enter Currency 1 Code : "
				, "\n\nInvalid Code ! Please Enter A Valid One : ");

			clsCurrency Currency2 = _ReadCurrencyByCode("\n\nPlease Enter Currency 2 Code : "
				, "\n\nInvalid Code ! Please Enter A Valid One : ");


			float Amount = clsInputSettings::ReadPositiveFloat("\n\nPlease Enter Amount To Exchange : "
				, "\n\nAmount Should Be A Possitive Number ! Please Enter Again : ");


			if (Currency1.GetCurrencyCode() == Currency2.GetCurrencyCode())
			{
				cout << "\n\nIs The Same Currency !\n\nYour Amount Still = " << Amount << " " << Currency1.GetCurrencyCode();
			}
			else
			{

				cout << "\n\nConvert From :" << endl;

				_PrintCurrencyCard(Currency1);

				if (Currency2.GetCurrencyCode() == "USD")
				{

					cout << "\n\n" << Amount << " " << Currency1.GetCurrencyCode() << " = "
						<< _ExchangeToUSD(Amount, Currency1.Rate) << " USD" << endl;


				}
				else if (Currency1.GetCurrencyCode() == "USD")
				{

					cout << "\n\n" << Amount << " USD" << " = "
						<< _ExchangeFromUSD(Amount, Currency2.Rate) << " " << Currency2.GetCurrencyCode() << endl;

				}
				else
				{

					float AmountInUSD = _ExchangeToUSD(Amount, Currency1.Rate);

					cout << "\n\n" << Amount << " " << Currency1.GetCurrencyCode() << " = "
						<< AmountInUSD << " USD" << endl;

					cout << "\n\nConverting From USD To :" << endl;

					_PrintCurrencyCard(Currency2);

					cout << "\n\n" << AmountInUSD << " USD" << " = "
						<< _ExchangeFromUSD(AmountInUSD, Currency2.Rate) << " " << Currency2.GetCurrencyCode() << endl;


				}

			}




		} while (clsInputSettings::ReadYesOrNo("\n\nDo You Want To Perform Another Calculation ? y/y ?"));

	}


};