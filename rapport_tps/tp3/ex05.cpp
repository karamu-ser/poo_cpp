#include <iostream>
#include <cmath>
using namespace std;

class Forme
{
	public:
		virtual double calculerAire() const = 0; // fonction virtuelle pure
};

class Rectangle : public Forme {
	private:
		double longueur;
		double largeur;
		
	public:
		Rectangle(double l, double L) : longueur(l), largeur(L) {}
		
		double calculerAire() const override {
			return longueur * largeur;
		}
};

class Cercle : public Forme
{
	private:
		double rayon;
		
	public:
		Cercle(double r) : rayon(r) {}
		
		double calculerAire() const override {
			return M_PI * rayon * rayon;
		}
};

class Triangle : public Forme
{
	private:
		double base;
		double hauteur;
		
	public:
		Triangle(double b, double h) : base(b), hauteur(h) {}
		
		double calculerAire() const override {
			return 0.5 * base * hauteur;
		}
};

int main()
{
    Rectangle rect(5, 4);
    Cercle cercle(3);
    Triangle triangle(6, 8);
    cout << "Aire du rectangle: " << rect.calculerAire() << endl;
    cout << "Aire du cercle: " << cercle.calculerAire() << endl;
    cout << "Aire du triangle: " << triangle.calculerAire() << endl;
    return 0;
}