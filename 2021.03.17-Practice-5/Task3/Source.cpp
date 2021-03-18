#include<iostream>
#include<fstream>
#include<ctime>

using namespace std;

int main()
{
	srand(time(0));
	const int n = 10;
	int a[n] = { 0 };
	for (int i = 0; i < n; a[i] = rand() % 10, ++i);
	cout << "random array written to in.txt" << endl;
	for (int i = 0; i < n; cout << a[i] << (i == n - 1 ? '\n' : ' '), ++i);

	ofstream fout("in.txt");
	for (int i = 0; i < n; fout << a[i] << ' ', ++i);
	fout.close();

	cout << "array read from in.txt" << endl;
	int b[n] = { 0 };
	ifstream fin("in.txt");
	for (int i = 0; i < n; fin >> b[i], ++i);
	fin.close();
	for (int i = 0; i < n; cout << b[i] << (i == n - 1 ? '\n' : ' '), ++i);

	/*
	00010111 = 1 | 2 | 4 | 16
	00010111 = ��� | ������� | �������� | ���
	00000001 1 - ���
	00000010 2 - �������
	00000100 4 - ��������
	00001000 8 - ���� ��������
	00010000 16 - ���
	00100000 32 - ���
	01000000 64 - ���� ����
	10000000 128 - ������� �����
	*/

	/*
	�����	����������
	in		������� ��� ����� (���������� �� ��������� ��� ifstream)
	out		������� ��� ������ (���������� �� ��������� ��� ofstream)
	binary	������� ���� � �������� ����
	a��		������������ ������; ������ � ����� �����
	ate		���������� �������� ��������� �� ����� �����
	trunc	���������� ����������, ���� ���� ���������� (���������� �� ���������, ���� ���� out ������, � ����� ate � ��� � ���)
	*/
	fstream fbin;
	fbin.open("in.bin", ios::binary | ios::out);
	if (!fbin)
	{
		cout << "�� ������� ������� ���� �� ������" << endl;
	}
	fbin.write((char*) a, sizeof(a));
	fbin.close();

	cout << "randomized array" << endl;
	for (int i = 0; i < n; b[i] = rand() % 10, ++i);
	for (int i = 0; i < n; cout << b[i] << (i == n - 1 ? '\n' : ' '), ++i);

	/*
	�����	��������
	open	��������� ���� ��� ������
	get		������ ���� ��� ����� �������� �� �����
	getline	������ ���������� ������ �� ���������� ����� ��� ������ �� ��������� ����� �� ������������� ������������
	read	��������� �������� ����� ���� �� ����� � ������
	eof		���������� ��������� �������� (true), ����� ��������� ������ ��������� ����� �����
	peek	������ ��������� ������ ������, �� �� �������� ���
	seekg	���������� ��������� ���������������� ����� � �������� ���������
	tellg	���������� ������� �������� ��������� ���������������� �����
	close	��������� ����
	*/
	fbin.open("in.bin", ios::binary | ios::in);
	if (!fbin)
	{
		cout << "�� ������� ������� ���� �� ������" << endl;
	}
	fbin.read((char*)b, sizeof(b));
	fbin.close();
	cout << "array read from in.bin" << endl;
	for (int i = 0; i < n; cout << b[i] << (i == n - 1 ? '\n' : ' '), ++i);


	return 0;
}