#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CarteBancaire
{
	protected:
	    string numero;
	    string titulaire;
	    double solde;
	    
	public:
	    static int nbCartes;
	    
	    CarteBancaire(string num, string tit, double sol = 0.0) 
	        : numero(num), titulaire(tit), solde(sol) {
	        nbCartes++;
	    }
	    
	    virtual void afficherInfo() const {
	        cout << "Carte bancaire n° " << numero 
	             << " - Titulaire: " << titulaire 
	             << " - Solde: " << solde << " DH" << endl;
	    }
	    
	    static void afficherNombreCartes() {
	        cout << "Nombre total de cartes bancaires: " << nbCartes << endl;
	    }
	    
	    virtual ~CarteBancaire() {}
};

int CarteBancaire::nbCartes = 0;

class CarteCredit : public CarteBancaire
{
	private:
	    double plafondCredit;
	    double creditUtilise;
	    
	public:
	    CarteCredit(string num, string tit, double sol, double plafond) 
	        : CarteBancaire(num, tit, sol), plafondCredit(plafond), creditUtilise(0.0) {}
	    
	    bool utiliserCredit(double montant)
		{
	        if (montant > 0 && creditUtilise + montant <= plafondCredit) {
	            creditUtilise += montant;
	            return true;
	        }
	        return false;
	    }
	    
	    void afficherInfo() const override
		{
	        cout << "Carte de credit n° " << numero 
	             << " - Titulaire: " << titulaire 
	             << " - Solde: " << solde << " DH"
	             << " - Plafond: " << plafondCredit << " DH"
	             << " - Credit utilise: " << creditUtilise << " DH" << endl;
	    }
};

class CarteDebit : public CarteBancaire
{
	private:
	    string compteLie;
	    
	public:
	    CarteDebit(string num, string tit, double sol, string compte) 
	        : CarteBancaire(num, tit, sol), compteLie(compte) {}
	    
	    void afficherInfo() const override
		{
	        cout << "Carte de debit n° " << numero 
	             << " - Titulaire: " << titulaire 
	             << " - Solde: " << solde << " DH"
	             << " - Compte lie: " << compteLie << endl;
	    }
};

int main() {
    vector<CarteBancaire*> portefeuille;
    
    portefeuille.push_back(new CarteBancaire("1111-2222-3333-4444", "Ahmed Hassan"));
    portefeuille.push_back(new CarteCredit("5555-6666-7777-8888", "Laila Benani", 1500, 5000));
    portefeuille.push_back(new CarteDebit("9999-0000-1111-2222", "Omar Idrissi", 2000, "MAD12345"));
    cout << "---- Portefeuille de cartes bancaires ----" << endl;
    for (auto carte : portefeuille)
        carte->afficherInfo();
    CarteCredit* carteCredit = dynamic_cast<CarteCredit*>(portefeuille[1]);
    if (carteCredit) {
        cout << "\nUtilisation du credit pour la carte de Laila Benani:" << endl;
        if (carteCredit->utiliserCredit(2000))
		
            cout << "Credit de 2000 DH utilise avec succes" << endl;
		else
            cout << "Utilisation du credit impossible, plafond depasse" << endl;
        carteCredit->afficherInfo();
    }
    cout << "\n---- Statistiques ----" << endl;
    CarteBancaire::afficherNombreCartes();
    for (auto carte : portefeuille)
        delete carte;
    return 0;
}