#include<iostream>

using namespace std;

class HumanData {
private:
	int age;
	string name;
	bool isMale;

public:
	HumanData(int age = 3, string name = "Bob", bool isMale = false) :
		age(age), name(name), isMale(isMale) { }

	int getAge() { return age; }
	void setAge(int age) { this->age = age; }
};

class Student{
private:
	HumanData human; //Student ИМЕЕТ(has) HumanData
	
public:
	string specialization;

	Student(string specialization = "math") :
		specialization(specialization) { }

	int getAge() { return human.getAge(); }

	void setAge(int age) { /*return*/ human.setAge(age); }
};

int main()
{
	return 0;
}