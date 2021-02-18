#include<iostream>
using namespace std;

int sum(int a, int b)
{
	return a + b;
}
int diff(int a, int b)
{
	return a - b;
}

int main()
{
	int (*op)(int, int);
	op = sum;
	cout << op(3, 2) << endl;
	op = diff;
	cout << op(3, 2) << endl;
	return 0;
}