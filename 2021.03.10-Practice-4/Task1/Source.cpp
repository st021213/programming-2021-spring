#include<iostream>
#define N 3

using namespace std;

int main()
{
	const int n = 3;
	int a[3]{ 4, 1, 3 };
	int b[n]{ 0 };
	int c[N]{ 0 };

	cout << sizeof(a) / sizeof(int) << endl;
	cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;

	for (int i = 0; i < 3; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	for (auto i = 0; i < 3; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	for (auto element : a) //for each - Для каждого
	{
		cout << element << " ";
	}
	cout << endl;

	for (auto element : a) //for each - Для каждого
	{
		cin >> element;
	}
	cout << endl;

	for (auto element : a) //for each - Для каждого
	{
		cout << element << " ";
	}
	cout << endl;

	cout << "Попытка выстрелить в ногу" << endl;
	int i = 0;
	for (auto element : a) //for each - Для каждого
	{
		cin >> a[i];
		++i;
	}
	cout << endl;

	cout << "Выстрелить в ногу не получилось" << endl;
	for (auto element : a) //for each - Для каждого
	{
		cout << element << " ";
	}
	cout << endl;

	return 0;
}