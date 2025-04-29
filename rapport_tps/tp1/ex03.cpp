#include <iostream>

using namespace std;

int main()
{
	int x;

	cout << "entrer un nombre entier : ";
	cin >> x;
	for (int y{1}; y <= 10; y++)
		cout << x << " * " << y << " = " << x * y << endl;
	return 0;
}