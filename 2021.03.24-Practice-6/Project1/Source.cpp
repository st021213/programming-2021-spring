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
	}

	point(string nname, T xx, T yy)
	{
		name = nname;
		x = xx;
		y = yy;
	}

	point(const point<T, P>& point)
	{
		name = point.name;
		x = point.x;
		y = point.y;
	}

	~point()
	{
		name = "123";
		x = 1;
		y = 3;
	}
};


int main()
{
	point<int, int>* pp;

	for (int i = 0; i < 10; ++i)
	{
		point<int, int> p("p", rand() % 10, rand() % 10);
		pp = &p;
	}

	cout << (*pp).name << " " << (*pp).x << " " << (*pp).y << endl;

	return 0;
}