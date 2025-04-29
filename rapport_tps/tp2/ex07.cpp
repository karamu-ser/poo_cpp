#include <iostream>

using namespace std;

class employee
{
	private:
		long salaire;
	public:
		employee(double salair) : salaire(salair) {}
		void argumenter(double pourcentage)
		{
        	this->salaire += this->salaire * (pourcentage / 100);
		}
		void afficher()
		{
        	cout << "le salaire = " << this->salaire << endl;
		}
};

int main()
{
	employee emp(5000);
	emp.afficher();
	emp.argumenter(20);
	emp.afficher();
}