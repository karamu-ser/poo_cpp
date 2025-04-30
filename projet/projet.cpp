#include "projet.h"

using namespace std;

class Vehicule {
protected:
    string modele;
    string marque;
    bool disponible;
public:
    Vehicule(const string &mod, const string &mar, bool dispo = true)
        : modele(mod), marque(mar), disponible(dispo) {}

    virtual ~Vehicule() {}
    string getModele() const { return modele; }
    string getMarque() const { return marque; }
    bool estDisponible() const { return disponible; }
    void setDisponible(bool etat) { disponible = etat; }
    virtual void afficherDetails() const {
        cout << "Marque : " << marque << "\nModèle : " << modele 
             << "\nDisponible : " << (disponible ? "Oui" : "Non") << endl;
    }
};

class Voiture : public Vehicule {
public:
    Voiture(const string &mod, const string &mar, bool dispo = true)
        : Vehicule(mod, mar, dispo) {}

    virtual void afficherDetails() const override {
        cout << "----- VOITURE -----" << endl;
        Vehicule::afficherDetails();
        cout << "-------------------" << endl;
    }
};

class Camion : public Vehicule {
private:
    double capaciteCharge; // en kg
public:
    Camion(const string &mod, const string &mar, double capacite, bool dispo = true)
        : Vehicule(mod, mar, dispo), capaciteCharge(capacite) {}
    double getCapaciteCharge() const { return capaciteCharge; }
    virtual void afficherDetails() const override {
        cout << "----- CAMION -----" << endl;
        Vehicule::afficherDetails();
        cout << "Capacité de charge : " << capaciteCharge << " kg" << endl;
        cout << "------------------" << endl;
    }
    void reserver(double chargeDemandee) {
        if (!disponible) {
            throw runtime_error("Ce camion n'est pas disponible pour réservation.");
        }
        if (chargeDemandee > capaciteCharge) {
            throw runtime_error("La charge demandée dépasse la capacité du camion.");
        }
        disponible = false;
        cout << "Réservation du camion effectuée avec succès pour une charge de "
             << chargeDemandee << " kg." << endl;
    }
};

class Moto : public Vehicule
{
private:
    int cylindree; 
public:
    Moto(const string &mod, const string &mar, int cyl, bool dispo = true)
        : Vehicule(mod, mar, dispo), cylindree(cyl) {}
    virtual void afficherDetails() const override {
        cout << "----- MOTO -----" << endl;
        Vehicule::afficherDetails();
        cout << "Cylindrée : " << cylindree << " cc" << endl;
        cout << "----------------" << endl;
    }
};
void reserverVehicule(Vehicule &v) {
    if (!v.estDisponible()) {
        throw runtime_error("Le véhicule n'est pas disponible pour réservation.");
    }
    v.setDisponible(false);
    cout << "Réservation effectuée avec succès pour le véhicule:" << endl;
    v.afficherDetails();
}

int main() {
    vector<Vehicule*> parc;
    parc.push_back(new Voiture("Model S", "Tesla"));
    parc.push_back(new Camion("F-Series", "Ford", 10000));
    parc.push_back(new Moto("CBR", "Honda", 600));

    cout << "Liste des véhicules disponibles:" << endl;
    for (size_t i = 0; i < parc.size(); ++i) {
        cout << "Indice " << i << " : " << endl;
        parc[i]->afficherDetails();
        cout << endl;
    }
    int choix;
    cout << "Entrez l'indice du véhicule à réserver (entre 0 et " << parc.size()-1 << ") : ";
    cin >> choix;
    if (choix < 0 || static_cast<size_t>(choix) >= parc.size())
        cout << "Indice invalide!" << endl;
	else
	{
        try
		{
            Camion* camionPtr = dynamic_cast<Camion*>(parc[choix]);
            if (camionPtr != nullptr) {
                double charge;
                cout << "Vous avez choisi un camion. Entrez la charge demandée (en kg) : ";
                cin >> charge;
                camionPtr->reserver(charge);
            }
			else
                reserverVehicule(*parc[choix]);
        } catch (const exception &e) {
            cout << "Erreur lors de la réservation : " << e.what() << endl;
        }
    }
    for (Vehicule* v : parc)
        delete v;
    parc.clear();
    return 0;
}