#pragma once

#include <iostream>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "clsScreen.h"
#include "clsBankUser.h"

using namespace std;

class clsFindUserScreen : protected clsScreen
{

private:

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

	static void ShowFindUserScreen()
	{

		_DrawScreenHeader("Find User Screen");

		clsBankUser User = clsBankUser::FindByUserName(clsInputSettings::ReadString("\nPlease enter UserName ? "));

		while (User.IsEmpty())
		{
			User =
				clsBankUser::FindByUserName(clsInputSettings::ReadString("\nUserName don\'t exist, Please enter another UserName ? "));
		}


		if (User.IsEmpty())
		{
			cout << "\n\nUser was\'t found, is an empty user !" << endl;
		}
		else
		{
			cout << "\n\nUser was found :-)" << endl;

			_PrintUserCard(User);
		}



	}

};
