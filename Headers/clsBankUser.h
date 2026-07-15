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
	int _Permisions;
	bool _MarkedForDelete = false;














public:




};


