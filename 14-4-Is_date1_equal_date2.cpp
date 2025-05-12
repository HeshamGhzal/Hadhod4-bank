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
bool Is_date1_equal_date2(sDate& date1, sDate& date2);










int main()
{
	sDate Date1, Date2;

	Date1.year = user_input("Enter year of date1 : ");

	Date1.month = user_input("Enter month of date1 : ");
	while (Date1.month < 1 || Date1.month> 12)
	{
		cout << "Wrong Month NUmber Reenter Month : ";
		cin >> Date1.month;
	}

	Date1.day = user_input("Enter day of date1 : ");
	while (Date1.day<1 || Date1.day> Number_of_days_in_month(Date1.year, Date1.month))
	{
		cout << "Wrong Day NUmber Reenter Day : ";
		cin >> Date1.day;
	}

	cout << "----------------------------------------\n";

	Date2.year = user_input("Enter year of date2 : ");

	Date2.month = user_input("Enter month of date2: ");
	while (Date2.month < 1 || Date2.month> 12)
	{
		cout << "Wrong Month NUmber Reenter Month : ";
		cin >> Date2.month;
	}

	Date2.day = user_input("Enter day of date2 : ");
	while (Date2.day<1 || Date2.day> Number_of_days_in_month(Date2.year, Date2.month))
	{
		cout << "Wrong Day NUmber Reenter Day : ";
		cin >> Date2.day;
	}

	cout << "\n" << Is_date1_equal_date2(Date1, Date2);


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

bool Is_date1_equal_date2(sDate& date1, sDate& date2)
{
	return(date1.year == date2.year ? (date1.month == date2.month ? (date1.day == date2.day) : false) : false);
}