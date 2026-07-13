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


int main()
{
	const string FileName = "BankData/Clients.txt", Separator = "#//#";
	
	clsMainScreen::ShowMainMenu(FileName, Separator);



	return 0;

}