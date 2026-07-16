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

	enum enMode {eEmptyMode = 0, eUpdateMode = 1, eAddNewMode = 2};





	//Data Memebers

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _Balance;
	bool _MarkedForDelete = false;






	//Methods help for reading and writing from database

	static clsBankClient _ConvertLineToClient(const string& Line, const string& Separator)
	{
		vector <string> vClient = clsString::Split(Line, Separator, false);

		return clsBankClient(eUpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4]
			, vClient[5], stof(vClient[6]));

	}

	static string _ConvertClientToLine(const clsBankClient& Client, const string& Separator)
	{
		string Line = "";

		Line += Client.FirstName + Separator;
		Line += Client.LastName + Separator;
		Line += Client.Email + Separator;
		Line += Client.Phone + Separator;
		Line += Client._AccountNumber + Separator;
		Line += Client._PinCode + Separator;
		Line += to_string(Client._Balance);

		return Line;
	}

	static vector <clsBankClient> _LoadAllClientsFromFile(const string& FileName, const string& Separator)
	{
		vector <clsBankClient> vClients;

		fstream File;

		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Line = "";

			while (getline(File, Line))
			{

				vClients.push_back(_ConvertLineToClient(Line, Separator));

			}

			File.close();
		}

		return vClients;
	}

	static void _SaveAllClientsToFile(const vector <clsBankClient>& vClients, const string& FileName, const string& Separator)
	{
		fstream File;

		File.open(FileName, ios::out);

		if (File.is_open())
		{

			for (const clsBankClient& Client : vClients)
			{
				if (!Client._MarkedForDelete)
				{
					File << _ConvertClientToLine(Client, Separator) + "\n";
				}
			}

			File.close();
		}

	}

	static void _AddLineToFile(const string& Line, const string& FileName, const string& Separator)
	{
		fstream File;

		File.open(FileName, ios::out | ios::app);

		if (File.is_open())
		{

			File << Line + "\n";

			File.close();
		}

	}



	






	//Get Ready Objects

	static clsBankClient _GetEmptyClient()
	{
		return clsBankClient(eEmptyMode, "", "", "", "", "", "", 0);
	}
















	//Core logic

	void _Update(const string& FileName, const string& Separator) const
	{
		vector <clsBankClient> _vClients = _LoadAllClientsFromFile(FileName, Separator);

		for (clsBankClient& Client : _vClients)
		{
			if (Client._AccountNumber == _AccountNumber)
			{
				Client = *this;

				break;
			}
		}

		_SaveAllClientsToFile(_vClients, FileName, Separator);

	}

	void _AddNew(const string& FileName, const string& Separator) const
	{
		
		_AddLineToFile(_ConvertClientToLine(*this, Separator), FileName, Separator);

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









	//Properities

	string GetAccountNumber() const
	{
		return _AccountNumber;
	}

	void SetPinCode(const string& PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode() const
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetBalance(float Balance)
	{
		_Balance = Balance;
	}

	float GetBalance() const
	{
		return _Balance;
	}

	__declspec(property(get = GetBalance, put = SetBalance)) float Balance;










	//Checks Methods

	bool IsEmpty() const
	{
		return _Mode == eEmptyMode;
	}

	static bool IsClientExist(const string& AccountNumber, const string& FileName, const string& Separator) 
	{
		return !Find(AccountNumber, FileName, Separator).IsEmpty();
	}









	//Get Ready Objects

	static clsBankClient GetAddNewClientObject(const string& AccountNumber)
	{

		return clsBankClient(eAddNewMode, "", "", "", "", AccountNumber, "", 0);
	}










	//Core Logic Methods

	static clsBankClient Find(const string& AccountNumber, const string& FileName, const string& Separator)
	{
		fstream File;

		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Line = "";
			
			while (getline(File, Line))
			{
				clsBankClient Client = _ConvertLineToClient(Line, Separator);

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

			while (getline(File, Line))
			{
				clsBankClient Client = _ConvertLineToClient(Line, Separator);

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

	void Deposit(float Amount, const string& FileName, const string& Separator)
	{
		_Balance += Amount;

		Save(FileName, Separator);
	}

	bool Withdraw(float Amount, const string& FileName, const string& Separator)
	{
		if (Amount > _Balance)
		{
			return false;
		}
		else
		{
			_Balance -= Amount;

			Save(FileName, Separator);

			return true;
		}

		return false;
	}

	enum enSaveResult{ svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExist = 2};

	enSaveResult Save(const string& FileName, const string& Separator) const
	{
		switch (_Mode)
		{

		case eEmptyMode:
		{
			if (IsEmpty())
			{
				return svFaildEmptyObject;
			}
		}

		case eUpdateMode:
		{
			_Update(FileName, Separator);

			return svSucceeded;
		}

		case eAddNewMode:

			if (IsClientExist(_AccountNumber, FileName, Separator))
			{
				return svFaildAccountNumberExist;
			}
			else
			{

				_AddNew(FileName, Separator);

				return svSucceeded;
			}
		}

	}

	bool Delete(const string& FileName, const string& Separator)
	{
		vector <clsBankClient> _vClients = _LoadAllClientsFromFile(FileName, Separator);


		for (clsBankClient& Client : _vClients)
		{
			if (Client._AccountNumber == _AccountNumber)
			{
				Client._MarkedForDelete = true;

				_SaveAllClientsToFile(_vClients, FileName, Separator);

				*this = _GetEmptyClient();

				return true;
			}
		}


		return false;

	}

	static vector <clsBankClient> GetClientsList(const string& FileName, const string& Separator)
	{
		return _LoadAllClientsFromFile(FileName, Separator);
	}

	static double GetTotalBalance(const string& FileName, const string& Separator)
	{
		const vector <clsBankClient> _vClients = _LoadAllClientsFromFile(FileName, Separator);

		double TotalBanace = 0;

		for (const clsBankClient& Client : _vClients)
		{
			TotalBanace += Client._Balance;
		}

		return TotalBanace;
	}





};