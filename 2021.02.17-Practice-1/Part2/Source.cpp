#include<iostream>

using namespace std;

int sum(int a = 0, int b = 0)
{
	return a + b;
}

int sum(float a)
{
	return sum(a, 0);
}

int sum(double a)
{
	return sum(a, 0);
}

int diff(int a, int b)
{
	return a + b;
}

int diff(int a)
{
	return diff(a, 0);
}

int diff()
{
	return diff(0);
}

int main()
{
	cout << sum(3, 5) << endl;
	cout << diff(4) << endl;
	cout << diff() << endl;
	cout << sum(5) << endl;
	cout << sum((float)5) << endl;
	cout << sum(5.0f) << endl;
	cout << sum(5.0) << endl;
	return 0;
}