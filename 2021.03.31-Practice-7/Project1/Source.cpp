#include<iostream>
#include<string>

using namespace std;

struct point {
	/*����*/
	string name;
	int x;
	int y;

	/*����������� �� ���������*/
	point() : name("default"), x(0), y(0) {	}

	/*����������� � �����������*/
	point(string nname, int xx, int yy) : name(nname), x(xx), y(yy) { }

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

	string toString()
	{
		string result = "";
		result += name; //������������ �����
		result += '(';
		result += x;
		result += ';';
		result += y;
		result += ')';
		return result;
	}

	void add(const point& point)
	{
		x += point.x;
		y += point.y;
	}
};

int main()
{
	point p1("p1", 4, 2);
	point p2("p2", 5, 1);


	p1.print();
	p2.print();
	p1.add(p2);
	p1.print();


	return 0;
}