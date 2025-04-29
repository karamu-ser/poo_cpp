#include <iostream>

class MathUtils
{
    public:
        static int somme(int a, int b)
        {
            return a + b;
        }
        static int multi(int a, int b)
        {
            return a * b;
        }
        static int sous(int a, int b)
        {
            return a - b;
        }
};

int main()
{
    int a = 48, b = 18;
    std::cout << a << " + " << b << " = " << MathUtils::somme(a, b) << std::endl;
    std::cout << a << " * " << b << " = " << MathUtils::multi(a, b) << std::endl;
    std::cout << a << " - " << b << " = " << MathUtils::sous(a, b) << std::endl;
    return 0;
}