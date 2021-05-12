#include<iostream>

using namespace std;

class Animal
{
private:
	string name;

public:
	Animal(string name = "Animal") : name(name) {}

	Animal(const Animal& animal) : name(animal.name) {}

	~Animal() {}

	string getName()
	{
		return name;
	}

	void setName(string name)
	{
		this->name = name;
	}

	virtual string voice()
	{
		return "VOICE OF ANIMAL";
	}
};

class Dog : public Animal
{
public:
	Dog(string name = "Bobik") : Animal("(Dog)" + name) {}
	Dog(const Dog& dog) : Animal(dog) {}
	void setName(string name)
	{
		Animal::setName("(Dog)" + name);
	}
	virtual string voice()
	{
		return "BARK";
	}
};

int main()
{
	Dog dog1("Bobik");
	Dog dog2("Barbos");
	cout << dog1.voice() << endl;
	cout << dog2.voice() << endl;
	Animal animal;
	cout << animal.getName() << ":" << animal.voice() << endl;
	animal = dog1;
	cout << dog1.getName() << ":" << animal.voice() << endl;

	Animal* panimal = new Animal();
	cout << panimal->getName() << ":" << panimal->voice() << endl;
	delete panimal;

	panimal = new Dog("Bobik");
	cout << panimal->getName() << ":" << panimal->voice() << endl;

	return 0;
}
