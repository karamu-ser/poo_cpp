#include <iostream>
#include <string>

class Etudiant {
private:
    std::string nom;
    int age;

public:
    Etudiant(std::string nom, int age) : nom(nom), age(age) {} // ?? constructeurs 
    void afficher() const {
        std::cout << "Nom : " << nom << ", age : " << age << std::endl;
    }
};

int main() {
    int nombreEtudiants;

    std::cout << "Entrez le nombre d'étudiants : ";
    std::cin >> nombreEtudiants;

    Etudiant *etudiants = new Etudiant[nombreEtudiants]
	{
        Etudiant("Alice", 20),
        Etudiant("Bob", 22),
        Etudiant("Charlie", 19)
    };

    for (int i = 0; i < nombreEtudiants; i++)
	{
        etudiants[i].afficher();
    }
    delete[] etudiants;
    return 0;
}
