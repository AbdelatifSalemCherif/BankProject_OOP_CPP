#pragma once

#include <iostream>
#include <iomanip>

#include "clsOutputSettings.h"
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputSettings.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsTransferScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{

private:

	enum enTransactionsMenuOptions { optDeposite = 1, optWithdraw = 2, optTotalBalance = 3, optTransfer = 4, optExit = 5};

	static void _GoBackToTransactionsMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";

		system("pause>0");
		ShowTransactionsMenu();
	}

	static void _ShowDespositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalaceScreen()
	{
		clsTotalBalanceScreen::ShowTotalBalanceScreen();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _PerformTransactionsMenuOption(enTransactionsMenuOptions Option)
	{

		switch(Option)
		{
		case optDeposite:
		{
			clsOutputSettings::RestScreen();

			_ShowDespositScreen();

			_GoBackToTransactionsMenu();

			break;
		}

		case optWithdraw:
		{
			clsOutputSettings::RestScreen();

			_ShowWithdrawScreen();

			_GoBackToTransactionsMenu();

			break;
		}

		case optTotalBalance:
		{
			clsOutputSettings::RestScreen();

			_ShowTotalBalaceScreen();

			_GoBackToTransactionsMenu();

			break;
		}

		case optTransfer:
		{
			clsOutputSettings::RestScreen();

			_ShowTransferScreen();

			_GoBackToTransactionsMenu();

			break;
		}

		case optExit:
		{

			break;
		}

		}
	}

public:

	static void ShowTransactionsMenu()
	{

		clsOutputSettings::RestScreen();

		if (!_CheckAccessRights(clsBankUser::prmTransactions))
		{
			return;
		}

		_DrawScreenHeader("Transactions Screen");

		cout << endl;

		cout << setw(37) << left << "" << "===================================================================\n\n";
		cout << setw(37) << left << "" << "\t\t\t\tTransactions Menu\n\n";
		cout << setw(37) << left << "" << "===================================================================\n\n";

		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balace.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n\n";

		cout << setw(37) << left << "" << "===================================================================\n\n";


		cout << setw(37) << left << "";
		_PerformTransactionsMenuOption((enTransactionsMenuOptions)clsInputSettings::
			ReadShortInRange(1, 5, "Choose What Do You Want To Do ? [1 to 5] ? "));
	}



};


