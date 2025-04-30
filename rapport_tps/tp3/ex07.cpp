#include <iostream>
#include <cmath>
using namespace std;

class FigureGeometrique
{
public:
    virtual double calculerAire() const = 0;
    virtual double calculerPerimetre() const = 0;
    virtual ~FigureGeometrique() {}
};

class Rectangle : public FigureGeometrique
{
	private:
		double longueur;
		double largeur;
		
	public:
		Rectangle(double l, double L) : longueur(l), largeur(L) {}
		
		double calculerAire() const override {
			return longueur * largeur;
		}
		
		double calculerPerimetre() const override {
			return 2 * (longueur + largeur);
		}
};

class Cercle : public FigureGeometrique
{
	private:
		double rayon;
		
	public:
		Cercle(double r) : rayon(r) {}
		
		double calculerAire() const override {
			return M_PI * rayon * rayon;
		}
		
		double calculerPerimetre() const override {
			return 2 * M_PI * rayon;
		}
};

class Triangle : public FigureGeometrique
{
	private:
		double cote1, cote2, cote3;
		
	public:
		Triangle(double c1, double c2, double c3) : cote1(c1), cote2(c2), cote3(c3) {}
		
		double calculerAire() const override {
			// Formule de Héron
			double s = (cote1 + cote2 + cote3) / 2;
			return sqrt(s * (s - cote1) * (s - cote2) * (s - cote3));
		}
		
		double calculerPerimetre() const override {
			return cote1 + cote2 + cote3;
		}
};

void afficherDetails(const FigureGeometrique* figure)
{
    cout << "Aire: " << figure->calculerAire() << endl;
    cout << "Perimetre: " << figure->calculerPerimetre() << endl;
}

int main()
{
    Rectangle rect(5, 4);
    Cercle cercle(3);
    Triangle triangle(3, 4, 5);
    cout << "Rectangle:" << endl;
    afficherDetails(&rect);
    cout << endl;
    cout << "Cercle:" << endl;
    afficherDetails(&cercle);
    cout << endl;
    cout << "Triangle:" << endl;
    afficherDetails(&triangle);
    return 0;
}