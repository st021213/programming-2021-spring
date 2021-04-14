#include<iostream>

using namespace std;

// 1. Класс всегда имеет доступ ко всем своим членам и методам
// 2. Доступ к члену или методу класса извне основывается на его модификаторе доступа
// 3. Доступ к наследованному члену или методу класса-наследника основывается на модификаторе доступа наследования
class Human {
public:
	int age;
	string name;
	bool isMale;

	Human(int age = 3, string name = "Bob", bool isMale = false) :
		age(age), name(name), isMale(isMale) { }
};

class Student : public /*private, protected*/ Human {
public:
	string spec;

	Student(string spec = "math") :
		Human(18, "Jane", false), //внутри инициализатора можно вызывать конструктор родительского класса
		spec(spec)
	{
	}

	Student(int age, string name, int isMale, string spec)
	{
		Human(age, name, isMale);
		this->spec = spec;
	}
};

// Родительский класс  дочерний класс(public)  дочерний класс(private)  дочерний класс(protected)
// public	             public                       private              protected
// private	             private                      private              private
// protected             protected                    private              protected

int main()
{
	//RAII - Resource Acquisition Is Initialization

	Human human;
	Student student;
	cout << human.name << endl;
	cout << student.name << endl;

	human = (Human)student;

	cout << human.name << endl;

	//student = (Student)human;



	return 0;
}