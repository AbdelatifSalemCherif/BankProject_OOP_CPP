#pragma once

#include<iostream>
#include<string>
#include<vector>



using namespace std;


class clsString;

class clsOutputSettings
{

public:



	// Print variables all data types

	static void PrintNumber(string MessageToUserBefore, int Number, string MessageToUserAfter)
	{
		cout << MessageToUserBefore << Number << MessageToUserAfter;

	}

	static void PrintNumber(string MessageToUserBefore, short Number, string MessageToUserAfter)
	{
		cout << MessageToUserBefore << Number << MessageToUserAfter;

	}

	static void PrintNumber(string MessageToUserBefore, float Number, string MessageToUserAfter)
	{
		cout << MessageToUserBefore << Number << MessageToUserAfter;

	}

	static void PrintNumber(string MessageToUserBefore, long long Number, string MessageToUserAfter)
	{
		cout << MessageToUserBefore << Number << MessageToUserAfter;

	}

	static void PrintNumber(string MessageToUserBefore, double Number, string MessageToUserAfter)
	{
		cout << MessageToUserBefore << Number << MessageToUserAfter;

	}

	static void PrintNumber(string MessageToUserBefore, long double Number, string MessageToUserAfter)
	{
		cout << MessageToUserBefore << Number << MessageToUserAfter;

	}

	static void PrintBoolian(string MessageToUserBefore, bool Bool, string MessageToUserAfter)
	{
		cout << MessageToUserBefore << Bool << MessageToUserAfter;

	}

	static void PrintString(string MessageToUserBefore, string String, string MessageToUserAfter)
	{
		cout << MessageToUserBefore << String << MessageToUserAfter;

	}

	static void PrintCharacter(string MessageToUserBefore, char Character, string MessageToUserAfter)
	{
		cout << MessageToUserBefore << Character << MessageToUserAfter;

	}













	// Print Array all data types 

	static void PrintArray(int Arr[], int Length, string Header = "\nArray Elements :\n", string WordBetweenElements = "\n"
		, string WordBeforePosition = "", bool ShowPosition = false, string WordAfterPoition = "")
	{
		cout << Header;

		if (ShowPosition)
		{
			for (int i = 0; i < Length; i++)
			{

				cout << WordBeforePosition << i + 1 << WordAfterPoition << Arr[i] << WordBetweenElements;
			}
		}
		else
		{
			for (int i = 0; i < Length; i++)
			{

				cout << Arr[i] << WordBetweenElements;
			}
		}
	}

	static void PrintArray(float Arr[], int Length, string Header = "\nArray Elements :\n", string WordBetweenElements = "\n"
		, string WordBeforePosition = "", bool ShowPosition = false, string WordAfterPoition = "")
	{
		cout << Header;

		cout << Header;

		if (ShowPosition)
		{
			for (int i = 0; i < Length; i++)
			{

				cout << WordBeforePosition << i + 1 << WordAfterPoition << Arr[i] << WordBetweenElements;
			}
		}
		else
		{
			for (int i = 0; i < Length; i++)
			{

				cout << Arr[i] << WordBetweenElements;
			}
		}
	}

	static void PrintArray(double Arr[], int Length, string Header = "\nArray Elements :\n", string WordBetweenElements = "\n"
		, string WordBeforePosition = "", bool ShowPosition = false, string WordAfterPoition = "")
	{
		cout << Header;

		if (ShowPosition)
		{
			for (int i = 0; i < Length; i++)
			{

				cout << WordBeforePosition << i + 1 << WordAfterPoition << Arr[i] << WordBetweenElements;
			}
		}
		else
		{
			for (int i = 0; i < Length; i++)
			{

				cout << Arr[i] << WordBetweenElements;
			}
		}
	}

