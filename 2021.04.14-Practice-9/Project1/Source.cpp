#include<iostream>

using namespace std;

class Human {
public:
	int age;
	string name;
	bool isMale;

	Human(int age = 3, string name = "Bob", bool isMale = false) :
		age(age), name(name), isMale(isMale) { }
};

class Student : Human { //Student ЯВЛЯЕТСЯ(is a) Human 
public:
	string specialization;

	Student(string specialization = "math") : 
		specialization(specialization) { }
};

int main()
{
	return 0;
}