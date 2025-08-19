
#include <iostream>

using namespace std;

class Book
{
public:
	Book(string t, string a, int p)
	{
		title = t;
		author = a;
		pageCount = p;;
	}

	~Book() { cout << "Book nesnesi siliniyor: " << title << endl; };

	string getTitle() const { return title; }
	string getAutore() const { return author; }
	int getPageCount() const { return pageCount; }

	void setTitle(string t) { title = t; }
	void setAuthor(string a) { author = a; }
	void setPageCount(int p) { if (p > 0) { pageCount = p; } }


	void printInfo() const 
	{
		cout << "----------/--------\n";
		cout << "Kitap Ad�: " << title << endl;
		cout << "Yazar: " << author << endl;
		cout << "Sayfa Say�s�: " << pageCount << endl;
		
	}
private:
	string title;
	string author;
	int pageCount;
};

int main()
{
	Book book1 = { "Hayvan �ifti�i","Orwell",180 };
	Book book2 = { "1984","Orwell",120 };
	
	book1.printInfo();
	book2.printInfo();
	
	int newPageCounter;
	cout << book1.getTitle() << " Kitab�n yeni sayfa say�s�n� giriniz: ";
	cin >> newPageCounter;
	book1.setPageCount(newPageCounter);

	cout << book1.getTitle() << " Kitab�n yeni sayfa say�s�" << book1.getPageCount() << " olarak g�ncellendi\n";

}
