#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include<iomanip>


using namespace std;

struct sDate
{
	short year = 0;
	short month = 1;
	short day = 0;
};

short user_input(string input);
short Number_of_days_in_month(short year, short month);
sDate Adding_Days_to_date(sDate date, short add);









int main()
{
	sDate Date;

	Date.year = user_input("Enter year : ");

	Date.month = user_input("Enter month : ");
	while (Date.month < 1 || Date.month> 12)
	{
		cout << "Wrong Month NUmber Reenter Month : ";
		cin >> Date.month;
	}

	Date.day = user_input("Enter day : ");
	while (Date.day<1 || Date.day> Number_of_days_in_month(Date.year, Date.month))
	{
		cout << "Wrong Day NUmber Reenter Day : ";
		cin >> Date.day;
	}

	short add = user_input("enter days to add : ");


	Date = Adding_Days_to_date(Date, add);
	cout << Date.day << '/' << Date.month << '/' << Date.year;

	cout << endl;
}

short user_input(string input)
{
	cout << input;
	int Number;
	cin >> Number;
	return Number;
}//-----[31]1,3,5,7,8,10,12

bool is_leapYear(int year)
{

	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short Number_of_days_in_month(short year, short month)
{
	if (month < 1 || month>12) return 0;

	//return((is_leapYear(year) && month == 2) ? 29 : (!is_leapYear(year) && month == 2) ? 28 : (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) ? 31 : 30);

	short month_arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//hadhod
	return(month == 2 ? (is_leapYear(year) ? 29 : 28) : month_arr[month]);//hadhod
}

short days_from_the_beginning_ofYear(short day, short month, short year)
{
	short sumDays = 0;
	for (short i = 1; i < month; i++)
	{
		sumDays += Number_of_days_in_month(year, i);
	}
	return sumDays + day;
}

//string Date_from_Number_of_days(short days, short year)
//{
//	short sumDays = days;
//	string Date;
//	for (short i = 1; i <= 12; i++)
//	{
//		Date = to_string(sumDays) + '/' + to_string(i) + '/' + to_string(year);
//
//		if (sumDays <= Number_of_days_in_month(year, i))
//		{
//			return Date;
//		}
//		sumDays -= Number_of_days_in_month(year, i);
//	}
//}

sDate Date_from_Number_of_days_struct_type(short days, short year)
{
	sDate date;
	date.year = year;
	short reminder = days;
	short monthDays = 0;
	date.month = 1;
	while (true)
	{
		monthDays = Number_of_days_in_month(year, date.month);
		date.day = reminder;
		if (reminder <= monthDays)break;
		reminder -= monthDays;
		date.month++;
	}
	return date;
}


sDate Adding_Days_to_date(sDate date, short add)
{

	short reminderDays = date.day + add;
	short monthDays = 0;

	while (true)
	{
		monthDays = Number_of_days_in_month(date.year, date.month);
		date.day = reminderDays;
		if (reminderDays <= monthDays)break;
		reminderDays -= monthDays;
		date.month++;
		if (date.month > 12)                //10/10/2022
		{                                              //Test Example add 2500 days
			date.year++;                   //14/8/2029
			date.month = 1;
		}
	}

	return date;
}