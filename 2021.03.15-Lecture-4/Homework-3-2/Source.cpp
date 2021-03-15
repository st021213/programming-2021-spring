#include<iostream>
#include<fstream>
#include<string>
using namespace std;
/*
������� ������������ ����� ���������� ��������� �������:
<������������ �����> ::= <��������> <�������> | <����> <��������> <�������>
<��������> ::= <����� ��� �����> . <����� ��� �����>
<�������> ::= E <����� ��� �����> | E <����> <����� ��� �����>
<����� ��� �����> ::= <�����> | <�����> <����� ��� �����>
<�����> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
<����> ::= + | -
*/

bool isSign(char c);
bool isDigit(char c);
bool isE(string str, int& index);
bool isDot(string str, int& index);
bool isNatural(string str, int& index);
bool isExp(string str, int& index);
bool isMantis(string str, int& index);
bool isReal(string str, int& index);

int main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	while (!fin.eof())
	{
		string str;
		int index = 0;
		fin >> str;
		cout << str << " -> is ";
		fout << str << " -> is ";
		if (!isReal(str, index))
		{
			cout << "not ";
			fout << "not ";
		}
		cout << "real" << endl;
		fout << "real" << endl;
	}
	fout.close();
	fin.close();
	return 0;
}


bool isSign(char c)
{
	return c == '+' || c == '-';
}

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

bool isE(string str, int& index)
{
	if (str[index] == 'E')
	{
		++index;
		return true;
	}
	return false;
}

bool isDot(string str, int& index)
{
	if (str[index] == '.')
	{
		++index;
		return true;
	}
	return false;
}

bool isNatural(string str, int& index)
{
	/*<����� ��� �����> ::= <�����> | <�����> <����� ��� �����>*/
	if (!isDigit(str[index]))
	{
		return false;
	}
	while (isDigit(str[++index]));
	return true;
}

bool isExp(string str, int& index)
{
	/*<�������> ::= E <����� ��� �����> | E <����> <����� ��� �����>*/
	if (!isE(str, index))
	{
		return false;
	}
	if (isSign(str[index]))
	{
		++index;
	}
	if (isNatural(str, index))
	{
		return true;
	}
	return false;
}

bool isMantis(string str, int& index)
{
	/*<��������> ::= <����� ��� �����> . <����� ��� �����>*/
	if (isNatural(str, index) && isDot(str, index) && isNatural(str, index))
	{
		return true;
	}
	return false;
}

bool isReal(string str, int& index)
{
	/*<������������ �����> ::= <��������> <�������> | <����> <��������> <�������>*/
	if (isSign(str[index]))
	{
		++index;
	}
	if (isMantis(str, index) && isExp(str, index) && str[index] == '\0')
	{
		return true;
	}
	return false;
}