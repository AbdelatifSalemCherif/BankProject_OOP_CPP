#pragma once

#include <iostream>
#include <iomanip>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "clsScreen.h"
#include "Global.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{

private:



public:

	static void ShowLoginScreen(const string& ClientsFileName, const string& ClientsSeparator
		, const string& UsersFileName, const string& UsersSeparator)
	{

		clsOutputSettings::RestScreen();

		_DrawScreenHeader("Login Screen");


		//_Login(ClientsFileName, ClientsSeparator, UsersFileName, UsersSeparator);

	}
};



