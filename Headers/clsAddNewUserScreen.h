#pragma once

#include <iostream>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "clsScreen.h"
#include "clsBankUser.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{

private:

	static int _ReadPermissions()
	{

		if (clsInputSettings::ReadYesOrNo("\n\nDo you want to give full access ? y/n ? "))
		{
			return clsBankUser::eAll;
		}

		int Permissions = 0;

		cout << "\n\nDo you want to give access to :";

		if (clsInputSettings::ReadYesOrNo("\n\nShow Clients List ? y/n ? "))
		{
			Permissions += clsBankUser::prmClientsList;
		}

		if (clsInputSettings::ReadYesOrNo("\n\nAdd New Client ? y/n ? "))
		{
			Permissions += clsBankUser::prmAddNewClient;
		}

		if (clsInputSettings::ReadYesOrNo("\n\nDelete Client ? y/n ? "))
		{
			Permissions += clsBankUser::prmDeleteClient;
		}

		if (clsInputSettings::ReadYesOrNo("\n\nUpdate Client ? y/n ? "))
		{
			Permissions += clsBankUser::prmUpdateClient;
		}

		if (clsInputSettings::ReadYesOrNo("\n\nFind Client ? y/n ? "))
		{
			Permissions += clsBankUser::prmFindClient;
		}

		if (clsInputSettings::ReadYesOrNo("\n\nTransactions ? y/n ? "))
		{
			Permissions += clsBankUser::prmTransactions;
		}

		if (clsInputSettings::ReadYesOrNo("\n\nManage Users ? y/n ? "))
		{
			Permissions += clsBankUser::prmManageUsers;
		}

		return Permissions;
	}

	static void _ReadUserInfo(clsBankUser& User)
	{
		User.FirstName = clsInputSettings::ReadString("\nPlease enter First Name : ");
		User.LastName = clsInputSettings::ReadString("\nPlease enter Last Name : ");
		User.Email = clsInputSettings::ReadString("\nPlease enter Email : ");
		User.Phone = clsInputSettings::ReadString("\nPlease enter Phone : ");
		User.Password = clsInputSettings::ReadString("\nPlease enter Password : ");
		User.Permissions = _ReadPermissions();

	}

	static void _PrintUserCard(const clsBankUser& User)
	{
		cout << "\nUser Card :" << endl;
		cout << "------------------------------------------------" << endl;
		cout << "First Name  :" << User.FirstName << endl;
		cout << "Last Name   :" << User.LastName << endl;
		cout << "Full Name   :" << User.GetFullName() << endl;
		cout << "Email       :" << User.Email << endl;
		cout << "Phone       :" << User.Phone << endl;
		cout << "UserName    :" << User.UserName << endl;
		cout << "Password    :" << User.Password << endl;
		cout << "Permissions :" << User.Permissions << endl;
		cout << "------------------------------------------------" << endl;

	}


public:

	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("Add New User Screen");

		string UserName = clsInputSettings::ReadString("\nPlease enter UserName : ");

		while (clsBankUser::IsUserExist(UserName))
		{
			UserName = clsInputSettings::ReadString("\nThis UserName is exist, Please enter another UserName : ");
		}

		clsBankUser NewUser = clsBankUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUser);

		switch (NewUser.Save())
		{
		case clsBankUser::svFaildEmptyObject:
		{
			cout << "\nFaild, is an empty user !" << endl;

			break;
		}

		case clsBankUser::svFaildUserNameExist:
		{
			cout << "\nFaild, UserName exist !" << endl;

			break;
		}

		case clsBankUser::svSucceeded:
		{
			cout << "\nUser added successfuly :-) " << endl << endl;

			_PrintUserCard(NewUser);

			break;
		}

		}

	}


};


