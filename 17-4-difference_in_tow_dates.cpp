#include<iostream>
#include<string>
#include<iomanip>


using namespace std;

struct sdate
{
	int day = 0;
	short month = 0;
	short year = 0;
};

sdate adding_days_to_date(sdate date, short days_numbr_to_add);
int difference_in_tow_dates(sdate date1, sdate date2, bool include_end_day = false);







int main()
{
	//short year = User_input("Enter year : ");
	//20/9/2022=263
	// 
	//  //Test Example add 2500 days
	//10/10/2022
	 //14/8/2029
	sdate date1, date2;
	date1.day = 1;
	date1.month = 1;
	date1.year = 2022;

	date2.day = 25;
	date2.month = 3;
	date2.year = 2022;

	cout << difference_in_tow_dates(date1, date2,10);

	cout << endl;


	return 0;
}
short User_input(string year)
{
	short n;
	cout << year;
	cin >> n;
	return n;
}
bool is_leap_year(int y)
{
	return (y % 400 == 0 ? true : (y % 4 == 0 && y % 100 != 0) ? true : false);
}
short days_in_month(short year, short month)
{
	short arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return((is_leap_year(year) && month == 2) ? 29 : arr[month]);
}
short days_in_year(short year)
{
	return(is_leap_year(year) ? 366 : 365);
}

short day_order_in_week(short year, short month, short day)
{
	short a = (14 - month) / 12;
	short y = year - a;
	short m = month + (12 * a) - 2;
	short d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}
string day_name_in_week(short year, short month, short day)
{
	string arr[] = { "sun","mon","tus","Wed","thu","fri","sat" };
	return arr[day_order_in_week(year, month, day)];
}
string month_name_in_year(short m)
{
	string month[] = { "","Jan","Feb","Mar","Apr","Jun","Jul","Aug",
		"Sep","Oct","Nov","Dec" };
	return month[m];
}


short number_of_days_from_beginning_of_year(short day, short month, short year)
{
	short daysum = day;
	for (short i = 0; i < month; i++)
	{
		daysum += days_in_month(year, i);
	}
	return daysum;
}
sdate return_number_of_days_to_date(short year, short days_numbr)
{
	sdate date;
	date.day = days_numbr;
	date.month = 1;
	date.year = year;
	while (date.day > days_in_month(year, date.month))
	{
		date.day -= days_in_month(year, date.month);
		date.month++;
	}
	return date;
}

sdate adding_days_to_date(sdate date, short days_numbr_to_add)
{
	date.day = date.day + days_numbr_to_add;
	short month_days = 0;

	while (true)
	{
		month_days = days_in_month(date.year, date.month);

		if (date.day <= month_days)break;

		date.day -= month_days;
		date.month++;
		if (date.month > 12)
		{
			date.year++;
			date.month = 1;
		}
	}
	return date;
}

bool is_date1_less_than_date2(sdate date1, sdate date2)
{
	/*if (date1.year < date2.year)return true;
	else if (date1.year == date2.year && date1.month < date2.month)return true;
	else if (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day)return true;
	else return false;*/
	return(date1.year < date2.year ? true :
		(date1.year == date2.year && date1.month < date2.month ? true :
			(date1.year == date2.year && date1.month == date2.month && date1.day < date2.day ? true :
				false)));
}
bool is_date1_equal_date2(sdate date1, sdate date2)
{
	return(date1.year == date2.year &&
		date1.month == date2.month &&
		date1.day == date2.day);
}
bool is_last_day_in_month(sdate date)
{
	return date.day == days_in_month(date.year, date.month);
}
bool is_last_month_in_year(sdate date)
{
	return date.year == 12;
}

sdate add_one_day_to_date(sdate date)
{
	date.day = date.day + 1;
	if (date.day > days_in_month(date.year, date.month))
	{
		date.month++;
		date.day = 1;
	}
	if (date.month > 12)
	{
		date.year++;
		date.month = 1;
	}
	return date;
}
//int difference_in_tow_dates(sdate date1, sdate date2, bool include_end_day)
//{
//	//(1/1/2022)-(25/3/2022)=83
//	if (is_date1_less_than_date2(date1, date2))
//	{
//		int def = 0;
//		short year_def = date2.year - date1.year;
//
//		short start_year_dayes = days_in_year(date1.year) -
//			number_of_days_from_beginning_of_year(date1.day, date1.month, date1.year);
//		short end_year_dayes = number_of_days_from_beginning_of_year(date2.day, date2.month, date2.year);
//
//		if (year_def == 0)
//			def = end_year_dayes;
//		if (year_def == 1)
//			def = start_year_dayes + end_year_dayes;
//		if (year_def > 1)
//		{
//			for (int i = date1.year; i < date2.year - 1; i++)
//			{
//				def += days_in_year(i);
//			}
//			def += start_year_dayes + end_year_dayes;
//		}
//
//		return (include_end_day ? def : --def);
//	}
//	else if (is_date1_equal_date2(date1, date2))
//	{
//		return 0;
//	}
//	else return -1;
//}
int difference_in_tow_dates(sdate date1, sdate date2, bool include_end_day)
{
	//(1/1/2022)-(25/3/2022)=83
	int diff = 0;

	while (is_date1_less_than_date2(date1, date2))
	{
		date1=add_one_day_to_date( date1);
		diff++;
	}
	return include_end_day?++diff: diff;
}
