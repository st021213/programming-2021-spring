#include<iostream>
using namespace std;

int sum(int a, int b = 0)
{
	return a + b;
}

int sum(float a, float b = 0)
{
	return a + b;
}

int main()
{
	cout << sum(4.f, 2.f);
	return 0;
}
