#pragma once

#include <iostream>
#include<string>
#include<cctype>
#include "clsString.h";

using namespace std;


class clsInputSettings
{
public:


    static bool CheckPostiveNumber(int Number)
    {
        return Number >= 0;
    }

    static bool CheckPostiveNumber(short Number)
    {
        return Number >= 0;
    }

    static bool CheckPostiveNumber(float Number)
    {
        return Number >= 0;
    }

    static bool CheckPostiveNumber(double Number)
    {
        return Number >= 0;
    }

    static bool CheckPostiveNumber(long long Number)
    {
        return Number >= 0;
    }

    static bool CheckPostiveNumber(long double Number)
    {
        return Number >= 0;
    }







    static bool CheckNumberInRange(int Number, int From, int To)
    {
        return Number >= From && Number <= To;
    }

    static bool CheckNumberInRange(short Number, short From, short To)
    {
        return Number >= From && Number <= To;
    }

    static bool CheckNumberInRange(long long Number, long long From, long long To)
    {
        return Number >= From && Number <= To;
    }

    static bool CheckNumberInRange(float Number, float From, float To)
    {
        return Number >= From && Number <= To;
    }

    static bool CheckNumberInRange(double Number, double From, double To)
    {
        return Number >= From && Number <= To;
    }

    static bool CheckNumberInRange(long double Number, long double From, long double To)
    {
        return Number >= From && Number <= To;
    }









    static int ValidateNumber(int& Number)
    {

        while (cin.fail())
        {
            cin.clear();

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "\aInvalid number, Enter a valid number ?" << endl;

            cin >> Number;
        }

        return Number;
    }

    static float ValidateNumber(float& Number)
    {

        while (cin.fail())
        {
            cin.clear();

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "\aInvalid number, Enter a valid number ?" << endl;

            cin >> Number;
        }

        return Number;
    }

    static double ValidateNumber(double& Number)
    {

        while (cin.fail())
        {
            cin.clear();

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "\aInvalid number, Enter a valid number ?" << endl;

            cin >> Number;
        }

        return Number;
    }

    static short ValidateNumber(short& Number)
    {

        while (cin.fail())
        {
            cin.clear();

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "\aInvalid number, Enter a valid number ?" << endl;

            cin >> Number;
        }

        return Number;
    }

    static long long ValidateNumber(long long& Number)
    {

        while (cin.fail())
        {
            cin.clear();

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "\aInvalid number, Enter a valid number ?" << endl;

            cin >> Number;
        }

        return Number;
    }

    static long double ValidateNumber(long double& Number)
    {

        while (cin.fail())
        {
            cin.clear();

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "\aInvalid number, Enter a valid number ?" << endl;

            cin >> Number;
        }

        return Number;
    }

    static bool ValidateBoolian(bool& Boolian)
    {
        while (cin.fail())
        {
            cin.clear();

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "\aInvalid Boolian, Enter a valid Boolian ?" << endl;

            cin >> Boolian;
        }

        return Boolian;
    }





    static int ReadNumber(int TypeFunction = 0, string MessageToUser = "\nPlease enter an Integer Number ?\n")
    {
        int Number = 0;
        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber(Number);

        return Number;

    }

    static float ReadNumber(float TypeFunction = 0, string MessageToUser = "\nPlease enter a float Number ?\n")
    {
        float Number = 0;
        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber(Number);

        return Number;

    }

    static short ReadNumber(short TypeFunction = 0, string MessageToUser = "\nPlease enter a Short Number ?\n")
    {
        short Number = 0;
        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber(Number);

        return Number;

    }

    static long long int ReadNumber(long long TypeFunction = 0, string MessageToUser = "\nPlease enter a Long Integer Number ?\n")
    {
        long long int Number = 0;
        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber(Number);

        return Number;

    }

    static double ReadNumber(double TypeFunction = 0, string MessageToUser = "\nPlease enter a Double Number ?\n")
    {
        double Number = 0;
        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber(Number);


        return Number;
    }

    static long double ReadNumber(long double TypeFunction = 0, string MessageToUser = "\nPlease enter a Long Double Number ?\n")
    {
        long double Number = 0;
        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber(Number);

        return Number;

    }

    static bool ReadBoolian(string MessageToUser = "\nPlease enter true (1) or false (0) ?\n")
    {
        bool Bool = true;
        cout << MessageToUser;
        cin >> Bool;

        Bool = ValidateBoolian(Bool);

        return Bool;
    }

    static string ReadString(string MessageToUser = "\nPlease enter a String ?\n")
    {
        string String = " ";
        cout << MessageToUser;
        getline(cin >> ws, String);
        /*cin.ignore(1, '\n');*/


        return String;

    }

    static char ReadCharacter(string MessageToUser = "\nPlease enter a Character ?\n")
    {
        char Char = 'A';
        cout << MessageToUser;
        cin >> Char;

        return Char;

    }








    static int ReadPositiveNumber(int TypeFunction = 0, string MessageToUser = "\nPlease enter a positive integer ?\n"
        , string ErrorMessage = "\n\nShould be a Positive Number !\n\n")
    {
        int Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber(Number);

        while (!CheckPostiveNumber(Number))
        {
            cout << "\a" << ErrorMessage << MessageToUser;
            cin >> Number;

            Number = ValidateNumber(Number);

        }

        return Number;
    }

    static float ReadPositiveNumber(float TypeFunction = 0, string MessageToUser = "\nPlease enter a positive float ?\n"
        , string ErrorMessage = "\n\nShould be a Positive Number !\n\n")
    {
        float Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber(Number);

        while (!CheckPostiveNumber(Number))
        {
            cout << "\a" << ErrorMessage << MessageToUser;
            cin >> Number;

            Number = ValidateNumber(Number);

        }

        return Number;
    }

