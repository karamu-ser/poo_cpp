#include <iostream>
using namespace std;

class Vehicule {
public:
    virtual void rouler() {
        cout << "Le vehicule roule" << endl;
    }
};

class Voiture : public virtual Vehicule {
public:
    void rouler() override {
        cout << "La voiture roule sur 4 roues" << endl;
    }
};

class Moto : public virtual Vehicule
{
	public:
		void rouler() override {
			cout << "La moto roule sur 2 roues" << endl;
		}
};

class Tricycle : public Voiture, public Moto
{
	public:
		void rouler() override {
			cout << "Le tricycle roule sur 3 roues" << endl;
		}
};

int main()
{
    Tricycle tricycle;
    tricycle.rouler();
    
    return 0;
}