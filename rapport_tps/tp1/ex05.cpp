#include <iostream>
#include <vector>
#include <string>
using namespace std;

inline int surface_rectangle(int l, int L)
{
	return l * L;
}
int main()
{
    int longueur = 10;
    int largeur = 5;
    int surface = surface_rectangle(longueur, largeur);
    std::cout << "La surface du rectangle est : " << surface << " unités carrées." << std::endl;
    return 0;
}