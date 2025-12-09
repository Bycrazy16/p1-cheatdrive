#include <iostream>
#include "mazzo.h" /* init_mazzo(), pesca_carta() */

using namespace std;

void gioca(int &punteggio);

int main() {
	int punteggio = 0;
	
	init_mazzo();
	gioca(punteggio);
	
	if (punteggio == 21) {
		cout << "HAI VINTO!" << endl;
	} else {
		if (punteggio > 21)
			cout << "HAI PERSO, il punteggio totale e' " << punteggio << endl;
		else
			cout << "TI SEI RITIRATO, il tuo punteggio totale e' " << punteggio << endl;
	}
}

void gioca(int &punteggio) {
	char vuole_carta;
	
	do {
		int carta = pesca_carta();
		cout << "Il banco da carta con valore " << carta << endl;
		punteggio += carta;
		cout << "	Hai totalizzatp " << punteggio << " punti " << endl;
		if (punteggio < 21) {
			cout << "	Vuoi un'altra carta? (s/n) ";
			cin >> vuole_carta;
		}
	} while (punteggio < 21 && vuole_carta == 's');
} 
