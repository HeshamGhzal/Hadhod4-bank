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
string Date_from_Number_of_days(short days, short year);
sDate Date_from_Number_of_days_struct_type(short days, short year);








int main()
{
	short year = user_input("Enter year : ");
	short month = user_input("Enter month : ");
	while (month < 1 || month> 12)
	{
		cout << "Wrong Month NUmber Reenter Month : ";
		cin >> month;
	}
	short day = user_input("Enter day : ");
	while (day<1 || day> Number_of_days_in_month(year, month))
	{
		cout << "Wrong Day NUmber Reenter Day : ";
		cin >> day;
	}

	cout << "Days Until[" << day << '/' << month <<
		"] from the th beginning of year [" << year << "] = " <<
		days_from_the_beginning_ofYear(day, month, year) << " day";


	short days = days_from_the_beginning_ofYear(day, month, year);
	cout << endl;

	cout << "Date is : " << Date_from_Number_of_days(days, year) << "   string";
	cout << endl;

	sDate Date = Date_from_Number_of_days_struct_type(days, year);
	cout << "Date is : " << Date.day << '/' << Date.month << '/' << Date.year << "   struct";


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

string Date_from_Number_of_days(short days, short year)
{
	short sumDays = days;
	string Date;
	for (short i = 1; i <= 12; i++)
	{
		Date = to_string(sumDays) + '/' + to_string(i) + '/' + to_string(year);

		if (sumDays <= Number_of_days_in_month(year, i))
		{
			return Date;
		}
		sumDays -= Number_of_days_in_month(year, i);
	}
}

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
sdate return_number_of_days_to_date(short year, short dayes_numbr)
{
	sdate date;
	date.day = dayes_numbr;
	date.month = 1;
	date.year = year;
	while (date.day > days_in_month(year, date.month))
	{
		date.day -= days_in_month(year, date.month);
		date.month++;
	}
	return date;
}