	static void PrintArray(short Arr[], int Length, string Header = "\nArray Elements :\n", string WordBetweenElements = "\n"
		, string WordBeforePosition = "", bool ShowPosition = false, string WordAfterPoition = "")
	{
		cout << Header;

		if (ShowPosition)
		{
			for (int i = 0; i < Length; i++)
			{

				cout << WordBeforePosition << i + 1 << WordAfterPoition << Arr[i] << WordBetweenElements;
			}
		}
		else
		{
			for (int i = 0; i < Length; i++)
			{

				cout << Arr[i] << WordBetweenElements;
			}
		}
	}

	static void PrintArray(long long Arr[], int Length, string Header = "\nArray Elements :\n", string WordBetweenElements = "\n"
		, string WordBeforePosition = "", bool ShowPosition = false, string WordAfterPoition = "")
	{
		cout << Header;

		if (ShowPosition)
		{
			for (int i = 0; i < Length; i++)
			{

				cout << WordBeforePosition << i + 1 << WordAfterPoition << Arr[i] << WordBetweenElements;
			}
		}
		else
		{
			for (int i = 0; i < Length; i++)
			{

				cout << Arr[i] << WordBetweenElements;
			}
		}
	}

	static void PrintArray(long double Arr[], int Length, string Header = "\nArray Elements :\n", string WordBetweenElements = "\n"
		, string WordBeforePosition = "", bool ShowPosition = false, string WordAfterPoition = "")
	{
		cout << Header;

		if (ShowPosition)
		{
			for (int i = 0; i < Length; i++)
			{

				cout << WordBeforePosition << i + 1 << WordAfterPoition << Arr[i] << WordBetweenElements;
			}
		}
		else
		{
			for (int i = 0; i < Length; i++)
			{

				cout << Arr[i] << WordBetweenElements;
			}
		}
	}

	static void PrintArray(char Arr[], int Length, string Header = "\nArray Elements :\n", string WordBetweenElements = "\n"
		, string WordBeforePosition = "", bool ShowPosition = false, string WordAfterPoition = "")
	{
		cout << Header;

		if (ShowPosition)
		{
			for (int i = 0; i < Length; i++)
			{

				cout << WordBeforePosition << i + 1 << WordAfterPoition << Arr[i] << WordBetweenElements;
			}
		}
		else
		{
			for (int i = 0; i < Length; i++)
			{

				cout << Arr[i] << WordBetweenElements;
			}
		}
	}

	static void PrintArray(string Arr[], int Length, string Header = "\nArray Elements :\n", string WordBetweenElements = "\n"
		, string WordBeforePosition = "", bool ShowPosition = false, string WordAfterPoition = "")
	{
		cout << Header;

		if (ShowPosition)
		{
			for (int i = 0; i < Length; i++)
			{

				cout << WordBeforePosition << i + 1 << WordAfterPoition << Arr[i] << WordBetweenElements;
			}
		}
		else
		{
			for (int i = 0; i < Length; i++)
			{

				cout << Arr[i] << WordBetweenElements;
			}
		}
	}


















	// Print vector all data types

	static void PrintVector(vector <int>& Vector, string Header = "\nVector Elements :\n", string WordBetweenElements = "\n"
		, string WordBeforePosition = "", bool ShowPosition = false, string WordAfterPoition = "")
	{
		cout << Header;

		if (ShowPosition)
		{
			for (short i = 0; i < Vector.size(); i++)
			{

				cout << WordBeforePosition << i + 1 << WordAfterPoition << Vector[i] << WordBetweenElements;
			}
		}
		else
		{
			for (int& i : Vector)
			{
				cout << i << WordBetweenElements;
			}
		}

	}

	static void PrintVector(vector <short>& Vector, string Header = "\nVector Elements :\n", string WordBetweenElements = "\n"
		, string WordBeforePosition = "", bool ShowPosition = false, string WordAfterPoition = "")
	{
		cout << Header;

		if (ShowPosition)
		{
			for (short i = 0; i < Vector.size(); i++)
			{

				cout << WordBeforePosition << i + 1 << WordAfterPoition << Vector[i] << WordBetweenElements;
			}
		}
		else
		{
			for (short& i : Vector)
			{
				cout << i << WordBetweenElements;
			}
		}

	}

