#include <iostream>

#include "clsMainScreen.h"

using namespace std;

int main()
{
	const string FileName = "BankData/Clients.txt", Separator = "#//#";
	
	clsMainScreen::ShowMainMenu(FileName, Separator, "", "");



	return 0;

}