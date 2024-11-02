#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <time.h>
#include <vector>

using namespace std;

fstream f;
ifstream fin;

bool golit;

void mainMenu();
void threeDots();

bool verificaCuvantExistent(string cuvant) {
	string cuvinte[120], c;
	bool existent = false;
	f.open("cuvinte.in");
	int i = 0;
	while (getline(f, c)) {
		for (i; i < cuvant.length(); i++) {
			if (c[i] == toupper(cuvant[i]) || c[i] == tolower(cuvant[i]));
			else break;
		}
		if (i == cuvant.length()) {
			existent = true; 
			break;
		}
		else;
	}
	f.close();
	if (existent) return true;
	else return false;
}

bool esteGol() {
	fin.open("cuvinte.in");
	if (fin.peek() == ifstream::traits_type::eof()) {
		fin.close();
		return true;
	}
	else return false;
}

bool nu_e_litera(string cuvant) {
	bool nu_e_litera = false;
	for (int i = 0; i < cuvant.length(); i++) {
		if (!(cuvant[i] >= 'a' && cuvant[i] <= 'z') && !(cuvant[i] >= 'A' && cuvant[i] <= 'Z'))
		{
			nu_e_litera = true;
			break;
		}
	}
	if (nu_e_litera) return true;
	else return false;
}

void adaugaCuvant() {
	string cuvant;
	system("cls");
	cout << "~~~~~HANGMAN~~~~~\n\nCuvantul de adaugat: "; cin >> cuvant;
	verificaCuvantExistent(cuvant);
	nu_e_litera(cuvant);
	while (nu_e_litera(cuvant) || verificaCuvantExistent(cuvant)) {
		system("cls");
		if (verificaCuvantExistent(cuvant)) {
			cout << "~~~~~HANGMAN~~~~~\n\nAcest cuvant exista in baza de date!\n\nCuvantul de adaugat: "; cin >> cuvant;
			verificaCuvantExistent(cuvant);
		}
		else {
			cout << "~~~~~HANGMAN~~~~~\n\nCuvintele contin doar litere!\n\nCuvantul de adaugat: "; cin >> cuvant;
			nu_e_litera(cuvant);
		}
	}
	for (int i = 0; i <= cuvant.length(); i++) 
	{
		cuvant[i] = tolower(cuvant[i]);
	}
	f.open("cuvinte.in", ios::app);
	f << cuvant << endl;
	f.close();
	system("cls");
	cout << "~~~~~HANGMAN~~~~~\n\nCuvantul a fost adaugat cu succes, vei fi redirectionat catre meniul principal.\n\nSe incarca";
	threeDots();
	mainMenu();
}

void golireFisier() {
	if (esteGol()) {
		mainMenu();
	}
	else
	{
		system("cls");
		cout << "Baza de date a fost golita. Vei fi redirectionat catre meniul principal!\n";
		f.open("cuvinte.in", ios::out | ios::trunc);
		f.close();
		threeDots();
		mainMenu();
	}
}

void Iesire() {
	system("cls");
	cout << "~~~~~HANGMAN~~~~~\n\nJocul se va inchide in catea secunde.\n\nSe incarca";
	threeDots();
	exit(0);
}

void verificaGhicit(string cuvant_random, char litera) {
	string cuvant;
	cuvant += litera;
	cout << cuvant << " ";
}

