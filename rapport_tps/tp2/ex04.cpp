#include <iostream>

class Livre
{
	private :
		std::string titre;
	public:
		std::string auteur;
		Livre (std::string T, std::string A) : titre(T), auteur(A) {};
		std::string getter()
		{
			return titre;
		}
		void setter(std::string nouveau)
		{
			titre = nouveau;
		}
};

using namespace std;

int main()
{
	Livre liv("Linux", "Philippe Banquet");
	cout << "titre du livre " << liv.getter() << " d'auteur " << liv.auteur << "." << endl; 
	liv.setter("cpp");
	cout << "titre du livre " << liv.getter() << " d'auteur " << liv.auteur << "." << endl;
	return 0;
}