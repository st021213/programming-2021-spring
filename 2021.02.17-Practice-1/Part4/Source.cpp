#include<iostream>

using namespace std;

// 4 5 7 9 2
int sum(int n, ...)
{
	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		//cout << endl << &n << endl;
		int* ptr = &n + 1 + i;
		//cout << endl << ptr << endl;
		cout << *ptr;
		if (i == n - 1)
		{
			cout << " = ";
		}
		else
		{
			cout << " + ";
		}
		result += *ptr;
	}
	return result;
}

int main()
{
	cout << sum(6, 1, 2, 3, 4, 5, 6) << endl;
	cout << sum(3, 5, 7, 9) << endl;
	return 0;
}