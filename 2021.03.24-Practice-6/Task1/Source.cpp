#include<iostream>
#include<string>

using namespace std;

template<typename T, typename P>
struct point {
	string name;
	T x;
	P y;

	point()
	{
		name = "default";
		x = 0;
		y = 0;
		cout << "Default constructor call" << endl;
	}

	point(string nname, T xx, T yy)
	{
		name = nname;
		x = xx;
		y = yy;
		cout << "Parametrized constructor call" << endl;
	}

	point(const point<T, P> &point)
	{
		name = point.name;
		x = point.x;
		y = point.y;
		cout << "Copy constructor call" << endl;
	}

	~point()
	{
		name = "";
		x = 0;
		y = 0;
	}
};

void print(point<int, int> p)
{
	cout << p.name << "(" << p.x << "; " << p.y << ")" << endl;
}

void add(point<int, int> p)
{
	++p.x;
	++p.y;
}

void addP(point<int, int> &p)
{
	++p.x;
	++p.y;
}

int main()
{
	point<int, int> p1;
	p1.name = "p1";
	p1.x = 4;
	p1.y = 2;

	point<int, int> p2("p2", 4, 2);

	print(p1);

	point<int, int> p3(p1);
	p3.name = "p3";

	//int x(4);
	//cout << x << endl;

	add(p1);

	addP(p3);


	return 0;
}