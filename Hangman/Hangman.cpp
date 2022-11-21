#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <time.h>

using namespace std;

fstream f("cuvinte.in");

void choice(int choice);
char folosita[33];

void mainMenu() {
	system("cls");
	cout << "~~~~~HANGMAN~~~~~";
	int alegere;
	cout << "~~~~~HANGMAN~~~~~\n\nAlege din meniul de mai jos\n\n1.Intra in joc\n2.Iesi din joc\n\nAlegere: ";
	cin >> alegere;
	choice(alegere);
}
void threeDots() {
	for (int i = 0; i < 3; i++) {
		cout << ".";
		Sleep(1000);
	}
}
bool analiza(string cuvant, char litera) {
	int i = 0;
	for (i; i < cuvant.length(); i++) {
		if (cuvant[i] == litera) {
			return true;
		}
	}
	return false;
}
void choice(int choice) {
	switch (choice) {
	case 1: {
		int i = 0, j = 0, random, sanse = 5;
		string cuvinte[120], cuvant, cuvant_de_ghicit, cuvant_ghicit[20];
		char litera, litera_folosita[33];
		system("cls");
		cout << "~~~~~HANGMAN~~~~~\n\nUn cuvant a fost ales.\nTrebuie sa ii ghicesti pe rand literele.\n\n";
		while (getline(f, cuvant)) {
			cuvinte[i] = cuvant;
			i++;
		}
		random = rand() % i;
		cuvant_de_ghicit = cuvinte[random];
		for (int i = 0; i < cuvant_de_ghicit.length(); i++) {
			cout << "_ ";
			cuvant_ghicit[i] = "_";
		}
		cout << "\n\nAi " << sanse << " sanse\n\n" << "Litera: ";
		cin >> litera;
		while (sanse != 0) {
			if (analiza(cuvant_de_ghicit, litera)) {
				string cuvant_final;
				int k = 0;
				for (int i = 0; i < cuvant_de_ghicit.length(); i++) {

				}
				for (int i = 0; i < cuvant_de_ghicit.length(); i++) {
					//k++;
					//if (cuvant_de_ghicit[i] == cuvant_final[i]) {
						if (k == cuvant_de_ghicit.length() - 1) {
							cout << "Felicitari, ai castigat! Vei fi redirectionat la meniul initial.\n\nSe incarca";
							threeDots();
						}
					//}
					else break;
				}
				system("cls");
				cout << "~~~~~HANGMAN~~~~~\n\n";
				litera_folosita[j] = litera;
				j++;
				cout << "Litere folosite: ";
				/*if (cuvant_de_ghicit == cuvant_ghicit) {
					cout << "Felicitari ai castigat!";
				}
				for (int i = 0; i < cuvant_ghicit.length(); i++) {
				
				}*/

				for (int i = 0; i < cuvant_de_ghicit.length(); i++) {
					
				}
				for (int i = 0; i < cuvant_de_ghicit.length(); i++) {
					if (cuvant_de_ghicit[i] == litera) cuvant_ghicit[i] = litera;
				}
				cout << "\n\n";
				for (int i = 0; i < cuvant_de_ghicit.length(); i++) {
					cout << cuvant_ghicit[i] << " ";
				}
				cout << "\n\nAi " << sanse << " sanse\n\n" << "Litera: ";
				cin >> litera;
				k = cuvant_de_ghicit.length() - 1;
			}
		}
		break;
	}
	case 2: {
		system("cls");
		cout << "~~~~~HANGMAN~~~~~\n\nAplicatia se va inchide imediat\n\nSe incarca";
		threeDots();
		exit(0);
	}
		default: {
			break;
		}
	}
}

int main() {
	srand(time(NULL));
	mainMenu();
	string cuvant, cuvinte[10];
	int i = 0;
	while (getline(f, cuvant)) {
		cuvinte[i] = cuvant;
		i++;
	}
	for (int i = 0; i < 2; i++) {
		cout << cuvinte[i] << " ";
	}
	char cacat[10];
	cout << cuvinte[0];
	return 0;
}