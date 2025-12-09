#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAX_LENGTH = 81;

// Ritorna il numero di caratteri iniziali che 
//le due stringhe hanno in comune. La funzione e' case sensitive
int starts_with(const char *stringa, const char *sub) {
	int i;
	for (i = 0; stringa[i] == sub[i]; i++)
		;
	return i;
}

// Ritorna true se il carattere e' ammesso nella
// parola, false altrimenti.
//
bool is_allowed(char simbolo) {
	return ((simbolo >= 'a' && simbolo <= 'z')
			|| (simbolo >= 'A' && simbolo <= 'Z')
			|| (simbolo >= '0' && simbolo <= '9') || (simbolo == '.')
			|| (simbolo == '-') || (simbolo == '/'));
}

// Controlla se la parola compresa tra gli indici start/end
// e' valida. Ritorna true se la parola e' valida, false altrimenti
//
bool is_word(const char * word, int start, int end) {
	bool res = true;
	if (end < start) {
		// Gli indici che delimitano la parola devono essere validi
		// La parola deve essere lunga almeno un carattere
		res = false;
	} else if ((word[start] == '.') || (word[end] == '.')) {
		// Una parola non puo' iniziare o finire con un punto
		res = false;
	} else {
		// Controllo tutti i caratteri (compreso l'ultimo)
		for (int i = start; i <= end; i++) {
			if (!is_allowed(word[i])) {
				// Trovato carattere non permesso
				res = false;
			}
		}
	}
	return res;
}

// Controlla se la stringa e' un indirizzo https valido
///
bool is_https(char stringa[]) {
	bool res = false;
	int match = starts_with(stringa, "https://");
	int terminatore;

	//cerco l'indice del terminatore
	for (terminatore = 0; stringa[terminatore] != '\0'; terminatore++)
		;

	if (match < 8) // la stringa non inizia con "https://"
		res = false;
	else {
		if (is_word(stringa, match, terminatore - 1)) {
			res = true;
		}
	}
	return res;
}

int main(int argc, char * argv[]) {
	fstream myin, myout;

	// Controllo argomenti passati in ingresso
	if (argc != 3) {
		cerr << "Sintassi: ./a.out <myin> <myout>." << endl;
		exit (EXIT_FAILURE);
	}

	// Tentativo di apertura file di input
	myin.open(argv[1], ios::in);
	if (myin.fail()) {
		cerr << "Il file " << argv[1] << " non esiste o non e' accessibile.\n";
		exit (EXIT_FAILURE);
	}
	myout.open(argv[2], ios::out);

	char token[MAX_LENGTH];
	myin >> token;
	while (!myin.eof()) {
		if (is_https(token)) {
			// L'indirizzo e' valido
			myout << token << endl;
		}
		myin >> token;
	}
	// Chiude i file
	myin.close();
	myout.close();

	return 0;
}

