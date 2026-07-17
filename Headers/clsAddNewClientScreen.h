#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputSettings.h"

using namespace std;

class clsAddNewClientScreen : protected clsScreen
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

	static void ShowAddNewClientScreen()
	{

		if (!_CheckAccessRights(clsBankUser::eAddNewClient))
		{
			return;
		}

		_DrawScreenHeader("Add New Client Screen");

		string AccountNember = clsInputSettings::ReadString("\nPlease enter the account number : ");

		while (clsBankClient::IsClientExist(AccountNember))
		{
			AccountNember = clsInputSettings::ReadString("\nThis Account number is exist, Please enter another account number : ");
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNember);

		_ReadClientInfo(NewClient);

		switch (NewClient.Save())
		{
		case clsBankClient::svFaildEmptyObject:
		{
			cout << "\nFaild, is an empty client !" << endl;

			break;
		}

		case clsBankClient::svFaildAccountNumberExist:
		{
			cout << "\nFaild, Account number exist !" << endl;

			break;
		}

		case clsBankClient::svSucceeded:
		{
			cout << "\nClient added successfuly :-) " << endl << endl;

			_PrintClientCard(NewClient);

			break;
		}

		}

	}




};