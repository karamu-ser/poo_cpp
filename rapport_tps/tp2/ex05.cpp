#include <iostream>

using namespace std;

class voiture
{
	private:
		string marque;
	protected:
		string modele;
	public:
		string couleur;
		voiture (string MA, string MO, string C) : marque(MA), modele(MO), couleur(C) {};
		void affiche_ma()
		{
			cout << "la marque est : " << marque << endl;
		}
		void affiche_co()
		{
			cout << "couleur est : " << couleur << endl;
		}
};

class voi : public voiture
{
	public :
		voi(string MA, string MO, string C) : voiture(MA, MO, C) {}
		void affiche_mo()
		{
			cout << "modele est : " << modele << endl;
		}
};

int main() {
    voi voitur("Dacia", "Logan", "Noir");
    voitur.affiche_ma();
    voitur.affiche_mo(); 
    voitur.affiche_co();
    return 0;
}
