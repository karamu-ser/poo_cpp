#include <iostream>
#include <new>
using namespace std;

int main()
{
    int taille;
    
    cout << "Entrez la taille du tableau: ";
    cin >> taille;
    
    try
	{
        int* tableau = new int[taille];
        cout << "Allocation reussie pour " << taille << " entiers" << endl;
        delete[] tableau;
    }
	catch (const bad_alloc& e)
	{
        cout << "Erreur: Allocation de memoire impossible" << endl;
    }
    return 0;
}