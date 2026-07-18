#pragma once
#pragma warning(disable:4996)

#include <iostream>
#include"clsInputSettings.h";


using namespace std;




class clsDate
{
private:

    // Variables
    
    short _Year;
    short _Month;
    short _Day;

public:


    // Constructors

    clsDate()
    {
        GetTodayDate();
    }

    clsDate(short Year, short Month, short Day)
    {
        _Year = Year;
        _Month = Month;
        _Day = Day;
    }

    clsDate(string Date, string Format = "dd/mm/yyyy", string Separator = "/", string MessageToUser = "Dont Read Date From User")
    {
        if (MessageToUser == "Dont Read Date From User")
        {
            StringToDate(Date, Format, Separator);
        }

        else
        {
            ReadDateString(MessageToUser, Format, Separator);
        }

    }



















    static bool IsValideDate(short Year, short Month, short Day)
    {
        return Year > 0 && clsInputSettings::CheckShortInRange(Month, 1, 12)
            && clsInputSettings::CheckShortInRange(Day, 1, NumberOfDaysInMonth(Year, Month));
    }

    bool IsValideDate()
    {
        return IsValideDate(_Year, _Month, _Day);
    }

    /*clsDate ReadDate(string Header = "")
    {
        clsDate Date;

        cout << Header;

        Date._Day = clsInputSettings::ReadNumberInRange((short)1, (short)31, "Please enter a Day ? ");
        Date._Month = clsInputSettings::ReadNumberInRange((short)1, (short)12, "Please enter a Month ? ");
        Date._Year = clsInputSettings::ReadPositiveNumber((short)0, "Please enter a year ? ");

        while (!IsValideDate(Date))
        {
            cout << "\a\n\nThis Date Not Exist In Gregorian Calendar !\n" << endl << Header;

            Date._Day = clsInputSettings::ReadNumberInRange((short)1, (short)31, "Please enter a Day ? ");
            Date._Month = clsInputSettings::ReadNumberInRange((short)1, (short)12, "Please enter a Month ? ");
            Date._Year = clsInputSettings::ReadPositiveNumber((short)0, "Please enter a year ? ");
        }

        return Date;
    }*/

    static bool IsLeapYear(short Year)
    {
        return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
    }

    bool IsLeapYear()
    {
        return IsLeapYear(_Year);
    }

    static short NumberOfDaysInYear(short Year)
    {
        return (IsLeapYear(Year)) ? 366 : 365;
    }

    short NumberOfDaysInYear()
    {
        return NumberOfDaysInYear(_Year);
    }

    static int NumberOfHoursInYear(short Year)
    {
        return NumberOfDaysInYear(Year) * 24;
    }

    int NumberOfHoursInYear()
    {
        return NumberOfHoursInYear(_Year);
    }

    static int NumberOfMinutesInYear(short Year)
    {
        return NumberOfHoursInYear(Year) * 60;
    }

    int NumberOfMinutesInYear()
    {
        return NumberOfMinutesInYear(_Year);
    }

    static int NumberOfSecondsInYear(short Year)
    {
        return NumberOfMinutesInYear(Year) * 60;
    }

    int NumberOfSecondsInYear()
    {
        return NumberOfSecondsInYear(_Year);
    }

    static short NumberOfDaysInMonth(short Year, short Month)
    {
        if (Month < 1 || Month>12)
        {
            return 0;
        }

        short NumbersOfDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };


