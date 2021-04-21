#include<iostream>
#include<fstream>

using namespace std;

class Singleton
{
private:
	static Singleton* instance;
	Singleton() {};
	Singleton(const Singleton&) {};
	Singleton& operator=(Singleton&) {};

public:
	static Singleton* getInstance()
	{
		if (instance == 0)
		{
			instance = new Singleton();
		}
		return instance;
	}
	int count = 0;
	void init()
	{
		ifstream fin("1.txt");
		if (fin)
		{
			fin >> count;
		}
		fin.close();
	}
	void dispose()
	{

	}
};

Singleton* Singleton::instance = 0;

void banana()
{
	Singleton::getInstance()->count++;
}

void ban()
{
	Singleton::getInstance()->count+=10;
}

int main()
{
	Singleton::getInstance()->count = 5;
	Singleton::getInstance()->init();

	ban();
	banana();
	ban();
	ban();
	cout <<	Singleton::getInstance()->count++;

	Singleton::getInstance()->dispose();
	return 0;
}