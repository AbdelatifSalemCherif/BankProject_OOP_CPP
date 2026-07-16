#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputSettings.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen
{

private:

	static void _ReadClientInfo(clsBankClient& Client)
	{
		Client.FirstName = clsInputSettings::ReadString("\nPlease enter First Name : ");
		Client.LastName = clsInputSettings::ReadString("\nPlease enter Last Name : ");
		Client.Email = clsInputSettings::ReadString("\nPlease enter Email : ");
		Client.Phone = clsInputSettings::ReadString("\nPlease enter Phone : ");
		Client.PinCode = clsInputSettings::ReadString("\nPlease enter Pin Code : ");
		Client.Balance = clsInputSettings::ReadFloat("\nPlease enter Balance : ");

	}

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

	static void ShowUpdateClientScreen(const string& FileName, const string& Separator)
	{

		_DrawScreenHeader("Update Client Screen");

		clsBankClient Client = clsBankClient::Find(clsInputSettings::ReadString("\nPlease enter account number ? ")
			, FileName, Separator);

		while (Client.IsEmpty())
		{
			Client =
				clsBankClient::Find(clsInputSettings::ReadString("\nAccount number don\'t exist, Please enter another account number ? ")
					, FileName, Separator);
		}

		_PrintClientCard(Client);

		if (clsInputSettings::ReadYesOrNo("\n\nDo you want to update this client ? y/n ?"))
		{
			cout << "\n\nUpdating Client Info : " << endl;

			_ReadClientInfo(Client);

			if (Client.Save(FileName, Separator) == clsBankClient::svSucceeded)
			{
				cout << "\n\nClient was Saved Successfully :-) ";
			}
			else
			{
				cout << "\n\nClient wasn\'t Saved, is an empty client ! ";
			}
		}
		else
		{

			cout << "\n\nClient wasn\'t Update! ";
		}

	}

};