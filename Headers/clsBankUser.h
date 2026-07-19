#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Global.h"
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"


using namespace std;

class clsBankUser : public clsPerson
{

private:


	//----------------------------------------------- Data Memebers ------------------------------------------------------------------

	enum enMode { eEmptyMode = 0, eUpdateMode = 1, eAddNewMode = 2 };
	enMode _Mode;

	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;



	// ------------------------------ Methods help for reading and writing from database ---------------------------------------------

	static clsBankUser _ConvertRecordToUser(const string& Record, const string& Separator = "#//#")
	{
		vector <string> vClient = clsString::Split(Record, Separator, false);

		return clsBankUser(eUpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4]
			, vClient[5], stoi(vClient[6]));

	}

	static string _ConvertUserToRecord(const clsBankUser& User, const string& Separator = "#//#")
	{
		string Record = "";

		Record += User.FirstName + Separator;
		Record += User.LastName + Separator;
		Record += User.Email + Separator;
		Record += User.Phone + Separator;
		Record += User._UserName + Separator;
		Record += User._Password + Separator;
		Record += to_string(User._Permissions);

		return Record;
	}

	static vector <clsBankUser> _LoadAllUsersFromFile(const string& FileName = "BankData/Users.txt", const string& Separator = "#//#")
	{
		vector <clsBankUser> vUsers;

		fstream File;

		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Record = "";

			while (getline(File, Record))
			{

				vUsers.push_back(_ConvertRecordToUser(Record, Separator));

			}

			File.close();
		}

		return vUsers;
	}

	static void _SaveAllUsersToFile(const vector <clsBankUser>& vUsers, const string& FileName = "BankData/Users.txt"
	, const string& Separator = "#//#")
	{
		fstream File;

		File.open(FileName, ios::out);

		if (File.is_open())
		{

			for (const clsBankUser& User : vUsers)
			{
				if (!User._MarkedForDelete)
				{
					File << _ConvertUserToRecord(User, Separator) + "\n";
				}
			}

			File.close();
		}

	}

	static void _AddRecordToFile(const string& Record, const string& FileName = "BankData/Users.txt")
	{
		fstream File;

		File.open(FileName, ios::out | ios::app);

		if (File.is_open())
		{

			File << Record + "\n";

			File.close();
		}

	}




	// -------------------------------------------- Get Ready Objects ---------------------------------------------------------

	static clsBankUser _GetEmptyUser()
	{
		return clsBankUser(eEmptyMode, "", "", "", "", "", "", 0);
	}




	// ------------------------------------------------ Core logic -------------------------------------------------------------

	void _Update() const
	{
		vector <clsBankUser> _vUsers = _LoadAllUsersFromFile();

		for (clsBankUser& User : _vUsers)
		{
			if (User._UserName == _UserName)
			{
				User = *this;

				break;
			}
		}

		_SaveAllUsersToFile(_vUsers);

	}

	void _AddNew() const
	{

		_AddRecordToFile(_ConvertUserToRecord(*this));

	}




	// ------------------------------------------- Login Register Logic ---------------------------------------------------------

	struct stLoginRegister;

	stLoginRegister _GetNewLoginRegister() const
	{
		stLoginRegister LoginRegister;

		LoginRegister.Time = clsDate::GetNowDateWithTime();
		LoginRegister.UserName = _UserName;
		LoginRegister.FullName = GetFullName();
		LoginRegister.Email = Email;
		LoginRegister.Phone = Phone;
		LoginRegister.Password = _Password;
		LoginRegister.Permissions = _Permissions;


		return LoginRegister;

	}

	static stLoginRegister _ConvertRecordToLoginRegister(string& Record, const string& Separator = "#//#")
	{
		vector <string> vRecord = clsString::Split(Record, Separator);

		stLoginRegister LoginRegister;

		LoginRegister.Time = vRecord[0];
		LoginRegister.UserName = vRecord[1];
		LoginRegister.FullName = vRecord[2];
		LoginRegister.Email = vRecord[3];
		LoginRegister.Phone = vRecord[4];
		LoginRegister.Password = vRecord[5];
		LoginRegister.Permissions = stoi(vRecord[6]);

		return LoginRegister;

	}

	static string _ConvertLoginRegisterToRecord(stLoginRegister LoginRegister, const string& Separator = "#//#") 
	{
		string Record = "";

		Record += LoginRegister.Time + Separator;
		Record += LoginRegister.UserName + Separator;
		Record += LoginRegister.FullName + Separator;
		Record += LoginRegister.Email + Separator;
		Record += LoginRegister.Phone + Separator;
		Record += LoginRegister.Password + Separator;
		Record += to_string(LoginRegister.Permissions);

		return Record;
	}

	static vector <stLoginRegister> _LoadAllLoginRegisterFromFile(const string& FileName = "BankData/LoginRegister.txt")
	{
		vector <stLoginRegister> vLoginRegisters ;

		fstream File;

		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Record = "";

			while (getline(File, Record))
			{

				if (Record != "")
				{
					vLoginRegisters.push_back(_ConvertRecordToLoginRegister(Record));
				}

			}

			File.close();
		}

		return vLoginRegisters;

	}






