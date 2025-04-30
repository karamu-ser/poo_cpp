#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Animal 
{
	protected:
		string nom;
	public:
		Animal(string n) : nom(n) {}
		virtual void parler() 
		{
			cout << nom << " fait un bruit" << endl;
		}
		virtual ~Animal() {}
};

class Chien : public Animal 
{
	public:
		Chien(string n) : Animal(n) {}
		void parler() override 
		{
			cout << nom << " dit: Woof!" << endl;
		}
};

class Chat : public Animal
{
	public:
		Chat(string n) : Animal(n) {}
		void parler() override 
		{
			cout << nom << " dit: Miaou!" << endl;
		}
};

int main()
{
    queue<Animal*> fileAttente;
    fileAttente.push(new Chien("Rex"));
    fileAttente.push(new Chat("Felix"));
    fileAttente.push(new Chien("Max"));
    fileAttente.push(new Chat("Minette"));
    while (!fileAttente.empty())
	{
        Animal* animal = fileAttente.front();
        animal->parler();
        delete animal;
        fileAttente.pop();
    }
    return 0;
}