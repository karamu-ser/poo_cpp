#include <iostream>

using namespace std;

class calculatrice
{
	private:
		float resultat;
	public:
		void somme(int a, int b)
        {
            resultat = a + b;
        }
        void multi(int a, int b)
        {
            resultat = a * b;
        }
        void  sous(int a, int b)
        {
            resultat = a - b;
        }
        void div(int a, int b)
        {
			if (b == 0)
			{
				cout << "vraiment tu veux diviser par 0 !" << endl;
				return ;
			}
            resultat = (float) a/b;
        }
		friend class afficheur;
};

class afficheur
{
	public:
		void afficherResultat(calculatrice calc) {
        	std::cout << "Résultat : " << calc.resultat << std::endl;
    }
};

int main()
{
	calculatrice c;
	afficheur a;
	c.somme(1124, 1000);
	a.afficherResultat(c);
}