    static short ReadPositiveNumber(short TypeFunction = 0, string MessageToUser = "\nPlease enter a positive short ?\n"
        , string ErrorMessage = "\n\nShould be a Positive Number !\n\n")
    {
        short Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber(Number);

        while (!CheckPostiveNumber(Number))
        {
            cout << "\a" << ErrorMessage << MessageToUser;
            cin >> Number;

            Number = ValidateNumber(Number);

        }

        return Number;
    }

    static double ReadPositiveNumber(double TypeFunction = 0, string MessageToUser = "\nPlease enter a positive double ?\n"
        , string ErrorMessage = "\n\nShould be a Positive Number !\n\n")
    {
        double Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber(Number);

        while (!CheckPostiveNumber(Number))
        {
            cout << "\a" << ErrorMessage << MessageToUser;
            cin >> Number;

            Number = ValidateNumber(Number);

        }

        return Number;
    }

    static long long ReadPositiveNumber(long long TypeFunction = 0, string MessageToUser = "\nPlease enter a positive long integer ?\n"
        , string ErrorMessage = "\n\nShould be a Positive Number !\n\n")
    {
        long long Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber(Number);

        while (!CheckPostiveNumber(Number))
        {
            cout << "\a" << ErrorMessage << MessageToUser;
            cin >> Number;

            Number = ValidateNumber(Number);

        }
        return Number;
    }

    static long double ReadPositiveNumber(long double TypeFunction = 0, string MessageToUser = "\nPlease enter a positive Long Double ?\n"
        , string ErrorMessage = "\n\nShould be a Positive Number !\n\n")
    {
        long double Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber(Number);

        while (!CheckPostiveNumber(Number))
        {
            cout << "\a" << ErrorMessage << MessageToUser;
            cin >> Number;

            Number = ValidateNumber(Number);

        }

        return Number;
    }









    static int ReadNumberInRange(int From, int To, string MessageToUser)
    {
        int Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber(Number);

        while (!CheckNumberInRange(Number, From, To))
        {
            cout << "\a\n\nShould be Between " << From << " to " << To << endl << endl << MessageToUser;
            cin >> Number;

            Number = ValidateNumber(Number);
        }

        return Number;
    }

    static float ReadNumberInRange(float From, float To, string MessageToUser)
    {
        float Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber(Number);

        while (!CheckNumberInRange(Number, From, To))
        {
            cout << "\a\n\nShould be Between " << From << " to " << To << endl << endl << MessageToUser;
            cin >> Number;

            Number = ValidateNumber(Number);
        }

        return Number;
    }

    static short ReadNumberInRange(short From, short To, string MessageToUser)
    {
        short Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber(Number);

        while (!CheckNumberInRange(Number, From, To))
        {
            cout << "\a\n\nShould be Between " << From << " to " << To << endl << endl << MessageToUser;
            cin >> Number;

            Number = ValidateNumber(Number);
        }

        return Number;
    }

    static long long ReadNumberInRange(long long From, long long To, string MessageToUser)
    {
        long long Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber(Number);

        while (!CheckNumberInRange(Number, From, To))
        {
            cout << "\a\n\nShould be Between " << From << " to " << To << endl << endl << MessageToUser;
            cin >> Number;

            Number = ValidateNumber(Number);
        }

        return Number;
    }

    static double ReadNumberInRange(double From, double To, string MessageToUser)
    {
        double Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber(Number);

        while (!CheckNumberInRange(Number, From, To))
        {
            cout << "\a\n\nShould be Between " << From << " to " << To << endl << endl << MessageToUser;
            cin >> Number;

            Number = ValidateNumber(Number);
        }
        return Number;
    }

    static long double ReadNumberInRange(long double From, long double To, string MessageToUser)
    {
        long double Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber(Number);

        while (!CheckNumberInRange(Number, From, To))
        {
            cout << "\a\n\nShould be Between " << From << " to " << To << endl << endl << MessageToUser;
            cin >> Number;

            Number = ValidateNumber(Number);
        }

        return Number;
    }



    static void RestScreen()
    {
        system("CLS");
        system("Color 0F");
    }


    static bool ReadYesOrNo(string MessageToUser, bool CleanConsol = false)
    {
        bool Yes = false, No = false;

        string UserChoice = "";

        do {
            cout << MessageToUser;
            cin >> UserChoice;

            Yes = clsString::ToUpperAllPhrase(UserChoice) == "Y" || clsString::ToUpperAllPhrase(UserChoice) == "YES";
            No = clsString::ToUpperAllPhrase(UserChoice) == "N" || clsString::ToUpperAllPhrase(UserChoice) == "NO";


        } while (UserChoice.length() > 3 || (!Yes && !No));

        if (CleanConsol && Yes)
            RestScreen();


        return Yes;

    }





    static int RandomNumberInRange(int From, int To)
    {
        int Number = rand();

        return (Number % (To - From + 1)) + From;
    }

    static short RandomNumberInRange(short From, short To)
    {
        short Number = rand();

        return (Number % (To - From + 1)) + From;
    }

    static long long RandomNumberInRange(long long From, long long To)
    {
        long long Number = rand();

        return (Number % (To - From + 1)) + From;
    }

    static char RandomCharacterInRange(char From, char To)
    {
        short Number = RandomNumberInRange((short)0, (short)127);


        return char((Number % (short(To) - short(From) + 1)) + short(From));
    }

    static string RandomWordInRange(short Length, char From, char To)
    {
        string Word = "";

        for (short i = 0; i < Length; i++)
        {
            Word = Word + RandomCharacterInRange(From, To);
        }

        return Word;
    }



};