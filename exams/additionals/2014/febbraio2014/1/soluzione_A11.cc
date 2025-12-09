#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAX_LENGTH = 81;

// Ritorna l'indice della prima occorrenza di simbolo
// in stringa, o l'indice del primo '\0' se non trovato.
// E' possibile utilizzare questa funzione anche per ricercare
// l'indice del carattere terminatore.
//
int index_of(const char *stringa, char simbolo) {
	int i;
	for (i = 0; (stringa[i] != simbolo) && (stringa[i] != '\0'); i++)
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
			|| (simbolo == '_'));
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

// Controlla se la stringa e' un indirizzo email valido
bool is_mail(char stringa[]) {
	bool res;
	int at = index_of(stringa, '@');
	int terminatore = index_of(stringa, '\0');
	if (at == terminatore) // la stringa non contiene un "@"
		res = false;
	else {
		if ((is_word(stringa, 0, at - 1))
				&& (is_word(stringa, at + 1, terminatore - 1))) {
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
		if (is_mail(token)) {
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
