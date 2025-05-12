#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include<iomanip>


using namespace std;

int user_input(string input);
void Print_week_days();
void read_days(short  year, short month);





int main()
{
	int year = user_input("Enter year : ");
	int month = user_input("Enter month : ");
	while (month < 1 || month >12)
	{
		cout << "Wrong Number : ";
		month = user_input("Enter month : ");
	}

	read_days(year, month);

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

short Number_of_days_in_month(short year, short month)
{
	if (month < 1 || month>12) return 0;

	//return((is_leapYear(year) && month == 2) ? 29 : (!is_leapYear(year) && month == 2) ? 28 : (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) ? 31 : 30);

	short month_arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//hadhod
	return(month == 2 ? (is_leapYear(year) ? 29 : 28) : month_arr[month]);//hadhod
}

short day_of_week_order(short year, short month, short day)
{
	short a = (14 - month) / 12;
	short y = year - a;
	short m = month + (12 * a) - 2;
	return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string month_of_year(short month)
{
	string dayarr[] = { "", "January","February","March","April","May","June","July","AugUst","September","October","November","December" };
	return dayarr[month];
}

string day_of_week(short day)
{
	string dayarr[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
	return dayarr[day];
}

void Print_week_days()
{
	for (short i = 0; i < 7; i++)
	{
		cout << setw(10) << left << day_of_week(i) << "|";
	}
	cout << "\n";
}

//vector<string>Fill_day_of_month(short year, short month)
//{
//	short counter = 1;
//	vector<string> dayarr(37);
//	short daysOfMonth = Number_of_days_in_month(year, month);
//	short startDayOfWeek = day_of_week_order(year, month, 1);
//	for (short i = 0; i < daysOfMonth; i++)
//	{
//		dayarr[i + startDayOfWeek] = to_string(counter++);
//	}
//	return dayarr;
//}
//
//void read_days(short  year, short month)
//{
//	cout << "\n                                " << month_of_year(month) << '/' << year << "                               \n\n";
//	Print_week_days();
//	vector<string> arr = Fill_day_of_month(year, month);
//	short Month_days = Number_of_days_in_month(year, month);
//	short Day_order_in_week = day_of_week_order(year, month, 1);
//	short counter = 0;
//	for (int i = 0; i < 6; i++)
//	{
//		for (int j = 0; j < 7; j++)
//		{
//			if (counter < Month_days + Day_order_in_week)
//				cout << setw(10) << arr[counter++] << '|';
//		}
//		cout << "\n";
//	}
//}

void read_days(short  year, short month)
{
	short Month_days = Number_of_days_in_month(year, month);
	short Day_order_in_week = day_of_week_order(year, month, 1);


	cout << "\n                                " << month_of_year(month) << '/' << year << "                               \n\n";

	Print_week_days();
	short counter = 0;

	for (int j = 0; j < Day_order_in_week; j++)
	{
		cout << setw(10) << " " << '|';
		counter++;
	}

	for (int i = 0; i < Month_days; i++)
	{
		cout << setw(10) << i + 1 << '|';
		counter++;
		if (counter == 7)
		{
			cout << "\n";
			counter = 0;
		}
	}
	cout << endl;
}
