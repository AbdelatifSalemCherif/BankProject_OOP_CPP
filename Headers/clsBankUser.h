#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


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

	static clsBankUser _ConvertLineToUser(const string& Line, const string& Separator)
	{
		vector <string> vClient = clsString::Split(Line, Separator, false);

		return clsBankUser(eUpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4]
			, vClient[5], stoi(vClient[6]));

	}

	static string _ConvertUserToLine(const clsBankUser& User, const string& Separator)
	{
		string Line = "";

		Line += User.FirstName + Separator;
		Line += User.LastName + Separator;
		Line += User.Email + Separator;
		Line += User.Phone + Separator;
		Line += User._UserName + Separator;
		Line += User._Password + Separator;
		Line += to_string(User._Permissions);

		return Line;
	}

	static vector <clsBankUser> _LoadAllUsersFromFile(const string& FileName, const string& Separator)
	{
		vector <clsBankUser> vUsers;

		fstream File;

		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Line = "";

			while (getline(File, Line))
			{

				vUsers.push_back(_ConvertLineToUser(Line, Separator));

			}

			File.close();
		}

		return vUsers;
	}

	static void _SaveAllUsersToFile(const vector <clsBankUser>& vUsers, const string& FileName, const string& Separator)
	{
		fstream File;

		File.open(FileName, ios::out);

		if (File.is_open())
		{

			for (const clsBankUser& User : vUsers)
			{
				if (!User._MarkedForDelete)
				{
					File << _ConvertUserToLine(User, Separator) + "\n";
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

	static clsBankUser _GetEmptyUser()
	{
		return clsBankUser(eEmptyMode, "", "", "", "", "", "", 0);
	}















	//Core logic

	void _Update(const string& FileName, const string& Separator) const
	{
		vector <clsBankUser> _vUsers = _LoadAllUsersFromFile(FileName, Separator);

		for (clsBankUser& User : _vUsers)
		{
			if (User._UserName == _UserName)
			{
				User = *this;

				break;
			}
		}

		_SaveAllUsersToFile(_vUsers, FileName, Separator);

	}

	void _AddNew(const string& FileName, const string& Separator) const
	{

		_AddLineToFile(_ConvertUserToLine(*this, Separator), FileName, Separator);

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











};


