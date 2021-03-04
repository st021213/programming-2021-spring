#include<iostream>

using namespace std;

template<typename T1, typename T2>
T1 sum(T1 a, T2 b)
{
	return a + b;
}

template<typename T1, typename T2>
T1 diff(T1 a, T2 b)
{
	return a - b;
}

template<typename T1, typename T2>
T1 mult(T1 a, T2 b)
{
	return a * b;
}

template<typename T1, typename T2>
T1 div(T1 a, T2 b)
{
	return a / b;
}

int operationIndex(char operation)
{
	switch (operation)
	{
	case '+':return 0;
	case '-':return 1;
	case '*':return 2;
	case '/':return 3;
	}
	return 0;
}

template<typename T1, typename T2>
T1 calculate(T1 a, T2 b, char operation)
{
	T1(*operations[4])(T1, T2) { sum, diff, mult, div };
	return operations[operationIndex(operation)](a, b);
}

bool argsValid(int argc, char* argv[])
{
	if (argc != 7)
	{
		return false;
	}
	//...
}

int main(int argc, char* argv[])
{
	char x[] = { '-','-','o','p','e','r','a','n','d','1' };
	char x[] = "--operand1";

	if (!argsValid(argc, argv))
	{
		cout << "Invalid arguments. Try again";
		return 0;
	}
	cout << calculate(4.0f, 125, '/');
	return 0;
}