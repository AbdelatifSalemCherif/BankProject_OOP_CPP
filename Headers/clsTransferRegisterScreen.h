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
		cout << "| " << left << setw(22) << TransferRegister.Time;
		cout << "| " << left << setw(17) << TransferRegister.SourceAccountNumber;
		cout << "| " << left << setw(22) << TransferRegister.DestinationAccountNumber;
		cout << "| " << left << setw(15) << TransferRegister.Amount;
		cout << "| " << left << setw(18) << TransferRegister.SourceNewBalance;
		cout << "| " << left << setw(23) << TransferRegister.DestinationNewBalance;
		cout << "| " << left << setw(9)  << TransferRegister.UserName << endl;
	}





public:


	static void ShowTransferRegisterScreen()
	{


		vector <clsBankClient::stTransferRegister> vTransferRegister = clsBankClient::GetAllTransferRegisterList();

		_DrawScreenHeader("Login Register Screen", "(" + to_string(vTransferRegister.size()) + ") Logins.");


		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"------------------------------------------------- " << endl;

		cout << setw(8) << left << "";
		cout << "| " << left << setw(22) << "Time";
		cout << "| " << left << setw(17) << "Source Acc.Number";
		cout << "| " << left << setw(22) << "Destination Acc.Number";
		cout << "| " << left << setw(15)  << "Amount";
		cout << "| " << left << setw(18) << "Source New Balance";
		cout << "| " << left << setw(23) << "Destination New Balance";
		cout << "| " << left << setw(9)  << "UserName" << endl;

		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"------------------------------------------------- " << endl;

		for (clsBankClient::stTransferRegister& TransferRegister : vTransferRegister)
		{

			_PrintTranferRegisterLineOfTable(TransferRegister);
		}

		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------"
			"------------------------------------------------- " << endl;
	}


};
