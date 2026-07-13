#pragma once

#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsTotalBalanceScreen : protected clsScreen
{

private:

	static void _PrintClientLineOfTotalBalanceTable(const clsBankClient& Client)
	{

		cout << setw(25) << left << "| " << setw(15) << left << Client.GetAccountNumber();
		cout << "| " << setw(40) << left << Client.FirstName + " " + Client.LastName;
		cout << "| " << setw(30) << left << to_string(Client.Balance) << endl;

	}



public:




};