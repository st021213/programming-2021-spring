#include<iostream>
using namespace std;

// 1.75_10 -> 1.11_2

void printLong(long l)
{
	for (int i = sizeof(l) * 8 - 1; i >= 0; --i)
	{
		//1101 >> 2
		//0011 & 1
		//0001 = 1
		//0001 = 1 - значение третьего бита справа

		//1101 >> 1
		//0110 & 1
		//0001 = 1
		//0000 = 0 - значение второго бита справа
		int bit = (l >> i) & 1;
		cout << bit;
		if (i % 8 == 0)
		{
			cout << " ";
		}
	}
	cout << endl;
}

void printFloat(float f)
{
	void* ptr = (&f);
	long l = *((long*)ptr);
	printLong(l);
}

int main()
{
	printLong(5);
	printFloat(5);
	return 0;
}