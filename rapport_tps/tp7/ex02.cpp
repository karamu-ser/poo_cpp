#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nombres = {5, 2, 8, 1, 9, 3};
    
    cout << "Vector avant tri: ";
    for (int n : nombres)
        cout << n << " ";
    cout << endl;
    sort(nombres.begin(), nombres.end());
    cout << "Vector apres tri: ";
    for (int n : nombres)
        cout << n << " ";
    cout << endl;
    return 0;
}