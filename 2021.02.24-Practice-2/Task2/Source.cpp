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

void calc(int a, int b, char symb, int (*op)(int, int))
{
	cout << a << " " << symb << " " << b << " = " << op(a, b) << endl;
}

int main()
{
	calc(3, 2, '+', sum);
	calc(3, 2, '-', diff);

	int (*ops[3])(int, int) = { sum, diff, mult };
	ops[0] = mult;
	ops[1] = sum;
	ops[2] = diff;
	for (int i = 0; i < 3; ++i)
	{
		calc(9, 1, '?', ops[i]);
	}

	return 0;
}