#include <iostream>

using namespace std;

const int DIM = 81;

// Dichiarare qui sotto la funzione estrai
char *estrai(char stringa[]);
void estrai_ric(char stringa[], int i, char app[], int i_app);

int main() {
	char stringa[DIM];
	char * estratta;
	char risposta = 'n';

	do {
		cout << "Inserisci la stringa da controllare: ";
		cin >> stringa;

		estratta = estrai(stringa);

		cout << "La stringa estratta e': ";
		cout << estratta;
		cout << endl;
		cout << "Vuoi inserire un'altra stringa? [s/n] ";
		cin >> risposta;
	} while (risposta != 'n');

	return 0;
}

// Definire qui sotto la funzione estrai

char *estrai(char stringa[]) {
	char * app = new char[DIM];

	estrai_ric(stringa, 0, app, 0);

	return (app);
}

void estrai_ric(char stringa[], int i, char app[], int i_app) {
	if (stringa[i] == '\0') {
		app[i_app] = '\0';
	} else {
		if ((stringa[i] >= 'a') && (stringa[i] <= 'z')) {
			app[i_app] = stringa[i];
			estrai_ric(stringa, i + 1, app, i_app + 1);
		} else {
			estrai_ric(stringa, i + 1, app, i_app);
		}
	}
}
