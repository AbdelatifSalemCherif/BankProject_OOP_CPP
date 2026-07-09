#pragma once

#include <iostream>
#include <iomanip>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "clsScreen.h"
#include "clsClientsListScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:

	enum enMainMenuOptions { eClientsList = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClientInfo = 4, eFindClient = 5
		, eTransactions = 6, eManageUsers = 7, eExit = 8};

	static void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenue();
	}

	static void _ShowClientListScreen(const string& FileName, const string& Separator)
	{
		clsClientsListScreen::ShowClientsList(FileName, Separator);
	}

	static void _ShowAddNewClientScreen()
	{
		cout << "\nAdd New Client Screen will be here ...\n";
	}

	static void _ShowDeleteClientScreen()
	{
		cout << "\nDelete Client Screen will be here ...\n";
	}

	static void _ShowUpdateClientInfoScreen()
	{
		cout << "\nUpdate Client Screen will be here ...\n";
	}

	static void _ShowFindClientScreen()
	{
		cout << "\nFind Client Screen will be here ...\n";
	}
	
	static void _TransactionsMenue()
	{
		cout << "\nTransactions Screen will be here ...\n";
	}

	static void _ShowManageUsersMenue()
	{
		cout << "\nManage Users Menue will be here ...\n";
	}

	static void _ShowEndScreen()
	{
		cout << "\nEnd Screen Will be here...\n";
	}

	static void _PerformMainMenueOption(enMainMenuOptions MainOption)
	{
		switch (MainOption)
		{
		case eClientsList:
		{
			clsOutputSettings::RestScreen();

			_ShowClientListScreen();

			_GoBackToMainMenue();

			break;
		}

		case eAddNewClient:
		{
			clsOutputSettings::RestScreen();

			_ShowAddNewClientScreen();

			_GoBackToMainMenue();

			break;
		}

		case eDeleteClient:
		{
			clsOutputSettings::RestScreen();

			_ShowDeleteClientScreen();

			_GoBackToMainMenue();

			break;
		}

		case eUpdateClientInfo:
		{
			clsOutputSettings::RestScreen();

			_ShowUpdateClientInfoScreen();

			_GoBackToMainMenue();

			break;
		}

		case eFindClient:
		{
			clsOutputSettings::RestScreen();

			_ShowFindClientScreen();

			_GoBackToMainMenue();

			break;
		}

		case eTransactions:
		{
			clsOutputSettings::RestScreen();

			_TransactionsMenue();

			_GoBackToMainMenue();

			break;
		}

		case eManageUsers:
		{
			clsOutputSettings::RestScreen();

			_ShowManageUsersMenue();

			_GoBackToMainMenue();

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

	
	static void ShowMainMenue()
	{
		clsOutputSettings::RestScreen();

		_DrawScreenHeader("Main Screen");
		
		cout << setw(37) << left << "" << "===================================================================\n";
		cout << setw(37) << left << "" << "\t\t\t\tMain Menue\n\n";
		cout << setw(37) << left << "" << "===================================================================\n";

		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] eExit.\n\n";

		cout << setw(37) << left << "" << "===================================================================\n\n";


		cout << setw(37) << left << "";
		_PerformMainMenueOption((enMainMenuOptions)clsInputSettings::ReadShortInRange(1, 8, "Choose What Do You Want To Do ? [1 to 8] ? "));


	}



};