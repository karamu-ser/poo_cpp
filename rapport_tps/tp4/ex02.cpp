#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Produit
{
private:
    string nom;
    T prix;
    
public:
    Produit(string n, T p) : nom(n), prix(p) {}
    
    void afficher() {
        cout << "Nom: " << nom << endl;
        cout << "Prix: " << prix << endl;
    }
};

int main()
{
    Produit<int> p1("Livre", 25);
    cout << "Produit avec prix entier:" << endl;
    p1.afficher();
    cout << endl;
    
    Produit<double> p2("Ordinateur", 899.99);
    cout << "Produit avec prix decimal:" << endl;
    p2.afficher();
    
    return 0;
}