#include <iostream>
#include <iomanip>

#include "clsBankClient.h"
#include "clsInputSettings.h"
#include "clsUtility.h"

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

void PrintClientLineOfList(const clsBankClient& Client)
{
	cout << "| " << left << setw(15) << Client.GetAccountNumber();
	cout << "| " << left << setw(20) << Client.FirstName + " " + Client.LastName;
	cout << "| " << left << setw(30) << Client.Email;
	cout << "| " << left << setw(15) << Client.Phone;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(15) << to_string(Client.Balance) << endl;
}

void ShowClientsList()
{
	vector <clsBankClient> vClients = clsBankClient::GetClientsList(FileName, Separator);


	cout << "\n\t\t\t\t\t\tClient List (" << vClients.size() << ") Clients" << endl;

	cout << "----------------------------------------------------------------------------------------------------------------"
		"-------" << endl;
	
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(20) << "Client Name";
	cout << "| " << left << setw(30) << "Email";
	cout << "| " << left << setw(15) << "Phone";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(15) << "Balance" << endl;

	cout << "----------------------------------------------------------------------------------------------------------------"
		"-------" << endl;

	if (vClients.size() == 0)
	{
		cout << "\t\t\t\tNo Clients Available In System !" << endl;
	}
	else
	{
		for (const clsBankClient& Client : vClients)
		{
			PrintClientLineOfList(Client);
		}
	}

	cout << "----------------------------------------------------------------------------------------------------------------"
		"-------" << endl;
}

void PrintClientLineOfTotalBalanceTable(const clsBankClient& Client)
{

}

void ShowTotalBalance()
{

}

int main()
{
	
	cout << clsUtility::GetNumberText(1471482) << endl;



	return 0;

}