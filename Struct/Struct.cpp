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
		cout << index + 1 << ". Kitap Ad�: " << title << endl;
		cout << index + 1 << ". Kitap Yazar�: " << author << endl;
		cout << index + 1 << ". Sayfa Say�s�: " << pageCount << endl;
	}
};

vector<Book> books = 
{
	Book("Hayvan �iftli�i","Orwell",90),
	Book("1984","Orwell",200)
};



int main ()
{
	for (size_t i = 0; i < books.size(); i++)
	{
		books[i].printBooks(i);
	}
}