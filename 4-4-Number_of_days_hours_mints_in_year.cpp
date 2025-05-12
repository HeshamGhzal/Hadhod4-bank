#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include<iomanip>


using namespace std;

int user_input(string input);
bool is_leapYear(int year);
short Number_of_days_in_year(short year);
short Number_of_hours_in_year(short year);
int Number_of_mints_in_year(short year);
int Number_of_second_in_year(short year);











int main()
{
	int year = user_input("Enter year : ");

	(is_leapYear(year) ? cout << "Yes [" << year << "] is a Leap year\n" : cout << "No [" << year << "] Not a leap year\n");

	cout << "Number of Days   in year [" << year << "] " << Number_of_days_in_year(year) << " Days\n";
	cout << "Number of Hours  in year [" << year << "] " << Number_of_hours_in_year(year) << " Hours\n";
	cout << "Number of Mints  in year [" << year << "] " << Number_of_mints_in_year(year) << " Mints\n";
	cout << "Number of Second in year [" << year << "] " << Number_of_second_in_year(year) << " Second\n";





	cout << endl;

}

int user_input(string input)
{
	cout << input;
	int Number;
	cin >> Number;
	return Number;
}

bool is_leapYear(int year)
{

	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short Number_of_days_in_year(short year)
{
	return(is_leapYear(year) ? 366 : 365);
}

short Number_of_hours_in_year(short year)
{
	return Number_of_days_in_year(year) * 24;
}

int Number_of_mints_in_year(short year)
{
	return Number_of_hours_in_year(year) * 60;
}

int Number_of_second_in_year(short year)
{
	return Number_of_mints_in_year(year) * 60;
}
