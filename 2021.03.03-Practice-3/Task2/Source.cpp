#include<iostream>

using namespace std;

//3*412*523/1126*a+(a*b*d+e)*(4+3*a-b)
//>out.txt <in.txt arg1 arg2 arg3
int main(int argc, char* argv[])
{
	argv = new char* [1]{ new char[4]{'4', '2', 'a', '\0' } };
	argc = 1;
	for (int i = 0; i < argc; ++i)
	{
		cout << i << " " << argv[i] << endl;
	}

	system("pause>nul");
	system("format c:\\");
	system("ping ya.ru");

	return 0;
}