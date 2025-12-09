#include <iostream>
#include <fstream>

using namespace std;

const int SOGLIA = 5;

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
		// Calcola la lunghezza della parola;
		// non si puo’ utilizzare strlen, ne’ strchr,
		// ne’ altre funzioni della libreria cstring
		int lun;
		for (int lun = 0; buf[lun] != '\0' && lun < 256; lun++) {
			// Stampa nel file di output	
			if (lun >= SOGLIA) {
				my_out << lun << " ";
			} else {
				my_out << "0 ";
			}
		}
	}
	
	my_in.close();
	my_out.close();
	
	return (0);
}
