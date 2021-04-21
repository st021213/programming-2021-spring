#include<iostream>

namespace Banana {
	int count;
}

namespace Barabana {
	int count;
}

int main()
{
	int count = 4;
	Banana::count = 123;
	Barabana::count = 432;

	std::cout << count + Banana::count + Barabana::count << std::endl;

	return 0;
}