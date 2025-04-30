#include <iostream>

using namespace std;

class animal
{
    private:
        string nom;
        float age;
    public:
        animal(string n, float a) : nom(n), age(a) {};
        void afficherInfo_animal();
};

class chien: public animal
{
    private:
        string race;
    public:
        chien(string n, float a, string r) : animal(n, a), race(r) {};
        void afficherInfo_chien();

};
class oiseau: public chien
{
    private:
        string couleur;
    public:
        oiseau(string n, float a, string r, string c) : chien(n, a,r), couleur(c) {};
        void afficherInfo_oiseau();
};


void animal::afficherInfo_animal()
{
    cout << "le nom : " << this->nom << " | age : " << this->age << endl;
}
void chien::afficherInfo_chien()
{
    afficherInfo_animal();
    cout << "la race : " << this->race << endl;
}
void oiseau::afficherInfo_oiseau()
{
    afficherInfo_chien();
    cout << "la race : " << this->couleur << endl;
}

int main()
{
    cout << "\n----------------class animal -------------------\n" << endl;
    animal ani("maxi", 1);
    ani.afficherInfo_animal();

    cout << "\n----------------class chien -------------------\n" << endl;
    chien ch("maxi", 4 , "rote");
    ch.afficherInfo_chien();

    cout << "\n----------------class oiseau -------------------\n" << endl;
    oiseau oi("twiti", 0.5, "Perruche", "jaune");
    oi.afficherInfo_oiseau();
}