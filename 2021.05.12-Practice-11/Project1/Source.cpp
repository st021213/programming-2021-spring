#include<iostream>

using namespace std;

class Animal
{
private:
	string name;

public:
	Animal(string name = "Animal") : name(name) {}
	
	Animal(const Animal& animal) : name(animal.name) {}

	~Animal(){}

	string getName()
	{
		return name;
	}

	void setName(string name)
	{
		this->name = name;
	}
};

int main()
{
	Animal dog("Dog");
	Animal dog1(dog);
	dog1.setName(dog.getName() + "1");
	cout << dog1.getName();
	return 0;
}