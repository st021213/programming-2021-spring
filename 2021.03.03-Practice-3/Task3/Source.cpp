#include<iostream>
#include<string>

using namespace std;

/*
Понятие выражение определено следующим образом:
<выражение> ::= <терм> | <терм> + <выражение> | <терм> – <выражение>
<терм> ::= <множитель> | <множитель> * <терм> | <множитель> / <терм>
<множитель> ::= <целое без знака> | <идентификатор> | (<выражение>)
<целое без знака> ::= <цифра> | <цифра> <целое без знака>
<идентификатор> ::= <буква>
<цифра> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
<буква> ::= a | b | c | d | e | f | x | y | z
*/

bool isDigit(char c);
bool isLetter(char c);
bool isIdentifier(string str, int& index);
bool isNatural(string str, int& index);
bool isMult(string str, int& index);
bool isTerm(string str, int& index);
bool isExpression(string str, int& index);

int main()
{
	//является ли данная строка выражением
	string expr = "3*412*523/1126*a+(a*b*d+e)*(4+3*a-b)";
	int index = 0;
	if (isExpression(expr, index))
	{
		cout << "OK";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
	/*
	if (c >= '0' && c <= '9')
	{
		return true;
	}
	return false;
	*/
}

bool isLetter(char c)
{
	return c >= 'a' && c <= 'f' || c >= 'x' && c <= 'z';
}

bool isIdentifier(string str, int& index)
{
	if (isLetter(str[index]))
	{
		++index;
		return true;
	}
	return false;
}

bool isNatural(string str, int& index)
{
	if (isDigit(str[index]))
	{
		while (isDigit(str[++index]));
		/*
		while (isDigit(str[index]))
		{
			++index;
		}*/
		return true;
	}
	return false;
}

bool isMult(string str, int& index)
{
	//<множитель> :: = <целое без знака> | <идентификатор> | (<выражение>)
	if (isNatural(str, index) || isIdentifier(str, index))
	{
		return true;
	}

	int memIndex = index;
	if (str[index++] == '(' && isExpression(str, index) && str[index++] == ')')
	{
		return true;
	}
	index = memIndex;
	return false;
	/*
	if (str[index] == '(')
	{
		++index;
		if (isExpression(str, index))
		{
			if (str[index] == ')')
			{
				++index;
				return true;
			}
		}
	}
	*/
}

bool isTerm(string str, int& index)
{
	if (!isMult(str, index))
	{
		return false;
	}

	int memIndex = index;
	if ((str[index] == '*' || str[index] == '/') && !isTerm(str, ++index))
	{
		index = memIndex;
		return false;
	}
	return true;
	/*
	int memIndex = index;
	if (str[index] == '*' || str[index] == '/')
	{
		++index;
		if (!isTerm(str, index))
		{
			index = memIndex;
			return false;
		}
		return true;
	}
	return true;
	*/
}

bool isExpression(string str, int& index)
{
	if (!isTerm(str, index))
	{
		return false;
	}

	int memIndex = index;
	if ((str[index] == '+' || str[index] == '-') && !isExpression(str, ++index))
	{
		index = memIndex;
		return false;
	}
	return true;
}
