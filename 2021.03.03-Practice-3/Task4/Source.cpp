#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	while (!fin.eof()) //до тех пор пока файл не закончился
	{
		string str;
		fin >> str;
		cout << str;
		fout << str;
		system("pause");
	}
	fout.close();
	system("pause");
	system("pause");
	system("pause");
	fin.close();
	return 0;
}