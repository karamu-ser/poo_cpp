#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nombres = {10, 20, 30, 40, 50};
    int elementRecherche;
    cout << "Elements du vector: ";
    for (int n : nombres)
        cout << n << " ";
    cout << endl;
    cout << "Entrez l'element a rechercher: ";
    cin >> elementRecherche;
    auto resultat = find(nombres.begin(), nombres.end(), elementRecherche);
    if (resultat != nombres.end()) {
        cout << "Element " << elementRecherche << " trouve a la position ";
        cout << resultat - nombres.begin() << endl;
    }
	else
        cout << "Element " << elementRecherche << " non trouve" << endl;
    return 0;
}