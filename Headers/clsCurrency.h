#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "clsString.h"

using namespace std;

class clsCurrency
{

private:

	// --------------------------------------------------- Data Members -----------------------------------------------------------------

	enum enMode {eEmptyMode = 1, eUpdateMode = 2};
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;



public:

	// --------------------------------------------------- Constructors -----------------------------------------------------------------

	clsCurrency(enMode Mode, const string& Country, const string& CurrencyCode, const string& CurrencyName, float Rate)
	{
		_Mode = Mode;

		_Country = Country;

		_CurrencyCode = CurrencyCode;

		_CurrencyName = CurrencyName;

		_Rate = Rate;

	}



	
	// ----------------------------------------------------- Properties -----------------------------------------------------------------

	string GetCountry() const
	{
		return _Country;
	}

	string GetCurrencyCode() const
	{
		return _CurrencyCode;
	}

	string GetCurrencyName() const
	{
		return _CurrencyName;
	}

	float GetRate() const
	{
		return _Rate;
	}

	void SetRate(float NewRate)
	{

		_Rate = NewRate;

		//_Update();    ******************************
	}

	__declspec(property(get = GetRate, put = SetRate)) float Rate;





};



