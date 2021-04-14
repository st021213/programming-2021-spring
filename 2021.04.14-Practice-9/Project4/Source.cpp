#include<iostream>

using namespace std;

class Human {
public:
	int age;
	string name;
	bool isMale;

	Human(int age = 3, string name = "Bob", bool isMale = false) :
		age(age), name(name), isMale(isMale)
	{
		this->age = age;
		this->name = name;
		this->isMale = isMale;
	}
};

class Student : public Human {
public:
	string spec;

	Student(string spec = "math") :
		Human(18, "Jane", false),
		spec(spec)
	{
	}

	Student(int age, string name, int isMale, string spec) :
		Human(age, name, isMale),
		spec(spec)
	{
	}

	Student(int age, string name, string spec) :
		Student(age, name, true, spec)
	{
		Student(age, name, true, spec);
	}
};

int main()
{
	Student student1;
	cout << student1.name << endl;

	Student student2(21, "Biba", true, "phil");
	cout << student2.name << endl;

	Student student3(21, "Biba", "phil");
	cout << student3.name << endl;


	return 0;
}