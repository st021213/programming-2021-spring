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

	for (auto element : a) //for each - ��� �������
	{
		cout << element << " ";
	}
	cout << endl;

	for (auto element : a) //for each - ��� �������
	{
		cin >> element;
	}
	cout << endl;

	for (auto element : a) //for each - ��� �������
	{
		cout << element << " ";
	}
	cout << endl;

	cout << "������� ���������� � ����" << endl;
	int i = 0;
	for (auto element : a) //for each - ��� �������
	{
		cin >> a[i];
		++i;
	}
	cout << endl;

	cout << "���������� � ���� �� ����������" << endl;
	for (auto element : a) //for each - ��� �������
	{
		cout << element << " ";
	}
	cout << endl;

	return 0;
}