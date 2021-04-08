#include<iostream>

using namespace std;
//Объектно-Ориентированное Программирование
//Наследование

class Animal
{
private:
	string name;

protected:
	int age;

public:
	int getAge() { return age; }
	void setAge(int age) { this->age = age; }
	string getName() { return name; }
	void setName(string name) { this->name = name; }
};

struct Banana
{
	int count;
	char banana;
};

struct Cat : Animal, Banana //да, так сделать можно, но так делать не стоит
{
	int color;
	void Meow()
	{
		cout << "Mew" << endl;
	}
};

class Bird {
private:
	Animal animal;
	
public:
	string getName()
	{
		return animal.getName();
	}
};

struct Dog : Animal
{
	int size;
	int color;
	void Bark()
	{
		cout << getName() << " " << age << endl;
		cout << "Bark" << endl;
	}
};

int main()
{
	Animal animal;
	Cat cat;
	Dog dog;
	cout << sizeof(Animal) << endl;
	cout << sizeof(Cat) << endl;
	cout << sizeof(Dog) << endl;

	return 0;
}