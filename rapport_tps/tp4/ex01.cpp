#include <iostream>
using namespace std;

template <typename T>
T minimum(T a, T b)
{
    return (a < b) ? a : b;
}

int main()
{
    int a = 10, b = 5;
    cout << "Le minimum entre " << a << " et " << b << " est: " << minimum(a, b) << endl;
    float c = 3.14f, d = 2.71f;
    cout << "Le minimum entre " << c << " et " << d << " est: " << minimum(c, d) << endl;
    char e = 'a', f = 'z';
    cout << "Le minimum entre " << e << " et " << f << " est: " << minimum(e, f) << endl;
    return 0;
}