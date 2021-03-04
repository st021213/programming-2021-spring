#include<iostream>

using namespace std;

template<class T1, class T2>
T1 sum(T1 a, T2 b)
{
	return a + b;
}

int main()
{
	cout << sum(4, 2) << endl;
	cout << sum(9.5f, 2.8f) << endl;
	cout << sum(9.5f, 3) << endl;
	return 0;
}