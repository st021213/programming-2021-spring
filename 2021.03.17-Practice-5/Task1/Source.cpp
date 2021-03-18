#include<iostream>
#include<fstream>
using namespace std;

struct Point {
	int x;
	int y;
	int z;
	Point() : x(rand() % 10), y(rand() % 10), z(rand() % 10) {}
	friend ostream& operator<<(ostream& stream, const Point& point)
	{
		stream << "(" << point.x << "; " << point.y << "; " << point.z << ")";
		return stream;
	}
};

int main()
{
	cout << sizeof(Point) << endl;
	Point p1;
	Point p2;
	/*
	�����	����������
	in		������� ��� ����� (���������� �� ��������� ��� ifstream)
	out		������� ��� ������ (���������� �� ��������� ��� ofstream)
	binary	������� ���� � �������� ����
	a��		������������ ������; ������ � ����� �����
	ate		���������� �������� ��������� �� ����� �����
	trunc	���������� ����������, ���� ���� ���������� (���������� �� ���������, ���� ���� out ������, � ����� ate � ��� � ���)
	*/
	cout << p1 << p2 << endl;
	fstream fout;
	fout.open("in.txt", ios::binary | ios::out);
	if (!fout)
	{
		cout << "�� ������� ������� ����";
	}
	fout.write((char*)(&p1), sizeof(Point));
	fout.write((char*)(&p2), sizeof(Point));
	fout.close();

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
	Point p3;
	Point p4;
	fstream fin;
	cout << p3 << p4 << endl;
	fin.open("in.txt", ios::binary | ios::in);
	if (!fin)
	{
		cout << "�� ������� ������� ����";
	}
	fin.read((char*)(&p3), sizeof(Point));
	cout << p3;
	fin.seekg(-(int)sizeof(Point), ios::cur);
	fin.read((char*)(&p4), sizeof(Point));
	cout << p4;
	fin.read((char*)(&p4), sizeof(Point));
	fin.close();
	cout << p3 << p4 << endl;


	//seekg seekp tellg tellp
	fin.seekg(15, ios::cur); // ������������ ������ �� 15 ���� ������������ �������� �������������� ��������� ���������
	fin.seekg(-17, ios::cur); // ������������ ����� �� 17 ���� ������������ �������� �������������� ��������� ���������
	fin.seekg(24, ios::beg); // ������������ � 24-�� ����� ������������ ������ �����
	fin.seekg(25); // ������������ � 25-�� ����� �����
	fin.seekg(-27, ios::end); // ������������ � 27-�� ����� �� ����� �����
	
	fin.seekg(0, ios::beg); // ������������ � ������ �����
	fin.seekg(0, ios::end); // ������������ � ����� �����

	return 0;
}