#include <iostream>
#include <string>

// Classe représentant un livre.
class Livre {
private:
    std::string titre;
    std::string auteur;
public:
    Livre(const std::string &t, const std::string &a)
        : titre(t), auteur(a) {}
    
    void afficher() const {
        std::cout << "Titre : " << titre << ", Auteur : " << auteur << std::endl;
    }
};

// Classe Bibliotheque qui gère une collection de livres.
// Utilise un tableau dynamique de pointeurs vers Livre.
class Bibliotheque {
private:
    Livre** livres;  // Pointeur vers un tableau de pointeurs sur Livre.
    int nbLivres;    // Nombre de livres actuellement dans la bibliothèque.
    int capacite;    // Capacité actuelle du tableau.
    
    // Méthode privée pour agrandir dynamiquement le tableau.
    void agrandir() {
        capacite *= 2;
        Livre** nouveauTableau = new Livre*[capacite];
        for (int i = 0; i < nbLivres; ++i) {
            nouveauTableau[i] = livres[i];
        }
        delete[] livres;
        livres = nouveauTableau;
    }
    
public:
    // Constructeur avec une capacité initiale (par défaut 10).
    Bibliotheque(int cap = 10)
        : nbLivres(0), capacite(cap) {
        livres = new Livre*[capacite];
    }
    
    // Destructeur pour libérer la mémoire allouée dynamiquement.
    ~Bibliotheque() {
        for (int i = 0; i < nbLivres; ++i) {
            delete livres[i];
        }
        delete[] livres;
    }
    
    // Méthode d'ajout d'un livre. Si le tableau est plein, il sera agrandi.
    void ajouterLivre(const std::string &titre, const std::string &auteur) {
        if (nbLivres == capacite) {
            agrandir();
        }
        livres[nbLivres] = new Livre(titre, auteur);
        nbLivres++;
    }
    
    // Méthode pour afficher tous les livres de la bibliothèque.
    void afficherBibliotheque() const {
        std::cout << "Contenu de la bibliothèque :" << std::endl;
        for (int i = 0; i < nbLivres; ++i) {
            livres[i]->afficher();
        }
    }
};

int main() {
    Bibliotheque biblio;
    
    biblio.ajouterLivre("Les Misérables", "Victor Hugo");
    biblio.ajouterLivre("1984", "George Orwell");
    biblio.ajouterLivre("Le Petit Prince", "Antoine de Saint-Exupéry");
    
    biblio.afficherBibliotheque();
    
    return 0;
}