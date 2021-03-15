#include<iostream>
#include<string>

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

template<typename T1, typename T2>
T1 mod(T1 a, T2 b)
{
	while (a > b) a -= b;
	return a;
}

int operationIndex(char operation)
{
	switch (operation)
	{
	case '+':return 0;
	case '-':return 1;
	case '*':return 2;
	case '/':return 3;
	case '%':return 4;
	}
	return 0;
}

template<typename T1, typename T2>
T1 calculate(T1 a, T2 b, char operation)
{
	T1(*operations[5])(T1, T2) { sum, diff, mult, div, mod };
	return operations[operationIndex(operation)](a, b);
}

bool isInt(string str)
{
	return str.find('.') == -1;
}

bool isDouble(string str)
{
	/*
	if (str.find('.') != -1)
	{
		return true;
	}
	return false;
	*/
	return str.find('.') != -1;
}

int main(int argc, char* argv[])
{
	string op;
	string op1;
	string op2;
	for (int i = 0; i < argc; ++i)
	{
		//cout << argv[i] << endl;
	}
	//string arg = argv[1];
	if (strcmp(argv[1], "--operator") == 0) //сделать проверку "--operator1" "--operator2"
	{
		op = argv[2]; op1 = argv[4]; op2 = argv[6];
	}
	if (strcmp(argv[3], "--operator") == 0)
	{
		op = argv[4]; op1 = argv[2]; op2 = argv[6];
	}
	if (strcmp(argv[5], "--operator") == 0)
	{
		op = argv[6]; op1 = argv[4]; op2 = argv[2];
	}

	cout << op1 << " ";
	cout << op << " ";
	cout << op2 << " = ";
	if (isInt(op1) && isInt(op2))
	{
		cout << calculate(stoi(op1), stoi(op2), op[0]) << endl;
	}
	else if (isDouble(op1) && isDouble(op2))
	{
		cout << calculate(stod(op1), stod(op2), op[0]) << endl;
	}
	else
	{
		if (isInt(op1))
		{
			cout << calculate(stoi(op1), stod(op2), op[0]) << endl;
		}
		else
		{
			cout << calculate(stod(op1), stoi(op2), op[0]) << endl;
		}
	}

	return 0;
}