#include <iostream>

#include "clsBankClient.h"
#include "clsInputSettings.h"

using namespace std;

const string FileName = "BankData/Clients.txt", Separator = "#//#";

void ReadClientInfo(clsBankClient& Client)
{
	Client.FirstName = clsInputSettings::ReadString("\nPlease enter First Name : ");
	Client.LastName = clsInputSettings::ReadString("\nPlease enter Last Name : ");
	Client.Email = clsInputSettings::ReadString("\nPlease enter Email : ");
	Client.Phone = clsInputSettings::ReadString("\nPlease enter Phone : ");
	Client.PinCode = clsInputSettings::ReadString("\nPlease enter Pin Code : ");
	Client.Balance = clsInputSettings::ReadFloat("\nPlease enter Balance : ");

}

void UpdateClient()
{

	clsBankClient Client = clsBankClient::Find(clsInputSettings::ReadString("\nPlease enter account number ? ")
		, FileName, Separator);

	while (Client.IsEmpty())
	{
		Client = 
			clsBankClient::Find(clsInputSettings::ReadString("\nAccount number don\'t exist, Please enter another account number ? ")
			, FileName, Separator);
	}

	Client.Print();


	cout << "\n\nUpdating Client Info : " << endl;

	ReadClientInfo(Client);


	if (Client.Save(FileName, Separator) == clsBankClient::svSucceeded)
	{
		cout << "\n\nClient was Saved Successfully :-) ";
	}
	else
	{
		cout << "\n\nClient wasn\'t Saved Successfully, is an empty client ! ";
	}

}

void AddNewClient()
{
	string AccountNember = clsInputSettings::ReadString("\nPlease enter the account number : ");

	while (clsBankClient::IsClientExist(AccountNember, FileName, Separator))
	{
		AccountNember = clsInputSettings::ReadString("\nThis Account number is exist, Please enter another account number : ");
	}

	clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNember);

	ReadClientInfo(NewClient);

	switch (NewClient.Save(FileName, Separator))
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
		cout << "\nClient added successfuly :-) " << endl;

		break;
	}

	}

}

void DeleteClient()
{

	clsBankClient Client = clsBankClient::Find(clsInputSettings::ReadString("\nPlease enter account number ? ")
		, FileName, Separator);

	while (Client.IsEmpty())
	{
		Client =
			clsBankClient::Find(clsInputSettings::ReadString("\nAccount number don\'t exist, Please enter another account number ? ")
				, FileName, Separator);
	}

	Client.Print();


	if (clsInputSettings::ReadYesOrNo("\n\nDo you want to delete this client ? y/n ? "))
	{

		if(Client.Delete(FileName, Separator))
		{
			cout << "\n\nClient deleted successfully :-) " << endl;

			Client.Print();
			
		}
		else
		{
			cout << "\n\nClient hasn\'t deleted !" << endl;
		}

	}


}


int main()
{
	
	

	return 0;

}