public:





	// ------------------------------------------------- Constructors -------------------------------------------------------------
	  
	clsBankUser(enMode Mode, const string& FirstName, const string& LastName, const string& Email, const string& Phone
		, const string UserName, const string& Password, int Permissions) : clsPerson(FirstName, LastName, Email, Phone)
	{

		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;

	}




	// -------------------------------------------------- Permissions -----------------------------------------------------------

	enum enPermissions { eAll = 0xFFFFFFFF, prmClientsList = 0x01, prmAddNewClient = 0x02, prmDeleteClient = 0x04
		, prmUpdateClient = 0x08, prmFindClient = 0x10, prmTransactions = 0x20, prmManageUsers = 0x40, prmLoginRegister = 0x08};





	// -------------------------------------------------- Properities ------------------------------------------------------------

	void SetUserName(const string& UserName)
	{
		_UserName = UserName;
	}

	string GetUserName() const
	{
		return _UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(const string& Password)
	{
		_Password = Password;
	}

	string GetPassword() const
	{
		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	int GetPermissions() const
	{
		return _Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;




	// --------------------------------------------------- Checks Methods -------------------------------------------------------

	bool IsEmpty() const
	{
		return _Mode == eEmptyMode;
	}

	static bool IsUserExist(const string& UserName)
	{
		return !FindByUserName(UserName).IsEmpty();
	}

	bool CheckAccessPermission(enPermissions Permission)
	{
		return (_Permissions & Permission) == Permission;

	}



	// -------------------------------------------------- Get Ready Objects ------------------------------------------------------

	static clsBankUser GetAddNewUserObject(const string& UserName)
	{

		return clsBankUser(eAddNewMode, "", "", "", "", UserName, "", 0);
	}




	// ------------------------------------------------- Core Logic Methods -------------------------------------------------------

	static clsBankUser FindByUserName(const string& UserName, const string& FileName = "BankData/Users.txt"
		, const string& Separator = "#//#")
	{
		fstream File;

		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Record = "";

			while (getline(File, Record))
			{
				clsBankUser User = _ConvertRecordToUser(Record, Separator);

				if (User._UserName == UserName)
				{
					File.close();

					return User;
				}
			}

			File.close();

		}

		return _GetEmptyUser();

	}

	static clsBankUser FindByUserNameAndPassword(const string& UserName, const string& Password
		, const string& FileName = "BankData/Users.txt", const string& Separator = "#//#")
	{
		fstream File;

		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Record = "";

			while (getline(File, Record))
			{
				clsBankUser User = _ConvertRecordToUser(Record, Separator);

				if (User._UserName == UserName && User._Password == Password)
				{
					File.close();

					return User;
				}
			}

			File.close();

		}

		return _GetEmptyUser();

	}

	enum enSaveResult { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserNameExist = 2 };

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

			if (IsUserExist(_UserName))
			{
				return svFaildUserNameExist;
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
		vector <clsBankUser> _vUsers = _LoadAllUsersFromFile();


		for (clsBankUser& User : _vUsers)
		{
			if (User._UserName == _UserName)
			{
				User._MarkedForDelete = true;

				_SaveAllUsersToFile(_vUsers);

				*this = _GetEmptyUser();

				return true;
			}
		}


		return false;

	}

	static vector <clsBankUser> GetUsersList()
	{
		return _LoadAllUsersFromFile();
	}



	// -------------------------------------------------- Login Register Logic ------------------------------------------------------

	struct stLoginRegister
	{
		string Time;
		string UserName;
		string FullName;
		string Email;
		string Phone;
		string Password;
		int Permissions;
	};

	void SaveNewLogin(const string& FileName = "BankData/LoginRegister.txt", const string& Separator = "#//#") const
	{

		_AddRecordToFile(_ConvertLoginRegisterToRecord(_GetNewLoginRegister(), Separator), FileName);



	}

	static vector <stLoginRegister> GetAllLoginReristerList(const string& FileName = "BankData/LoginRegister.txt")
	{

		return _LoadAllLoginRegisterFromFile(FileName);

	}






};


