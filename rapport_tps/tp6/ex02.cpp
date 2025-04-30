#include <iostream>
#include <vector>
using namespace std;

class Instrument
{
	public:
		virtual void jouer() = 0;
		virtual ~Instrument() {}
};

class Guitare : public Instrument
{
	public:
		void jouer() override {
			cout << "La guitare joue des accords" << endl;
		}
};

class Piano : public Instrument
{
	public:
		void jouer() override {
			cout << "Le piano joue des notes" << endl;
		}
};

int main()
{
    vector<Instrument*> instruments;
    
    instruments.push_back(new Guitare());
    instruments.push_back(new Piano());
    
    cout << "Sons des instruments:" << endl;
    for (Instrument* instrument : instruments) {
        instrument->jouer();
    }
    
    for (Instrument* instrument : instruments) {
        delete instrument;
    }
    
    return 0;
}