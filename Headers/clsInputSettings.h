#pragma once

#include <iostream>
#include<string>
#include<cctype>
#include "clsString.h";

using namespace std;


class clsInputSettings
{
public:


    // ------------------------------------------------- Check positive numbers --------------------------------------------------------- 

   /* static bool CheckPostiveNumber(int Number)
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

    static bool CheckPostiveDouble(double Number)
    {
        return Number >= 0;
    }

    static bool CheckPostiveLongLong(long long Number)
    {
        return Number >= 0;
    }

    static bool CheckPostiveLongDouble(long double Number)
    {
        return Number >= 0;
    }*/

    template <typename T>
    static bool CheckPositiveNumber(T Number)
    {
        return Number >= 0;
    }



    // ----------------------------------------------------- Check numbers in range -----------------------------------------------------

    /*static bool CheckNumberInRange(int Number, int From, int To)
    {
        return Number >= From && Number <= To;
    }

    static bool CheckNumberInRange(short Number, short From, short To)
    {
        return Number >= From && Number <= To;
    }

    static bool CheckLongLongInRange(long long Number, long long From, long long To)
    {
        return Number >= From && Number <= To;
    }

    static bool CheckFloatInRange(float Number, float From, float To)
    {
        return Number >= From && Number <= To;
    }

    static bool CheckDoubleInRange(double Number, double From, double To)
    {
        return Number >= From && Number <= To;
    }

    static bool CheckLongDoubleInRange(long double Number, long double From, long double To)
    {
        return Number >= From && Number <= To;
    }*/

    template <typename T>
    static bool CheckNumberInRange(T Number, T From, T To)
    {

        if (From > To)
        {
            T Temp = From;
            From = To;
            To = Temp;
        }

        return Number >= From && Number <= To;
    }



    // ------------------------------------------------------- Number Validation --------------------------------------------------------

    static int ValidateInteger(int Number)
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

    static float ValidateFloat(float Number)
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

    static double ValidateDouble(double Number)
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

    static short ValidateShort(short Number)
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

    static long long ValidateLongLong(long long Number)
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

    static long double ValidateLongDouble(long double Number)
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

    static bool ValidateBoolian(bool Boolian)
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

    template <typename T>
    static T ValidateNumber(T Number)
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



    // -------------------------------------------------- Read Variables ----------------------------------------------------------------

    static int ReadInteger(const string& MessageToUser = "\nPlease enter an Integer Number ?\n")
    {
        int Number = 0;
        cout << MessageToUser;
        cin >> Number;

        Number = ValidateInteger(Number);

        return Number;

    }

    static float ReadFloat(const string& MessageToUser = "\nPlease enter a float Number ?\n")
    {
        float Number = 0;
        cout << MessageToUser;
        cin >> Number;

        Number = ValidateFloat(Number);

        return Number;

    }

    static short ReadShort(const string& MessageToUser = "\nPlease enter a Short Number ?\n")
    {
        short Number = 0;
        cout << MessageToUser;
        cin >> Number;

        Number = ValidateShort(Number);

        return Number;

    }

    static long long int ReadLongLong(const string& MessageToUser = "\nPlease enter a Long Integer Number ?\n")
    {
        long long int Number = 0;
        cout << MessageToUser;
        cin >> Number;

        Number = ValidateLongLong(Number);

        return Number;

    }

    static double ReadDouble(const string& MessageToUser = "\nPlease enter a Double Number ?\n")
    {
        double Number = 0;
        cout << MessageToUser;
        cin >> Number;

        Number = ValidateDouble(Number);


        return Number;
    }

    static long double ReadLongDouble(const string& MessageToUser = "\nPlease enter a Long Double Number ?\n")
    {
        long double Number = 0;
        cout << MessageToUser;
        cin >> Number;

        Number = ValidateLongDouble(Number);

        return Number;

    }

    static bool ReadBoolian(const string& MessageToUser = "\nPlease enter true (1) or false (0) ?\n")
    {
        bool Bool = true;
        cout << MessageToUser;
        cin >> Bool;

        Bool = ValidateBoolian(Bool);

        return Bool;
    }

