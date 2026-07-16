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

using namespace std;

class clsManageUsersScreen : protected clsScreen
{

private:

	enum enManageUsersMenuOptions {eUsersList = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eExit = 6};

	static void _GoBackToManageUsersScreen(const string& FileName, const string& Separator)
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowManageUsersMenu(FileName, Separator);
	}

	static void _ShowUsersListScreen(const string& FileName, const string& Separator)
	{
		clsUsersListScreen::ShowUsersListScreen(FileName, Separator);
	}

	static void _ShowAddNewUserScreen(const string& FileName, const string& Separator)
	{
		clsAddNewUserScreen::ShowAddNewUserScreen(FileName, Separator);
	}

	static void _ShowDeleteUserScreen(const string& FileName, const string& Separator)
	{
		clsDeleteUserScreen::ShowDeleteUserScreen(FileName, Separator);
	}

	static void _ShowUpdateUserScreen(const string& FileName, const string& Separator)
	{
		clsUpdateUserScreen::ShowUpdateUserScreen(FileName, Separator);
	}

	static void _ShowFindUserScreen(const string& FileName, const string& Separator)
	{
		cout << "\n\nFind User Screen Will Be Here...\n\n";
	}

	static void _PerformManageUsersMenuOption(enManageUsersMenuOptions Option, const string& FileName, const string& Separator)
	{
		switch (Option)
		{

		case eUsersList:
		{
			clsOutputSettings::RestScreen();

			_ShowUsersListScreen(FileName, Separator);

			_GoBackToManageUsersScreen(FileName, Separator);

			break;
		}

		case eAddNewUser:
		{

			clsOutputSettings::RestScreen();

			_ShowAddNewUserScreen(FileName, Separator);

			_GoBackToManageUsersScreen(FileName, Separator);

			break;
		}

		case eDeleteUser:
		{

			clsOutputSettings::RestScreen();

			_ShowDeleteUserScreen(FileName, Separator);

			_GoBackToManageUsersScreen(FileName, Separator);

			break;
		}

		case eUpdateUser:
		{
			clsOutputSettings::RestScreen();

			_ShowUpdateUserScreen(FileName, Separator);

			_GoBackToManageUsersScreen(FileName, Separator);

			break;
		}

		case eFindUser:
		{
			clsOutputSettings::RestScreen();

			_ShowFindUserScreen(FileName, Separator);

			_GoBackToManageUsersScreen(FileName, Separator);

			break;
		}

		case eExit:
		{

		}

		}

	}

public:

	static void ShowManageUsersMenu(const string& FileName, const string& Separator)
	{

		clsOutputSettings::RestScreen();

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