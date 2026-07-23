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


public:

	static void ShowTransferScreen()
	{

		_DrawScreenHeader("Transfer Screen");



		clsBankClient SourceClient = _ReadClient("\nPlease Enter Account Number To Transfer From : "
			, "\nAccount Number Isn\'t Correct, Please Enter Another One : ");

		_PrintClientCard(SourceClient);



		clsBankClient DestionationClient = _ReadClient("\nPlease Enter Account Number To Transfer To : ",
			"\nAccount Number Isn\'t Correct, Please Enter Another One : ");

		_PrintClientCard(DestionationClient);




		float Amount = clsInputSettings::ReadNumberInRange<float>(0, SourceClient.Balance,
			"\n\nPlease Enter Transfer Amount ? It Must Be Less Than " + to_string(SourceClient.Balance) + " ? ");




		if (clsInputSettings::ReadYesOrNo("\n\nAre You Sure You Want To Perform This Transaction ? y/n ?"))
		{

			if (SourceClient.Transfer(Amount, DestionationClient))
			{
		
				cout << "\n\nTransfer Done Successfully :-) :\n\n";

			}
			else
			{

				cout << "\a\n\nTransfer FAILD ! Or Is The Same Client ! Try again.";

			}

		}
		else
		{
			cout << "\n\nNothing Hapenned ! ";

		}

		cout << "\n\n";
		_PrintClientCard(SourceClient);

		cout << "\n\n";
		_PrintClientCard(DestionationClient);
		


	}



};

