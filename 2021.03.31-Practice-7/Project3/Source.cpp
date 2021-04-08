#include<iostream>
#include<string>

using namespace std;

struct point {
	/*����*/
	string name;
	int x;
	int y;

	/*����������� �� ���������*/
	point(){
		this->name = "default";
		this->x = 0;
		this->y = 0;
	}

	/*����������� � �����������*/
	point(string name, int x, int y) : name(name), x(x), y(y) {	}

	/*����������� �����������*/
	point(const point& point) : name(point.name), x(point.x), y(point.y) { }

	/*����������*/
	~point()
	{
		name = "";
		x = 0;
		y = 0;
	}

	/*������*/
	void print()
	{
		cout << name << "(" << x << "; " << y << ")" << endl;
	}

	void add(const point& point)
	{
		x += point.x;
		y += point.y;
	}
};

int main()
{
	point* p1 = new point("banana", 5, 2);
	delete p1;

	return 0;
}