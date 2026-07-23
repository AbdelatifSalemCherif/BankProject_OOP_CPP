#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "clsString.h"
#include "clsUtility.h"
#include "clsPerson.h"
#include "Global.h"

using namespace std;

class clsBankClient : public clsPerson
{

private:


	// ------------------------------------------------ Data Memebers ----------------------------------------------------------------

	enum enMode { eEmptyMode = 0, eUpdateMode = 1, eAddNewMode = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _Balance;
	bool _MarkedForDelete = false;



	// --------------------------------- Methods help for reading and writing from database -------------------------------------------

	static clsBankClient _ConvertRecordToClient(const string& Record, const string& Separator = "#//#")
	{
		vector <string> vClient = clsString::Split(Record, Separator, false);

		return clsBankClient(eUpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4]
			, clsUtility::DecryptWord(vClient[5], 2), stof(vClient[6]));

	}

	static string _ConvertClientToRecord(const clsBankClient& Client, const string& Separator = "#//#")
	{
		string Record = "";

		Record += Client.FirstName + Separator;
		Record += Client.LastName + Separator;
		Record += Client.Email + Separator;
		Record += Client.Phone + Separator;
		Record += Client._AccountNumber + Separator;
		Record += clsUtility::EncryptWord(Client._PinCode, 2) + Separator;
		Record += to_string(Client._Balance);

		return Record;
	}

	static vector <clsBankClient> _LoadAllClientsFromFile(const string& FileName = "BankData/Clients.txt")
	{
		vector <clsBankClient> vClients;

		fstream File;

		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Record = "";

			while (getline(File, Record))
			{

				vClients.push_back(_ConvertRecordToClient(Record));

			}

			File.close();
		}

		return vClients;
	}

	static void _SaveAllClientsToFile(const vector <clsBankClient>& vClients, const string& FileName = "BankData/Clients.txt")
	{
		fstream File;

		File.open(FileName, ios::out);

		if (File.is_open())
		{

			for (const clsBankClient& Client : vClients)
			{
				if (!Client._MarkedForDelete)
				{
					File << _ConvertClientToRecord(Client) + "\n";
				}
			}

			File.close();
		}

	}

	static void _AddRecordToFile(const string& Record, const string& FileName = "BankData/Clients.txt")
	{
		fstream File;

		File.open(FileName, ios::out | ios::app);

		if (File.is_open())
		{

			File << Record + "\n";

			File.close();
		}

	}


	// ------------------------------------------------ Get Ready Objects --------------------------------------------------------------

	static clsBankClient _GetEmptyClient()
	{
		return clsBankClient(eEmptyMode, "", "", "", "", "", "", 0);
	}


	// --------------------------------------------------- Core logic ------------------------------------------------------------------

	void _Update() const
	{
		vector <clsBankClient> _vClients = _LoadAllClientsFromFile();

		for (clsBankClient& Client : _vClients)
		{
			if (Client._AccountNumber == _AccountNumber)
			{
				Client = *this;

				break;
			}
		}

		_SaveAllClientsToFile(_vClients);

	}

	void _AddNew() const
	{
		
		_AddRecordToFile(_ConvertClientToRecord(*this));

	}


	// ------------------------------------------------ Transfer Register -------------------------------------------------------------- 

	struct stTransferRegister;

	void _SaveNewTransferRegister(float Amount, const clsBankClient& DestinationClient,
		const string& FileName = "BankData/TransferRegister.txt", const string& Separator = "#//#") const
	{

		_AddRecordToFile(_ConvertTransferRegisterToRecord(_GetNewTransferRegister(Amount, DestinationClient), Separator), FileName);


	}

	stTransferRegister _GetNewTransferRegister(float Amount, const clsBankClient& DestinastionClient) const
	{
		stTransferRegister TransferRegister;

		TransferRegister.Time = clsDate::GetNowDateWithTime();
		TransferRegister.SourceAccountNumber = _AccountNumber;
		TransferRegister.DestinationAccountNumber = DestinastionClient._AccountNumber;
		TransferRegister.Amount = Amount;
		TransferRegister.SourceNewBalance = _Balance;
		TransferRegister.DestinationNewBalance = DestinastionClient._Balance;
		TransferRegister.UserName = CurrentUser.UserName;


		return TransferRegister;

	}

	static stTransferRegister _ConvertRecordToTransferRegister(string& Record, const string& Separator = "#//#")
	{
		vector <string> vRecord = clsString::Split(Record, Separator);

		stTransferRegister TransferRegister;

		TransferRegister.Time = vRecord[0];
		TransferRegister.SourceAccountNumber = vRecord[1];
		TransferRegister.DestinationAccountNumber = vRecord[2];
		TransferRegister.Amount = stof(vRecord[3]);
		TransferRegister.SourceNewBalance = stof(vRecord[4]);
		TransferRegister.DestinationNewBalance = stof(vRecord[5]);
		TransferRegister.UserName = vRecord[6];

		return TransferRegister;

	}

	static string _ConvertTransferRegisterToRecord(const stTransferRegister& TransferRegister, const string& Separator = "#//#")
	{
		string Record = "";

		Record += TransferRegister.Time + Separator;
		Record += TransferRegister.SourceAccountNumber + Separator;
		Record += TransferRegister.DestinationAccountNumber + Separator;
		Record += to_string(TransferRegister.Amount) + Separator;
		Record += to_string(TransferRegister.SourceNewBalance) + Separator;
		Record += to_string(TransferRegister.DestinationNewBalance) + Separator;
		Record += TransferRegister.UserName;

		return Record;
	}

	static vector <stTransferRegister> _LoadAllTransferRegisterFromFile(const string& FileName = "BankData/TransferRegister.txt")
	{
		vector <stTransferRegister> vTransferRegisters;

		fstream File;

		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Record = "";

			while (getline(File, Record))
			{

				if (Record != "")
				{
					vTransferRegisters.push_back(_ConvertRecordToTransferRegister(Record));
				}

			}

			File.close();
		}

		return vTransferRegisters;

	}