	static void PrintVector(vector <long long>& Vector, string Header = "\nVector Elements :\n", string WordBetweenElements = "\n"
		, string WordBeforePosition = "", bool ShowPosition = false, string WordAfterPoition = "")
	{
		cout << Header;

		if (ShowPosition)
		{
			for (short i = 0; i < Vector.size(); i++)
			{

				cout << WordBeforePosition << i + 1 << WordAfterPoition << Vector[i] << WordBetweenElements;
			}
		}
		else
		{
			for (long long& i : Vector)
			{
				cout << i << WordBetweenElements;
			}
		}

	}

	static void PrintVector(vector <float>& Vector, string Header = "\nVector Elements :\n", string WordBetweenElements = "\n"
		, string WordBeforePosition = "", bool ShowPosition = false, string WordAfterPoition = "")
	{
		cout << Header;

		if (ShowPosition)
		{
			for (short i = 0; i < Vector.size(); i++)
			{

				cout << WordBeforePosition << i + 1 << WordAfterPoition << Vector[i] << WordBetweenElements;
			}
		}
		else
		{
			for (float& i : Vector)
			{
				cout << i << WordBetweenElements;
			}
		}

	}

	static void PrintVector(vector <double>& Vector, string Header = "\nVector Elements :\n", string WordBetweenElements = "\n"
		, string WordBeforePosition = "", bool ShowPosition = false, string WordAfterPoition = "")
	{
		cout << Header;

		if (ShowPosition)
		{
			for (short i = 0; i < Vector.size(); i++)
			{

				cout << WordBeforePosition << i + 1 << WordAfterPoition << Vector[i] << WordBetweenElements;
			}
		}
		else
		{
			for (double& i : Vector)
			{
				cout << i << WordBetweenElements;
			}
		}

	}

	static void PrintVector(vector <long double>& Vector, string Header = "\nVector Elements :\n", string WordBetweenElements = "\n"
		, string WordBeforePosition = "", bool ShowPosition = false, string WordAfterPoition = "")
	{
		cout << Header;

		if (ShowPosition)
		{
			for (short i = 0; i < Vector.size(); i++)
			{

				cout << WordBeforePosition << i + 1 << WordAfterPoition << Vector[i] << WordBetweenElements;
			}
		}
		else
		{
			for (long double& i : Vector)
			{
				cout << i << WordBetweenElements;
			}
		}

	}

	static void PrintVector(vector <char>& Vector, string Header = "\nVector Elements :\n", string WordBetweenElements = "\n"
		, string WordBeforePosition = "", bool ShowPosition = false, string WordAfterPoition = "")
	{
		cout << Header;

		if (ShowPosition)
		{
			for (short i = 0; i < Vector.size(); i++)
			{

				cout << WordBeforePosition << i + 1 << WordAfterPoition << Vector[i] << WordBetweenElements;
			}
		}
		else
		{
			for (char& i : Vector)
			{
				cout << i << WordBetweenElements;
			}
		}

	}

	static void PrintVector(vector <string>& Vector, string Header = "\nVector Elements :\n", string WordBetweenElements = "\n"
		, string WordBeforePosition = "", bool ShowPosition = false, string WordAfterPoition = "")
	{
		cout << Header;

		if (ShowPosition)
		{
			for (short i = 0; i < Vector.size(); i++)
			{

				cout << WordBeforePosition << i + 1 << WordAfterPoition << Vector[i] << WordBetweenElements;
			}
		}
		else
		{
			for (string& i : Vector)
			{
				cout << i << WordBetweenElements;
			}
		}

	}














	// Consol methods

	static void RestScreen()
	{
		system("CLS");
		system("Color 0F");
	}

	static void SystemPause(string MessageToUser)
	{
		cout << MessageToUser;

		system("pause>0");
	}


};