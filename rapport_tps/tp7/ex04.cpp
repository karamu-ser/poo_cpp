#include <iostream>
#include <vector>
using namespace std;

class Animal
{
	protected:
		string nom;
		
	public:
		Animal(string n) : nom(n) {}
		
		virtual void afficher() const {
			cout << "Animal: " << nom << endl;
		}
		
		virtual ~Animal() {}
};

class Chien : public Animal
{
	public:
		Chien(string n) : Animal(n) {}
		
		void afficher() const override {
			cout << "Chien: " << nom << endl;
		}
};

class Chat : public Animal
{
	public:
		Chat(string n) : Animal(n) {}
		
		void afficher() const override {
			cout << "Chat: " << nom << endl;
		}
};

int main()
{
    vector<Animal*> animaux;
    
    animaux.push_back(new Animal("Inconnu"));
    animaux.push_back(new Chien("Rex"));
    animaux.push_back(new Chat("Felix"));
    
    cout << "Liste des animaux:" << endl;
    for (Animal* animal : animaux)
        animal->afficher();
    for (Animal* animal : animaux)
        delete animal;
    return 0;
}