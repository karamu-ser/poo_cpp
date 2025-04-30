#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicule
{
	protected:
	    string marque;
	    string modele;
	    string immatriculation;
	    
	public:
	    static int nbVehicules;
	    
	    Vehicule(string marq, string mod, string immat) 
	        : marque(marq), modele(mod), immatriculation(immat) 
			{
	        nbVehicules++;
	    }
	    
	    virtual void afficher() const 
		{
	        cout << "Vehicule: " << marque << " " << modele 
	             << " - Immatriculation: " << immatriculation << endl;
	    }
	    
	    static int getNbVehicules() 
		{
	        return nbVehicules;
	    }
	    
	    virtual ~Vehicule() {}
};

int Vehicule::nbVehicules = 0;

class Voiture : public Vehicule {
	private:
	    int nombrePortes;
	    
	public:
	    Voiture(string marq, string mod, string immat, int portes) 
	        : Vehicule(marq, mod, immat), nombrePortes(portes) {}
	    
	    void afficher() const override 
		{
	        cout << "Voiture: " << marque << " " << modele 
	             << " - Immatriculation: " << immatriculation 
	             << " - Nombre de portes: " << nombrePortes << endl;
    }
};

class Camion : public Vehicule 
{
	private:
	    double capaciteCharge; // en tonnes
	    
	public:
	    Camion(string marq, string mod, string immat, double capacite) 
	        : Vehicule(marq, mod, immat), capaciteCharge(capacite) {}
	    
	    bool estLourd() const
		{
	        return capaciteCharge > 3.0; // seuil de 3 tonnes
	    }
	    
	    void afficher() const override {
	        cout << "Camion: " << marque << " " << modele 
	             << " - Immatriculation: " << immatriculation 
	             << " - Capacite de charge: " << capaciteCharge << " tonnes"
	             << " - Type: " << (estLourd() ? "Lourd" : "Leger") << endl;
	    }
};

int main()
{
    vector<Vehicule*> parc;
    
    parc.push_back(new Voiture("Renault", "Clio", "123-ABC-45", 5));
    parc.push_back(new Camion("Volvo", "FH16", "456-DEF-78", 7.5));
    parc.push_back(new Voiture("Peugeot", "308", "789-GHI-10", 3));
    parc.push_back(new Camion("MAN", "TGX", "101-JKL-12", 2.5));
    cout << "---- Parc de vehicules ----" << endl;
    for (auto vehicule : parc)
        vehicule->afficher();
    cout << "\n---- Statistiques ----" << endl;
    cout << "Nombre total de vehicules: " << Vehicule::getNbVehicules() << endl;
    int nombreCamionsLourds = 0;
    for (auto vehicule : parc) {
        Camion* camion = dynamic_cast<Camion*>(vehicule);
        if (camion && camion->estLourd())
            nombreCamionsLourds++;
    }
    cout << "Nombre de camions lourds: " << nombreCamionsLourds << endl;
    for (auto vehicule : parc)
        delete vehicule;
    return 0;
}