#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include<iomanip>


using namespace std;

int user_input(string input);
bool is_leapYear(int year);
short Number_of_days_in_month(short year, short month);
short Number_of_hours_in_month(short year, short month);
int Number_of_mints_in_month(short year, short month);
int Number_of_second_in_month(short year, short month);











int main()
{
	int year = user_input("Enter year : ");
	int month = user_input("Enter month : ");


	(is_leapYear(year) ? cout << "Yes [" << year << "] is a Leap year\n" : cout << "No [" << year << "] Not a leap year\n");
	cout << "In year [" << year << "] : \n";
	cout << "Number of Days   in month [" << month << "] " << Number_of_days_in_month(year, month) << " Days\n";
	cout << "Number of Hours  in month [" << month << "] " << Number_of_hours_in_month(year, month) << " Hours\n";
	cout << "Number of Mints  in month [" << month << "] " << Number_of_mints_in_month(year, month) << " Mints\n";
	cout << "Number of Second in month [" << month << "] " << Number_of_second_in_month(year, month) << " Second\n";

	cout << endl;
}

int user_input(string input)
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

short days_in_month(short year, short month)
{
	short arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return((is_leap_year(year) && month == 2) ? 29 : arr[month]);
}

short Number_of_hours_in_month(short year, short month)
{
	return Number_of_days_in_month(year, month) * 24;
}

int Number_of_mints_in_month(short year, short month)
{
	return Number_of_hours_in_month(year, month) * 60;
}

int Number_of_second_in_month(short year, short month)
{
	return Number_of_mints_in_month(year, month) * 60;
}
