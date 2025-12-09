#include <iostream>
#include "util.h"

using namespace std;

// Inserire qui la DICHIARAZIONE della funzione modificaMatrice

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

// Inserire qui la DEFINIZIONE della funzione modificaMatrice
