#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputSettings.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{

private:

	static void _PrintClientCard(const clsBankClient& Client)
	{
		cout << "\nClient Card :" << endl;
		cout << "------------------------------------------------" << endl;
		cout << "Full Name  :" << Client.GetFullName() << endl;
		cout << "Acc.Number :" << Client.GetAccountNumber() << endl;
		cout << "Balance    :" << Client.Balance << endl;
		cout << "------------------------------------------------" << endl;

	}

	static clsBankClient _ReadClient(const string& MessageToUser, const string& ErrorMessage)
	{
		clsBankClient Client = clsBankClient::Find(clsInputSettings::ReadString(MessageToUser));

		while (Client.IsEmpty())
		{
			Client = clsBankClient::Find(clsInputSettings::ReadString(ErrorMessage));
		}

		return Client;
	}

	static clsBankClient _ReadClient(const clsBankClient& ExptionClient, const string& MessageToUser, const string& ErrorMessage)
	{

	
		clsBankClient Client = clsBankClient::Find(clsInputSettings::ReadString(MessageToUser));

		while (Client.IsEmpty() || Client.GetAccountNumber() == ExptionClient.GetAccountNumber())
		{
			Client = clsBankClient::Find(clsInputSettings::ReadString(ErrorMessage));
		}

		return Client;
	}



public:

	static void ShowTransferScreen()
	{

		_DrawScreenHeader("Transfer Screen");

		clsBankClient ClientTransferFrom = _ReadClient("\nPlease Enter Account Number To Transfer From : "
			, "\nAccount Number Isn\'t Correct, Please Enter Another One : ");

		_PrintClientCard(ClientTransferFrom);


		clsBankClient ClientTransferTo = _ReadClient(ClientTransferFrom, "\nPlease Enter Account Number To Transfer To : ",
			"\nAccount Number Isn\'t Correct, Or You Entered The Same Account Number To Transform From, Please Enter Another One : ");

		_PrintClientCard(ClientTransferTo);


		float Amount = clsInputSettings::ReadFloatInRange(0, ClientTransferFrom.Balance,
			"\n\nPlease Enter Transfer Amount ? It Must Be Less Than " + to_string(ClientTransferFrom.Balance));


		if (clsInputSettings::ReadYesOrNo("\n\nAre You Sure You Want To Perform This Transaction ? y/n ?"))
		{

			if (ClientTransferTo.Withdraw(Amount))

			{
				ClientTransferFrom.Deposit(Amount);

				cout << "\n\nTransfer Done Successfully :-) :\n\n";

				_PrintClientCard(ClientTransferFrom);

				cout << "\n\n";

				_PrintClientCard(ClientTransferTo);

			}
			else
			{

				cout << "\n\nTransfer FAILD ! Try again";

			}


		}
		else
		{
			cout << "\n\nNothing Hapenned ! ";

		}
		


	}



};

