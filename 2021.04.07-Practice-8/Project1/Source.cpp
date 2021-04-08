#include<iostream>

using namespace std;

//class - все по умолчанию private
//struct - все по умолчанию public
class Date {
private:
	int day; //инкапсулированное поле
	int month;
	int year;

public:
	void setDay(int day)
	{
		this->day = day;
	} //сеттер

	int getDay()
	{
		return this->day;
	} //геттер

	void setMonth(int month)
	{
		this->month = month;
	}

	int getMonth()
	{
		return month;
	}

	void setYear(int year)
	{
		this->year = year;
	}

	//так делать плохо
	int& getYear()
	{
		return year;
	}
};

int main()
{
	Date date;

	date.setDay(42);
	cout << date.getDay() << endl;

	return 0;
}