void jocPrincipal() {
	string cuvant, cuvant_random;
	char litera_folosita[33], litere_cuvant_random[100], cuvant_ghicit[100];
	vector<string> cuvinte;
	cuvinte.clear();
	int i = 1 /**/, incercari = 5;
	//verificare fisier gol
	if (esteGol()) {
		mainMenu();
	}
	else {
		f.open("cuvinte.in");
		while (getline(f, cuvant)) {
			cuvinte.push_back(cuvant);
		}
		f.close();
		for (i-1; i < cuvinte.size() - 1; i++) { // 
			i++;
		}
		int r = rand() % i;
		cuvant_random = cuvinte[r];
		for (i = 0; i < cuvant_random.length(); i++) {
			litere_cuvant_random[i] = cuvant_random[i];
			cuvant_ghicit[i] = '_';
		}
		int k = 0;
		for (i = 0; i < 33; i++) {
			litera_folosita[i] = ' ';
		}
		bool ghicit = false;
		while (incercari != 0 && !ghicit) {
			char litera, c;
			bool l = false;
			system("cls");
			for (i = 0; i < cuvant_random.length(); i++) {
				if (cuvant_random[i] == cuvant_ghicit[i]);
				else break;
			}
			if (i == cuvant_random.length()) {
				ghicit = true;
				break;
			}
			cout << "~~~~~HANGMAN~~~~~\n\nUn cuvant a fost ales. Tu trebuie sa ii ghicesti pe rand literele. Ai " << incercari << " incercari.\n\nLitere folosite: ";
			for (i = 0; i < 33; i++) {
				if (litera_folosita[i] == ' ') break;
				else cout << litera_folosita[i] << " ";
			}
			cout << "\n\nCuvant: ";
			for (i = 0; i < cuvant_random.length(); i++) {
				cout << cuvant_ghicit[i] << " ";
			}
			cout << "\n\nLitera: "; cin >> litera;

			//VERIFICARE FOLOSINTA ALTE CARACTERE
			while (!((litera >= 'a' && litera <= 'z') || !(litera >= 'A' && litera <= 'Z')) && incercari != 0) {
				system("cls");
				incercari--;
				cout << "~~~~~HANGMAN~~~~~\n\nSunt acceptate doar litere!\n\nAi " << incercari << " incercari.\n\nLitere folosite: ";
				for (i = 0; i < 33; i++) {
					cout << litera_folosita[i] << " ";
				}
				cout << "\n\nCuvant: ";
				for (i = 0; i < cuvant_random.length(); i++) {
					cout << cuvant_ghicit[i] << " ";
				}
				cout << "\n\nLitera: "; cin >> litera;
			}
			///////////////////////////////////////
			//VERIFICARE FOLOSINTA LITERE DEJA FOLOSITE
			for (i = 0; i < 33; i++) {
				c = litera_folosita[i];
				if (litera == toupper(c) || litera == tolower(c)) {
					incercari--; break;
				}
			}
			while (((litera == toupper(c) || litera == tolower(c)) || !(litera >= 'a' && litera <= 'z') && !(litera >= 'A' && litera <= 'Z')) && incercari != 0) {
				system("cls");
				incercari--;
				cout << "~~~~~HANGMAN~~~~~\n\nNu poti folosi decat litere nefolosite (exclus simboluri/numere)!\n\nAi " << incercari << " incercari.\n\nLitere folosite: ";
				for (i = 0; i < 33; i++) {
					cout << litera_folosita[i] << " ";
				}
				cout << "\n\nCuvant: ";
				for (i = 0; i < cuvant_random.length(); i++) {
					cout << cuvant_ghicit[i] << " ";
				}
				cout << "\n\nLitera: ";
				cin >> litera;
				for (i = 0; i < 33; i++) {
					c = litera_folosita[i];
					if (litera == toupper(c) || litera == tolower(c)) break;
				}
			}
			////////////////////////////////////////////
			for (i = 0; i < cuvant_random.length(); i++) {
				if (litera == cuvant_random[i]) {
					cuvant_ghicit[i] = litera;
				}
			}
			litera_folosita[k] = litera;
			k++;
		}
		if (ghicit) {
			system("cls");
			cout << "~~~HANGMAN~~~~~\n\nAi castigat! Vei fi redirectionat catre meniul principal.\n\nSe incarca";
			threeDots();
			mainMenu();
		}
		if (incercari == 0) {
			system("cls");
			cout << "~~~HANGMAN~~~~~\n\nAi pierdut! Vei fi redirectionat catre meniul principal.\n\nSe incarca";
			threeDots();
			mainMenu();
		}
	}
}

void choice(char choice) {
	switch (choice) {
		case '1': {
			jocPrincipal();
			break;
		}
		case '2': {
			//listaCuvinte();
			break;
		}
		case '3': {
			adaugaCuvant();
		}
		case '4': {
			golireFisier();
		}
		case '5': {
			Iesire();
			break;
		}
		default: {
			break;
		}
	}
}


void mainMenu() {
	char alegere;
	system("cls");
	cout << "~~~~~HANGMAN~~~~~\n\nAlege din meniul de mai jos\n\n1.Intra in joc\n2.Lista cuvinte\n3.Adauga cuvant\n4.Stergere lista cuvinte\n5.Iesi din joc\n\nAlegere: ";
	cin >> alegere;
	while (!(alegere >= '1' && alegere <= '9')) {
		system("cls");
		cout << "~~~~~HANGMAN~~~~~\n\nAlege din meniul de mai jos\n\n1.Intra in joc\n2.Adauga cuvant\n3.Iesi din joc\n\nAlegere: ";
		cin >> alegere;
	}
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
	mainMenu();
	return 0;
}