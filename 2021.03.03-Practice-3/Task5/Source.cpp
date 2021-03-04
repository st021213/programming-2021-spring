#include<iostream>
#include<string>
using namespace std;
int main(int argc, char* argv[])
{
	int a = stoi(argv[2]);
	double d = stod(argv[4]);
	cout << a << " + " << " = " << a + d << endl;
	for (int i = 0; i < argc; ++i)
	{
		cout << i << " " << argv[i] << endl;
		cout << argv[i][0] << endl;
	} 
}