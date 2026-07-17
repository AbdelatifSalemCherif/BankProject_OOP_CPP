#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputSettings.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen
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

	static void ShowDeleteClientScreen()
	{

		if (!_CheckAccessRights(clsBankUser::eDeleteClient))
		{
			return;
		}

		_DrawScreenHeader("Delete Client Screen");

		clsBankClient Client = clsBankClient::Find(clsInputSettings::ReadString("\nPlease enter account number ? "));

		while (Client.IsEmpty())
		{
			Client =
				clsBankClient::Find(
					clsInputSettings::ReadString("\nAccount number don\'t exist, Please enter another account number ? "));
		}

		_PrintClientCard(Client);


		if (clsInputSettings::ReadYesOrNo("\n\nDo you want to delete this client ? y/n ? "))
		{

			if (Client.Delete())
			{
				cout << "\n\nClient deleted successfully :-) " << endl;
			
				_PrintClientCard(Client);
			}
			else
			{
				cout << "\n\nClient hasn\'t deleted !" << endl;
			}

			

		}
		else
		{
			cout << "\n\nClient hasn\'t deleted !" << endl;
		}

	}


};
