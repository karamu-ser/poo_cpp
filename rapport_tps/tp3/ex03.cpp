#include <iostream>
#include <string>

using namespace std;

class Personne
{
    private:
        string nom;
    protected:
        void setNom(const string& n)
        {
            nom = n;
        }
        string getNom() const
        {
            return nom;
        }
};
class Etudiant : protected Personne
{
    public:
        void definirNomEtudiant(const string& n)
        {
            setNom(n);
        }
        void afficherNomEtudiant()
        {
            cout << "Nom de l'etudiant : " << getNom() << endl;
        }
};
class Professeur : private Personne
{
    public:
        void definirNomProfesseur(const string& n)
        {
            setNom(n);
        }
        void afficherNomProfesseur() {
            cout << "Nom du professeur : " << getNom() << endl;
        }
};
int main()
{
    Etudiant etudiant;
    etudiant.definirNomEtudiant("abderrahman karam");
    etudiant.afficherNomEtudiant();
    Professeur professeur;
    professeur.definirNomProfesseur("Ibtissam Bakkouri");
    professeur.afficherNomProfesseur();

    return 0;
}
