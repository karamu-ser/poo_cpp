#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    int tableau[5] = {10, 20, 30, 40, 50};
    int index;
    
    cout << "Entrez un index (0-4): ";
    cin >> index;
    
    try
	{
        if (index < 0 || index >= 5)
		{
            throw out_of_range("Index hors limites");
        }
        cout << "Valeur a l'index " << index << ": " << tableau[index] << endl;
    }
	catch (const out_of_range& e)
	{
        cout << "Erreur: " << e.what() << endl;
    }
    
    return 0;
}