public:



	// --------------------------------------------------- Constructors ----------------------------------------------------------------

	clsBankClient(enMode Mode, const string& FirstName, const string& LastName, const string& Email, const string& Phone
		, const string AccountNumber, const string& PinCode, float Balance) : clsPerson(FirstName, LastName, Email, Phone)
	{

		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_Balance = Balance;

	}


	// ---------------------------------------------------- Properities ----------------------------------------------------------------

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



	// ---------------------------------------------------- Checks Methods -------------------------------------------------------------

	bool IsEmpty() const
	{
		return _Mode == eEmptyMode;
	}

	static bool IsClientExist(const string& AccountNumber) 
	{
		return !Find(AccountNumber).IsEmpty();
	}



	// --------------------------------------------------- Get Ready Objects -----------------------------------------------------------

	static clsBankClient GetAddNewClientObject(const string& AccountNumber)
	{

		return clsBankClient(eAddNewMode, "", "", "", "", AccountNumber, "", 0);
	}



	// --------------------------------------------------- Core Logic Methods ----------------------------------------------------------

	static clsBankClient Find(const string& AccountNumber, const string& FileName = "BankData/Clients.txt")
	{
		fstream File;

		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Record = "";
			
			while (getline(File, Record))
			{
				clsBankClient Client = _ConvertRecordToClient(Record);

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

	static clsBankClient Find(const string& AccountNumber, const string& PinCode, const string& FileName = "BankData/Clients.txt")
	{
		fstream File;

		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Record = "";

			while (getline(File, Record))
			{
				clsBankClient Client = _ConvertRecordToClient(Record);

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

	void Deposit(float Amount)
	{
		_Balance += Amount;

		Save();
	}

	bool Withdraw(float Amount)
	{
		if (Amount > _Balance)
		{
			return false;
		}
		else
		{
			_Balance -= Amount;

			Save();

			return true;
		}

		return false;
	}

	bool Transfer(float Amount, clsBankClient& DestinationClient)
	{

		if (_AccountNumber == DestinationClient._AccountNumber || !Withdraw(Amount))
		{
			return false;
		}

		DestinationClient.Deposit(Amount);

		_SaveNewTransferRegister(Amount, DestinationClient);

		return true;

	}

	enum enSaveResult{ svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExist = 2};

	enSaveResult Save() const
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
			_Update();

			return svSucceeded;
		}

		case eAddNewMode:

			if (IsClientExist(_AccountNumber))
			{
				return svFaildAccountNumberExist;
			}
			else
			{

				_AddNew();

				return svSucceeded;
			}
		}

	}

	bool Delete()
	{
		vector <clsBankClient> _vClients = _LoadAllClientsFromFile();


		for (clsBankClient& Client : _vClients)
		{
			if (Client._AccountNumber == _AccountNumber)
			{
				Client._MarkedForDelete = true;

				_SaveAllClientsToFile(_vClients);

				*this = _GetEmptyClient();

				return true;
			}
		}


		return false;

	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadAllClientsFromFile();
	}

	static double GetTotalBalance()
	{
		const vector <clsBankClient> _vClients = _LoadAllClientsFromFile();

		double TotalBanace = 0;

		for (const clsBankClient& Client : _vClients)
		{
			TotalBanace += Client._Balance;
		}

		return TotalBanace;
	}

	

	// ---------------------------------------------------- Transfer Register Logic ----------------------------------------------------

	struct stTransferRegister
	{
		string Time, SourceAccountNumber, DestinationAccountNumber, UserName;

		float SourceNewBalance, DestinationNewBalance, Amount;

	};

	static vector <stTransferRegister> GetAllTransferRegisterList()
	{
		return _LoadAllTransferRegisterFromFile();
	}


};