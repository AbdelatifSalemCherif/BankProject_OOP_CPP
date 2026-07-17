#pragma once

#include <iostream>

#include "clsBankUser.h"


const string ClientsFileName = "BankData/Clients.txt", ClientsSeparator = "#//#"
, UsersFileName = "BankData/Users.txt", UsersSeparator = "#//#";

clsBankUser CurrentUser = clsBankUser::Find("", "", UsersFileName, UsersSeparator);

