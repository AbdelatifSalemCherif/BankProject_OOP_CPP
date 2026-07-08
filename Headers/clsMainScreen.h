#pragma once

#include <iostream>
#include <iomanip>
#include "clsOutputSettings.h"
#include "clsInputSettings.h"


#include "clsScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{




public:

	enum enMainOption {ClientsList, AddNewClient, DeleteClient, UpdateClientInfo, FindClient, Transactions, ManageUsers, Logout};

	static void ShowMainSreen()
	{
		clsOutputSettings::RestScreen();

		_DrawScreenHeader("Main Screen");

		cout << setw(37) << left << "" << "===================================================================\n\n";

		cout << setw(37) << left << "" << "\t\t\tMain Menue\n\n";

		cout << setw(37) << left << "" << "===================================================================\n\n";

		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Logout.\n\n";

		cout << setw(37) << left << "" << "===================================================================\n\n";


		_PerformMainMenueOption(clsInputSettings::ReadShortInRange(1, 8, "Choose What Do You Want To Do ? [1 to 8] ? "));





	}



};