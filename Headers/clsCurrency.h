#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "clsString.h"

using namespace std;

class clsCurrency
{

private:

	// --------------------------------------------------- Data Members -----------------------------------------------------------------

	enum enMode {eEmptyMode = 1, eUpdateMode = 2};
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;



public:

	






};



