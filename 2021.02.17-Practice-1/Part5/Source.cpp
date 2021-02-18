#include<iostream>

using namespace std;

void hello()
{
	cout << "HELLO" << endl;
}

void goodbye()
{
	cout << "GOODBYE" << endl;
}

void sayWord(void (*word)())
{
	cout << "I AM SAYING ";
	word();
}

int main()
{
	void(*say)();
	say = hello;
	say();
	say = goodbye;
	say();

	sayWord(hello);
	sayWord(goodbye);

	return 0;
}