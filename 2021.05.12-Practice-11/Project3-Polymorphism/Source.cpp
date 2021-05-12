#include<iostream>
#include<cstdlib>

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
		return "VOICE OF FAT ANIMAL";
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

class Cat : public Animal
{
public:
	Cat(string name = "Murzik") : Animal("(Cat)" + name) {}
	Cat(const Cat& cat) : Animal(cat) {}
	void setName(string name)
	{
		Animal::setName("(Cat)" + name);
	}
	virtual string voice()
	{
		return "MEW";
	}
};

class Lion : public Animal
{
public:
	Lion(string name = "Simba") : Animal("(Lion)" + name) {}
	Lion(const Lion& lion) : Animal(lion) {}
	void setName(string name)
	{
		Animal::setName("(Lion)" + name);
	}
	virtual string voice()
	{
		return "ROAR";
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
	
	cout << "ARRAY OF ANIMALS" << endl;
	Animal* animals[10] = {0};
	for(int i = 0; i < 10; ++i)
	{
		switch (rand()%3)
		{
			case 0:
				animals[i] = new Dog();
				break;
			case 1:
				animals[i] = new Cat();
				break;
			case 2:
				animals[i] = new Lion();
				break;
		}
	}
	
	for(int i = 0; i < 10; ++i)
	{
		cout << animals[i]->getName() << ":" << animals[i]->voice() << endl;
	}


	return 0;
}
