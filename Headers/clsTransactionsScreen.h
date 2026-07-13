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

using namespace std;

class clsTransactionsScreen : protected clsScreen
{

private:

	enum enTransactionsMenuOptions { eDeposite = 1, eWithdraw = 2, eTotalBalance = 3, eExit = 4};

	static void _GoBackToTransactionsMenu(const string& FileName, const string& Separator)
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";

		system("pause>0");
		ShowTransactionsMenu(FileName, Separator);
	}

	static void _ShowDespositScreen(const string& FileName, const string& Separator)
	{
		clsDepositScreen::ShowDepositScreen(FileName, Separator);
	}

	static void _ShowWithdrawScreen(const string& FileName, const string& Separator)
	{
		clsWithdrawScreen::ShowWithdrawScreen(FileName, Separator);
	}

	static void _ShowTotalBalaceScreen(const string& FileName, const string& Separator)
	{
		clsTotalBalanceScreen::ShowTotalBalanceScreen(FileName, Separator);
	}

	static void _PerformTransactionsMenuOption(enTransactionsMenuOptions Option,const string& FileName, const string& Separator)
	{

		switch(Option)
		{
		case eDeposite:
		{
			clsOutputSettings::RestScreen();

			_ShowDespositScreen(FileName, Separator);

			_GoBackToTransactionsMenu(FileName, Separator);

			break;
		}

		case eWithdraw:
		{
			clsOutputSettings::RestScreen();

			_ShowWithdrawScreen(FileName, Separator);

			_GoBackToTransactionsMenu(FileName, Separator);

			break;
		}

		case eTotalBalance:
		{
			clsOutputSettings::RestScreen();

			_ShowTotalBalaceScreen(FileName, Separator);

			_GoBackToTransactionsMenu(FileName, Separator);

			break;
		}

		case eExit:
		{

			break;
		}

		}
	}

public:

	static void ShowTransactionsMenu(const string& FileName, const string& Separator)
	{

		clsOutputSettings::RestScreen();

		_DrawScreenHeader("Transactions Screen");

		cout << endl;

		cout << setw(37) << left << "" << "===================================================================\n\n";
		cout << setw(37) << left << "" << "\t\t\t\tTransactions Menu\n\n";
		cout << setw(37) << left << "" << "===================================================================\n\n";

		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balace.\n";
		cout << setw(37) << left << "" << "\t[4] Main Menue.\n\n";

		cout << setw(37) << left << "" << "===================================================================\n\n";


		cout << setw(37) << left << "";
		_PerformTransactionsMenuOption((enTransactionsMenuOptions)
			clsInputSettings::ReadShortInRange(1, 4, "Choose What Do You Want To Do ? [1 to 4] ? "),
			FileName, Separator);
	}



};


