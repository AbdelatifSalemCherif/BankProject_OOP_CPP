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








}

int main()
{
	
	UpdateClient();

	return 0;

}