    static string ReadString(const string& MessageToUser = "\nPlease enter a String ?\n")
    {
        string String = " ";
        cout << MessageToUser;
        getline(cin >> ws, String);
        /*cin.ignore(1, '\n');*/


        return String;

    }

    static char ReadCharacter(const string& MessageToUser = "\nPlease enter a Character ?\n")
    {
        char Char = 'A';
        cout << MessageToUser;
        cin >> Char;

        return Char;

    }

    template <typename T>
    static T ReadNumber(const string& MessageToUser = "\nPlease enter a Character ?\n")
    {
        T Number;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber<T>(Number);

        return Number;
    }



    // --------------------------------------------- Read Positive Number ---------------------------------------------------------------

    /*static int ReadPositiveNumber(const string& MessageToUser = "\nPlease enter a positive integer ?\n"
        , string ErrorMessage = "\n\nShould be a Positive Number !\n\n")
    {
        int Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateInteger(Number);

        while (!CheckPostiveNumber(Number))
        {
            cout << "\a" << ErrorMessage << MessageToUser;
            cin >> Number;

            Number = ValidateInteger(Number);

        }

        return Number;
    }

    static float ReadPositiveNumber(const string& MessageToUser = "\nPlease enter a positive float ?\n"
        , string ErrorMessage = "\n\nShould be a Positive Number !\n\n")
    {
        float Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateFloat(Number);

        while (!CheckPostiveNumber(Number))
        {
            cout << "\a" << ErrorMessage << MessageToUser;
            cin >> Number;

            Number = ValidateFloat(Number);

        }

        return Number;
    }

    static short ReadPositiveNumber(const string& MessageToUser = "\nPlease enter a positive short ?\n"
        , string ErrorMessage = "\n\nShould be a Positive Number !\n\n")
    {
        short Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateShort(Number);

        while (!CheckPostiveNumber(Number))
        {
            cout << "\a" << ErrorMessage << MessageToUser;
            cin >> Number;

            Number = ValidateShort(Number);

        }

        return Number;
    }

    static double ReadPositiveDouble(const string& MessageToUser = "\nPlease enter a positive double ?\n"
        , string ErrorMessage = "\n\nShould be a Positive Number !\n\n")
    {
        double Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateDouble(Number);

        while (!CheckPostiveDouble(Number))
        {
            cout << "\a" << ErrorMessage << MessageToUser;
            cin >> Number;

            Number = ValidateDouble(Number);

        }

        return Number;
    }

    static long long ReadPositiveLongLong(const string& MessageToUser = "\nPlease enter a positive long integer ?\n"
        , string ErrorMessage = "\n\nShould be a Positive Number !\n\n")
    {
        long long Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateLongLong(Number);

        while (!CheckPostiveLongLong(Number))
        {
            cout << "\a" << ErrorMessage << MessageToUser;
            cin >> Number;

            Number = ValidateLongLong(Number);

        }
        return Number;
    }

    static long double ReadPositiveLongDouble(const string& MessageToUser = "\nPlease enter a positive Long Double ?\n"
        , string ErrorMessage = "\n\nShould be a Positive Number !\n\n")
    {
        long double Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateLongDouble(Number);

        while (!CheckPostiveLongDouble(Number))
        {
            cout << "\a" << ErrorMessage << MessageToUser;
            cin >> Number;

            Number = ValidateLongDouble(Number);

        }

        return Number;
    }*/

    template <typename T>
    static T ReadPositiveNumber(const string& MessageToUser = "\nPlease enter a positive Number ?\n"
        , string ErrorMessage = "\n\nShould be a Positive Number !\n\n")
    {
        T Number;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber<T>(Number);

        while (!CheckPositiveNumber(Number))
        {
            cout << "\n\a" << ErrorMessage;
            cin >> Number;

            Number = ValidateNumber<T>(Number);

        }

        return Number;
    }




    // ---------------------------------------------- Read Number In Range --------------------------------------------------------------

