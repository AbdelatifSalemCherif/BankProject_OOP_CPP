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

	enum enMode { eEmptyMode = 0, eUpdateMode = 1, eAddNewMode = 2 };







	//Data Memebers

	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;








	





	//Methods help for reading and writing from database

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

	static void _AddRecordToFile(const string& Line, const string& FileName = "BankData/Users.txt")
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

	static clsBankUser _GetEmptyUser()
	{
		return clsBankUser(eEmptyMode, "", "", "", "", "", "", 0);
	}















	//Core logic

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



























	// Login Register Logic 

	string _ConvertUserInfoToLoginRecord(const string& Separator = "#//#") const
	{
		string Line = "";

		Line += clsDate::GetNowDateWithTime() + Separator;
		Line += _UserName + Separator;
		Line += GetFullName() + Separator;
		Line += Email + Separator;
		Line += Phone + Separator;
		Line += _Password + Separator;
		Line += to_string(_Permissions);

		return Line;
	}

	static vector <string> _ConvertLoginRecordToUserInfo(string& Record, const string& Separator = "#//#")
	{

		return clsString::Split(Record, Separator);

	}

	static vector <string> _LoadAllRecordsFromFile(const string& FileName = "BankData/LoginRegister.txt")
	{
		vector <string> vRecords ;

		fstream File;

		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Record = "";

			while (getline(File, Record))
			{

				if (Record != "")
				{
					vRecords.push_back(Record);
				}

			}

			File.close();
		}

		return vRecords;

	}












public:


	clsBankUser(enMode Mode, const string& FirstName, const string& LastName, const string& Email, const string& Phone
		, const string UserName, const string& Password, int Permissions) : clsPerson(FirstName, LastName, Email, Phone)
	{

		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;

	}












	// Permissions

	enum enPermissions { eAll = 0xFFFFFFFF, eClientsList = 0x01, eAddNewClient = 0x02, eDeleteClient = 0x04
		, eUpdateClient = 0x08, eFindClient = 0x10, eTransactions = 0x20, eManageUsers = 0x40};

















	//Properities

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

















	//Checks Methods

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























	//Get Ready Objects

	static clsBankUser GetAddNewUserObject(const string& UserName)
	{

		return clsBankUser(eAddNewMode, "", "", "", "", UserName, "", 0);
	}





















	//Core Logic Methods

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





























	// Login Register Logic

	void SaveLogin(const string& FileName = "BankData/LoginRegister.txt", const string& Separator = "#//#") const
	{

		_AddRecordToFile(_ConvertUserInfoToLoginRecord(Separator), FileName);



	}

	static vector <string> GetAllLoginRecords(const string& FileName = "BankData/LoginRegister.txt")
	{

		return _LoadAllRecordsFromFile(FileName);

	}

	static vector <string> SplitLoginRecord(string& Record, const string& Separator = "#//#")
	{
		return _ConvertLoginRecordToUserInfo(Record, Separator);
	}














};


