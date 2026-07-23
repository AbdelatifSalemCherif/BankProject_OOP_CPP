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

    template <typename T>
    static bool CheckPositiveNumber(T Number)
    {
        return Number >= 0;
    }


    // ----------------------------------------------------- Check numbers in range -----------------------------------------------------

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


    static char RandomCharacterInRange(char From, char To)
    {
        short Number = RandomNumberInRange<short>(0, 127);


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
    }

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