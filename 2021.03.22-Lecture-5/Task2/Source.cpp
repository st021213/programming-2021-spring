#include<iostream>

using namespace std;

void printArray(int* a, int length)
{
	for (int i = 0; i < length; ++i)
	{
		if (i == 5)
		{
			i = 5;
		}
		cout << a[i] << ' ';
	}
}

int main()
{
	//Ctrl + F5 - запуск без отладки
	//F5 - запуск с отладкой
	//F10 - пошаговое выполнение программы без заходов в функцию
	//F11 - пошаговое выполнение программы с заходом в функцию
	//F9 - добавить точку остановка на текущей строке
	//Ctrl + F10 - выполнить до точки
	//Shift + F11 - выполнить функцию до конца и остановиться в точке ее вызова
	const int n = 10;
	int a[n] = { 0 };
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 10;
	}
	printArray(a, n);

	return 0;
}