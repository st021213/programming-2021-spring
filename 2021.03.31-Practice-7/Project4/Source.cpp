#include<iostream>

using namespace std;

enum fruit {
	banana = 32,
	apelsina = 4,
	baklazhana = 0
};

enum queryParameter {
	name = 1,   //0000 0001
	photo = 2,  //0000 0010
	weight = 4, //0000 0100
	flor = 8,   //0000 1000
};
//5 + 9 -> 1110

int main()
{
	fruit a;
	a = banana;
	cout << a << endl;
	a = apelsina;
	cout << a << endl;
	a = baklazhana;
	cout << a << endl;
	a = (fruit)1;
	cout << a << endl;

	queryParameter f;
	f = (queryParameter) (weight + flor + name); //МЕ апн
	f = (queryParameter) (weight | flor | name); //   апн
	cout << f << endl;

	cout << floor(4.23f);
	return 0;
}