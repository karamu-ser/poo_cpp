#include <iostream>
#include <string>

class Etudiant {
	private:
		std::string nom;
		int age;
	
	public:
		Etudiant() : nom("Inconnu"), age(0) {} // constructeur
		Etudiant(std::string nom, int age) : nom(nom), age(age) {}
		void afficher() const {
			std::cout << "le nom : " << nom << " / l'age : " << age << std::endl;
		}
};	

int main() {
    int nombreEtudiants = 3;
	Etudiant* etudiants = new Etudiant[nombreEtudiants];
	etudiants[0] = Etudiant("Abderrahman", 21);
	etudiants[1] = Etudiant("amal", 22);
	etudiants[2] = Etudiant("amine", 19);
    for (int i = 0; i < nombreEtudiants; i++)
        etudiants[i].afficher();
    delete[] etudiants;
    return 0;
}
