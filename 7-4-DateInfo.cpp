#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include<iomanip>


using namespace std;

int user_input(string input);
void printDateInfo();












int main()
{
	printDateInfo();


	cout << endl;
}

int user_input(string input)
{
	cout << input;
	int Number;
	cin >> Number;
	return Number;
}//-----[31]1,3,5,7,8,10,12

short day_of_week_order(short year, short month, short day)
{
	short a = (14 - month) / 12;
	short y = year - a;
	short m = month + (12 * a) - 2;
	short result = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return result;
}

string day_of_week(short day)
{
	string dayarr[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Frayday" };
	return dayarr[day];
}

void printDateInfo()
{
	int year = user_input("Enter year  : ");
	int month = user_input("Enter month  : ");
	int day = user_input("Enter day  : ");
	cout << "\nDate      : " << day << '/' << month << '/' << year << "\n";
	cout << "Day order : " << day_of_week_order(year, month, day) << "\n";
	cout << "Day Name  : " << day_of_week(day_of_week_order(year, month, day));
}