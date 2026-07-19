#pragma once

#include <iostream>
#include <iomanip>

#include "clsOutputSettings.h"
#include "clsInputSettings.h"
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsTransferRegisterScreen : protected clsScreen
{

private:

	static void _PrintTranferRegisterLineOfTable(clsBankClient::stTransferRegister& TransferRegister)
	{

		cout << setw(8) << left << "";
		cout << "| " << left << setw(25) << TransferRegister.Time;
		cout << "| " << left << setw(20) << TransferRegister.SourceAccountNumber;
		cout << "| " << left << setw(20) << TransferRegister.DestinationAccountNumber;
		cout << "| " << left << setw(7)  << TransferRegister.Amount;
		cout << "| " << left << setw(20) << TransferRegister.SourceNewBalance;
		cout << "| " << left << setw(20) << TransferRegister.DestinationNewBalance;
		cout << "| " << left << setw(15)<< TransferRegister.UserName << endl;
	}





public:


	static void ShowTransferRegisterScreen()
	{

		if (!_CheckAccessRights(clsBankUser::prmLoginRegister))
		{
			return;
		}

		vector <clsBankUser::stLoginRegister> vLoginRegister = clsBankUser::GetAllLoginReristerList();

		_DrawScreenHeader("Login Register Screen", "(" + to_string(vLoginRegister.size()) + ") Logins.");


		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"------------------------------------------- " << endl;

		cout << setw(8) << left << "";
		cout << "| " << left << setw(25) << "Time";
		cout << "| " << left << setw(20) << "Source Acc.Number";
		cout << "| " << left << setw(20) << "Destination Acc.Number";
		cout << "| " << left << setw(7)  << "Amount";
		cout << "| " << left << setw(20) << "Source New Balance";
		cout << "| " << left << setw(20) << "Destination New Balance";
		cout << "| " << left << setw(15) << "UserName" << endl;

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
