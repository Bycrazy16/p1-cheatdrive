#include <iostream>
#include <cstring>

using namespace std;

const char SEGNAPOSTO = '?';

// Dichiarare qui sotto la funzione invert
char* invert(char* in, int dim);
void invert_ric(char* in, char* out, int dim, int pos);
bool lettere_a_o(char c);

int main(int argc, char* argv[]) {
	char *inverse;
	int dim;

	if (argc < 2) {
		cerr << "Il comando richiede un argomento." << endl;
		return -1;
	}

	dim = strlen(argv[1]);
	inverse = invert(argv[1], dim);
	cout << "Array invertito: ";

	for (int i = 0; i < dim; i++) {
		cout << inverse[i] << " ";
	}
	cout << endl;

	return 0;
}

bool lettere_a_o(char c) {
	return (c == 'a' || c == 'A' || c == 'o' || c == 'O');
}

// Definire qui sotto la funzione invert
char* invert(char* in, int dim) {
	// Allocazione dinamica
	char* out = new char[dim];
	// Chiamata iniziale
	invert_ric(in, out, dim, 0);
	// Ritorno puntatore ad array dinamico
	return out;
}

void invert_ric(char* in, char* out, int dim, int pos) {
	// Finisce quando non ha piu' caratteri da copiare
	if (pos < dim) {
		// Copia l'ultimo carattere di in nel primo carattere
		// di out, e cosi' via; sostituisce con il carattere
		// segnaposto se e' il caso
		if (lettere_a_o(in[dim - pos - 1])) {
			out[pos] = SEGNAPOSTO;
		} else {
			out[pos] = in[dim - pos - 1];
		}
		// Chiamata ricorsiva
		invert_ric(in, out, dim, pos + 1);
	}
}

