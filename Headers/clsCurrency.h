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


	// ------------------------------ Methods help to download and upload clsCurrency objects to file ------------------------------------ 

	static clsCurrency _ConvertRecordToCurrency(const string& Record, const string& Separator = "#//#")
	{

		vector <string> vRecord = clsString::Split(Record, Separator);

	
		return clsCurrency(eUpdateMode, vRecord[0], vRecord[1], vRecord[2], stof(vRecord[3]));

	}

	static string _ConvertCurrencyToRecord(const clsCurrency& Currency, const string& Separator = "#//#")
	{

		string Record = "";		

		Record += Currency._Country + Separator;
		Record += Currency._CurrencyCode+ Separator;
		Record += Currency._CurrencyName + Separator;
		Record += to_string(Currency._Rate);

		return Record;

	}

	static vector <clsCurrency> _LoadAllCurrenciesFromFile(const string& FileName = "BankData/Currencies.txt")
	{

		vector <clsCurrency> vCurrencies;

		fstream File;

		File.open(FileName, ios::in);

		if (File.is_open())
		{

			string Record = "";


			while (getline(File, Record))
			{
				vCurrencies.push_back(_ConvertRecordToCurrency(Record));
			}


			File.close();
		}


	}

	static void _SaveAllCurrenciesToFile(const vector <clsCurrency> vCurrencies, const string& FileName = "BankData/Currencies.txt")
	{

		fstream File;

		File.open(FileName, ios::out);

		if (File.is_open())
		{

			for (const clsCurrency& Currency : vCurrencies)
			{

				File << _ConvertCurrencyToRecord(Currency) << "\n";

			}


			File.close();
		}


	}

	static void _PushRecordToFile(const string& Record, const string& FileName = "BankData/Currencies.txt")
	{

		fstream File;

		File.open(FileName, ios::out | ios::app);


		if (File.is_open())
		{

			File << Record << "\n";

			File.close();
		}


	}



	// ------------------------------------------------- Ready Objects -------------------------------------------------------------------

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(eEmptyMode, "", "", "", 0);
	}



	// --------------------------------------------------- Logic Core --------------------------------------------------------------------

	void _Update()
	{
		vector <clsCurrency> _vCurrencuies = _LoadAllCurrenciesFromFile();

		for (clsCurrency& Currency : _vCurrencuies)
		{

			if (Currency._CurrencyCode == _CurrencyCode)
			{
				Currency._Rate = _Rate;

				break;
			}

		}

		_SaveAllCurrenciesToFile(_vCurrencuies);

	}




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

		_Update();

	}

	__declspec(property(get = GetRate, put = SetRate)) float Rate;



	//--------------------------------------------------- Check Methods ------------------------------------------------------------------

	bool IsEmpty()
	{
		return _Mode == eEmptyMode;
	}

	


	// --------------------------------------------------- Logic Core --------------------------------------------------------------------

	static clsCurrency FindByCode(const string& CurrencyCode, const string& FileName = "BankData/Currencies.txt")
	{

		fstream File;

		File.open(FileName, ios::in);

		if (File.is_open())
		{

			string Record = "";

			while (getline(File, Record))
			{
				clsCurrency Currency = _ConvertRecordToCurrency(Record);

				if (Currency._CurrencyCode == CurrencyCode)
				{
					File.close();

					return Currency;
				}

			}


			File.close();
		}


		return _GetEmptyCurrencyObject();

	}

	static clsCurrency FindByCountry(const string& Country, const string& FileName = "BankData/Currencies.txt")
	{
		fstream File;

		File.open(FileName, ios::in);

		if (File.is_open())
		{

			string Record = "";

			while (getline(File, Record))
			{
				clsCurrency Currency = _ConvertRecordToCurrency(Record);

				if (Currency._Country == Country)
				{
					File.close();

					return Currency;
				}

			}


			File.close();
		}


		return _GetEmptyCurrencyObject();

	}







};



