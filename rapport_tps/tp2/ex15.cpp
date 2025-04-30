#include <iostream>
#include <string>

class Livre
{
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

class Bibliotheque
{
private:
    Livre** livres;
    int nbLivres;    
    int capacite;

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
    Bibliotheque(int cap = 10)
        : nbLivres(0), capacite(cap) {
        livres = new Livre*[capacite];
    }
    ~Bibliotheque() {
        for (int i = 0; i < nbLivres; ++i) {
            delete livres[i];
        }
        delete[] livres;
    }
    void ajouterLivre(const std::string &titre, const std::string &auteur) {
        if (nbLivres == capacite) {
            agrandir();
        }
        livres[nbLivres] = new Livre(titre, auteur);
        nbLivres++;
    }
    void afficherBibliotheque() const {
        std::cout << "Contenu de la bibliotheque :" << std::endl;
        for (int i = 0; i < nbLivres; ++i) {
            livres[i]->afficher();
        }
    }
};

int main() {
    Bibliotheque biblio;
    
    biblio.ajouterLivre("Les Miserables", "Victor Hugo");
    biblio.ajouterLivre("1984", "George Orwell");
    biblio.ajouterLivre("Le Petit Prince", "Antoine de Saint-Exupery");
    
    biblio.afficherBibliotheque();
    
    return 0;
}