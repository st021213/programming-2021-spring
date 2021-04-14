#include<iostream>

using namespace std;

class Human {
public:
	int age;
	string name;
	bool isMale;

	/*
	Human(int age = 3, string name = "Bob", bool isMale = false) :
		age(age), name(name), isMale(isMale) { }
	*/

	Human(int age, string name, bool isMale) :
		age(age), name(name), isMale(isMale) { }

	Human(int age, string name) :
		age(age), name(name), isMale(false) { }

	Human(int age) :
		age(age), name("Bob"), isMale(false) { }

	Human() :
		age(3), name("Bob"), isMale(false) { }
};

class Human1 {
public:
	int age;
	string name;
	bool isMale;

	/*
	Human(int age = 3, string name = "Bob", bool isMale = false) :
		age(age), name(name), isMale(isMale) { }
	*/

	Human1(int age, string name, bool isMale) :
		age(age), name(name), isMale(isMale) { }

	Human1(int age, string name) :
		Human1(age, name, false) { }

	Human1(int age) :
		Human1(age, "Bob", false) { }

	Human1() :
		Human1(3, "Bob", false) { }
};

class Human2 {
public:
	int age;
	string name;
	bool isMale;

	/*
	Human(int age = 3, string name = "Bob", bool isMale = false) :
		age(age), name(name), isMale(isMale) { }
	*/

	Human2(int age, string name, bool isMale) :
		age(age), name(name), isMale(isMale) { }

	Human2(int age, string name) :
		Human2(age, name, false) { }

	Human2(int age) :
		Human2(age, "Bob") { }

	Human2() :
		Human2(3) { }
};

int main()
{
	Human human;
	Human1 human1;
	Human2 human2;
	return 0;
}