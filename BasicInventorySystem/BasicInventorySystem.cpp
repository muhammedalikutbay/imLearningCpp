#include <iostream>  
#include <vector>  
#include <string>
#include <limits>

using namespace std;



static void addItem(vector<string>& inventory)
{
	string item;
	cout << "Lütfen Item Ýsmini Giriniz: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, item);
	inventory.push_back(item);
}

static void listInventory(const vector<string>& inventory) 
{
	if (inventory.empty()) {
		cout << "Envanter Boþ" << endl;
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
		cout << "Geçersiz ID!\n";
	}
}

static void editItem(vector<string>& inventory, const int id) 
{
	if (id-1>=0 && id-1 < inventory.size())
	{
		string item;
		cout << "Lütfen Yeni Item Ýsmini Giriniz: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, item);
		inventory[id - 1] = item;
		cout << "Item Güncellendi!\n";
	}
	else
	{
		cout << "Geçersiz ID!\n";
	}
}


static int getId()
{
	int id;
	cout << "Lütfen Ýþlem Yapacaðýnýz Itemin IDsini Giriniz:";
	cin >> id;
	return id;
}

static void findItem(vector<string>& inventory)
{
	bool found = false;
	string name;
	cout << "Lütfen Aranacak Item Ýsmini Giriniz: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);

	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i].find(name) != string::npos) {
			cout << "Bulundu: " << i + 1 << ". " << inventory[i] << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "Aradýðýnýz item yok.\n";
	}
}


int main()
{
	int selection = 0;
	cout << "Lütfen yapmak istediðiniz iþlemi seçin";
	vector<string> inventory;

	do
	{
		cout << "\n--- Menü ---\n";
		cout << "1. Item Ekle\n";
		cout << "2. Envanteri Listele\n";
		cout << "3. Item Sil\n";
		cout << "4. Item Adý Düzenle\n";
		cout << "5. Item Aramam\n";
		cout << "6. Çýkýþ\n";
		cout << "Seçiminiz: ";
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
			cout << "Ýyi Günler! \n";
			break;
		default:
			cout << "Geçersiz seçim!\n";
			break;
		}

	} while (selection != 6);

}
