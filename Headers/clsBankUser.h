#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


#include "clsPerson.h"
#include "clsString.h"

using namespace std;

class clsBankUser : public clsPerson
{

private:

	enum enMode { eEmptyMode = 0, eUpdateMode = 1, eAddNewMode = 2 };







	//Data Memebers

	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;








	






public:


	clsBankUser(enMode Mode, const string& FirstName, const string& LastName, const string& Email, const string& Phone
		, const string UserName, const string& Password, int Permissions) : clsPerson(FirstName, LastName, Email, Phone)
	{

		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;

	}



};


