#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {

	fstream my_in, my_out;					// dichiara due stream
	char tmp[31];							// Per semplicita' si assuma che ogni parola contenuta nel testo del primo file abbia al massimo lunghezza 30 caratteri

	if (argc != 3) {						// controllo l'input dell'utente
		cout << "Usage: ./a.out <sourcefile>\n";
		exit(0);
	}

	my_in.open(argv[1], ios::in);			// apre lo stream in lettura
	my_out.open(argv[2], ios::out);			// apre lo stream in scrittura

	// ========================================================================================================================================================================== //

	// CASO PRIMO CARATTERE DEL FILE
	my_in >> tmp;							// inizia a scrivere da my_in all'interno della stringa di char temporanea
	if (!(tmp[0] >= 'A' && tmp[0] <= 'Z')) {// se il primo carattere non corriponde ad un carattere maiuscolo allora
		tmp[0] = tmp[0] + ('A' - 'a');		// converti il primo carattere da minuscolo a maiuscolo
	}

	// ALL'INTERNO DEL TESTO
	while (!my_in.eof()) {					// finchè non raggiungi la fine del file
		my_out << tmp << " ";				// stampa all'interno del file di output
		if (tmp[strlen(tmp) - 1] == '.' || tmp[strlen(tmp) - 1] == '?' || tmp[strlen(tmp) - 1] == '!') {	// se l'ultimo carattere e' '.', '?' o '!'
			my_in >> tmp;																					// 
			if (!(tmp[0] >= 'A' && tmp[0] <= 'Z')) {														// se il primo carattere non corriponde ad un carattere minuscolo allora
				tmp[0] = tmp[0] + ('A' - 'a');																// converti l'ultimo carattere inserito da minuscolo a maiuscolo
			}
		} else {																							// se l'ultimo carattere non è uno di quelli specificati allora
			my_in >> tmp;																					// continua a scrivere dentro my_in
		}
	}
	
	// ========================================================================================================================================================================== //

	my_in.close();							// chiude lo stream in lettura
	my_out.close();							// chiude lo stream in scrittura
	
	return (0);
}
