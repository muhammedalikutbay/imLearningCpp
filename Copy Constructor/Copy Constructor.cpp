#include <iostream>

using namespace std;

class Weapon {
    string name;
    int damage;
public:
    Weapon(string n, int d) : name(n), damage(d) {}

    Weapon(const Weapon& other) {
        cout << "Kopya constructor çaðrýldý!\n";
        name = other.name;
        damage = other.damage;
    }

    void print() {
        cout << name << " - Hasar: " << damage << endl;
    }
};

int main() {
    Weapon sword("Kýlýç", 50);
    Weapon copySword = sword; 
    copySword.print();
}
