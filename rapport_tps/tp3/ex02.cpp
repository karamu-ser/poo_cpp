#include <iostream>
#include <cmath>
using namespace std;


class Forme {
public:
    virtual double calculerAire() const = 0;
};
class Rectangle : public Forme {
private:
    double largeur, hauteur;
public:
    Rectangle(double l, double h) : largeur(l), hauteur(h) {}
    double calculerAire() const override {
        return largeur * hauteur;
    }
};

class Cercle : public Forme {
private:
    double rayon;
public:
    Cercle(double r) : rayon(r) {}
    double calculerAire() const override {
        return M_PI * rayon * rayon;
    }
};

class Triangle : public Forme {
private:
    double base, hauteur;
public:
    Triangle(double b, double h) : base(b), hauteur(h) {}
    double calculerAire() const override {
        return (base * hauteur) / 2.0;
    }
};
int main() {
    Forme* formes[3];

    formes[0] = new Rectangle(4.0, 5.0);
    formes[1] = new Cercle(3.0);
    formes[2] = new Triangle(6.0, 4.0);

    for (int i = 0; i < 3; ++i) {
        cout << "L'aire de la forme est : " << formes[i]->calculerAire() << endl;
        delete formes[i];
    }
    return 0;
}
