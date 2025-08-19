
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
		cout << "Kitap Adý: " << title << endl;
		cout << "Yazar: " << author << endl;
		cout << "Sayfa Sayýsý: " << pageCount << endl;
		
	}
private:
	string title;
	string author;
	int pageCount;
};

int main()
{
	Book book1 = { "Hayvan Çiftiði","Orwell",180 };
	Book book2 = { "1984","Orwell",120 };
	
	book1.printInfo();
	book2.printInfo();
	
	int newPageCounter;
	cout << book1.getTitle() << " Kitabýn yeni sayfa sayýsýný giriniz: ";
	cin >> newPageCounter;
	book1.setPageCount(newPageCounter);

	cout << book1.getTitle() << " Kitabýn yeni sayfa sayýsý" << book1.getPageCount() << " olarak güncellendi\n";

}
