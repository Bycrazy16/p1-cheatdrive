#include <iostream>
#include <fstream>

using namespace std;

const char CARATTERE = 'a';

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
		// Calcola numero di occorrenze di CARATTERE
		// nella parola
		int n = 0;
		// Non si puo’ utilizzare strlen, ne’ strchr,
		// ne’ altre funzioni della libreria cstring
		for (int i = 0; buf[i] != '\0' && i < 256; i++) {
			if (buf[i] == CARATTERE) {
				n++;
			}
		}
		// Stampa nel file di output
		my_out << n << " ";
	}
	
	my_in.close();
	my_out.close();
	
	return (0);
}
