#include <iostream>

using namespace std;

void printBits(float number)
{
	int x = 0; 
	void* ptr = &number;
	long a = *(long*)(ptr);
	for (int i = sizeof(a) * 8 - 1; i >= 0; --i)
	{
		x = ((a >> i) & 1);
		cout << x;
		if (i % 8 == 0)
		{
			cout << ' ';
		}
	}
}

int main()
{
	printBits((float)32);
	return 0;
}