#include<iostream>

using namespace std;

void hello()
{
	cout << "Hello" << endl;
}

void hi()
{
	cout << "Hi" << endl;
}

void callFunction(void (func)())
{
	func();
}

int main()
{
	void (*say)();
	say = hello;
	callFunction(say);
	say = hi;
	callFunction(say);

	return 0;
}