#include<iostream>
#include"MagicClass.h"

using namespace std;

void print(MagicClass& m)
{
	cout << m.getA() << " " << m.getB() << " " << m.getC() << endl;
}

void printF(MagicClass& m)
{
	cout << m.a << " " << m.b << " " << m.c << endl;
}

int main()
{
	MagicClass m1, m2, m3;
	print(m1);
	print(m2);
	print(m3);
	printF(m1);
	printF(m2);
	printF(m3);
}