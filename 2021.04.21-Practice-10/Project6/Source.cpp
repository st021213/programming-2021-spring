#include<iostream>

using namespace std;

class MagicClass {
private:
	int a;
	int b;
	int c;

public:
	MagicClass(int a = 5, int b = 89, int c = 124) : a(a), b(b), c(c) { }

	int getA() { return a; }

	void setA(int a) { this->a = a; }

	int getB() { return b; }

	void setB(int b) { this->b = b; }

	int getC() { return c; }

	void setC(int c) { this->c = c; }

	friend void printF(MagicClass& m);
};

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