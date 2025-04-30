#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Produit
{
	protected:
		string nom;
		
	public:
		Produit(string n) : nom(n) {}
		
		virtual void afficher() const {
			cout << "Produit: " << nom << endl;
		}
		
		virtual ~Produit() {}
};

class ProduitElectronique : public Produit
{
	private:
		int garantie;
		
	public:
		ProduitElectronique(string n, int g) : Produit(n), garantie(g) {}
		
		void afficher() const override {
			cout << "Produit electronique: " << nom << ", Garantie: " << garantie << " mois" << endl;
		}
};

class ProduitAlimentaire : public Produit
{
	private:
		string dateExpiration;
		
	public:
		ProduitAlimentaire(string n, string date) : Produit(n), dateExpiration(date) {}
		
		void afficher() const override
		{
			cout << "Produit alimentaire: " << nom << ", Date d'expiration: " << dateExpiration << endl;
		}
};

int main()
{
    vector<Produit*> produits;
    produits.push_back(new ProduitElectronique("Ordinateur", 24));
    produits.push_back(new ProduitAlimentaire("Yaourt", "15/05/2025"));
    produits.push_back(new ProduitElectronique("Telephone", 12));
    produits.push_back(new ProduitAlimentaire("Pain", "02/05/2025"));
    cout << "Liste des produits:" << endl;
    for (Produit* p : produits)
        p->afficher();
    for (Produit* p : produits)
        delete p;
    return 0;
}