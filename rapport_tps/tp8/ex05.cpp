#include <iostream>
#include <deque>
#include <string>
using namespace std;

class Transport {
protected:
    string nom;
public:
    Transport(string n) : nom(n) {}
    virtual void deplacer() {
        cout << nom << " se deplace" << endl;
    }
    virtual ~Transport() {}
};

class Voiture : public Transport {
public:
    Voiture(string n) : Transport(n) {}
    void deplacer() override {
        cout << "La voiture " << nom << " roule sur la route" << endl;
    }
};

class Train : public Transport {
public:
    Train(string n) : Transport(n) {}
    void deplacer() override {
        cout << "Le train " << nom << " circule sur les rails" << endl;
    }
};

int main() {
    deque<Transport*> terminal;
    
    terminal.push_back(new Voiture("Renault"));
    terminal.push_back(new Train("TGV"));
    terminal.push_front(new Voiture("Peugeot"));
    terminal.push_back(new Train("Intercites"));
    
    for (auto transport : terminal) {
        transport->deplacer();
    }
    
    for (auto transport : terminal) {
        delete transport;
    }
    
    return 0;
}