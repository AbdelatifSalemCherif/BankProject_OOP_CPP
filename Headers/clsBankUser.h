#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Global.h"
#include "clsPerson.h"
#include "clsString.h"


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

	static clsBankUser _ConvertLineToUser(const string& Line)
	{
		vector <string> vClient = clsString::Split(Line, "#//#", false);

		return clsBankUser(eUpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4]
			, vClient[5], stoi(vClient[6]));

	}

	static string _ConvertUserToLine(const clsBankUser& User)
	{
		string Line = "";

		Line += User.FirstName + "#//#";
		Line += User.LastName + "#//#";
		Line += User.Email + "#//#";
		Line += User.Phone + "#//#";
		Line += User._UserName + "#//#";
		Line += User._Password + "#//#";
		Line += to_string(User._Permissions);

		return Line;
	}

	static vector <clsBankUser> _LoadAllUsersFromFile()
	{
		vector <clsBankUser> vUsers;

		fstream File;

		File.open("BankData/Users.txt", ios::in);

		if (File.is_open())
		{
			string Line = "";

			while (getline(File, Line))
			{

				vUsers.push_back(_ConvertLineToUser(Line));

			}

			File.close();
		}

		return vUsers;
	}

	static void _SaveAllUsersToFile(const vector <clsBankUser>& vUsers)
	{
		fstream File;

		File.open("BankData/Users.txt", ios::out);

		if (File.is_open())
		{

			for (const clsBankUser& User : vUsers)
			{
				if (!User._MarkedForDelete)
				{
					File << _ConvertUserToLine(User) + "\n";
				}
			}

			File.close();
		}

	}

	static void _AddLineToFile(const string& Line)
	{
		fstream File;

		File.open("BankData/Users.txt", ios::out | ios::app);

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

		_AddLineToFile(_ConvertUserToLine(*this));

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
		return !Find(UserName).IsEmpty();
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

	static clsBankUser Find(const string& UserName)
	{
		fstream File;

		File.open("BankData/Users.txt", ios::in);

		if (File.is_open())
		{
			string Line = "";

			while (getline(File, Line))
			{
				clsBankUser User = _ConvertLineToUser(Line);

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

	static clsBankUser Find(const string& UserName, const string& Password)
	{
		fstream File;

		File.open("BankData/Users.txt", ios::in);

		if (File.is_open())
		{
			string Line = "";

			while (getline(File, Line))
			{
				clsBankUser User = _ConvertLineToUser(Line);

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



};


