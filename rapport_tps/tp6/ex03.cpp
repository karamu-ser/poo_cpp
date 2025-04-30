#include <iostream>
#include <string>
using namespace std;

class Personne
{
	protected:
		string nom;
		int age;
		
	public:
		Personne(string n, int a) : nom(n), age(a) {}
		
		friend ostream& operator<<(ostream& os, const Personne& p) {
			os << "Nom: " << p.nom << ", Age: " << p.age;
			return os;
		}
};

class Etudiant : public Personne
{
	private:
		double moyenne;
		
	public:
		Etudiant(string n, int a, double m) : Personne(n, a), moyenne(m) {}
		
		friend ostream& operator<<(ostream& os, const Etudiant& e)
		{
			os << static_cast<const Personne&>(e) << ", Moyenne: " << e.moyenne;
			return os;
		}
};

int main()
{
    Personne personne("Jean", 30);
    Etudiant etudiant("Marie", 20, 15.5);
    
    cout << "Personne: " << personne << endl;
    cout << "Etudiant: " << etudiant << endl;
    
    return 0;
}