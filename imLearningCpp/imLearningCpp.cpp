
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

double averageCalculate(const vector<int> &notes)
{
	double totalNotes = 0;
	for (int x : notes) totalNotes += x;
	double average = totalNotes / notes.size();
	cout << "Öðrencinin Ortalamasý: " << average << endl;
	return average;
}

void letterGrade(const double average)
{
	char letterGrade;
	if (average > 89)
	{
		letterGrade = 'A';
	}
	else if (average > 79)
	{
		letterGrade = 'B';
	}
	else if (average > 69)
	{
		letterGrade = 'C';
	}
	else if (average > 49)
	{
		letterGrade = 'D';
	}
	else
	{
		letterGrade = 'F';
	}

	

	cout << "Öðrencinin Harf Notu: " << letterGrade;

	switch (letterGrade)
	{
	default:
		break;
	case 'A':
		cout << " - " << "Mükemmel" << endl;
		break;
	case 'B':
		cout << " - " << "Ýyi" << endl;
		break;
	case 'C':
		cout << " - " << "Orta" << endl;
		break;
	case 'D':
		cout << " - " << "Geçti" << endl;
		break;
	case 'F':
		cout << " - " << "Kaldý" << endl;
		break;
	}
}

void studenInfo()
{
	string studentName;
	int lengthOfQuiz;
	cout << "Öðrenci Adýný Giriniz: ";
	cin >> studentName;
	cout << "Girilecek Sýnav Sayýsý: ";
	cin >> lengthOfQuiz;

	vector<int> notes(lengthOfQuiz);

	for (int i = 0; i < lengthOfQuiz; i++)
	{
		cout << i + 1 << ". Sýnav Notunu Giriniz: ";
		cin >> notes[i];
	}

	cout << "Öðrenci Adý: " << studentName << endl;
	for (int i = 0; i < notes.size(); i++)
	{
		cout << i + 1 << ". Sýnav Notu: " << notes[i] << endl;
	}

	letterGrade(averageCalculate(notes));

}

int main()
{
	SetConsoleOutputCP(65001); // Çýktý UTF-8
	SetConsoleCP(65001);       // Girdi UTF-8

	cout << "Basit Öðrenci Not Sistemi!\n";
	studenInfo();
}


