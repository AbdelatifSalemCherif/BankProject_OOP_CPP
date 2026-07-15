#pragma once

#include <iostream>
#include <iomanip>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "clsScreen.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{

private:

	enum enMainMenuOptions { eClientsList = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClientInfo = 4, eFindClient = 5
		, eTransactions = 6, eManageUsers = 7, eExit = 8};

	static void _GoBackToMainMenu(const string& ClientsFileName, const string& ClientsSeparator,
		const string& UsersFileName, const string& UsersSeparator)
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenu(ClientsFileName, ClientsSeparator, UsersFileName, UsersSeparator);
	}

	static void _ShowClientListScreen(const string& FileName, const string& Separator)
	{
		clsClientsListScreen::ShowClientsListScreen(FileName, Separator);
	}

	static void _ShowAddNewClientScreen(const string& FileName, const string& Separator)
	{
		clsAddNewClientScreen::ShowAddNewClientScreen(FileName, Separator);
	}

	static void _ShowDeleteClientScreen(const string& FileName, const string& Separator)
	{
		clsDeleteClientScreen::ShowDeleteClientScreen(FileName, Separator);
	}

	static void _ShowUpdateClientInfoScreen(const string& FileName, const string& Separator)
	{
		clsUpdateClientScreen::ShowUpdateClientScreen(FileName, Separator);
	}

	static void _ShowFindClientScreen(const string& FileName, const string& Separator)
	{
		clsFindClientScreen::ShowFindClientScreen(FileName, Separator);
	}
	
	static void _TransactionsMenu(const string& FileName, const string& Separator)
	{
		clsTransactionsScreen::ShowTransactionsMenu(FileName, Separator);
	}

	static void _ShowManageUsersMenu(const string& FileName, const string& Separator)
	{
		clsManageUsersScreen::ShowManageUsersMenu(FileName, Separator);
	}

	static void _ShowEndScreen()
	{
		cout << "\nEnd Screen Will be here...\n";
	}

	static void _PerformMainMenuOption(enMainMenuOptions MainOption, const string& ClientsFileName, const string& ClientsSeparator,
		const string& UsersFileName, const string& UsersSeparator)
	{
		switch (MainOption)
		{
		case eClientsList:
		{
			clsOutputSettings::RestScreen();

			_ShowClientListScreen(ClientsFileName, ClientsSeparator);

			_GoBackToMainMenu(ClientsFileName, ClientsSeparator, UsersFileName, UsersSeparator);

			break;
		}

		case eAddNewClient:
		{
			clsOutputSettings::RestScreen();

			_ShowAddNewClientScreen(ClientsFileName, ClientsSeparator);

			_GoBackToMainMenu(ClientsFileName, ClientsSeparator, UsersFileName, UsersSeparator);

			break;
		}

		case eDeleteClient:
		{
			clsOutputSettings::RestScreen();

			_ShowDeleteClientScreen(ClientsFileName, ClientsSeparator);

			_GoBackToMainMenu(ClientsFileName, ClientsSeparator, UsersFileName, UsersSeparator);

			break;
		}

		case eUpdateClientInfo:
		{
			clsOutputSettings::RestScreen();

			_ShowUpdateClientInfoScreen(ClientsFileName, ClientsSeparator);

			_GoBackToMainMenu(ClientsFileName, ClientsSeparator, UsersFileName, UsersSeparator);

			break;
		}

		case eFindClient:
		{
			clsOutputSettings::RestScreen();

			_ShowFindClientScreen(ClientsFileName, ClientsSeparator);

			_GoBackToMainMenu(ClientsFileName, ClientsSeparator, UsersFileName, UsersSeparator);

			break;
		}

		case eTransactions:
		{
			clsOutputSettings::RestScreen();

			_TransactionsMenu(ClientsFileName, ClientsSeparator);

			_GoBackToMainMenu(ClientsFileName, ClientsSeparator, UsersFileName, UsersSeparator);

			break;
		}

		case eManageUsers:
		{
			clsOutputSettings::RestScreen();

			_ShowManageUsersMenu(UsersFileName, UsersSeparator);

			_GoBackToMainMenu(ClientsFileName, ClientsSeparator, UsersFileName, UsersSeparator);

			break;
		}

		case eExit:
		{
			clsOutputSettings::RestScreen();

			_ShowEndScreen();

			//_LoginScreen();

			break;
		}

		}
	}



public:

	
	static void ShowMainMenu(const string& ClientsFileName, const string& ClientsSeparator, const string& UsersFileName,
		const string& UsersSeparator)
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
		cout << setw(37) << left << "" << "\t[8] Exit.\n\n";

		cout << setw(37) << left << "" << "===================================================================\n\n";


		cout << setw(37) << left << "";
		_PerformMainMenuOption((enMainMenuOptions)
			clsInputSettings::ReadShortInRange(1, 8, "Choose What Do You Want To Do ? [1 to 8] ? "), 
			ClientsFileName, ClientsSeparator, UsersFileName, UsersSeparator);


	}



};