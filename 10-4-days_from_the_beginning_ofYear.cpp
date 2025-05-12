#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include<iomanip>


using namespace std;

short user_input(string input);
short days_from_the_beginning_ofYear(short day, short month, short year);





int main()
{
	short year = user_input("Enter year : ");
	short month = user_input("Enter month : ");
	short day = user_input("Enter day : ");
	cout << "Days Until[" << day << '/' << month <<
		"] from the th beginning of year [" << year << "] = " <<
		days_from_the_beginning_ofYear(day, month, year) << " day";
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