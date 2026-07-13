#pragma once

#include <iostream>
#include <iomanip>

#include "clsOutputSettings.h"
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputSettings.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{

private:

	enum enTransactionsMenuOptions { eDeposite = 1, eWithdraw = 2, eTotalBalance = 3, eExit = 4};

	static void _PerformTransactionsMenueOption(enTransactionsMenuOptions Option,const string& FileName, const string& Separator)
	{
		
	}

public:

	static void ShowTransactionsMenu(const string& FileName, const string& Separator)
	{

		clsOutputSettings::RestScreen();

		_DrawScreenHeader("Transactions Screen");

		cout << setw(37) << left << "" << "===================================================================\n";
		cout << setw(37) << left << "" << "\t\t\t\tTransactions Menu\n\n";
		cout << setw(37) << left << "" << "===================================================================\n";

		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balace.\n";
		cout << setw(37) << left << "" << "\t[4] Main Menue.\n";

		cout << setw(37) << left << "" << "===================================================================\n\n";


		cout << setw(37) << left << "";
		_PerformTransactionsMenueOption((enTransactionsMenuOptions)
			clsInputSettings::ReadShortInRange(1, 4, "Choose What Do You Want To Do ? [1 to 4] ? "),
			FileName, Separator);
	}



};


