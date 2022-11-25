#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <time.h>
#include <list>

using namespace std;

fstream f;

void mainMenu();
void threeDots();

bool verificaCuvantExistent(string cuvant) {
	string cuvinte[120], c;
	bool existent = false;
	f.open("cuvinte.in");
	while (getline(f, c)) {
		if (c == cuvant) existent = true;
	}
	f.close();
	if (existent) return true;
	else return false;
}

void adaugaCuvant() {
	string cuvant;
	system("cls");
	cout << "~~~~~HANGMAN~~~~~\n\nCuvantul de adaugat: "; cin >> cuvant;
	while (verificaCuvantExistent(cuvant)) {
		system("cls");
		cout << "~~~~~HANGMAN~~~~~\n\nAcest cuvant exista in baza de date!\n\nCuvantul de adaugat: "; cin >> cuvant;
	}
	f.open("cuvinte.in", ios::app);
	f << cuvant << endl;
	f.close();
	cout << "\nCuvantul a fost adaugat cu succes, vei fi redirectionat catre meniul principal.\n\nSe incarca";
	threeDots();
	mainMenu();
}

void Iesire() {
	system("cls");
	cout << "~~~~~HANGMAN~~~~~\n\nJocul se va inchide in catea secunde.\n\nSe incarca";
	threeDots();
	exit(0);
}

void choice(int choice) {
	switch (choice) {
	case 1: {
		list<string> cuvinte;
		string s;
		f.open("cuvinte.txt");
		int i = 0;
		while (getline(f, s)) {
			cuvinte.push_back(s);
		}
		for (string v : cuvinte) {
			cout << v << endl;
		}
		f.close();
		break;
	}
	case 2: {
		adaugaCuvant();
		break;
	}
	case 3: {
		Iesire();
		break;
	}
	default: {
		break;
	}
	}
}

void mainMenu() {
	system("cls");
	cout << "~~~~~HANGMAN~~~~~";
	int alegere;
	cout << "~~~~~HANGMAN~~~~~\n\nAlege din meniul de mai jos\n\n1.Intra in joc\n2.Adauga cuvant\n3.Iesi din joc\n\nAlegere: ";
	cin >> alegere;
	choice(alegere);
}

void threeDots() {
	for (int i = 0; i < 3; i++) {
		cout << ".";
		Sleep(1000);
	}
}

int main() {
	srand(time(NULL));
	f.open("cuvinte.txt");
	mainMenu();
	return 0;
}