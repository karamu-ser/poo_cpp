#include <iostream>

using namespace std;

inline int max(int l, int L)
{
	return (l < L) ? L : l;
}

int main()
{
    int a = 8;
    int b = 12;
    int maximum = max(a, b);
    std::cout << "La valeur maximale est : " << maximum << std::endl;
    return 0;
}