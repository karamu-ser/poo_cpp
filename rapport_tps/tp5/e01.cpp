#include <iostream>
using namespace std;

double diviser(double a, double b)
{
    if (b == 0)
	{
        throw runtime_error("Division par zero");
    }
    return a / b;
}

int main()
{
    double a, b;
    
    cout << "Entrez deux nombres: ";
    cin >> a >> b;
    
    try
	{
        double resultat = diviser(a, b);
        cout << "Le resultat de " << a << " / " << b << " est: " << resultat << endl;
    }
	catch (const runtime_error& e)
	{
        cout << "Erreur: " << e.what() << endl;
    }
    
    return 0;
}