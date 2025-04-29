#include <iostream>

using namespace std;

int main()
{
	int x;
	double long y; // pour handle jusqu'a 16bits
	int z;

	cout << "entrer un nombre entier : ";
	cin >> x;
	if (x < 0)
		cout << "Les factorielles des entiers négatifs ne peuvent pas être calculées" << endl;
	else if (x == 0 || x == 1)
		cout << "le factoriel de " << x << " est : " << "1" << endl;
	else
	{
		y = x;
		z = x;
		while (x != 1)
			y *= --x;
		cout << "le factoriel de " << z << " est : " << y << endl;
	}
	return 0;
}