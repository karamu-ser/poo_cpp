#include <iostream>

using namespace std;

int ifprime(int x)
{
	float i;
	
	if (x == 1 || x == 0)
		return 0;
	for (int y{x - 1}; y != 1; y--)
	{
		i = x % y;
		if (i == (float)0)
			return 0;
	}
	return 1;
}

int main()
{
	int s{0};

	for (int x{1}; x <= 100; x++)
		if (ifprime(x))
			s += x;
	cout << "la somme de tous les nombres primes de 1 à 100 est : " << s << endl;
	return 0;
}