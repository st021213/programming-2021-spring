#include<iostream>
#include<fstream>

using namespace std;

struct Point
{
	int x;
	int y;
	Point()
	{
		x = rand() % 10;
		y = rand() % 10;
	}
};


int main()
{
	Point p1;
	Point p2;
	//cout << sizeof(Point) << endl;
	//cout << sizeof(int) << endl;

	fstream fbin;
	fbin.open("in.bin", ios::binary | ios::out);
	fbin.write((char*)&p1, sizeof(Point));
	fbin.write((char*)&p2, sizeof(Point));
	fbin.close();

	Point p3;
	Point p4;
	fbin.open("in.bin", ios::binary | ios::in);
	fbin.read((char*)&p3, sizeof(Point));
	fbin.read((char*)&p4, sizeof(Point));
	fbin.close();

	cout << "Point 1 : (" << p1.x << "; " << p1.y << ")" << endl;
	cout << "Point 2 : (" << p2.x << "; " << p2.y << ")" << endl;
	cout << "Point 3 : (" << p3.x << "; " << p3.y << ")" << endl;
	cout << "Point 4 : (" << p4.x << "; " << p4.y << ")" << endl;

	return 0;
}