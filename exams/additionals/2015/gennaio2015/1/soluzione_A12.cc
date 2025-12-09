#include <iostream>
#include <fstream>

using namespace std;

// Vocali, minuscole e maiuscole
const int NUMERO_VOCALI = 10;
const char VOCALI[NUMERO_VOCALI + 1] = "aAeEiIoOuU";

int main(int argc, char* argv[]) {
	
	fstream my_in, my_out;
	
	char buf[256];
	
	if (argc != 3) {
		cout << "Sintassi: ./a.out <input> <output>\n";
		exit(0);
	}
	
	my_in.open(argv[1], ios::in);
	my_out.open(argv[2], ios::out);
	
	// cin-loop
	while (my_in >> buf) {
		// Verifica se la parola comincia per vocale
		bool vocale = false;
		// Non si puo’ utilizzare strlen, ne’ strchr,
		// ne’ altre funzioni della libreria cstring
		for (int i = 0; i < NUMERO_VOCALI && !vocale; i++) {
			if (buf[0] == VOCALI[i]) {
				vocale = true;
			}
		}
		// Stampa nel file di output
		if (vocale) {
			my_out << "1 ";
		} else {
			my_out << "0 ";
		}
	}
}