        return (Month == 2 && IsLeapYear(Year)) ? 29 : NumbersOfDay[Month];

    }

    short NumberOfDaysInMonth()
    {
        return NumberOfDaysInMonth(_Year, _Month);
    }

    static int NumberOfHoursInMonth(short Year, short Month)
    {
        return NumberOfDaysInMonth(Year, Month) * 24;
    }

    int NumberOfHoursInMonth()
    {
        return NumberOfHoursInMonth(_Year, _Month);
    }

    static int NumberOfMinutesInMonth(short Year, short Month)
    {
        return NumberOfHoursInMonth(Year, Month) * 60;
    }

    int NumberOfMinutesInMonth()
    {
        return NumberOfMinutesInMonth(_Year, _Month);
    }

    static int NumberOfSecondsInMonth(short Year, short Month)
    {
        return NumberOfMinutesInMonth(Year, Month) * 60;
    }

    int NumberOfSecondsInMonth()
    {
        return NumberOfSecondsInMonth(_Year, _Month);
    }

    static short DayIndex(short Year, short Month, short Day)
    {
        short a = (14 - Month) / 12, y = Year - a, m = Month + 12 * a - 2;

        return (Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    }

    short DayIndex()
    {
        return DayIndex(_Year, _Month, _Day);
    }

    static string GetDayName(short ThisDayIndex)
    {
        string DaysName[7] = { "Sun", "Mon", "Tue", "Wed", "Thur", "Fri", "Sut" };

        return DaysName[ThisDayIndex];
    }

    string GetDayName()
    {
        return GetDayName(this->DayIndex());
    }

    static string GetMonthName(short ThisMonthIndex)
    {
        string MonthNames[13] = { "","Jan", "Fib", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dic" };

        return MonthNames[ThisMonthIndex];
    }

    string GetMonthName()
    {
        return GetMonthName(_Month);
    }

    static bool IsLastDayInMonth(short Year, short Month, short Day)
    {
        return Day == NumberOfDaysInMonth(Year, Month);
    }

    bool IsLastDayInMonth()
    {
        return IsLastDayInMonth(_Year, _Month, _Day);
    }

    static bool IsLastMonthInYear(short Year, short Month, short Day)
    {
        return Month == 12;
    }

    bool IsLastMonthInYear()
    {
        return IsLastMonthInYear(_Year, _Month, _Day);
    }

    static bool IsFirstDayInMonth(short Year, short Month, short Day)
    {
        return Day == 1;
    }

    bool IsFirstDayInMonth()
    {
        return IsFirstDayInMonth(_Year, _Month, _Day);
    }

    static bool IsFirstMonthInYear(short Year, short Month, short Day)
    {
        return Month == 1;
    }

    bool IsFirstMonthInYear()
    {
        return IsFirstMonthInYear(_Year, _Month, _Day);
    }

    static bool IsEqualDate(short Year1, short Month1, short Day1, short Year2, short Month2, short Day2)
    {
        return (Year1 == Year2) && (Month1 == Month2) && (Day1 == Day2);
    }

    bool IsEqualDate(clsDate Date)
    {
        return IsEqualDate(_Year, _Month, _Day, Date._Year, Date._Month, Date._Day);
    }

    static bool IsDate1BeforeDate2(short Year1, short Month1, short Day1, short Year2, short Month2, short Day2)
    {

        if (Year1 <= Year2)
        {
            if (Year1 == Year2)
            {
                if (Month1 == Month2)
                {
                    return Day1 < Day2;
                }
                else if (Month1 < Month2)
                {
                    return true;
                }

            }
            else
            {
                return true;
            }
        }

        return false;
    }

    bool IsBeforeDate2(clsDate Date2)
    {
        return IsDate1BeforeDate2(_Year, _Month, _Day, Date2._Year, Date2._Month, Date2._Day);
    }

    static bool IsDate1AfterDate2(short Year1, short Month1, short Day1, short Year2, short Month2, short Day2)
    {
        return IsDate1BeforeDate2(Year2, Month2, Day2, Year1, Month1, Day1);
    }

    bool IsAfterDate2(clsDate Date2)
    {
        return IsDate1BeforeDate2(Date2._Year, Date2._Month, Date2._Day, _Year, _Month, _Day);
    }

    static int DayOrderInYear(short Year, short Month, short Day)
    {
        int Sum = 0;

        for (short i = 1; i < Month; i++)
        {
            Sum += NumberOfDaysInMonth(Year, i);
        }

        return Sum + Day;

    }

    int DayOrderInYear()
    {
        return DayOrderInYear(_Year, _Month, _Day);
    }

    static bool IsEndOfWeek(short Year, short Month, short Day, bool IsArabCountry = true)
    {
        short ThisDayIndex = DayIndex(Year, Month, Day);

        return IsArabCountry ? ThisDayIndex == 6 : ThisDayIndex == 0;
    }

    bool IsEndOfWeek(bool IsArabCountry = true)
    {
        return IsEndOfWeek(_Year, _Month, _Day, IsArabCountry);
    }

    static bool IsEndOfWeek(short ThisDayIndex, bool IsArabCountry)
    {
        return IsArabCountry ? ThisDayIndex == 6 : ThisDayIndex == 0;
    }

    static bool IsWeekEnd(short Year, short Month, short Day, bool IsArabCountry = true)
    {
        short ThisDayIndex = DayIndex(Year, Month, Day);

        return IsArabCountry ? ThisDayIndex > 4 : ThisDayIndex == 0 || ThisDayIndex == 6;
    }

    bool IsWeekEnd(bool IsArabCountry = true)
    {
        return IsWeekEnd(_Year, _Month, _Day, IsArabCountry);
    }

    static bool IsWeekEnd(short ThisDayIndex, bool IsArabCountry)
    {

        return IsArabCountry ? ThisDayIndex > 4 : ThisDayIndex == 0 || ThisDayIndex == 6;
    }

    static bool IsBusinessDay(short Year, short Month, short Day, bool IsArabCountry = true)
    {
        return !IsWeekEnd(Year, Month, Day, IsArabCountry);
    }

    bool IsBusinessDay(bool IsArabCountry = true)
    {
        return IsBusinessDay(_Year, _Month, _Day, IsArabCountry);
    }

    static bool IsBusinessDay(short ThisDayIndex, bool IsArabCountry)
    {
        return !IsWeekEnd(ThisDayIndex, IsArabCountry);
    }

    static short DaysUntilTheEndOfYear(short Year, short Month, short Day)
    {
        return NumberOfDaysInYear(Year) - DayOrderInYear(Year, Month, Day);
    }

    short DaysUntilTheEndOfYear()
    {
        return DaysUntilTheEndOfYear(_Year, _Month, _Day);
    }

    static short DaysUntilTheEndOfMonth(short Year, short Month, short Day)
    {
        return NumberOfDaysInMonth(Year, Month) - Day;
    }

    short DaysUntilTheEndOfMonth()
    {
        return DaysUntilTheEndOfMonth(_Year, _Month, _Day);
    }

    static int DaysUntilTheEndOfWeek(short Year, short Month, short Day, bool IsArabCountry = true)
    {
        short ThisDayIndex = DayIndex(Year, Month, Day);

        return IsArabCountry ? 7 - (ThisDayIndex + 1) : (++ThisDayIndex > 2) ? 9 - ThisDayIndex : 2 - ThisDayIndex;
    }

    int DaysUntilTheEndOfWeek(bool IsArabCountry = true)
    {
        return DaysUntilTheEndOfWeek(_Year, _Month, _Day, IsArabCountry);
    }

    void DateFromDayOrderInYear(int DayOrderInYear)
    {

        short NumberOfDayInMonth;

        for (short i = 1; i <= 12; i++)
        {
            NumberOfDayInMonth = NumberOfDaysInMonth(_Year, i);

            if (DayOrderInYear <= NumberOfDayInMonth)
            {
                _Month = i;
                _Day = DayOrderInYear;
                i = 13;
            }

            DayOrderInYear -= NumberOfDayInMonth;
        }

    }

    static int CalculateDiffrenceFromTowDates(short Year1, short Month1, short Day1, short Year2, short Month2
        , short Day2, bool IncludingLastDay2 = false)
    {
        bool IsDate1AfterDate1 = !IsDate1BeforeDate2(Year1, Month1, Day1, Year2, Month2, Day2);

        if (IsDate1AfterDate1)
        {
            short TempYear = Year2, TempMonth = Month2, TempDay = Day2;

            Year2 = Year1;
            Month2 = Month1;
            Day2 = Day1;

            Year1 = TempYear;
            Month1 = TempMonth;
            Day1 = TempDay;

        }


        int Sum = DayOrderInYear(Year2, Month2, Day2) - DayOrderInYear(Year1, Month1, Day1);

        while (Year1 < Year2)
        {
            Sum += NumberOfDaysInYear(Year1++);
        }


        return (IncludingLastDay2) ? ((IsDate1AfterDate1) ? (-1) * Sum - 1 : ++Sum) : ((IsDate1AfterDate1) ? (-1) * Sum : Sum);
    }

    int CalculateDiffrenceFromTowDates(clsDate Date, bool IncludingLastDay = false)
    {
        return CalculateDiffrenceFromTowDates(_Year, _Month, _Day, Date._Year, Date._Month, Date._Day, IncludingLastDay);
    }

    void GetTodayDate()
    {

        time_t t = time(0);

        tm* Time = localtime(&t);

        _Year = Time->tm_year + 1900;
        _Month = Time->tm_mon + 1;
        _Day = Time->tm_mday;

    }

    static string GetNowDateWithTime()
    {
        time_t t = time(0);

        tm* Time = localtime(&t);

        return  to_string(Time->tm_mday) + "/" + to_string(Time->tm_mon + 1) + "/" + to_string(Time->tm_year + 1900) + " - "
            + to_string(Time->tm_hour) + ":" + to_string(Time->tm_min) + ":" + to_string(Time->tm_sec);
    }

    static void PrintDate(short Year, short Month, short Day, string MessageBefore = "\n", string MessageAfter = "\n")
    {
        cout << MessageBefore << Day << "/" << Month << "/" << Year << MessageAfter;
    }

    void PrintDate(string MessageBefore = "\n", string MessageAfter = "\n")
    {
        PrintDate(_Year, _Month, _Day, MessageBefore, MessageAfter);
    }

    static void IncreaseDateByOneDay(short& Year, short& Month, short& Day)
    {
        if (IsLastDayInMonth(Year, Month, Day))
        {
            if (IsLastMonthInYear(Year, Month, Day))
            {
                Year++;
                Month = 1;
                Day = 1;
            }
            else
            {
                Month++;
                Day = 1;
            }
        }
        else
        {
            Day++;
        }
    }

    void IncreaseDateByOneDay()
    {
        IncreaseDateByOneDay(_Year, _Month, _Day);
    }

    static void IncreaseDateByXDay(short& Year, short& Month, short& Day, int Days)
    {
        Days += DayOrderInYear(Year, Month, Day);
        Day = 1;
        Month = 1;

        int DaysOfYear = NumberOfDaysInYear(Year), DaysOfMonth = 31;


        while (Days >= DaysOfYear)
        {
            Days -= DaysOfYear;
            DaysOfYear = NumberOfDaysInYear(++Year);

        }

        while (Days > DaysOfMonth)
        {
            Days -= DaysOfMonth;
            DaysOfMonth = NumberOfDaysInMonth(Year, ++Month);
        }

        Day = Days;
    }

    void IncreaseDateByXDay(int Days)
    {
        IncreaseDateByXDay(_Year, _Month, _Day, Days);
    }

    static void IncreaseDateByOneWeek(short& Year, short& Month, short& Day)
    {
        return IncreaseDateByXDay(Year, Month, Day, 7);
    }

    void IncreaseDateByOneWeek()
    {
        IncreaseDateByOneWeek(_Year, _Month, _Day);
    }

    static void IncreaseDateByXWeek(short& Year, short& Month, short& Day, int Weeks)
    {
        return IncreaseDateByXDay(Year, Month, Day, 7 * Weeks);
    }

    void IncreaseDateByXWeek(int Weeks)
    {
        IncreaseDateByXWeek(_Year, _Month, _Day, Weeks);
    }

    static void IncreaseDateByOneMonth(short& Year, short& Month, short& Day)
    {
        if (++Month == 13)
        {
            Month = 1;
            Year++;
        }

        short DaysInThisMonth = NumberOfDaysInMonth(Year, Month);

        Day = (Day > DaysInThisMonth) ? DaysInThisMonth : Day;
    }

    void IncreaseDateByOneMonth()
    {
        IncreaseDateByOneMonth(_Year, _Month, _Day);
    }

    static void IncreaseDateByXMonth(short& Year, short& Month, short& Day, short Months)
    {
        for (short i = 1; i <= Months; i++)
        {
            IncreaseDateByOneMonth(Year, Month, Day);
        }
    }

    void IncreaseDateByXMonth(short Months)
    {
        IncreaseDateByXMonth(_Year, _Month, _Day, Months);
    }

    static void IncreaseDateByOneYear(short& Year)
    {
        ++Year;
    }

    void IncreaseDateByOneYear()
    {
        IncreaseDateByOneYear(_Year);
    }

    static void IncreaseDateByXYear(short& Year, short Years)
    {
        Year += Years;
    }

    void IncreaseDateByXYear(short Years)
    {
        IncreaseDateByXYear(_Year, Years);
    }

    static void IncreaseDateByOneDecade(short& Year)
    {
        return IncreaseDateByXYear(Year, 10);
    }

    void IncreaseDateByOneDecade()
    {
        IncreaseDateByOneDecade(_Year);
    }

    static void IncreaseDateByXDecade(short& Year, short Decades)
    {
        Year += Decades * 10;
    }

    void IncreaseDateByXDecade(short Decades)
    {
        IncreaseDateByXDecade(_Year, Decades);
    }

    static void IncreaseDateByOneCentury(short& Year)
    {
        Year += 100;
    }

    void IncreaseDateByOneCentury()
    {
        IncreaseDateByOneCentury(_Year);
    }

    static void IncreaseDateByOneMillennium(short& Year)
    {
        Year += 1000;
    }

    void IncreaseDateByOneMillennium()
    {
        IncreaseDateByOneMillennium(_Year);
    }

    static void DecreaseDateByOneDay(short& Year, short& Month, short& Day)
    {
        if (IsFirstDayInMonth(Year, Month, Day))
        {
            if (IsFirstMonthInYear(Year, Month, Day))
            {
                Year--;
                Month = 12;
                Day = 31;
            }
            else
            {
                Day = NumberOfDaysInMonth(Year, --Month);
            }
        }
        else
        {
            Day--;
        }
    }

    void DecreaseDateByOneDay()
    {
        DecreaseDateByOneDay(_Year, _Month, _Day);
    }

    static void DecreaseDateByXDay(short& Year, short& Month, short& Day, int Days)
    {
        Days += DaysUntilTheEndOfYear(Year, Month, Day);
        Day = 31;
        Month = 12;

        int DaysOfYear = NumberOfDaysInYear(Year), DaysOfMonth = 31;


        while (Days >= DaysOfYear)
        {
            Days -= DaysOfYear;
            DaysOfYear = NumberOfDaysInYear(--Year);

        }

        while (Days >= DaysOfMonth)
        {
            Days -= DaysOfMonth;

            DaysOfMonth = NumberOfDaysInMonth(Year, --Month);
        }

        Day = DaysOfMonth - Days;
    }

    void DecreaseDateByXDay(int Days)
    {
        DecreaseDateByXDay(_Year, _Month, _Day, Days);
    }

    static void DecreaseDateByOneWeek(short& Year, short& Month, short& Day)
    {
        return DecreaseDateByXDay(Year, Month, Day, 7);
    }

    void DecreaseDateByOneWeek()
    {
        DecreaseDateByOneWeek(_Year, _Month, _Day);
    }

    static void DecreaseDateByXWeek(short& Year, short& Month, short& Day, int Weeks)
    {
        return DecreaseDateByXDay(Year, Month, Day, 7 * Weeks);
    }

    void DecreaseDateByXWeek(int Weeks)
    {
        DecreaseDateByXWeek(_Year, _Month, _Day, Weeks);
    }

    static void DecreaseDateByOneMonth(short& Year, short& Month, short& Day)
    {
        if (--Month == 0)
        {
            Month = 12;
            Year--;
        }


        short DaysInThisMonth = NumberOfDaysInMonth(Year, Month);

        Day = (Day > DaysInThisMonth) ? DaysInThisMonth : Day;
    }

    void DecreaseDateByOneMonth()
    {
        DecreaseDateByOneMonth(_Year, _Month, _Day);
    }

    static void DecreaseDateByXMonth(short& Year, short& Month, short& Day, short Months)
    {
        for (short i = 1; i <= Months; i++)
        {
            DecreaseDateByOneMonth(Year, Month, Day);
        }
    }

    void DecreaseDateByXMonth(short Months)
    {
        DecreaseDateByXMonth(_Year, _Month, _Day, Months);
    }

    static void DecreaseDateByOneYear(short& Year)
    {
        Year--;
    }

    void DecreaseDateByOneYear()
    {
        DecreaseDateByOneYear(_Year);
    }

    static void DecreaseDateByXYear(short& Year, short Years)
    {
        Year -= Years;
    }

    void DecreaseDateByXYear(short Years)
    {
        DecreaseDateByXYear(_Year, Years);
    }

    static void DecreaseDateByOneDecade(short& Year)
    {
        DecreaseDateByXYear(Year, 10);
    }

    void DecreaseDateByOneDecade()
    {
        DecreaseDateByOneDecade(_Year);
    }

    static void DecreaseDateByXDecade(short& Year, short Decades)
    {
        Year -= Decades * 10;
    }

    void DecreaseDateByXDecade(short Decades)
    {
        DecreaseDateByXDecade(_Year, Decades);
    }

    static void DecreaseDateByOneCentury(short& Year)
    {
        Year -= 100;
    }

    void DecreaseDateByOneCentury()
    {
        DecreaseDateByOneCentury(_Year);
    }

    static void DecreaseDateByOneMillennium(short& Year)
    {
        Year -= 1000;
    }

    void DecreaseDateByOneMillennium()
    {
        DecreaseDateByOneMillennium(_Year);
    }







    static int GetActualVacationDays(short YearFrom, short MonthFrom, short DayFrom,
        short YearTo, short MonthTo, short DayTo, bool IsArabCountry = true)
    {
        int NumberOfDays = CalculateDiffrenceFromTowDates(YearFrom, MonthFrom, DayFrom, YearTo, MonthTo, DayTo);

        int ActualVacation = (NumberOfDays / 7) * 5;

        short ThisDayIndex = DayIndex(YearFrom, MonthFrom, DayFrom);

        for (short i = NumberOfDays % 7; i >= 1; i--)
        {
            if (IsBusinessDay(ThisDayIndex, IsArabCountry))
            {
                ActualVacation++;
            }

            ThisDayIndex = (ThisDayIndex == 6) ? 0 : ThisDayIndex + 1;
        }

        return ActualVacation;
    }

    int GetActualVacationDays(clsDate DateTo, bool IsArabCountry = true)
    {
        return GetActualVacationDays(_Year, _Month, _Day, DateTo._Year, DateTo._Month, DateTo._Day, IsArabCountry);
    }

    static void GetDateByActualVacation(short& Year, short& Month, short& Day, int ActualVacation, bool IsArabCountry = true)
    {
        short NumberOfWeeks = ActualVacation / 5, ThisDayIndex = DayIndex(Year, Month, Day);

        ActualVacation %= 5;

        IncreaseDateByXWeek(Year, Month, Day, NumberOfWeeks);

        while (ActualVacation > 0 || IsWeekEnd(ThisDayIndex, IsArabCountry))
        {
            ActualVacation -= (IsBusinessDay(ThisDayIndex, IsArabCountry)) ? 1 : 0;

            IncreaseDateByXDay(Year, Month, Day, 1);

            ThisDayIndex += (ThisDayIndex == 6) ? -6 : 1;
        }
    }

    void GetDateByActualVacation(int ActualVacation, bool IsArabCountry = true)
    {
        GetDateByActualVacation(_Year, _Month, _Day, ActualVacation, IsArabCountry);
    }

    static void GetDateByActualVacation(short YearFrom, short MonthFrom, short DayFrom,
        short& YearTo, short& MonthTo, short& DayTo, int ActualVacation, bool IsArabCountry = true)
    {

        YearTo = YearFrom;
        MonthTo = MonthFrom;
        DayTo = DayFrom;

        GetDateByActualVacation(YearTo, MonthTo, DayTo, ActualVacation, IsArabCountry);

    }

    void GetDateByActualVacation(clsDate& DateTo, int ActualVacation, bool IsArabCountry = true)
    {
        GetDateByActualVacation(_Year, _Month, _Day, DateTo._Year, DateTo._Month, DateTo._Day, ActualVacation, IsArabCountry);
    }




    static void StringToDate(short& Year, short& Month, short& Day, string DateString, string Format = "dd/mm/yyyy",
        string Separator = "/")
    {

        vector <string> vDateString = clsString::Split(DateString, Separator);

        Year = 0;
        Month = 0;
        Day = 0;

        if (vDateString.size() == 3)
        {
            vector <string> vFormat = clsString::Split(Format, Separator);

            for (short i = 0; i < 3; i++)
            {
                if (clsString::IsANumber(vDateString[i]))
                {
                    if (clsString::ToLowerAllPhrase(vFormat[i]) == "dd")
                    {
                        Day = stoi(vDateString[i]);
                    }
                    else if (clsString::ToLowerAllPhrase(vFormat[i]) == "mm")
                    {
                        Month = stoi(vDateString[i]);
                    }
                    else if (clsString::ToLowerAllPhrase(vFormat[i]) == "yyyy")
                    {
                        Year = stoi(vDateString[i]);
                    }
                }
            }
        }
    }

    void StringToDate(string DateString, string Format = "dd/mm/yyyy", string Separator = "/")
    {
        StringToDate(_Year, _Month, _Day, DateString, Format, Separator);
    }

    static bool IsValidatStringDate(string DateString, string Format = "dd/mm/yyyy", string Separator = "/")
    {
        short Year = 0, Month = 0, Day = 0;

        StringToDate(Year, Month, Day, DateString, Format, Separator);

        return IsValideDate(Year, Month, Day);
    }

    static void ReadDateString(short& Year, short& Month, short& Day, string MessageToUser,
        string Format = "dd/mm/yyyy", string Separator = "/")
    {
        string DateString = clsInputSettings::ReadString(MessageToUser);

        while (!IsValidatStringDate(DateString, Format, Separator))
        {
            cout << "\a\n\nThis Date with this Format : " << DateString << " is WRONG ! Please enter The Date Like this : " <<
                Format << endl << endl;
            DateString = clsInputSettings::ReadString(MessageToUser);

        }

        StringToDate(Year, Month, Day, DateString, Format, Separator);

    }

    void ReadDateString(string MessageToUser, string Format = "dd/mm/yyyy", string Separator = "/")
    {
        ReadDateString(_Year, _Month, _Day, MessageToUser, Format, Separator);
    }

    static string DateToString(short Year, short Month, short Day, string  Format = "dd/mm/yyyy")
    {
        string Temp[3] = { "dd","mm","yyyy" };
        short arrDate[3] = { Day, Month, Year };

        for (short i = 0; i < 3; i++)
        {
            Format = clsString::ReplaceAllWords_UsingOwnFind(Format, Temp[i], to_string(arrDate[i]), false);
        }

        return Format;
    }

    string DateToString(string  Format = "dd/mm/yyyy")
    {
        return DateToString(_Year, _Month, _Day, Format);
    }





    static void PrintMonthCalandar(short Year, short Month)
    {
        short FirstDayIndex = DayIndex(Year, Month, 1) + 1, LastDay = NumberOfDaysInMonth(Year, Month);
        clsString Word("");

        cout << endl << endl;

        cout << "----------------------" << GetMonthName(Month) << "----------------------" << endl;

        for (short i = 1; i <= 7; i++)
        {
            Word.Value = (GetDayName(i - 1));

            Word.FillWordSideWithSameCaracter(Word.Value, ' ', 7);
            cout << Word.Value;
        }
        cout << endl;

        short Counter = 0;

        for (short i = 1; i <= 6; i++)
        {
            for (short j = 1; j <= 7; j++)
            {
                if (i == 1 && FirstDayIndex > j)
                {
                    Word.Value = " ";

                    Word.FillWordSideWithSameCaracter(Word.Value, ' ', 7);
                    cout << Word.Value;
                }
                else
                {
                    ++Counter;

                    Word.Value = to_string(Counter);

                    Word.FillWordSideWithSameCaracter(Word.Value, ' ', 7);
                    cout << Word.Value;

                    if (Counter == LastDay)
                    {
                        j = 8;
                        i = 7;
                    }

                }
            }
            cout << endl;
        }

        cout << "-----------------------------------------------" << endl;

    }

    void PrintMonthCalandar()
    {
        PrintMonthCalandar(_Year, _Month);
    }

    static void PrintYearCalendar(short Year)
    {
        cout << "-----------------------------------" << endl;
        cout << "\tCalendar  *  " << Year << endl;
        cout << "-----------------------------------" << endl;


        for (short i = 1; i <= 12; i++)
        {
            PrintMonthCalandar(Year, i);
            cout << endl;
        }
    }

    void PrintYearCalendar()
    {
        PrintYearCalendar(_Year);
    }

};