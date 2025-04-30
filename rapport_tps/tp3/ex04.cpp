#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string nom;
    int age;
    
public:
    Animal(string n, int a) : nom(n), age(a) {}
    
    virtual void afficherInfo() {
        cout << "Nom: " << nom << ", Age: " << age << " ans" << endl;
    }
};

class Chien : public Animal {
private:
    string race;
    
public:
    Chien(string n, int a, string r) : Animal(n, a), race(r) {}
    
    void afficherInfo() {
        Animal::afficherInfo();
        cout << "Race: " << race << endl;
    }
};

class Chat : public Animal {
private:
    bool domestique;
    
public:
    Chat(string n, int a, bool d) : Animal(n, a), domestique(d) {}
    
    void afficherInfo() {
        Animal::afficherInfo();
        cout << "Domestique: " << (domestique ? "Oui" : "Non") << endl;
    }
};
class Oiseau : public Animal {
private:
    string couleur;
public:
    Oiseau(string n, int a, string c) : Animal(n, a), couleur(c) {}
    
    void afficherInfo() {
        Animal::afficherInfo();
        cout << "Couleur: " << couleur << endl;
    }
};
int main() {
    Animal* animaux[3];
    
    animaux[0] = new Chien("Rex", 3, "Berger Allemand");
    animaux[1] = new Chat("Felix", 2, true);
    animaux[2] = new Oiseau("Piaf", 1, "Bleu");
    
    for (int i = 0; i < 3; i++) {
        animaux[i]->afficherInfo();
        cout << endl;
    }
    for (int i = 0; i < 3; i++)
        delete animaux[i];
    return 0;
}