#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MembreUniversite{
	protected:
	    string nom;
	    string prenom;
	    string id;
	    
	public:
	    static int nbMembres;
	    
	    MembreUniversite(string n, string p, string i) 
	        : nom(n), prenom(p), id(i)
		{
       		nbMembres++;
	    }
	    
	    virtual void afficherInfos() const
		{
	        cout << "Membre: " << prenom << " " << nom 
	             << " - ID: " << id << endl;
	    }
	    
	    static int getNbMembres()
		{
	        return nbMembres;
	    }
	    
	    virtual ~MembreUniversite() {}
};

int MembreUniversite::nbMembres = 0;

class Etudiant : public MembreUniversite
{
	private:
	    string filiere;
	    int niveau;
	    
	public:
	    Etudiant(string n, string p, string i, string f, int niv) 
	        : MembreUniversite(n, p, i), filiere(f), niveau(niv) {}
	    
	    void afficherInfos() const override
		{
	        cout << "Etudiant: " << prenom << " " << nom 
	             << " - ID: " << id 
	             << " - Filiere: " << filiere 
	             << " - Niveau: " << niveau << endl;
	    }
};

class Enseignant : public MembreUniversite
{
	private:
	    string grade;
	    string departement;
	    
	public:
	    Enseignant(string n, string p, string i, string g, string d) 
	        : MembreUniversite(n, p, i), grade(g), departement(d) {}
	    
	    void afficherInfos() const override {
	        cout << "Enseignant: " << prenom << " " << nom 
	             << " - ID: " << id 
	             << " - Grade: " << grade 
	             << " - Departement: " << departement << endl;
	    }
};

int main()
{
    vector<MembreUniversite*> membres;
    
    membres.push_back(new Etudiant("El Amrani", "Salma", "E12345", "Informatique", 2));
    membres.push_back(new Enseignant("Bensouda", "Karim", "P00123", "Professeur", "Mathematiques"));
    membres.push_back(new Etudiant("Bouazizi", "Younes", "E54321", "Physique", 3));
    membres.push_back(new Enseignant("Chraibi", "Fatima", "P00456", "Maitre de conferences", "Informatique"));
    membres.push_back(new Etudiant("Douiri", "Hicham", "E67890", "Mathematiques", 1));
    cout << "---- Membres de l'universite ----" << endl;
    for (auto membre : membres)
        membre->afficherInfos();
    cout << "\n---- Statistiques ----" << endl;
    cout << "Nombre total de membres: " << MembreUniversite::getNbMembres() << endl;
    int nbEtudiants = 0;
    int nbEnseignants = 0;
    for (auto membre : membres) {
        if (dynamic_cast<Etudiant*>(membre)) {
            nbEtudiants++;
        } else if (dynamic_cast<Enseignant*>(membre)) {
            nbEnseignants++;
        }
    }
    cout << "Nombre d'etudiants: " << nbEtudiants << endl;
    cout << "Nombre d'enseignants: " << nbEnseignants << endl;
    for (auto membre : membres)
        delete membre;
    return 0;
}