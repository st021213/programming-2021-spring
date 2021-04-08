#include<iostream>
#include<string>

using namespace std;

struct point {
	/*поля*/
	string name;
	int x;
	int y;

	/*конструктор по умолчанию*/
	point() : name("default"), x(0), y(0) {	}

	/*конструктор с параметрами*/
	point(string nname, int xx, int yy) : name(nname), x(xx), y(yy) { }

	/*конструктор копирования*/
	point(const point& point) : name(point.name), x(point.x), y(point.y) { }

	/*деструктор*/
	~point()
	{
		name = "";
		x = 0;
		y = 0;
	}

	/*методы*/
	void print()
	{
		cout << name << "(" << x << "; " << y << ")" << endl;
	}

	string toString()
	{
		string result = "";
		result += name; //конкатенация строк
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