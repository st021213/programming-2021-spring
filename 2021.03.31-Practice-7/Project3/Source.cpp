#include<iostream>
#include<string>

using namespace std;

struct point {
	/*поля*/
	string name;
	int x;
	int y;

	/*конструктор по умолчанию*/
	point(){
		this->name = "default";
		this->x = 0;
		this->y = 0;
	}

	/*конструктор с параметрами*/
	point(string name, int x, int y) : name(name), x(x), y(y) {	}

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