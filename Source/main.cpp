#include <iostream>

#include "clsBankClient.h"

using namespace std;

int main()
{

	clsBankClient Client1 = clsBankClient::Find("A003", "BankData/Clients.txt", "#//#");

	Client1.Print();

	clsBankClient Client2 = clsBankClient::Find("A001", "1234", "BankData/Clients.txt", "#//#");

	Client2.Print();




}