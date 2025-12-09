#include <iostream>
#include "util.h"

using namespace std;

float** modificaMatrice(float** matrice, int nc, int nr);

const int NR = 10;
const int NC = 10;

int main(int argc, char * argv[]) {
	float** matriceOriginale = generaMatrice(NR, NC);

	cout << "Matrice originale:" << endl;
	stampaMatrice(matriceOriginale, NR, NC);
	cout << endl;

	float** matriceModificata = modificaMatrice(matriceOriginale, NR, NC);

	cout << "Matrice modificata:" << endl;
	stampaMatrice(matriceModificata, NR, NC);
	cout << endl;

	return 0;
}

float** modificaMatrice(float** matrice, int nc, int nr) {
	// Alloca dinamicamente la matrice da ritornare
	float** daRitornare = new float*[nr];
	for (int i = 0; i < nc; i++) {
		daRitornare[i] = new float[nc];
	}
	// Copia i dati da matrice originale a matrice
	// da ritornare, modificandoli
	for (int i = 0; i < nr; i++) {
		for (int j = 0; j < nc; j++) {
			// Inverso se non nullo
			daRitornare[i][j] = matrice[i][j] == 0 ? 0 : 1 / matrice[i][j];
		}
	}
	// Ritorna la matrice
	return daRitornare;
}
