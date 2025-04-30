#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    string str;
    
    cout << "Entrez un nombre entier: ";
    cin >> str;
    
    try
	{
        int nombre = stoi(str);
        cout << "Conversion reussie: " << nombre << endl;
    }
	catch (const invalid_argument& e)
	{
        cout << "Erreur: Impossible de convertir en entier" << endl;
    }
	catch (const out_of_range& e)
	{
        cout << "Erreur: Nombre trop grand pour un entier" << endl;
    }
    
    return 0;
}