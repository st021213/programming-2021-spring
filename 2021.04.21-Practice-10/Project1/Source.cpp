#include<iostream>

using namespace std;

static int scount = 2;
extern int ecount = 2;

void banana(int a)
{
	static int count = a;
	++count;
	cout << "BANANA COUNT : " << count << endl;
}

void barabana(int a)
{
	static int count = a;
	++count;
	cout << "BARABANA COUNT : " << count << endl;
}

int main()
{
	banana(5);
	banana(2);
	barabana(1);
	barabana(5);
	banana(2);
	return 0;
}