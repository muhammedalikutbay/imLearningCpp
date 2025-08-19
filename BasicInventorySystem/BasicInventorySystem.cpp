#include <iostream>  
#include <vector>  
#include <string>
#include <limits>

using namespace std;



static void addItem(vector<string>& inventory)
{
	string item;
	cout << "L�tfen Item �smini Giriniz: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, item);
	inventory.push_back(item);
}

static void listInventory(const vector<string>& inventory) 
{
	if (inventory.empty()) {
		cout << "Envanter Bo�" << endl;
	}
	else {
		cout << "--- Envanter ---" << endl;
		for (int i = 0; i < inventory.size(); i++) {
			cout << i + 1 << ". " << inventory[i] << endl;
		}
	}
}


static void deleteItem(vector<string>& inventory, const int id)
{
	if (id >= 0 && id < inventory.size())
	{
		string item = inventory[id-1];
		inventory.erase(inventory.begin() + (id-1));
		cout << "Item \"" << item << "\" silindi.\n";
	}
	else {
		cout << "Ge�ersiz ID!\n";
	}
}

static void editItem(vector<string>& inventory, const int id) 
{
	if (id-1>=0 && id-1 < inventory.size())
	{
		string item;
		cout << "L�tfen Yeni Item �smini Giriniz: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, item);
		inventory[id - 1] = item;
		cout << "Item G�ncellendi!\n";
	}
	else
	{
		cout << "Ge�ersiz ID!\n";
	}
}


static int getId()
{
	int id;
	cout << "L�tfen ��lem Yapaca��n�z Itemin IDsini Giriniz:";
	cin >> id;
	return id;
}

static void findItem(vector<string>& inventory)
{
	bool found = false;
	string name;
	cout << "L�tfen Aranacak Item �smini Giriniz: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);

	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i].find(name) != string::npos) {
			cout << "Bulundu: " << i + 1 << ". " << inventory[i] << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "Arad���n�z item yok.\n";
	}
}


int main()
{
	int selection = 0;
	cout << "L�tfen yapmak istedi�iniz i�lemi se�in";
	vector<string> inventory;

	do
	{
		cout << "\n--- Men� ---\n";
		cout << "1. Item Ekle\n";
		cout << "2. Envanteri Listele\n";
		cout << "3. Item Sil\n";
		cout << "4. Item Ad� D�zenle\n";
		cout << "5. Item Aramam\n";
		cout << "6. ��k��\n";
		cout << "Se�iminiz: ";
		cin >> selection;

		string item;
		switch (selection)
		{
		case 1:
			addItem(inventory);
			break;
		case 2:
			listInventory(inventory);
			break;
		case 3:
			deleteItem(inventory, getId());
				break;
		case 4:
			editItem(inventory, getId());
			break;
		case 5:
			findItem(inventory);
			break;
		case 6:
			cout << "�yi G�nler! \n";
			break;
		default:
			cout << "Ge�ersiz se�im!\n";
			break;
		}

	} while (selection != 6);

}
