#include <iostream>

#include "clsLoginScreen.h"


using namespace std;

template <typename Typ> bool CheckNumberInRange(Typ Number, Typ From, Typ To)
{
    return Number >= From && Number <= To;
}

template <typename T> T ValidateNumber(T Number)
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

template <typename Type> Type ReadNumberInRange(Type From, Type To, const string& MessageToUser)
{
    Type Number = 0;

    cout << MessageToUser;
    cin >> Number;

    Number = ValidateNumber<Type>(Number);

    while (!CheckNumberInRange(Number, From, To))
    {
        cout << "\a\n\nShould be Between " << From << " to " << To << endl << endl << MessageToUser;
        cin >> Number;

        Number = ValidateNumber(Number);
    }

    return Number;
}



int main()
{
	


	/*while (clsLoginScreen::ShowLoginScreen())
	{

	}*/


	return 0;

}