#include <iostream>
#include "mazzo.h" /* init_mazzo(), pesca_carta() */

using namespace std;

void gioca(int &punteggio);

int main() {
	int punteggio = 0;

	init_mazzo();
	gioca(punteggio);

	if (punteggio == 15) {
		cout << "HAI VINTO!" << endl;
	} else {
		if (punteggio > 15)
			cout << "HAI PERSO, il tuo punteggio totale e’ " << punteggio << endl;
		else
			cout << "TI SEI RITIRATO, il tuo punteggio totale e’ " << punteggio << endl;
	}
}

void gioca(int &punteggio) {
	char vuole_carta;
	
	do {
		int carta = pesca_carta();
		cout << "Il banco da carta con valore " << carta << endl;
		punteggio += carta;
		cout << "	Hai totalizzato " << punteggio << " punti " << endl;
		if (punteggio < 15) {
			cout << "	Vuoi un’altra carta? (s/n) ";
			cin >> vuole_carta;
		}
	} while (punteggio < 15 && vuole_carta == ’s’);
}
