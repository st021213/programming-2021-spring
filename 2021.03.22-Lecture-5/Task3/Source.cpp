#include<iostream>

using namespace std;

void printArray(int* a, int length)
{
	if (length < 1)
	{
		throw exception("wrong length");
	}

	for (int i = 0; i < length; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main()
{
	const int n = 10;
	int a[n] = { 0 };
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 10;
	}

	printArray(a, n);

	try
	{
		printArray(a, -5);
	}
	catch (exception e)
	{
		cout << e.what();
	}

	return 0;
}