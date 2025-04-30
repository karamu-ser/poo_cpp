#include <iostream>
#include <vector>
using namespace std;

class Employe
{
	protected:
		string nom;
		
	public:
		Employe(string n) : nom(n) {}
		
		virtual void travailler() const {
			cout << "L'employe travaille" << endl;
		}
		
		virtual ~Employe() {}
};

class Manager : public Employe
{
	public:
		Manager(string n) : Employe(n) {}
		
		void travailler() const override
		{
			cout << "Le manager " << nom << " supervise le travail" << endl;
		}
};

class Technicien : public Employe
{
	public:
		Technicien(string n) : Employe(n) {}
		
		void travailler() const override
		{
			cout << "Le technicien " << nom << " execute une tache technique" << endl;
		}
};

int main()
{
    vector<Employe*> employes;
    employes.push_back(new Manager("Jean"));
    employes.push_back(new Technicien("Pierre"));
    employes.push_back(new Manager("Marie"));
    employes.push_back(new Technicien("Sophie"));
    
    cout << "Employes au travail:" << endl;
    for (Employe* emp : employes)
        emp->travailler();
    for (Employe* emp : employes)
        delete emp;
    return 0;
}