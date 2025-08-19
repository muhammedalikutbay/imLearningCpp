
#include <iostream>

using namespace std;

class Player
{
	public:
		Player(int m);
		~Player();

	private:
		int health;
		int maxHealth;
	public:
		int getHealth() const {return health; };
		void takeDamage(int damage) { health -= damage; health < 0 ? health = 0: health=health; }
		void heal(int amount) { health += amount; health >= maxHealth ? health = maxHealth: health = health ; }
		void printStatus() const { cout << "Oyuncunun caný:" << getHealth() << "/" << maxHealth << endl; getHealth() <= 0 ? cout << "Oyuncu Ölü\n" : cout << "Oyuncu Hayatta\n"; }

		bool isDead() const {
			if (getHealth()<=0)
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
};

Player::Player(int m)
{
	maxHealth = m;
	health = maxHealth;
}

Player::~Player()
{
}


int main()
{
	Player sercan(100);
	sercan.takeDamage(20);
	sercan.printStatus();
	sercan.heal(50);
	if (sercan.isDead()==false)
	{
		sercan.printStatus();
	}


}

