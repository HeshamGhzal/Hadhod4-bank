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
short days_from_the_beginning_ofYear(short day, short month, short year);
bool Is_last_day_in_month(sDate date);
bool Is_last_month_of_year(sDate date);










int main()
{
	sDate Date1;

	Date1.year = user_input("Enter year  : ");

	Date1.month = user_input("Enter month  : ");
	while (Date1.month < 1 || Date1.month> 12)
	{
		cout << "Wrong Month NUmber Reenter Month : ";
		cin >> Date1.month;
	}

	Date1.day = user_input("Enter day : ");
	while (Date1.day<1 || Date1.day> Number_of_days_in_month(Date1.year, Date1.month))
	{
		cout << "Wrong Day NUmber Reenter Day : ";
		cin >> Date1.day;
	}
	cout << Is_last_day_in_month(Date1);
	cout << "\n=================================\n";
	cout << Is_last_month_of_year(Date1);


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

bool Is_last_day_in_month(sDate date)
{
	return(date.day == Number_of_days_in_month(date.year, date.month) ? true : false);
}

bool Is_last_month_of_year(sDate date)
{
	return(date.month == 12 ? true : false);
}