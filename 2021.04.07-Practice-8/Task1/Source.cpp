#include<iostream>

using namespace std;
//��������-��������������� ����������������
//������������

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

	date.day = 5; //��� ������ �����
	cout << date.day << endl;

	date.setDay(42); //��� ������ ������
	cout << date.getDay() << endl;

	return 0;
}