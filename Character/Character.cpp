#include <iostream>
#include <string>
using namespace std;

// ---- Temel Karakter Sınıfı ----
class Character {
private:
    int health;   // kapsülleme: dışarıdan doğrudan erişilemiyor

protected:
    int level;    // miras alan class'lar erişebilir

public:
    string name;

    // Constructor
    Character(string pName, int pHealth, int pLevel)
        : name(pName), health(pHealth), level(pLevel) {
        cout << "Karakter oluşturuldu: " << name << endl;
    }

    // Sağlık set/get
    void setHealth(int h) {
        if (h < 0) h = 0;
        health = h;
    }
    int getHealth() { return health; }

    // Hasar alma
    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
        cout << name << " " << damage << " hasar aldı! Kalan sağlık: " << health << endl;
    }

    // Sanal fonksiyon: polymorphism
    virtual void attack() {
        cout << name << " yumruk attı!" << endl;
    }
};

// ---- Oyuncu sınıfı (Character'dan miras alıyor) ----
class Player : public Character {
public:
    Player(string pName, int pHealth, int pLevel)
        : Character(pName, pHealth, pLevel) {
    }

    void attack() override {
        cout << name << " kılıçla saldırdı!" << endl;
    }
};

// ---- Düşman sınıfı ----
class Enemy : public Character {
public:
    Enemy(string pName, int pHealth, int pLevel)
        : Character(pName, pHealth, pLevel) {
    }

    void attack() override {
        cout << name << " pençe attı!" << endl;
    }
};

// ---- Main ----
int main() {
    Player p1("Ahmet", 100, 1);
    Enemy e1("Kurt", 50, 1);

    p1.attack();   // polymorphism → Player kendi override ettiği fonksiyonu çalıştırır
    e1.attack();   // Enemy kendi override ettiği fonksiyonu çalıştırır

    e1.takeDamage(30);
    p1.takeDamage(20);

    return 0;
}
