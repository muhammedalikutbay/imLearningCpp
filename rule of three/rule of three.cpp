#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

class Item
{
private:
	char* name;
	int value;

public:
	Item(const char* n, int v) 
	{
		name = new char[strlen(n)+1];
		strcpy(name, n);
		value = v;
		cout << "(custom constructor)Item created: " << name << endl;
	}

	Item() {
		name = new char[1];
		name[0] = '\0'; 
		value = 0;
		cout << "(dufualt constructor)Item created: " << name << endl;
	}

	Item(const Item& other)
	{
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		value = other.value;
		cout << "Item copied (copy constructor): " << name << endl;
	}

	Item& operator=(const Item& other) {
		if (this != &other) 
		{
			delete[] name; 
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
			value = other.value;
		}
		cout << "Item copied (assignment): " << name << endl;
		return *this;
	}

	~Item(){ delete[] name; }

	void print() const {
		cout << "Item Name: " << name << ", Value: " << value << endl;
	}


};

int main() {
	Item sword("Sword", 50);   
	sword.print();
	Item potion("Health Potion", 25);
	potion.print();

	Item copySword = sword;   
	copySword.print();
	potion = sword;
	potion.print();

}
