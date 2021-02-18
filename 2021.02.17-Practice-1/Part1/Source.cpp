#include<iostream>

using namespace std;

void printBits(short s)
{
	int bitlength = sizeof(s) * 8;
	for (int i = 0; i < bitlength; ++i)
	{
		unsigned short bit = s;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
}

int main()
{
	cout << "signed integer" << endl;
	cout << "INT : " << sizeof(int) << endl;
	cout << "LONG : " << sizeof(long) << endl;
	cout << "LONG LONG : " << sizeof(long long) << endl;
	cout << "SHORT : " << sizeof(short) << endl;
	// 0 000 0000 0000 0000 => -2^(15) .. 2^(15) - 1
	// 1 000 0000 0000 0001 != -1
	// 0 111 1111 1111 1111 => 2^15 - 1
	//10 000 0000 0000 0000 = 0

	cout << "unsigned integer" << endl;
	cout << "UINT : " << sizeof(unsigned int) << endl;
	cout << "ULONG : " << sizeof(unsigned long) << endl;
	cout << "ULONG LONG : " << sizeof(unsigned long long) << endl;
	cout << "USHORT : " << sizeof(unsigned short) << endl;
	//0000 0000 0000 0000 => 0 .. 2^16 - 1

	cout << endl << "operations" << endl;
	printBits(15);
	cout << endl;
	short s = 15;
	int i = s;
	i = 1222222251;
	s = i;
	cout << s << endl;
	//приведение типа
	long l = (long)s;
	float f = 4.7;
	// 0 0000000 00000 000 00000000 00000000
	i = (int)f;
	cout << i << endl;

	cout << "INT : " << sizeof(int) << endl;
	cout << "FLOAT : " << sizeof(float) << endl;
	void* ptr;
	ptr = &f;
	cout << *((int*)ptr) << endl;
	cout << "PTR LONG : " << sizeof(long*) << endl;
	cout << "PTR LONG LONG : " << sizeof(long long*) << endl;
	return 0;
}