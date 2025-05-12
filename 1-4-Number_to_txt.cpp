#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include<iomanip>


using namespace std;

int user_input(string input);

string Number_to_txt(int Number);




int main()
{
	int Number = user_input("Enter Number : ");


	if (Number < 0)
	{
		cout << Number << " : " << "Negetive " << Number_to_txt(-Number);
	}
	else
		cout << Number << " : " << Number_to_txt(Number)
		<< endl;


	return 0;

}

int user_input(string input)
{
	cout << input;
	int Number;
	cin >> Number;
	return Number;
}

static string Number_to_txt_from_1_to_19(int Number)
{
	string arr[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten"
	,"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
	return arr[Number];
}

static string Number_to_txt_from_20_to_99(int Number)
{
	string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
	if (Number < 20)return Number_to_txt_from_1_to_19(Number);

	int num = Number / 10;
	int reminder = Number % 10;
	return arr[num] + " " + Number_to_txt_from_1_to_19(reminder);
}
string Number_to_txt_from_100_to_999(int Number)
{
	if (Number < 100)return Number_to_txt_from_20_to_99(Number);

	int num = Number / 100;
	int reminder = Number % 100;
	return Number_to_txt_from_1_to_19(num) + " Hundred(s) " + Number_to_txt_from_20_to_99(reminder);
}

static string Number_to_txt_from_1000_to_999999(int Number)
{
	if (Number < 1000)return Number_to_txt_from_100_to_999(Number);

	int num = Number / 1000;
	int reminder = Number % 1000;
	return Number_to_txt_from_100_to_999(num) + " Thousand(s) " + Number_to_txt_from_100_to_999(reminder);
}

static string Number_to_txt_from_1000000_to_999999999(int Number)
{
	if (Number < 1000000)return Number_to_txt_from_1000_to_999999(Number);

	int num = Number / 1000000;
	int reminder = Number % 1000000;
	return Number_to_txt_from_1000_to_999999(num) + " Million(s) " + Number_to_txt_from_1000_to_999999(reminder);
}

static string Number_to_txt_from_1000000000_to_999999999999(int Number)
{
	if (Number < 1000000000)return Number_to_txt_from_1000000_to_999999999(Number);

	int num = Number / 1000000000;
	int reminder = Number % 1000000000;
	return Number_to_txt_from_1000000_to_999999999(num) + " Billion(s) " + Number_to_txt_from_1000000_to_999999999(reminder);
}

string Number_to_txt(int Number)
{
	if (Number == 0)
		return "Zero";

	if (Number > 0 && Number < 20)
		return Number_to_txt_from_1_to_19(Number);

	if (Number > 19 && Number < 100)
		return Number_to_txt_from_20_to_99(Number);

	if (Number > 99 && Number < 1000)
		return Number_to_txt_from_100_to_999(Number);

	if (Number > 999 && Number < 1000000)
		return Number_to_txt_from_1000_to_999999(Number);

	if (Number > 999999 && Number < 1000000000)
		return Number_to_txt_from_1000000_to_999999999(Number);

	if (Number > 999999999 && Number < 1000000000000)
		return Number_to_txt_from_1000000000_to_999999999999(Number);

	return "";
}


