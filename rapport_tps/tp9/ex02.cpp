#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Professeur
{
	protected:
	    string nom;
	    string prenom;
	    string matricule;
	    
	public:
	    static int nombreProfesseurs;
	    
	    Professeur(string n, string p, string mat) 
	        : nom(n), prenom(p), matricule(mat)
		{
        nombreProfesseurs++;
    	}
	    
	    virtual void afficher() const
		{
	        cout << "Professeur: " << prenom << " " << nom 
	             << " - Matricule: " << matricule << endl;
	    }
	    
	    static void afficherNombreProfesseurs()
		{
	        cout << "Nombre total de professeurs: " << nombreProfesseurs << endl;
	    }
	    
	    virtual ~Professeur() {}
};

int Professeur::nombreProfesseurs = 0;

class ProfesseurPermanent : public Professeur
{
	private:
	    double salaireFixe;
	    
	public:
	    ProfesseurPermanent(string n, string p, string mat, double salaire) 
	        : Professeur(n, p, mat), salaireFixe(salaire) {}
	    
	    void afficher() const override 
		{
	        cout << "Professeur permanent: " << prenom << " " << nom 
	             << " - Matricule: " << matricule 
	             << " - Salaire fixe: " << salaireFixe << " DH" << endl;
	    }
};

class ProfesseurVacataire : public Professeur
{
	private:
	    int nombreHeures;
	    double tarifHoraire;
	    
	public:
	    ProfesseurVacataire(string n, string p, string mat, int heures, double tarif) 
	        : Professeur(n, p, mat), nombreHeures(heures), tarifHoraire(tarif) {}
	    
	    double calculerSalaire() const {
	        return nombreHeures * tarifHoraire;
	    }
	    
	    void afficher() const override {
	        cout << "Professeur vacataire: " << prenom << " " << nom 
	             << " - Matricule: " << matricule 
	             << " - Heures: " << nombreHeures 
	             << " - Tarif horaire: " << tarifHoraire << " DH"
	             << " - Salaire total: " << calculerSalaire() << " DH" << endl;
	    }
};

int main()
{
    vector<Professeur*> professeurs;
    professeurs.push_back(new ProfesseurPermanent("Alaoui", "Mohammed", "P001", 15000));
    professeurs.push_back(new ProfesseurVacataire("Benani", "Samira", "V001", 45, 200));
    professeurs.push_back(new ProfesseurPermanent("Idrissi", "Karim", "P002", 20000));
    professeurs.push_back(new ProfesseurVacataire("Saidi", "Fatima", "V002", 30, 250));
    cout << "---- Liste des professeurs ----" << endl;
    for (auto prof : professeurs)
        prof->afficher();
    cout << "\n---- Statistiques ----" << endl;
    Professeur::afficherNombreProfesseurs();
    for (auto prof : professeurs)
        delete prof;
    return 0;
}