#pragma once

#include<iostream>

using namespace std;

class clsUtility
{

public:

    static string GetNumberText(int Number)
    {

        static short Counter = 0;

        string NumberBeforeTwentyName[20] = { "", "One ", "Tow ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight "
            , "Nine ","Ten ","Eleven ","Twelve ", "Theerteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen "
            , "Eighteen ", "Nineteen " };

        string NumberAfterTwentyName[8] = { "Twenty ", "Theerty ", "Fourty ", "Fifty ", "Sixty ", "Seventy ", "Eighty "
            , "Ninety " };

        string PowersName[4] = { "" ,"Thaousends ","Millions ","Billions " };

        if (Counter == 0 && Number == 0)
        {
            return "Zero";
        }

        if (Number > 0)
        {
            short LastThreeDigits = Number % 1000, TowRightDigits = LastThreeDigits % 100, LeftDigit = LastThreeDigits / 100;

            string Text = "";

            if (LeftDigit > 0)
            {
                Text = NumberBeforeTwentyName[LeftDigit] + "Handreds ";
            }

            if (TowRightDigits < 20)
            {
                Text += NumberBeforeTwentyName[TowRightDigits];

                if (Text != "")
                {
                    Text += PowersName[Counter];
                }

            }
            else
            {

                Text += NumberAfterTwentyName[(TowRightDigits / 10) - 2] + NumberBeforeTwentyName[TowRightDigits % 10];

                if (Text != "")
                {
                    Text += PowersName[Counter];
                }

            }

            Counter++;

            return GetNumberText(Number / 1000) + Text;

        }

        Counter = 0;

        return "";

    }





};