#include<iostream>
#include<cstdarg>
using namespace std;

int sum(int n, ...)
{
	int result = 0;
	for (int* ptr = &n; n > 0; n--)
	{
		result += *(++ptr);
	}
	return result;
}

int main()
{
	cout << sum(6, 4, 2, 1, 5, 6, 0) << endl;
	cout << sum(4, 4, 2, 6, 0) << endl;
	return 0;
}