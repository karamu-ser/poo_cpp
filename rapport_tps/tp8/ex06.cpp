#include <iostream>
#include <map>
#include <string>
using namespace std;

class Robot {
protected:
    string nom;
public:
    Robot(string n) : nom(n) {}
    virtual void executerTache() {
        cout << "Robot " << nom << " execute une tache generique" << endl;
    }
    virtual ~Robot() {}
};

class RobotMenager : public Robot {
public:
    RobotMenager(string n) : Robot(n) {}
    void executerTache() override {
        cout << "Le robot menager " << nom << " nettoie la maison" << endl;
    }
};

class RobotIndustriel : public Robot {
public:
    RobotIndustriel(string n) : Robot(n) {}
    void executerTache() override {
        cout << "Le robot industriel " << nom << " assemble des pieces" << endl;
    }
};

int main() {
    map<int, Robot*> robots;
    
    robots[1] = new Robot("R2D2");
    robots[2] = new RobotMenager("CleanBot");
    robots[3] = new RobotIndustriel("AssembleBot");
    robots[4] = new RobotMenager("DustBot");
    robots[5] = new RobotIndustriel("WeldBot");
    
    for (auto& paire : robots) {
        cout << "Robot ID " << paire.first << ": ";
        paire.second->executerTache();
    }
    
    for (auto& paire : robots) {
        delete paire.second;
    }
    
    return 0;
}