#include<iostream>

using namespace std;

void printArray(int* a, int length)
{
	for (int i = 0; i < length; ++i)
	{
		if (i == 5)
		{
			i = 5;
		}
		cout << a[i] << ' ';
	}
}

int main()
{
	//Ctrl + F5 - ������ ��� �������
	//F5 - ������ � ��������
	//F10 - ��������� ���������� ��������� ��� ������� � �������
	//F11 - ��������� ���������� ��������� � ������� � �������
	//F9 - �������� ����� ��������� �� ������� ������
	//Ctrl + F10 - ��������� �� �����
	//Shift + F11 - ��������� ������� �� ����� � ������������ � ����� �� ������
	const int n = 10;
	int a[n] = { 0 };
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 10;
	}
	printArray(a, n);

	return 0;
}