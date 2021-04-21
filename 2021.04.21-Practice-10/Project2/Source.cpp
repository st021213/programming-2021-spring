#include<iostream>

using namespace std;

class Student {
private:
	int id;

public:
	static int count;
	Student(int id = 0) : id(id)
	{
		count = id + 1;
		cout << count;
	}
};

int Student::count = 0;

int main()
{
	Student s1(42), s2(543), s3(212);
	cout << Student::count << endl;
	cout << s1.count << endl;
	return 0;
}