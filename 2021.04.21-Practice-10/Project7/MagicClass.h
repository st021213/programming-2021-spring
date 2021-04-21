#pragma once

class MagicClass {
private:
	int a;
	int b;
	int c;

public:
	MagicClass(int a = 5, int b = 89, int c = 124) : a(a), b(b), c(c) { }

	int getA();

	void setA(int a);

	int getB();

	void setB(int b);

	int getC();

	void setC(int c) { this->c = c; }

	friend void printF(MagicClass& m);
};
