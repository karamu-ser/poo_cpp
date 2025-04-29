#include <iostream>

class MathUtils
{
public:
    static long long factoriel(int n)
	{
        if (n < 0) return -1;
        long long resultat = 1;
        for (int i = 2; i <= n; i++)
            resultat *= i;
        return resultat;
    }
    static int pgcd(int a, int b)
	{
        while (b != 0)
		{
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main()
{
    int nombre = 5;
    std::cout << "Factoriel de " << nombre << " : " << MathUtils::factoriel(nombre) << std::endl;
    int a = 48, b = 18;
    std::cout << "PGCD de " << a << " et " << b << " : " << MathUtils::pgcd(a, b) << std::endl;
    return 0;
}
