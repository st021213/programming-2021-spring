#include<iostream>

using namespace std;

int sum(int a, int b);
//int f(int);
int g(int);

int f(int n)
{
	if (n > 0)
	{
		return g(n - 1);
	}
	return 0;
}

int g(int n)
{
	if (n > 0)
	{
		return f(n - 1);
	}
	return 0;
}

int main()
{
	cout << sum(2, 5) << endl;
	return 0;
}

int sum(int a, int b)
{
	return a + b;
}