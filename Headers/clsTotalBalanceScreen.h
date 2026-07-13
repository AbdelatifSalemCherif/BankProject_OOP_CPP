#pragma once

#include <iostream>
#include <iomanip>

#include "clsUtility.h"
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

	static void ShowTotalBalanceScreen(const string& FileName, const string& Separator)
	{

		_DrawScreenHeader("Total Balance Screen");

		vector <clsBankClient> vClients = clsBankClient::GetClientsList(FileName, Separator);


		cout << "\n\t\t\t\t\t\tTotal Balance (" << vClients.size() << ") Clients" << endl;

		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"--------------------------- " << endl;

		cout << setw(25) << left << "| " << setw(15) << left << "Account Number";
		cout << "| " << setw(40) << left << "Client Name";
		cout << "| " << setw(30) << left << "Balance" << endl;

		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"--------------------------- " << endl;

		if (vClients.size() == 0)
		{
			cout << "\t\t\t\tNo Clients Available In System !" << endl;
		}
		else
		{
			for (const clsBankClient& Client : vClients)
			{
				_PrintClientLineOfTotalBalanceTable(Client);
			}
		}

		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"--------------------------- " << endl;

		const double TotalBalace = clsBankClient::GetTotalBalance(FileName, Separator);

		cout << "\t\t\tTotal Balance = " << TotalBalace << endl;

		cout << "\t\t\t\t" << clsUtility::GetNumberText(TotalBalace) << endl;


	}



};