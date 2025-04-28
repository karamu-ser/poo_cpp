#include <iostream>

using namespace std;

namespace a{
	int sum(int a, int b)
	{
		return a + b;
	}
}

namespace b{
	int sum(int a, int b)
	{
		return a + b + a;
	}
}

int main()
{
	sum(1, 1);
}