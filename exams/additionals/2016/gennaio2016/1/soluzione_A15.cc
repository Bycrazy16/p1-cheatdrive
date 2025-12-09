#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

// Spazio per il terminatore ('\0')
const char A_CAPO = '\r';

int min(int a, int b);

int main(int argc, char* argv[]) {
	// Stream ingresso/uscita
	fstream my_in, my_out;

	// Controllo parametri in ingresso
	if (argc != 4) {
		cerr << "Utilizzo: ./a.out <ingresso> <numero_righe> <uscita>\n";
		exit(-1);
	}

	// Apertura file in ingresso
	my_in.open(argv[1], ios::in);
	if (my_in.fail()) {
		cerr << "Apertura file " << argv[1] << " fallita.\n";
		exit(-1);
	}

	// Numero di caratteri da parametro da riga comando
	int numero_caratteri = atoi(argv[2]);
	// Allocazione dinamica
	char* caratteri = new char[numero_caratteri];

	// Supponiamo che vada sempre a buon fine
	my_out.open(argv[3], ios::out);

	char c;
	my_in.get(c);
	int caratteri_letti = 0, caratteri_contati = 0;
	while (!my_in.eof() && caratteri_contati < numero_caratteri) {
		caratteri[caratteri_letti++] = c;
		if (c != A_CAPO) {
			caratteri_contati++;
		}
		my_in.get(c);
	}

	for (int i = min(caratteri_letti, numero_caratteri) - 1; i >= 0; i--) {
		my_out << caratteri[i];
	}
	delete[] caratteri;

	// Chiusura stream
	my_in.close();
	my_out.close();
	
	return (0);
}

int min(int a, int b) {
	return a < b ? a : b;
}
