#include <iostream>
#include <cstring>

using namespace std;

const char SEGNAPOSTO = '*';

// Dichiarare qui sotto la funzione invert
char* invert(char* in, int dim);
void invert_ric(char* in, char* out, int dim, int pos);
bool vocale_maiuscola(char c);

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

bool vocale_maiuscola(char c) {
	return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
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
		if (vocale_maiuscola(in[dim - pos - 1])) {
			out[pos] = SEGNAPOSTO;
		} else {
			out[pos] = in[dim - pos - 1];
		}
		// Chiamata ricorsiva
		invert_ric(in, out, dim, pos + 1);
	}
}

