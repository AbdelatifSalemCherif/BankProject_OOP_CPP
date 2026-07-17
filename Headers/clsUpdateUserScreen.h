#pragma once

#include <iostream>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "clsScreen.h"
#include "clsBankUser.h"

using namespace std;

class clsUpdateUserScreen : protected clsScreen
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
			Permissions += clsBankUser::eClientsList;
		}

		if (clsInputSettings::ReadYesOrNo("\n\nAdd New Client ? y/n ? "))
		{
			Permissions += clsBankUser::eAddNewClient;
		}

		if (clsInputSettings::ReadYesOrNo("\n\nDelete Client ? y/n ? "))
		{
			Permissions += clsBankUser::eDeleteClient;
		}

		if (clsInputSettings::ReadYesOrNo("\n\nUpdate Client ? y/n ? "))
		{
			Permissions += clsBankUser::eUpdateClient;
		}

		if (clsInputSettings::ReadYesOrNo("\n\nFind Client ? y/n ? "))
		{
			Permissions += clsBankUser::eFindClient;
		}

		if (clsInputSettings::ReadYesOrNo("\n\nTransactions ? y/n ? "))
		{
			Permissions += clsBankUser::eTransactions;
		}

		if (clsInputSettings::ReadYesOrNo("\n\nManage Users ? y/n ? "))
		{
			Permissions += clsBankUser::eManageUsers;
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

	static void ShowUpdateUserScreen()
	{

		_DrawScreenHeader("Update User Screen");

		clsBankUser User = clsBankUser::Find(clsInputSettings::ReadString("\nPlease enter UserName ? "));

		while (User.IsEmpty())
		{
			User =
				clsBankUser::Find(
					clsInputSettings::ReadString("\nUserName don\'t exist, Please enter another UserName ? "));
		}

		_PrintUserCard(User);

		if (clsInputSettings::ReadYesOrNo("\n\nDo you want to update this user ? y/n ?"))
		{
			cout << "\n\nUpdating User Info : " << endl;

			_ReadUserInfo(User);

			if (User.Save() == clsBankUser::svSucceeded)
			{
				cout << "\n\nUser was Saved Successfully :-) ";
			}
			else
			{
				cout << "\n\nUser wasn\'t Saved, is an empty user ! ";
			}
		}
		else
		{

			cout << "\n\nUser wasn\'t Update! ";
		}

	}


};