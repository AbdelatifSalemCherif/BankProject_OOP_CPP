#pragma once

#include <iostream>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "clsScreen.h"
#include "Global.h"
#include "clsMainScreen.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{

private:

	static bool _Login(const string& ClientsFileName, const string& ClientsSeparator
		, const string& UsersFileName, const string& UsersSeparator)
	{

		short TrialsCounter = 2;

		string UserName = clsInputSettings::ReadString("\n\nPlease enter UserName : "),
			Password = clsInputSettings::ReadString("\nPlease enter Password : ");

		CurrentUser = clsBankUser::Find(UserName, Password, UsersFileName, UsersSeparator);

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

			CurrentUser = clsBankUser::Find(UserName, Password, UsersFileName, UsersSeparator);

		}

		clsMainScreen::ShowMainMenu(ClientsFileName, ClientsSeparator, UsersFileName, UsersSeparator);

		return true;

	}

public:

	static bool ShowLoginScreen(const string& ClientsFileName, const string& ClientsSeparator
		, const string& UsersFileName, const string& UsersSeparator)
	{

		clsOutputSettings::RestScreen();

		_DrawScreenHeader("Login Screen");


		return _Login(ClientsFileName, ClientsSeparator, UsersFileName, UsersSeparator);

	}



};



