#pragma once

#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsClientsListScreen : protected clsScreen
{
private:

	static void _PrintClientLineOfList(const clsBankClient& Client)
	{
		cout << setw(8) << left << "";
		cout << "| " << left << setw(15) << Client.GetAccountNumber();
		cout << "| " << left << setw(20) << Client.GetFullName();
		cout << "| " << left << setw(30) << Client.Email;
		cout << "| " << left << setw(15) << Client.Phone;
		cout << "| " << left << setw(10) << Client.PinCode;
		cout << "| " << left << setw(15) << to_string(Client.Balance) << endl;
	}


public:

	
	static void ShowClientsListScreen(const string& FileName, const string& Separator)
	{

		if (!_CheckAccessRights(clsBankUser::eClientsList))
		{
			return;
		}

		vector <clsBankClient> vClients = clsBankClient::GetClientsList(FileName, Separator);

		_DrawScreenHeader("Clients List Screen", "(" + to_string(vClients.size()) + ") Clients.");

		/*cout << "\n\t\t\t\t\t\tClient List (" << vClients.size() << ") Clients" << endl;*/

		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"--------------------------- " << endl;

		cout << setw(8) << left << "";
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(30) << "Email";
		cout << "| " << left << setw(15) << "Phone";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(15) << "Balance" << endl;

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

				_PrintClientLineOfList(Client);
			}
		}

		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"--------------------------- " << endl;
	}





};
