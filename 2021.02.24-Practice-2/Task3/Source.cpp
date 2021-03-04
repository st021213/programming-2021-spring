#include<iostream>

using namespace std;

// ravesli.com
//void main(void)
//int main(void)
//int main()
//void main()

int main(int argc, const char* argv[])
//int main(int argc, char** argv)
{
	argv[0] = "ban";
	for (int i = 0; i < argc; ++i)
	{
		cout << i << " " << argv[i] << endl;
	}
	return 0;
}