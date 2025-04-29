#include <iostream>

using namespace std;

class amie
{
	private:
		int nombre_amie;
	public:
		amie (int a) : nombre_amie(a) {};
		friend void print_nbr_amies(amie c);
};

void print_nbr_amies(amie c)
{
	cout << " le nombre des amies est : " << c.nombre_amie << endl;
}

int main()
{
	amie c(10);
	print_nbr_amies(c);
}