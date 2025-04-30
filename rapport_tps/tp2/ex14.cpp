#include <iostream>
#include <vector>

class Forme
{
    public:
        virtual void afficher();
        virtual ~Forme() {}
};
class Cercle : public Forme
{
    private:
        double rayon;
    public:
        Cercle(double r) : rayon(r) {}
        void afficher() {
            std::cout << "Cercle de rayon " << rayon << std::endl;
        }
};
class Rectangle : public Forme
{
    private:
        double largeur, hauteur;
    public:
        Rectangle(double l, double h) : largeur(l), hauteur(h) {}
        void afficher() {
            std::cout << "Rectangle de largeur " << largeur << " et hauteur " << hauteur << std::endl;
        }
};

int main()
{
    std::vector<Forme*> formes;
    formes.push_back(new Cercle(5.0));
    formes.push_back(new Rectangle(4.0, 6.0));
    for (const auto& forme : formes)
        forme->afficher();
    for (auto& forme : formes)
        delete forme;
    return 0;
}