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
int mult(int a, int b)
{
	return a * b;
}
int main()
{
	int (*ops[3])(int, int);
	ops[0] = sum;
	ops[1] = diff;
	ops[2] = mult;
	for (int i = 0; i < 3; ++i)
	{
		cout << ops[i](2, 5) << endl;
	}



	return 0;
}