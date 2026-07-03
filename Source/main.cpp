#include <iostream>

#include "clsBankClient.h"
#include "clsInputSettings.h"

using namespace std;

void ReadClientInfo(clsBankClient& Client)
{
	Client.FirstName = clsInputSettings::ReadString("\nPlease enter First Name : ");
	Client.LastName = clsInputSettings::ReadString("\nPlease enter Last Name : ");
	Client.Email = clsInputSettings::ReadString("\nPlease enter Email : ");
	Client.Phone = clsInputSettings::ReadString("\nPlease enter Phone : ");
	Client.PinCode = clsInputSettings::ReadString("\nPlease enter Pin Code : ");
	Client.Balance = clsInputSettings::ReadNumber((float)0, "\nPlease enter Balance : ");

}

void UpdateClient()
{

	clsBankClient Client = clsBankClient::Find(clsInputSettings::ReadString("\nPlease enter account number ? ")
		, "BankData/Clients.txt", "#//#");

	while (Client.IsEmpty())
	{
		Client = 
			clsBankClient::Find(clsInputSettings::ReadString("\nAccount number don\'t exist, Please enter another account number ? ")
			, "BankData/Clients.txt", "#//#");
	}

	Client.Print();


	cout << "\n\nUpdating Client Info : " << endl;

	ReadClientInfo(Client);

	//Save();

}

int main()
{
	
	

	return 0;

}