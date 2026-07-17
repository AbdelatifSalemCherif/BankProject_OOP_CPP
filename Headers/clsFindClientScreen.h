#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputSettings.h"

using namespace std;

class clsFindClientScreen : protected clsScreen
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

	static void ShowFindClientScreen(const string& FileName, const string& Separator)
	{

		if (!_CheckAccessRights(clsBankUser::eFindClient))
		{
			return;
		}

		_DrawScreenHeader("Find Client Screen");

		clsBankClient Client = clsBankClient::Find(clsInputSettings::ReadString("\nPlease enter account number ? ")
			, FileName, Separator);

		while (Client.IsEmpty())
		{
			Client =
				clsBankClient::Find(clsInputSettings::ReadString("\nAccount number don\'t exist, Please enter another account number ? ")
					, FileName, Separator);
		}


		if (Client.IsEmpty())
		{
			cout << "\n\nClient was\'t found, is an empty client !" << endl;
		}
		else
		{
			cout << "\n\nClient was found :-)" << endl;

			_PrintClientCard(Client);
		}



	}


};