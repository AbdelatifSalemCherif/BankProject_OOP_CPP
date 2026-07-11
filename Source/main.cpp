#include <iostream>
#include <iomanip>

#include "clsBankClient.h"
#include "clsInputSettings.h"
#include "clsUtility.h"
#include "clsMainScreen.h"

using namespace std;

//void ReadClientInfo(clsBankClient& Client)
//{
//	Client.FirstName = clsInputSettings::ReadString("\nPlease enter First Name : ");
//	Client.LastName = clsInputSettings::ReadString("\nPlease enter Last Name : ");
//	Client.Email = clsInputSettings::ReadString("\nPlease enter Email : ");
//	Client.Phone = clsInputSettings::ReadString("\nPlease enter Phone : ");
//	Client.PinCode = clsInputSettings::ReadString("\nPlease enter Pin Code : ");
//	Client.Balance = clsInputSettings::ReadFloat("\nPlease enter Balance : ");
//
//}
//
//
//void PrintClientLineOfTotalBalanceTable(const clsBankClient& Client)
//{
//	cout << "| " << left << setw(30) << Client.GetAccountNumber();
//	cout << "| " << left << setw(30) << Client.FirstName + " " + Client.LastName;
//	cout << "| " << left << setw(30) << to_string(Client.Balance) << endl;
//}
//
//void ShowTotalBalance()
//{
//	vector <clsBankClient> vClients = clsBankClient::GetClientsList(FileName, Separator);
//
//
//	cout << "\n\t\t\t\t\t\tTotal Balance (" << vClients.size() << ") Clients" << endl;
//
//	cout << "----------------------------------------------------------------------------------------------------------------"
//		"-------" << endl;
//
//	cout << "| " << left << setw(30) << "Account Number";
//	cout << "| " << left << setw(30) << "Client Name";
//	cout << "| " << left << setw(30) << "Balance" << endl;
//
//	cout << "----------------------------------------------------------------------------------------------------------------"
//		"-------" << endl;
//
//	if (vClients.size() == 0)
//	{
//		cout << "\t\t\t\tNo Clients Available In System !" << endl;
//	}
//	else
//	{
//		for (const clsBankClient& Client : vClients)
//		{
//			PrintClientLineOfTotalBalanceTable(Client);
//		}
//	}
//
//	cout << "----------------------------------------------------------------------------------------------------------------"
//		"-------" << endl;
//
//	const double TotalBalace = clsBankClient::GetTotalBalance(FileName, Separator);
//
//	cout << "\t\t\tTotal Balance = " << TotalBalace << endl;
//
//	cout << "\t\t\t\t" << clsUtility::GetNumberText(TotalBalace) << endl;
//
//
//}

int main()
{
	const string FileName = "BankData/Clients.txt", Separator = "#//#";
	
	clsMainScreen::ShowMainMenue(FileName, Separator);



	return 0;

}