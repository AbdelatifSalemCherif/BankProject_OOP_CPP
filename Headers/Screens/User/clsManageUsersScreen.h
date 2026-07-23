#pragma once

#include <iostream>
#include <iomanip>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "clsScreen.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsManageUsersScreen : protected clsScreen
{

private:

	enum enManageUsersMenuOptions {eUsersList = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eExit = 6};

	static void _GoBackToManageUsersScreen()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowManageUsersMenu();
	}

	static void _ShowUsersListScreen()
	{
		clsUsersListScreen::ShowUsersListScreen();
	}

	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersMenuOption(enManageUsersMenuOptions Option)
	{
		switch (Option)
		{

		case eUsersList:
		{
			clsOutputSettings::RestScreen();

			_ShowUsersListScreen();

			_GoBackToManageUsersScreen();

			break;
		}

		case eAddNewUser:
		{

			clsOutputSettings::RestScreen();

			_ShowAddNewUserScreen();

			_GoBackToManageUsersScreen();

			break;
		}

		case eDeleteUser:
		{

			clsOutputSettings::RestScreen();

			_ShowDeleteUserScreen();

			_GoBackToManageUsersScreen();

			break;
		}

		case eUpdateUser:
		{
			clsOutputSettings::RestScreen();

			_ShowUpdateUserScreen();

			_GoBackToManageUsersScreen();

			break;
		}

		case eFindUser:
		{
			clsOutputSettings::RestScreen();

			_ShowFindUserScreen();

			_GoBackToManageUsersScreen();

			break;
		}

		case eExit:
		{

		}

		}

	}

public:

	static void ShowManageUsersMenu()
	{

		clsOutputSettings::RestScreen();

		if (!_CheckAccessRights(clsBankUser::prmManageUsers))
		{
			return;
		}

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
			clsInputSettings::ReadNumberInRange(1, 6, "Choose What Do You Want To Do ? [1 to 6] ? "));


	}


};