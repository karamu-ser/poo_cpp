#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Professeur
{
	protected:
		string nom;
		double salaireBase;
		vector<string> matieres;
		
	public:
		Professeur(string n, double s) : nom(n), salaireBase(s) {}
		
		virtual ~Professeur() {}
		
		virtual double getSalaire() const = 0; // Méthode virtuelle pure
		
		virtual void afficherDetails() const
		{
			cout << "Nom: " << nom << endl;
			cout << "Salaire de base: " << salaireBase << " dhs" << endl;
			afficherMatieres();
		}
		
		void ajouterMatiere(const string& matiere)
		{
			matieres.push_back(matiere);
		}
		
		void afficherMatieres() const
		{
			cout << "Matieres enseignees: ";
			if (matieres.empty()) {
				cout << "Aucune";
			} else {
				for (size_t i = 0; i < matieres.size(); ++i)
				{
					cout << matieres[i];
					if (i < matieres.size() - 1)
					{
						cout << ", ";
					}
				}
			}
			cout << endl;
		}
};

class ProfesseurPermanent : public Professeur
{
	private:
		int heuresMaximales;
		
	public:
		ProfesseurPermanent(string n, double s, int hMax) 
			: Professeur(n, s), heuresMaximales(hMax) {}
		
		double getSalaire() const override
		{
			return salaireBase;
		}
		
		void afficherDetails() const override
		{
			cout << "Type: Professeur Permanent" << endl;
			Professeur::afficherDetails();
			cout << "Heures maximales d'enseignement: " << heuresMaximales << " heures" << endl;
			cout << "Salaire total: " << getSalaire() << " dhs" << endl;
		}
};

class ProfesseurVacataire : public Professeur
{
	private:
		int heuresEnseignees;
		double tarifHoraire;
		
	public:
		ProfesseurVacataire(string n, double s, int h, double tH) 
			: Professeur(n, s), heuresEnseignees(h), tarifHoraire(tH) {}
		
		double getSalaire() const override
		{
			return salaireBase + (heuresEnseignees * tarifHoraire);
		}
		
		void afficherDetails() const override
		{
			cout << "Type: Professeur Vacataire" << endl;
			Professeur::afficherDetails();
			cout << "Heures enseignees: " << heuresEnseignees << " heures" << endl;
			cout << "Tarif horaire: " << tarifHoraire << " dhs" << endl;
			cout << "Salaire total: " << getSalaire() << " dhs" << endl;
		}
};

int main()
{
    const int nbProfs = 4;
    Professeur* professeurs[nbProfs];

    professeurs[0] = new ProfesseurPermanent("omar", 30000, 192);
    professeurs[1] = new ProfesseurPermanent("amin", 3500, 160);
    professeurs[2] = new ProfesseurVacataire("farid", 5000, 60, 40);
    professeurs[3] = new ProfesseurVacataire("fatiha", 6000, 45, 45);
    professeurs[0]->ajouterMatiere("Mathematiques");
    professeurs[0]->ajouterMatiere("Informatique");
    professeurs[1]->ajouterMatiere("Physique");
    professeurs[2]->ajouterMatiere("Programmation C++");
    professeurs[2]->ajouterMatiere("Bases de donnees");
    professeurs[3]->ajouterMatiere("Anglais");
    for (int i = 0; i < nbProfs; ++i) {
        professeurs[i]->afficherDetails();
        cout << "------------------------------" << endl;
    }
    for (int i = 0; i < nbProfs; ++i)
        delete professeurs[i];
    return 0;
}