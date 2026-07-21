#pragma once

#include <iostream>
#include <iomanip>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "Global.h"
#include "clsScreen.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyMainScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{

private:

	enum enMainMenuOptions { eClientsList = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClientInfo = 4, eFindClient = 5
		, eTransactions = 6, eManageUsers = 7, eLoginRegister = 8, eCurrencyMainMenu = 9, eExit = 10};

	static void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenu();
	}

	static void _ShowClientListScreen()
	{
		clsClientsListScreen::ShowClientsListScreen();
	}

	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientInfoScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}
	
	static void _TransactionsMenu()
	{
		clsTransactionsScreen::ShowTransactionsMenu();
	}

	static void _ShowManageUsersMenu()
	{
		clsManageUsersScreen::ShowManageUsersMenu();
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyMainScreen()
	{
		clsCurrencyMainScreen::ShowCurrencyMainMenu();
	}

	static void _Logout()
	{
		CurrentUser = clsBankUser::FindByUserNameAndPassword("", "");
	}

	static void _PerformMainMenuOption(enMainMenuOptions MainOption)
	{
		switch (MainOption)
		{
		case eClientsList:
		{
			clsOutputSettings::RestScreen();

			_ShowClientListScreen();

			_GoBackToMainMenu();

			break;
		}

		case eAddNewClient:
		{
			clsOutputSettings::RestScreen();

			_ShowAddNewClientScreen();

			_GoBackToMainMenu();

			break;
		}

		case eDeleteClient:
		{
			clsOutputSettings::RestScreen();

			_ShowDeleteClientScreen();

			_GoBackToMainMenu();

			break;
		}

		case eUpdateClientInfo:
		{
			clsOutputSettings::RestScreen();

			_ShowUpdateClientInfoScreen();

			_GoBackToMainMenu();

			break;
		}

		case eFindClient:
		{
			clsOutputSettings::RestScreen();

			_ShowFindClientScreen();

			_GoBackToMainMenu();

			break;
		}

		case eTransactions:
		{
			clsOutputSettings::RestScreen();

			_TransactionsMenu();

			_GoBackToMainMenu();

			break;
		}

		case eManageUsers:
		{
			clsOutputSettings::RestScreen();

			_ShowManageUsersMenu();

			_GoBackToMainMenu();

			break;
		}

		case eLoginRegister:
		{
			clsOutputSettings::RestScreen();

			_ShowLoginRegisterScreen();

			_GoBackToMainMenu();

			break;
		}

		case eCurrencyMainMenu:
		{
			clsOutputSettings::RestScreen();

			_ShowCurrencyMainScreen();

			_GoBackToMainMenu();

			break;
		}

		case eExit:
		{
			clsOutputSettings::RestScreen();

			_Logout();

			break;
		}

		}
	}



public:

	
	static void ShowMainMenu()
	{
		clsOutputSettings::RestScreen();

		_DrawScreenHeader("Main Screen");

		cout << endl;
		
		cout << setw(37) << left << "" << "===================================================================\n\n";
		cout << setw(37) << left << "" << "\t\t\t\tMain Menu\n\n";
		cout << setw(37) << left << "" << "===================================================================\n\n";

		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Main Menu.\n";
		cout << setw(37) << left << "" << "\t[10] Exit.\n\n";

		cout << setw(37) << left << "" << "===================================================================\n\n";


		cout << setw(37) << left << "";
		_PerformMainMenuOption((enMainMenuOptions)
			clsInputSettings::ReadShortInRange(1, 10, "Choose What Do You Want To Do ? [1 to 10] ? "));


	}



};