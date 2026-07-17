#pragma once

#include <iostream>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "clsScreen.h"
#include "clsBankUser.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
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

	static void ShowDeleteUserScreen()
	{

		_DrawScreenHeader("Delete User Screen");

		clsBankUser User = clsBankUser::Find(clsInputSettings::ReadString("\nPlease enter UserName ? "));

		while (User.IsEmpty())
		{
			User =
				clsBankUser::Find(clsInputSettings::ReadString("\nUserName don\'t exist, Please enter another UserName ? "));
		}

		_PrintUserCard(User);


		if (clsInputSettings::ReadYesOrNo("\n\nDo you want to delete this user ? y/n ? "))
		{

			if (User.Delete())
			{
				cout << "\n\nUser deleted successfully :-) " << endl;

				_PrintUserCard(User);
			}
			else
			{
				cout << "\n\nUser hasn\'t deleted !" << endl;
			}



		}
		else
		{
			cout << "\n\nUser hasn\'t deleted !" << endl;
		}

	}


};