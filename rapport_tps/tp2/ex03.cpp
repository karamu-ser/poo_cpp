#include <iostream>

class CompteBancaire
{
	private:
		long solde = 0;
	public:
		void initialiser(long i)
		{
			solde = i;
		}
		void déposer(long i)
		{
			solde += i;
		}
		void retirer(long i)
		{
			solde -= i;
		}
		void afficher()
		{
			std::cout << "votre solde est : " << solde << " dhs." << std::endl;
		}
};

int main()
{
	CompteBancaire comp;
	comp.initialiser(5000);
	comp.déposer(10);
	comp.retirer(2000);
	comp.afficher();
}