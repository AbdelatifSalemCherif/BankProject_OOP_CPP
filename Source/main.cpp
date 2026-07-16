#include <iostream>

#include "clsMainScreen.h"

using namespace std;

int main()
{
	const string ClientsFileName = "BankData/Clients.txt", ClientsSeparator = "#//#"
		, UsersFileName = "BankData/Users.txt", UsersSeparator = "#//#";
	
	clsMainScreen::ShowMainMenu(ClientsFileName, ClientsSeparator, UsersFileName, UsersSeparator);



	return 0;

}