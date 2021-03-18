#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	const int n = 10;
	int a[n] = { 0 };
	for (int i = 0; i < n; a[i] = rand() % 10, ++i);
	for (int i = 0; i < n; cout << a[i] << (i == n - 1 ? '\n' : ' '), ++i);

	fstream fbin;
	fbin.open("in.bin", ios::binary | ios::out);
	if (!fbin)
	{
		cout << "Ќе удалось открыть файл на запись" << endl;
	}
	fbin.write((char*)a, sizeof(a));
	fbin.close();

	fbin.open("in.bin", ios::binary | ios::in);

	int b = 0;
	fbin.read((char*)&b, sizeof(int));
	cout << "read : " << b << endl;
	fbin.read((char*)&b, sizeof(int));
	cout << "read : " << b << endl;
	fbin.read((char*)&b, sizeof(int));
	cout << "read : " << b << endl;
	fbin.seekg(-(int)sizeof(int), ios::cur); //ios::beg ios::end
	fbin.read((char*)&b, sizeof(int));
	cout << "read : " << b << endl;

	fbin.seekg(15, ios::cur); // перемещаемс€ вперед на 15 байт относительно текущего местоположени€ файлового указател€
	fbin.seekg(-17, ios::cur); // перемещаемс€ назад на 17 байт относительно текущего местоположени€ файлового указател€
	fbin.seekg(24, ios::beg); // перемещаемс€ к 24-му байту относительно начала файла
	fbin.seekg(25); // перемещаемс€ к 25-му байту файла
	fbin.seekg(-27, ios::end); // перемещаемс€ к 27-му байту от конца файла
	fbin.seekg(0, ios::beg); // перемещаемс€ в начало файла
	fbin.seekg(0, ios::end); // перемещаемс€ в конец файла

	fbin.close();

	cout << "Trying to rewrite all odds to -1" << endl;

	fbin.open("in.bin", ios::binary | ios::in | ios::out);
	while (!fbin.eof())
	{
		fbin.read((char*)&b, sizeof(int));
		cout << "read : " << b;
		if (b % 2 == 1) 
		{
			fbin.seekg(-(int)sizeof(int), ios::cur);
			b = -1;
			fbin.write((char*)&b, sizeof(int));
			cout << " changed to -1";
			fbin.seekg(fbin.tellg(), ios::beg);
		}
		cout << endl;
		//cout << "\tTELLG: " << fbin.tellg() << " TELLP:" << fbin.tellp() << endl;
		//system("pause");
	}
	fbin.close();

	fbin.open("in.bin", ios::in);
	fbin.read((char*)&a, sizeof(a));
	for (int i = 0; i < n; cout << a[i] << (i == n - 1 ? '\n' : ' '), ++i);
	fbin.close();
	


	return 0;
}