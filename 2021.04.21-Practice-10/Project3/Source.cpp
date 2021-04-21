#include<iostream>

using namespace std;

class MasterBanana {
private:
	static MasterBanana* instance;
	MasterBanana(int count = 0)
	{
		this->count = count;
	}
	MasterBanana(const MasterBanana&);
	MasterBanana& operator= (MasterBanana&);
public:
	int count = 0;
	static MasterBanana* getInstance()
	{
		++instance->count;
		return instance;
	}
};

MasterBanana* MasterBanana::instance = 0;

int main()
{

	return 0;
}