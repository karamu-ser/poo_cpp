#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nombres;
    
    nombres.push_back(1);
    nombres.push_back(2);
    nombres.push_back(3);
    nombres.push_back(4);
    nombres.push_back(5);
    cout << "Elements du vector:" << endl;
    for (int i = 0; i < nombres.size(); i++)
        cout << nombres[i] << " ";
    cout << endl;

    return 0;
}