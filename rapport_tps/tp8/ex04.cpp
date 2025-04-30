#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Forme
{
	public:
		virtual void afficher()
		{
			cout << "Je suis une forme" << endl;
		}
		virtual ~Forme() {}
};

class Cercle : public Forme 
{
	private:
		double rayon;
	public:
		Cercle(double r) : rayon(r) {}
		void afficher() override
		{
			cout << "Je suis un cercle de rayon " << rayon << endl;
		}
};

class Rectangle : public Forme
{
	private:
		double largeur;
		double hauteur;
	public:
		Rectangle(double l, double h) : largeur(l), hauteur(h) {}
		void afficher() override
		{
			cout << "Je suis un rectangle de dimensions " << largeur << "x" << hauteur << endl;
		}
};

int main()
{
    vector<Forme*> formes;
    formes.push_back(new Forme());
    formes.push_back(new Cercle(5.0));
    formes.push_back(new Rectangle(4.0, 3.0));
    for (auto forme : formes)
        forme->afficher();
    for (auto forme : formes)
        delete forme;
    return 0;
}