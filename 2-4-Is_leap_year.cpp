#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include<iomanip>


using namespace std;

int user_input(string input);
bool is_leapYear(int year);






int main()
{
	int year = user_input("Enter year : ");

	(is_leapYear(year) ? cout << "Yes [" << year << "] is a Leap year" : cout << "No [" << year << "] Not a leap year");



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
	if (year % 400 == 0)return true;

	if (year % 4 == 0 && year % 100 != 0)return true;

	return false;
}
