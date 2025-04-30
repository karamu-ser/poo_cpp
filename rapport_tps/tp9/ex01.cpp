#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CompteBancaire
{
	protected:
	    string titulaire;
	    double solde;
	    
	public:
	    static int compteurComptes;
	    
	    CompteBancaire(string tit, double sol = 0.0) : titulaire(tit), solde(sol)
		{
	        compteurComptes++;
	    }
	    void deposer(double montant) {
	        if (montant > 0) {
	            solde += montant;
	        }
	    }
	    bool retirer(double montant)
		{
	        if (montant > 0 && solde >= montant) {
	            solde -= montant;
	            return true;
	        }
	        return false;
	    }
	    virtual void afficher() const
		{
	        cout << "Compte de " << titulaire << " - Solde: " << solde << " DH" << endl;
	    }
	    static void afficherNombreComptes()
		{
	        cout << "Nombre total de comptes: " << compteurComptes << endl;
	    }
	    virtual ~CompteBancaire() {}
};

int CompteBancaire::compteurComptes = 0;

class CompteCourant : public CompteBancaire
{
	private:
	    double decouvertAutorise;
	    
	public:
	    CompteCourant(string tit, double sol = 0.0, double decouvert = 0.0) 
	        : CompteBancaire(tit, sol), decouvertAutorise(decouvert) {}
	    
	    bool retirer(double montant)
		{
	        if (montant > 0 && solde + decouvertAutorise >= montant) {
	            solde -= montant;
	            return true;
	        }
	        return false;
	    }
	    
	    void afficher() const override
		{
	        cout << "Compte courant de " << titulaire 
	             << " - Solde: " << solde << " DH"
	             << " - Decouvert autorise: " << decouvertAutorise << " DH" << endl;
	    }
};

class CompteEpargne : public CompteBancaire
{
	private:
	    double tauxInteret;
	    
	public:
	    CompteEpargne(string tit, double sol = 0.0, double taux = 0.0) 
	        : CompteBancaire(tit, sol), tauxInteret(taux) {}
	    void calculerInterets()
		{
	        double interets = solde * tauxInteret / 100;
	        solde += interets;
	    }
	    void afficher() const override
		{
	        cout << "Compte epargne de " << titulaire 
	             << " - Solde: " << solde << " DH"
	             << " - Taux d'interet: " << tauxInteret << "%" << endl;
	    }
};

int main() {
    vector<CompteBancaire*> comptes;
    comptes.push_back(new CompteBancaire("Hassan", 1000));
    comptes.push_back(new CompteCourant("Sara", 2000, 500));
    comptes.push_back(new CompteEpargne("Karim", 5000, 2.5));
    comptes.push_back(new CompteCourant("Fatima", 1500, 200));
    comptes.push_back(new CompteEpargne("Youssef", 10000, 3.0));
    cout << "---- Liste des comptes bancaires ----" << endl;
    for (auto compte : comptes) 
        compte->afficher();
    CompteEpargne* compteEp = dynamic_cast<CompteEpargne*>(comptes[2]);
    if (compteEp) 
	{
        cout << "\nCalcul des interets pour le compte epargne de Karim:" << endl;
        compteEp->calculerInterets();
        compteEp->afficher();
    }
    CompteCourant* compteCou = dynamic_cast<CompteCourant*>(comptes[1]);
    if (compteCou) 
	{
        cout << "\nRetrait de 2400 DH du compte courant de Sara:" << endl;
        if (compteCou->retirer(2400)) 
		{
            cout << "Retrait effectue avec succes" << endl;
        } 
		else 
		{
            cout << "Retrait impossible, solde insuffisant" << endl;
        }
        compteCou->afficher();
    }
    cout << "\n---- Statistiques ----" << endl;
    CompteBancaire::afficherNombreComptes();
    for (auto compte : comptes)
        delete compte;
    return 0;
}