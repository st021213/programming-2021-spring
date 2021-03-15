#include<iostream>

using namespace std;

void swap(int& a, int& b);
void fillArray(int* a, int len);
void inputArray(int* a, int len);
void printArray(int* a, int len);
void mixArray(int* a, int len);
bool isSorted(int* a, int len, bool ascending = true);
void bubbleSort(int* a, int len);
void insertionSort(int* a, int len);
void selectionSort(int* a, int len);

int main()
{
	int len = 12;
	int* a = new int[len];
	fillArray(a, len);
	printArray(a, len);
	mixArray(a, len);
	printArray(a, len);
	//while (!isSorted(a, len))
	{
		mixArray(a, len);
	}
	printArray(a, len);

	cout << "Bubble sort" << endl;
	mixArray(a, len);
	printArray(a, len);
	bubbleSort(a, len);
	printArray(a, len);

	cout << "Insertion sort" << endl;
	mixArray(a, len);
	printArray(a, len);
	insertionSort(a, len);
	printArray(a, len);

	cout << "Selection sort" << endl;
	mixArray(a, len);
	printArray(a, len);
	selectionSort(a, len);
	printArray(a, len);
	delete[] a;

	return 0;
}

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void fillArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		a[i] = rand() % 90 + 10;
	}
}

void inputArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cin >> a[i];
	}
}

void printArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

void mixArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		swap(a[i], a[rand() % len]);
	}
}

bool isSorted(int* a, int len, bool ascending)
{
	for (int i = 0; i < len - 1; ++i)
	{
		//1 2 3 4 5 3
		if (a[i] > a[i + 1] == ascending)
		{
			return false;
		}
	}
	return true;
}

void bubbleSort(int* a, int len)
{
	//cout << endl;
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				//printArray(a, len);
			}
		}
	}
	//cout << endl;
}

void insertionSort(int* a, int len)
{
	for (int i = 1; i < len; ++i)
	{
		int t = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > t)
		{
			a[j] = a[j - 1];
			--j;
		}
		a[j] = t;
		//printArray(a, len);
	}
}

void selectionSort(int* a, int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		int index = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (a[j] < a[index])
			{
				index = j;
			}
		}
		swap(a[i], a[index]);
		//printArray(a, len);
	}
}

