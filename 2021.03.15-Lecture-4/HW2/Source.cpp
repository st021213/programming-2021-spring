#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<fstream>

using namespace std;

/*
Понятие вещественное число определено следующим образом:
<вещественное число> ::= <мантисса> <порядок> |<знак> <мантисса> <порядок>
<мантисса> ::= <целое без знака> . <целое без знака>
<порядок> ::= E <целое без знака> | E <знак> <целое без знака>
<целое без знака> ::= <цифра> | <цифра> <целое без знака>
<цифра> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 |7 | 8 | 9
<знак> ::= + | -
*/

bool isSign(char c);
bool isDigit(char c);
bool isNatural(string str, int& index);
bool isExp(string str, int& index);
bool isMantissa(string str, int& index);
bool isReal(string str, int& index);

int main()
{
	int index = 0;
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	while (!fin.eof())
	{
		string str;
		fin >> str;
		cout << str << endl;
		system("pause");
		if (isReal(str, index))
		{
			cout << "=)" << endl;
			fout << "=)" << endl;
		}
		else
		{
			cout << "=(" << endl;
			fout << "=(" << endl;
		}
	}
	fout.close();
	fin.close();
	return 0;
}

bool isSign(char c)
{
	return (c == '+' || c == '-');
}

bool isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool isNatural(string str, int& index)
{
	if (!isDigit(str[index]))
	{
		return false;
	}
	while (isDigit(str[++index]));
	return true;
}

bool isExp(string str, int& index)
{
	if (str[index] != 'E')
	{
		return false;
	}
	int memIndex = index;
	++index;
	if (isSign(str[index]))
	{
		++index;
	}
	if (isNatural(str, index))
	{
		return true;
	}
	index = memIndex;
	return false;
}

bool isMantissa(string str, int& index)
{
	int memIndex = index;
	if (isNatural(str, index) && str[index++] == '.' && isNatural(str, index))
	{
		return true;
	}
	index = memIndex;
	return false;
}

bool isReal(string str, int& index)
{
	if (isSign(str[index]))
	{
		++index;
	}
	int memIndex = index;
	if (isMantissa(str, index) && isExp(str, index) && str[index]=='\0')
	{
		return true;
	}
	index = memIndex;
	return false;
}