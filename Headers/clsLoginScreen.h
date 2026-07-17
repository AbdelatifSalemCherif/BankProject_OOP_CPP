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

	static void _Login(const string& ClientsFileName, const string& ClientsSeparator
		, const string& UsersFileName, const string& UsersSeparator)
	{

		string UserName = clsInputSettings::ReadString("\n\nPlease enter UserName : "),
			Password = clsInputSettings::ReadString("\nPlease enter Password : ");

		CurrentUser = clsBankUser::Find(UserName, Password, UsersFileName, UsersSeparator);

		while (CurrentUser.IsEmpty())
		{
			cout << "\n\nInvalid UserName/Passwor !";

			UserName = clsInputSettings::ReadString("\n\nPlease enter UserName : ");
			Password = clsInputSettings::ReadString("\nPlease enter Password : ");

			CurrentUser = clsBankUser::Find(UserName, Password, UsersFileName, UsersSeparator);

		}

		clsMainScreen::ShowMainMenu(ClientsFileName, ClientsSeparator, UsersFileName, UsersSeparator);

	}

public:

	static void ShowLoginScreen(const string& ClientsFileName, const string& ClientsSeparator
		, const string& UsersFileName, const string& UsersSeparator)
	{

		clsOutputSettings::RestScreen();

		_DrawScreenHeader("Login Screen");


		_Login(ClientsFileName, ClientsSeparator, UsersFileName, UsersSeparator);

	}



};



