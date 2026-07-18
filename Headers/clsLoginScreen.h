#pragma once

#include <iostream>
#include <fstream>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "clsScreen.h"
#include "Global.h"
#include "clsMainScreen.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{

private:

	static bool _Login()
	{

		short TrialsCounter = 2;

		string UserName = clsInputSettings::ReadString("\n\nPlease enter UserName : "),
			Password = clsInputSettings::ReadString("\nPlease enter Password : ");

		CurrentUser = clsBankUser::FindByUserNameAndPassword(UserName, Password);

		while (CurrentUser.IsEmpty())
		{

			if (TrialsCounter == 0)
			{
				return false;
			}

			cout << "\n\nInvalid UserName/Passwor !";

			cout << "\n\nYou have " << TrialsCounter-- << " trials to login.";

			UserName = clsInputSettings::ReadString("\n\nPlease enter UserName : ");
			Password = clsInputSettings::ReadString("\nPlease enter Password : ");

			CurrentUser = clsBankUser::FindByUserNameAndPassword(UserName, Password);

		}

		CurrentUser.SaveLogin();

		clsMainScreen::ShowMainMenu();

		return true;

	}

public:

	static bool ShowLoginScreen()
	{

		clsOutputSettings::RestScreen();

		_DrawScreenHeader("Login Screen");


		return _Login();

	}



};



