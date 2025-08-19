
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

double averageCalculate(const vector<int> &notes)
{
	double totalNotes = 0;
	for (int x : notes) totalNotes += x;
	double average = totalNotes / notes.size();
	cout << "��rencinin Ortalamas�: " << average << endl;
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

	

	cout << "��rencinin Harf Notu: " << letterGrade;

	switch (letterGrade)
	{
	default:
		break;
	case 'A':
		cout << " - " << "M�kemmel" << endl;
		break;
	case 'B':
		cout << " - " << "�yi" << endl;
		break;
	case 'C':
		cout << " - " << "Orta" << endl;
		break;
	case 'D':
		cout << " - " << "Ge�ti" << endl;
		break;
	case 'F':
		cout << " - " << "Kald�" << endl;
		break;
	}
}

void studenInfo()
{
	string studentName;
	int lengthOfQuiz;
	cout << "��renci Ad�n� Giriniz: ";
	cin >> studentName;
	cout << "Girilecek S�nav Say�s�: ";
	cin >> lengthOfQuiz;

	vector<int> notes(lengthOfQuiz);

	for (int i = 0; i < lengthOfQuiz; i++)
	{
		cout << i + 1 << ". S�nav Notunu Giriniz: ";
		cin >> notes[i];
	}

	cout << "��renci Ad�: " << studentName << endl;
	for (int i = 0; i < notes.size(); i++)
	{
		cout << i + 1 << ". S�nav Notu: " << notes[i] << endl;
	}

	letterGrade(averageCalculate(notes));

}

int main()
{
	SetConsoleOutputCP(65001); // ��kt� UTF-8
	SetConsoleCP(65001);       // Girdi UTF-8

	cout << "Basit ��renci Not Sistemi!\n";
	studenInfo();
}


