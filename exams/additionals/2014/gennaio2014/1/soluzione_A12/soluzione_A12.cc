#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// Dichiarazione della funzione "leggiMatrice"
char** leggiMatrice(fstream& in, int r, int c);

int main(int argc, char * argv[]) {
	fstream in;
	int righe, colonne, n;

	// Controllo argomenti passati in ingresso
	if (argc != 2) {
		cerr << "Sintassi: ./a.out <in>." << endl;
		exit (EXIT_FAILURE);
	}

	// Tentativo di apertura file di input
	in.open(argv[1], ios::in);
	if (in.fail()) {
		cerr << "Il file " << argv[1] << " non esiste o non e' accessibile.\n";
		exit (EXIT_FAILURE);
	}

	// Legge il numero di righe e delle colonne necessarie
	// dai primi due numeri contenuti nel file
	in >> righe >> colonne;

	// Invoca la funzione "leggiMatrice" 
	char** matrice = leggiMatrice(in, righe, colonne);

	// Chiude il file
	in.close();

	return 0;
}

// Implementazione della funzione "leggiMatrice"
char** leggiMatrice(fstream& in, int r, int c) {
	int i;
	char car;

	// Alloca la matrice dinamicamente
	char** m = new char*[r];
	for (i = 0; i < r; i++) {
		m[i] = new char[c];
	}

	// Legge i dati dal file
	i = 0;
	in >> car;
	while (!in.eof()) {
		m[i / c][i % c] = car;
		i++;
		in >> car;
	}

	// Ritorna la matrice
	return m;
}
