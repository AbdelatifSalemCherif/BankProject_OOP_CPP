#include <iostream>

#include "clsLoginScreen.h"

#include "clsCurrency.h"

using namespace std;

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




int main()
{
	
	clsCurrency Currency1 = clsCurrency::FindByCode("jod");

	if (Currency1.IsEmpty())
	{
		cout << "\n\nCurrency don\'t found ! " << endl;
	}
	else
	{
		_PrintCurrencyCard(Currency1);
	}



	clsCurrency Currency2 = clsCurrency::FindByCountry("alGERia");

	if (Currency2.IsEmpty())
	{
		cout << "\n\nCurrency don\'t found ! " << endl;
	}
	else
	{
		_PrintCurrencyCard(Currency2);
	}


	Currency1.Rate = .708;


	_PrintCurrencyCard(Currency1);


	/*while (clsLoginScreen::ShowLoginScreen())
	{

	}*/


	return 0;

}