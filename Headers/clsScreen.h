#pragma once

#include <iostream>

#include "Global.h"
#include "clsBankUser.h"

using namespace std;


class clsScreen
{

protected:

	static void _DrawScreenHeader(const string& Title, const string& SubTitle = "")
	{
		cout << "\t\t\t\t\t----------------------------------------------------------";

		cout << "\n\n\t\t\t\t\t\t\t\t" << Title;

		if (SubTitle != "")
		{
			cout << "\n\n\t\t\t\t\t\t\t\t" << SubTitle;
		}

		cout << "\n\n\t\t\t\t\t----------------------------------------------------------\n";

	}

	static bool _CheckAccessRights(clsBankUser::enPermissions Permission)
	{

		if (CurrentUser.CheckAccessPermission(Permission))
		{
			return true;
		}
		else
		{
			_DrawScreenHeader("Access Dinied ! Contact Your Admin,");

			return false;
		}

	}






};