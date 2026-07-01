#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


#include "clsPerson.h"
#include "clsString.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:

	enum enMode {EmptyMode = 0, UpdateMode = 1};

	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _Balance;

	static clsBankClient _ConvertLineToClient(const string& Line, const string& Separator)
	{
		vector <string> vClient = clsString::Split(Line, Separator, false);

		return clsBankClient(UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4]
			, vClient[5], stoi(vClient[6]));

	}

	static clsBankClient _GetEmptyClient()
	{
		return clsBankClient(EmptyMode, "", "", "", "", "", "", 0);
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

	void Print()
	{
		cout << "\nClient Card :" << endl;
		cout << "-------------------------------" << endl;
		cout << "First Name :" << endl;
		cout << "Last Name  :" << endl;
		cout << "Full Name  : " << endl;
		cout << "Email      :" << endl;
		cout << "Phone      :" << endl;
		cout << "Acc.Number :" << endl;
		cout << "Password   :" << endl;
		cout << "Balance    :" << endl;
		cout << "-------------------------------" << endl;

	}

	static clsBankClient Find(const string& AccountNumber, const string& FileName, const string& Separator)
	{
		fstream File;

		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Line = "";
			clsBankClient Client = _ConvertLineToClient(Line, Separator);

			while (getline(File, Line))
			{
				if (Client._AccountNumber == AccountNumber)
				{
					File.close();

					return Client;
				}
			}


			File.close();

		}

		return _GetEmptyClient();

	}

	static clsBankClient Find(const string& AccountNumber, const string& PinCode, const string& FileName, const string& Separator)
	{
		fstream File;

		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Line = "";
			clsBankClient Client = _ConvertLineToClient(Line, Separator);

			while (getline(File, Line))
			{
				if (Client._AccountNumber == AccountNumber && Client._PinCode == PinCode)
				{
					File.close();

					return Client;
				}
			}

			File.close();

		}

		return _GetEmptyClient();

	}







};