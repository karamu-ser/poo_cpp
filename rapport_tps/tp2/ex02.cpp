#include <iostream>

class personne
{
	private :
		std::string nom;
		int age;
		std::string adresse;
	public :
		personne (std::string n, int ag, std::string ad) : nom(n), age(ag), adresse(ad) {}
		void affiche()
		{
			std::cout << "nom : " << nom << std::endl;
			std::cout << "age : " << age << std::endl;
			std::cout << "adresse : " << adresse << std::endl;
		}
};

int	main()
{
	personne per("abderrahman", 21, "khouribga");
	per.affiche();
}