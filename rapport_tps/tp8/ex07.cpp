#include <iostream>
#include <map>
#include <string>
using namespace std;

class Vehicule
{
	protected:
	    string nom;
	public:
	    static int totalVehicules;
	    Vehicule(string n) : nom(n)
		{
	        totalVehicules++;
	    }
	    virtual void afficherType()
		{
	        cout << nom << " est un vehicule generique" << endl;
	    }
	    static void afficherTotal()
		{
	        cout << "Nombre total de vehicules: " << totalVehicules << endl;
	    }
	    virtual ~Vehicule() {}
};

int Vehicule::totalVehicules = 0;

class Voiture : public Vehicule
{
	public:
	    static int totalVoitures;
	    
	    Voiture(string n) : Vehicule(n)
		{
	        totalVoitures++;
	    }
	    
	    void afficherType() override
		{
	        cout << nom << " est une voiture" << endl;
	    }
	    
	    static void afficherTotal()
		{
	        cout << "Nombre total de voitures: " << totalVoitures << endl;
	    }
};

int Voiture::totalVoitures = 0;

class Camion : public Vehicule
{
	public:
	    static int totalCamions;
	    
	    Camion(string n) : Vehicule(n) {
	        totalCamions++;
	    }
	    
	    void afficherType() override {
	        cout << nom << " est un camion" << endl;
	    }
	    
	    static void afficherTotal() {
	        cout << "Nombre total de camions: " << totalCamions << endl;
	    }
};

int Camion::totalCamions = 0;

int main()
{
    map<string, Vehicule*> parc;
    parc["v1"] = new Vehicule("dacia");
    parc["c1"] = new Voiture("Clio");
    parc["c2"] = new Voiture("Megane");
    parc["t1"] = new Camion("Renault");
    parc["t2"] = new Camion("Volvo");
    parc["c3"] = new Voiture("Peugeot 308");
    Vehicule::afficherTotal();
    Voiture::afficherTotal();
    Camion::afficherTotal();
    cout << "\nDetails de chaque vehicule:\n";
    for (auto& paire : parc) {
        cout << paire.first << ": ";
        paire.second->afficherType();
    }
    for (auto& paire : parc)
        delete paire.second;
    return 0;
}