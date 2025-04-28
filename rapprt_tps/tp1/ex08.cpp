#include <iostream>

using namespace std;

inline float moyen(float *tab, int size)
{
	float s{0};
	for (int i{0}; i < size; i++)
		s += tab[i];
	return s / size;
}

int main()
{
	int size;
	cout << "entrer le size du tableau : ";
	cin >> size;
	float *tab;
	tab = new float[size];
	for (int i{0}; i < size; i++)
	{
		cout << "entrer nombre du " << i + 1 << " casse : ";
		cin >> tab[i];
	}
	cout << "la moyenne est : " << moyen(tab, size) << endl;
	delete (tab);
	return 0;
}