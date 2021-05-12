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
};

class Dog : public Animal
{
public:
	Dog(string name = "Bobik") : Animal("Dog: " + name) {}
	Dog(const Dog& dog) : Animal(dog) {}
	void setName(string name)
	{
		Animal::setName("Dog: " + name);
	}
	//если очень хочется, то можно научить его присваивать себе Animal
	Dog& operator=(Animal& animal)
	{
		setName(animal.getName());
		return (*this);
	}
};

int main()
{
	Dog dog;
	cout << dog.getName() << endl;
	dog.setName("Banana");
	cout << dog.getName() << endl;
		
	Animal animal1;
	cout << animal1.getName() << endl;
	animal1 = dog;
	cout << animal1.getName() << endl;

	dog = animal1;
	cout << dog.getName() << endl;

	animal1.setName("Animal1");
	cout << animal1.getName() << endl;


	cout << "Animal pointer work" << endl;
	Animal* animal = new Dog();
	cout << animal->getName() << endl;
	animal->setName("Animal pointer");
	cout << animal->getName() << endl;
	delete animal;

	return 0;
}