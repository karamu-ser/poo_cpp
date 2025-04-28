#include <iostream>

using namespace std;

int main()
{
	int s{0};
	for (int x{1}; x <= 100; x++)
		if ( !(x % 2))
			s += x;
	cout << "la somme de tous les nombres pairs de 1 à 100 est : " << s << endl;
	return 0;
}
