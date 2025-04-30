#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Livre
{
	protected:
		string titre;
	public:
		Livre(string t) : titre(t) {}
		virtual void afficher() {
			cout << "Livre: " << titre << endl;
		}
		virtual ~Livre() {}
};

class Roman : public Livre
{
	private:
		string auteur;
	public:
		Roman(string t, string a) : Livre(t), auteur(a) {}
		void afficher() override
		{
			cout << "Roman: " << titre << " par " << auteur << endl;
		}
};

class Magazine : public Livre
{
	private:
		int numero;
	public:
		Magazine(string t, int n) : Livre(t), numero(n) {}
		void afficher() override
		{
			cout << "Magazine: " << titre << " n°" << numero << endl;
		}
};

int main()
{
    vector<Livre*> bibliotheque;
    bibliotheque.push_back(new Livre("Livre general"));
    bibliotheque.push_back(new Roman("Les Miserables", "Victor Hugo"));
    bibliotheque.push_back(new Magazine("Science et Vie", 1098));
    for (auto livre : bibliotheque)
        livre->afficher();
    for (auto livre : bibliotheque)
        delete livre;
    return 0;
}