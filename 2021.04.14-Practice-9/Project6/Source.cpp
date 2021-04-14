#include<iostream>

using namespace std;

class Human {
public:
	string name;
	int age;

	Human(string name = "Bob", int age = 3) :name(name), age(age) { }
};

class Student : public Human{
public:
	string name;
	Student(string name = "Jane") : Human("Bill", 5), name(name) { }
};

int main()
{
	Human human;
	cout << human.name << " " << human.age << endl;

	Student student;
	cout << student.name << " " << student.age << endl;

	human = student;
	cout << human.name << " " << human.age << endl;

	((Human)student).name = "Banana";
	human = student;
	cout << human.name << " " << human.age << endl;
	cout << student.name << " " << student.age << endl << endl;

	student.Human::name = "Banana";
	human = student;
	cout << human.name << " " << human.age << endl;
	cout << student.name << " " << student.age << endl << endl;

	return 0;
}