
#include <iostream>

using namespace std;

class Item
{
private:
	string name;
	static int totalItems;
public:
	Item(string n) : name(n)
	{
		totalItems++;
	}
	~Item() { totalItems--; }

	static void print() { cout << "Total Item is " << totalItems << endl; }

};
int Item::totalItems = 0;



int main()
{
	Item i1("balta");
	Item i2("balta");
	Item i3("balta");
	Item i4("balta");
	Item i5("balta");
	Item::print();
	{
		Item i6("balta");
		Item::print();
	}
	Item::print();
}