    /*static int ReadNumberInRange(int From, int To, const string& MessageToUser)
    {
        int Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateInteger(Number);

        while (!CheckNumberInRange(Number, From, To))
        {
            cout << "\a\n\nShould be Between " << From << " to " << To << endl << endl << MessageToUser;
            cin >> Number;

            Number = ValidateInteger(Number);
        }

        return Number;
    }

    static float ReadNumberInRange(float From, float To, const string& MessageToUser)
    {
        float Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateFloat(Number);

        while (!CheckFloatInRange(Number, From, To))
        {
            cout << "\a\n\nShould be Between " << From << " to " << To << endl << endl << MessageToUser;
            cin >> Number;

            Number = ValidateFloat(Number);
        }

        return Number;
    }

    static short ReadNumberInRange(short From, short To, const string& MessageToUser)
    {
        short Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateShort(Number);

        while (!CheckNumberInRange(Number, From, To))
        {
            cout << "\a\n\nShould be Between " << From << " to " << To << endl << endl << MessageToUser;
            cin >> Number;

            Number = ValidateShort(Number);
        }

        return Number;
    }

    static long long ReadLongLongInRange(long long From, long long To, const string& MessageToUser)
    {
        long long Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateLongLong(Number);

        while (!CheckLongLongInRange(Number, From, To))
        {
            cout << "\a\n\nShould be Between " << From << " to " << To << endl << endl << MessageToUser;
            cin >> Number;

            Number = ValidateLongLong(Number);
        }

        return Number;
    }

    static double ReadDoubleInRange(double From, double To, const string& MessageToUser)
    {
        double Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateDouble(Number);

        while (!CheckDoubleInRange(Number, From, To))
        {
            cout << "\a\n\nShould be Between " << From << " to " << To << endl << endl << MessageToUser;
            cin >> Number;

            Number = ValidateDouble(Number);
        }
        return Number;
    }

    static long double ReadLongDoubleInRange(long double From, long double To, const string& MessageToUser)
    {
        long double Number = 0;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateLongDouble(Number);

        while (!CheckLongDoubleInRange(Number, From, To))
        {
            cout << "\a\n\nShould be Between " << From << " to " << To << endl << endl << MessageToUser;
            cin >> Number;

            Number = ValidateLongDouble(Number);
        }

        return Number;
    }*/

    template <typename T>
    static T ReadNumberInRange(T From, T To, const string& MessageToUser)
    {
        T Number ;

        cout << MessageToUser;
        cin >> Number;

        Number = ValidateNumber<T>(Number);

        while (!CheckNumberInRange<T>(Number, From, To))
        {
            cout << "\a\n\nShould be Between " << From << " to " << To << endl << endl << MessageToUser;
            cin >> Number;

            Number = ValidateNumber<T>(Number);
        }

        return Number;
    }




    // ------------------------------------ special read for yes or no cases from consol -------------------------------------------------

    static bool ReadYesOrNo(const string& MessageToUser, bool CleanConsol = false)
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
        {
            system("CLS");
            system("Color 0F");
        }


        return Yes;

    }



    // ----------------------------------------------------- Random number in range ------------------------------------------------------

    /*static int RandomIntegerInRange(int From, int To)
    {
        int Number = rand();

        return (Number % (To - From + 1)) + From;
    }

    static short RandomShortInRange(short From, short To)
    {
        short Number = rand();

        return (Number % (To - From + 1)) + From;
    }

    static long long RandomLongLongInRange(long long From, long long To)
    {
        long long Number = rand();

        return (Number % (To - From + 1)) + From;
    }

    static char RandomCharacterInRange(char From, char To)
    {
        short Number = RandomShortInRange(0, 127);


        return char((Number % (short(To) - short(From) + 1)) + short(From));
    }

    static string RandomStringInRange(short Length, char From, char To)
    {
        string Word = "";

        for (short i = 0; i < Length; i++)
        {
            Word = Word + RandomCharacterInRange(From, To);
        }

        return Word;
    }*/

    template <typename T>

    static T RandomNumberInRange(T From, T To)
    {

        T Number = rand();

        if (From > To)
        {

            T Temp = From;
            From = To;
            To = Temp;

        }

        return (Number % (To - From + 1)) + From;
    }


};