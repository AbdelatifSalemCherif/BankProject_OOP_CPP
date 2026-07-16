#pragma once

#include <iostream>
#include <iomanip>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "clsScreen.h"
#include "clsBankUser.h"

using namespace std;

class clsUsersListScreen : protected clsScreen
{

private:

	static void _PrintUserLineOfList(const clsBankUser& User)
	{
		cout << setw(8) << left << "";
		cout << "| " << left << setw(15) << User.UserName;
		cout << "| " << left << setw(20) << User.GetFullName();
		cout << "| " << left << setw(30) << User.Email;
		cout << "| " << left << setw(15) << User.Phone;
		cout << "| " << left << setw(10) << User.Password;
		cout << "| " << left << setw(15) << to_string(User.Permissions) << endl;
	}


public:


	static void ShowUsersListScreen(const string& FileName, const string& Separator)
	{
		vector <clsBankUser> vUsers = clsBankUser::GetUsersList(FileName, Separator);

		_DrawScreenHeader("Users List Screen", "(" + to_string(vUsers.size()) + ") Users.");


		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"--------------------------- " << endl;

		cout << setw(8) << left << "";
		cout << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(30) << "Email";
		cout << "| " << left << setw(15) << "Phone";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(15) << "Permissions" << endl;

		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"--------------------------- " << endl;

		if (vUsers.size() == 0)
		{
			cout << "\t\t\t\tNo Users Available In System !" << endl;
		}
		else
		{
			for (const clsBankUser& User : vUsers)
			{

				_PrintUserLineOfList(User);
			}
		}

		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"--------------------------- " << endl;
	}

};