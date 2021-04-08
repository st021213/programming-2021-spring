#include<iostream>
#include<string>
#define N 10
const int n = 10;

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

	void add(const point& point)
	{
		x += point.x;
		y += point.y;
	}
};

typedef struct {
	int a;
	int b;
}* bananaPtr;

int main()
{
	point p2;

	point *p1;
	p1 = new point();

	(*p1).x = 45;
	p1->y = 53;
	p1->print();
	
	delete p1;

	struct {
		int a;
		int b;
	} f;
	f.a = 4;
	f.b = 9;
	cout << f.a + f.b << endl;

	bananaPtr b = (bananaPtr)malloc(sizeof(int) * 2);
	b->a = 4;
	cout << b->a << endl;
	cout << b->b << endl;
	free(b);

	return 0;
}