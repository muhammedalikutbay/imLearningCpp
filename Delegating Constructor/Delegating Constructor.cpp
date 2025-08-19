#include <iostream>

using namespace std;

class Enemy
{
private:
	int health;
	int damage;
	string name;
public:
	Enemy(int h, int d, string n) : health(h), damage(d), name(n) { cout << "custom enemy created\n"; };
	Enemy() : Enemy(100, 10, "Goblin") { cout << "defualt enemy created\n"; };
	Enemy(const Enemy& other)
	{
		health = other.health;
		damage = other.damage;
		name = other.name;
		cout << "enemy copied\n";
	}
	
	void printStatus() const 
	{
		cout << "Enemy Name:"<<name <<endl;
		cout << "Enemy Health:" << health << endl;
		cout << "Enemy Damage:" << damage << endl;
	}
};


int main()
{
	Enemy e1;
	Enemy e2(500,50,"Dragon");
	Enemy e3 = e2;
	e1.printStatus();
	e2.printStatus();
	e3.printStatus();
}
