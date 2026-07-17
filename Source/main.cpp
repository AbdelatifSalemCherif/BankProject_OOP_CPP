#include <iostream>

#include "Global.h"
#include "clsLoginScreen.h"

using namespace std;

int main()
{
	

	while (clsLoginScreen::ShowLoginScreen(ClientsFileName, ClientsSeparator, UsersFileName, UsersSeparator))
	{

	}


	return 0;

}