#include <iostream>

using namespace std;

class Compteur
{
	private:
		static int nombreInstances;
	public:
		Compteur() {
			nombreInstances++;
		}

		static void aff_NombreInstances() {
			cout << "Le nombre d'instances est : " << nombreInstances << endl;
		}
};

int Compteur::nombreInstances = 0;

int main()
{
    Compteur c, c2;
    c.aff_NombreInstances();
	Compteur c3;
    c.aff_NombreInstances();

    return 0;
}
