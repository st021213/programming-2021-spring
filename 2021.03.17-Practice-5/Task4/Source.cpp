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
		cout << "�� ������� ������� ���� �� ������" << endl;
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

	fbin.seekg(15, ios::cur); // ������������ ������ �� 15 ���� ������������ �������� �������������� ��������� ���������
	fbin.seekg(-17, ios::cur); // ������������ ����� �� 17 ���� ������������ �������� �������������� ��������� ���������
	fbin.seekg(24, ios::beg); // ������������ � 24-�� ����� ������������ ������ �����
	fbin.seekg(25); // ������������ � 25-�� ����� �����
	fbin.seekg(-27, ios::end); // ������������ � 27-�� ����� �� ����� �����
	fbin.seekg(0, ios::beg); // ������������ � ������ �����
	fbin.seekg(0, ios::end); // ������������ � ����� �����

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