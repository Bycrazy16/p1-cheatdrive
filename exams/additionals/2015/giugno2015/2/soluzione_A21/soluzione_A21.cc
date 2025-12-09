#include <iostream>
#include "util.h"

using namespace std;

int** modificaMatrice(int** matrice, int nc, int nr);

const int NR = 10;
const int NC = 10;

int main(int argc, char * argv[]) {
	int** matriceOriginale = generaMatrice(NR, NC);
	
	cout << "Matrice originale:" << endl;
	stampaMatrice(matriceOriginale, NR, NC);
	cout << endl;
	
	int** matriceModificata = modificaMatrice(matriceOriginale, NR, NC);
	
	cout << "Matrice modificata:" << endl;
	stampaMatrice(matriceModificata, NR, NC);
	cout << endl;
	
	return 0;
}

int** modificaMatrice(int** matrice, int nc, int nr) {
	// Alloca dinamicamente la matrice da ritornare
	int** daRitornare = new int*[nr];
	for (int i = 0; i < nc; i++) {
		daRitornare[i] = new int[nc];
	}
	// Copia i dati da matrice originale a matrice
	// da ritornare, modificandoli
	for (int i = 0; i < nr; i++) {
		for (int j = 0; j < nc; j++) {
			// Valore assoluto
			daRitornare[i][j] = matrice[i][j] > 0 ? matrice[i][j] : -matrice[i][j];
		}
	}
	// Ritorna la matrice
	return daRitornare;
}
