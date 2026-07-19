#pragma once

#include <iostream>
#include <iomanip>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "clsScreen.h"
#include "clsBankUser.h"

using namespace std;


class clsLoginRegisterScreen : protected clsScreen
{

private:

	static void _PrintLoginRegisterLineOfTable(clsBankUser::stLoginRegister& LoginRegister)
	{
		
		cout << setw(8) << left << "";
		cout << "| " << left << setw(25) << LoginRegister.Time;
		cout << "| " << left << setw(10) << LoginRegister.UserName;
		cout << "| " << left << setw(25) << LoginRegister.FullName;
		cout << "| " << left << setw(30) << LoginRegister.Email;
		cout << "| " << left << setw(10) << LoginRegister.Phone;
		cout << "| " << left << setw(10) << LoginRegister.Password;
		cout << "| " << left << setw(5)  << LoginRegister.Permissions << endl;
	}


public:


	static void ShowLoginRegisterScreen()
	{
		vector <clsBankUser::stLoginRegister> vLoginRegister = clsBankUser::GetAllLoginReristerList();

		_DrawScreenHeader("Login Register Screen", "(" + to_string(vLoginRegister.size()) + ") Logins.");


		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"------------------------------------------- " << endl;

		cout << setw(8) << left << "";
		cout << "| " << left << setw(25) << "Time";
		cout << "| " << left << setw(10) << "UserName";
		cout << "| " << left << setw(25) << "Full Name";
		cout << "| " << left << setw(30) << "Email";
		cout << "| " << left << setw(10) << "Phone";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(5)  << "Permissions" << endl;

		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"------------------------------------------- " << endl;

		for (clsBankUser::stLoginRegister& LoginRegister : vLoginRegister)
		{

			_PrintLoginRegisterLineOfTable(LoginRegister);
		}

		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"------------------------------------------- " << endl;
	}

};



