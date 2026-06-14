#pragma once

#include <iostream>

#include "clsPerson.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:
	string _AccountNumber;
	string _PinCode;
	float _Balance;

public:

	clsBankClient(const string& FirstName, const string& LastName, const string& Email, const string& Phone, const string AccountNumber,
		const string& PinCode, float Balance) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_Balance = Balance;

	}

	void SetAccountNumber(const string& AccountNumber)
	{
		_AccountNumber = AccountNumber;
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	__declspec(property(get = GetAccountNumber, put = SetAccountNumber)) string AccountNumber;

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









};