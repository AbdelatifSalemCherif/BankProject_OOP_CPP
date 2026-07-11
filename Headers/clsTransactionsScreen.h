#pragma once

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputSettings.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{

private:

	enum enTransactionOptions { eDeposite = 1, eWithdraw = 2, eTotalBalance = 3, eExit = 4};



public:

	static void ShowTransactionsScreen(const string& FileName, const string& Separator)
	{





	}



};


