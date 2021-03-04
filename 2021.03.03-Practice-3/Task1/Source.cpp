#include<iostream>

using namespace std;

long long factorial(long long x)
{
	if (x == 0)
	{
		return 1;
	}
	return x * factorial(x - 1);
}

int main()
{
	cout << factorial(4) << endl;
	return 0;
}