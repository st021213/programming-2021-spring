#include<iostream>

using namespace std;

//class - ��� �� ��������� private
//struct - ��� �� ��������� public
class Date {
private:
	int day; //����������������� ����
	int month;
	int year;

public:
	void setDay(int day)
	{
		this->day = day;
	} //������

	int getDay()
	{
		return this->day;
	} //������

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

	//��� ������ �����
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