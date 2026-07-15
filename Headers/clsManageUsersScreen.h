#pragma once

#include <iostream>
#include <iomanip>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "clsScreen.h"

class clsManageUsersScreen : protected clsScreen
{

private:

	enum enManageUsersMenuOptions {eUsersList = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eExit = 6};

	static void _PerformManageUsersMenuOption(enManageUsersMenuOptions Option, const string& FileName, const string& Separator)
	{




	}

public:

	static void ShowManageUsersMenu(const string& FileName, const string& Separator)
	{

		_DrawScreenHeader("Manage Users Screen");

		cout << endl;

		cout << setw(37) << left << "" << "===================================================================\n\n";
		cout << setw(37) << left << "" << "\t\t\t\tManage Users Menu\n\n";
		cout << setw(37) << left << "" << "===================================================================\n\n";

		cout << setw(37) << left << "" << "\t[1] Show Users List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Exit.\n\n";

		cout << setw(37) << left << "" << "===================================================================\n\n";


		cout << setw(37) << left << "";
		_PerformManageUsersMenuOption((enManageUsersMenuOptions)
			clsInputSettings::ReadShortInRange(1, 6, "Choose What Do You Want To Do ? [1 to 6] ? "),
			FileName, Separator);


	}


};