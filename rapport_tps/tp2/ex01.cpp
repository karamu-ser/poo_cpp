#include <iostream>

class Rectangle
{
	private:
		double longueur;
		double largeur;
	public:
		Rectangle(double l, double L) : longueur(l), largeur(L) {}

		// Rectangle(double l, double L) {
        // 	longueur = l;
        // 	largeur = L;
    	// }
	
		double surface()
		{
			return longueur * largeur;
		}
		double perimetre()
		{
			return 2 * (longueur + largeur);
		}
};

int main()
{
    Rectangle rect(5.0, 3.0);
    std::cout << "Surface: " << rect.surface() << std::endl;
    std::cout << "Périmètre: " << rect.perimetre() << std::endl;
    return 0;
}
