#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


#include "clsPerson.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:

	enum enMode {EmptyMode = 0, UpdateMode = 1};

	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _Balance;

	clsBankClient _ConvertLineToClient(const string& Line)
	{

	}

public:

	clsBankClient(enMode Mode, const string& FirstName, const string& LastName, const string& Email, const string& Phone
		, const string AccountNumber, const string& PinCode, float Balance) : clsPerson(FirstName, LastName, Email, Phone)
	{

		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_Balance = Balance;

	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(const string& PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetBalance(float Balance)
	{
		_Balance = Balance;
	}

	float GetBalance()
	{
		return _Balance;
	}

	__declspec(property(get = GetBalance, put = SetBalance)) string Balance;

	bool IsEmpty()
	{
		return _Mode == EmptyMode;
	}

	clsBankClient Find(const string& AccountNumber, const string& FileName)
	{
		fstream File;

		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Line = "";

			while (getline(File, Line))
			{
				if()
			}


			File.close();

		}



	}







};