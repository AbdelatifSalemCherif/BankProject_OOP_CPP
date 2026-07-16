#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputSettings.h"

using namespace std;

class clsWithdrawScreen : protected clsScreen
{

private:

	static void _PrintClientCard(const clsBankClient& Client)
	{
		cout << "\nClient Card :" << endl;
		cout << "------------------------------------------------" << endl;
		cout << "First Name :" << Client.FirstName << endl;
		cout << "Last Name  :" << Client.LastName << endl;
		cout << "Full Name  :" << Client.GetFullName() << endl;
		cout << "Email      :" << Client.Email << endl;
		cout << "Phone      :" << Client.Phone << endl;
		cout << "Acc.Number :" << Client.GetAccountNumber() << endl;
		cout << "Password   :" << Client.PinCode << endl;
		cout << "Balance    :" << Client.Balance << endl;
		cout << "------------------------------------------------" << endl;

	}


public:

	static void ShowWithdrawScreen(const string& FileName, const string& Separator)
	{
		_DrawScreenHeader("Withdraw Screen");


		clsBankClient Client = clsBankClient::Find(clsInputSettings::ReadString("\nPlease enter the account number ? ")
			, FileName, Separator);

		while (Client.IsEmpty())
		{
			Client = clsBankClient::Find(clsInputSettings::ReadString("\nAccount number isn\'t correct, please enter another one ? ")
				, FileName, Separator);
		}


		_PrintClientCard(Client);


		float Amount = clsInputSettings::ReadPositiveFloat("\n\nPlease enter amount ? "
			, "\n\nAmount should be a positive number, please enter another one ? ");

		if (clsInputSettings::ReadYesOrNo("\n\nAre you sure you want to perfom this transaction ? y/n ?"))
		{
			if (Client.Withdraw(Amount, FileName, Separator))
			{
				cout << "\n\nAmount withdrew successfully :-)";

				cout << "\n\nNew balance is : " << Client.Balance << endl;
			}
			else
			{
				cout << "\n\nCannot withdraw, insufficient balance ! ";
				cout << "\n\nAmount to withdraw is : " << Amount;
				cout << "\n\nYour balance is : " << Client.Balance << endl;
			}
		}
		else
		{
			cout << "\n\nNo thing happened !\n";
		}

	}





};