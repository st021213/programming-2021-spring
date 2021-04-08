#include<iostream>

using namespace std;
//Объектно-Ориентированное Программирование
//Инкапсуляция

struct Date {

	int day;
	int month;
	int year;

	void setDay(int day)
	{
		this->day = day;
	}

	int getDay()
	{
		return this->day;
	}
};

int main()
{
	Date date;
	date.year = 23;
	date.month = 3;

	date.day = 5; //так делать плохо
	cout << date.day << endl;

	date.setDay(42); //так делать хорошо
	cout << date.getDay() << endl;

	return 0;
}