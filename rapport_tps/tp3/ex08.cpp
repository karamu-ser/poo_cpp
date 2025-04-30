#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Forme
{
	public:
		virtual double calculerAire() const = 0;
		virtual void afficher() const = 0;
		virtual ~Forme() {}
};

class Rectangle : public Forme
{
	private:
		double longueur;
		double largeur;
		
	public:
		Rectangle(double l, double L) : longueur(l), largeur(L) {}
		
		double calculerAire() const override
		{
			return longueur * largeur;
		}
		
		void afficher() const override
		{
			cout << "Rectangle: longueur = " << longueur << ", largeur = " << largeur << endl;
		}
};

class Cercle : public Forme
{
	private:
		double rayon;
		
	public:
		Cercle(double r) : rayon(r) {}
		
		double calculerAire() const override
		{
			return M_PI * rayon * rayon;
		}
		
		void afficher() const override
		{
			cout << "Cercle: rayon = " << rayon << endl;
		}
};

class Triangle : public Forme
{
	private:
		double base;
		double hauteur;
		
	public:
		Triangle(double b, double h) : base(b), hauteur(h) {}
		
		double calculerAire() const override
		{
			return 0.5 * base * hauteur;
		}
		
		void afficher() const override
		{
			cout << "Triangle: base = " << base << ", hauteur = " << hauteur << endl;
		}
};

class GestionnaireFormes
{
	private:
		vector<Forme*> formes;
		
	public:
		~GestionnaireFormes()
		{
			// Libérer la mémoire
			for (Forme* forme : formes)
			{
				delete forme;
			}
		}
		
		void ajouterForme(Forme* forme)
		{
			formes.push_back(forme);
		}
		
		double calculerAireTotale() const
		{
			double aireTotale = 0.0;
			for (const Forme* forme : formes)
			{
				aireTotale += forme->calculerAire();
			}
			return aireTotale;
		}
		
		void afficherFormes() const
		{
			for (const Forme* forme : formes)
			{
				forme->afficher();
				cout << "Aire: " << forme->calculerAire() << endl;
			}
		}
};

int main() {
    GestionnaireFormes gestionnaire;
    int choix;
    
    do
	{
        cout << "\nMenu:" << endl;
        cout << "1. Ajouter un rectangle" << endl;
        cout << "2. Ajouter un cercle" << endl;
        cout << "3. Ajouter un triangle" << endl;
        cout << "4. Afficher toutes les formes" << endl;
        cout << "5. Calculer l'aire totale" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix: ";
        cin >> choix;
        
        switch (choix)
		{
            case 1:
			{
                double longueur, largeur;
                cout << "Entrez la longueur: ";
                cin >> longueur;
                cout << "Entrez la largeur: ";
                cin >> largeur;
                gestionnaire.ajouterForme(new Rectangle(longueur, largeur));
                break;
            }
            case 2:
			{
                double rayon;
                cout << "Entrez le rayon: ";
                cin >> rayon;
                gestionnaire.ajouterForme(new Cercle(rayon));
                break;
            }
            case 3:
			{
                double base, hauteur;
                cout << "Entrez la base: ";
                cin >> base;
                cout << "Entrez la hauteur: ";
                cin >> hauteur;
                gestionnaire.ajouterForme(new Triangle(base, hauteur));
                break;
            }
            case 4:
                cout << "\nListe des formes:" << endl;
                gestionnaire.afficherFormes();
                break;
            case 5:
                cout << "\nAire totale: " << gestionnaire.calculerAireTotale() << endl;
                break;
            case 0:
                cout << "Au revoir!" << endl;
                break;
            default:
                cout << "Choix invalide!" << endl;
        }
    }
	while (choix != 0);
    return 0;
}