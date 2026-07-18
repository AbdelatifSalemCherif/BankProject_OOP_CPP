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

	static void _PrintLoginRecord(string& Record)
	{
		vector <string> vRecord = clsBankUser::SplitLoginRecord(Record);

		cout << setw(8) << left << "";
		cout << "| " << left << setw(15) << vRecord[0];
		cout << "| " << left << setw(20) << vRecord[1];
		cout << "| " << left << setw(30) << vRecord[2];
		cout << "| " << left << setw(15) << vRecord[3];
		cout << "| " << left << setw(10) << vRecord[4];
		cout << "| " << left << setw(10) << vRecord[5];
		cout << "| " << left << setw(15) << vRecord[6] << endl;
	}


public:


	static void ShowLoginRegisterScreen()
	{
		vector <string> vRecords = clsBankUser::GetAllLoginRecords();

		_DrawScreenHeader("Login Register Screen", "(" + to_string(vRecords.size()) + ") Logins.");


		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"--------------------------- " << endl;

		cout << setw(8) << left << "";
		cout << "| " << left << setw(15) << "Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(30) << "Full Name";
		cout << "| " << left << setw(15) << "Email";
		cout << "| " << left << setw(10) << "Phone";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(15) << "Permissions" << endl;

		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"--------------------------- " << endl;

		for (string& Record : vRecords)
		{

			_PrintLoginRecord(Record);
		}

		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"--------------------------- " << endl;
	}

};



