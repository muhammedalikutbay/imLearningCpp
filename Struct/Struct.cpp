#include <iostream>
#include <vector>

using namespace std;

struct Book
{
	string title;
	string author;
	int pageCount;

	Book(string t, string a, int p) : title(t), author(a), pageCount(p) {};

	 void printBooks(int index) const
	{
		cout << "-----------*------------\n";
		cout << index + 1 << ". Kitap Adý: " << title << endl;
		cout << index + 1 << ". Kitap Yazarý: " << author << endl;
		cout << index + 1 << ". Sayfa Sayýsý: " << pageCount << endl;
	}
};

vector<Book> books = 
{
	Book("Hayvan Çiftliði","Orwell",90),
	Book("1984","Orwell",200)
};



int main ()
{
	for (size_t i = 0; i < books.size(); i++)
	{
		books[i].printBooks(i);
	}
}