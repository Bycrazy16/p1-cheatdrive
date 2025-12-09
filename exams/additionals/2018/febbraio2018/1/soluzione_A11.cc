#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAX_LENGTH = 81;

int index_of(const char *stringa, char simbolo);
bool is_allowed(char simbolo);
bool valid_word(const char * word, int start, int end);
bool is_mail(char stringa[]);

int main(int argc, char * argv[]) {
  fstream in;

  // Controllo argomenti passati in ingresso
  if (argc != 2) {
    cerr << "Sintassi: ./a.out <in>." << endl;
    exit(EXIT_FAILURE);
  }

  // Tentativo di apertura file di input
  in.open(argv[1], ios::in);
  if (in.fail()) {
    cerr << "Il file " << argv[1] << " non esiste o non e' accessibile.\n";
    exit(EXIT_FAILURE);
  }

  char token[MAX_LENGTH];
  in >> token;
  while (!in.eof()) {
    if (is_mail(token)) {
      // L'indirizzo e' valido
      cout << token << endl;
    }
    in >> token;
  }

  // Chiude il file
  in.close();

  return 0;
}

// Ritorna l'indice della prima occorrenza di simbolo
// in stringa, o -1 se non trovata.
// Il primo carattere ha indice pari a 0 (zero)
// E' possibile utilizzare questa funzione anche per ricercare 
// l'indice del carattere terminatore.
int index_of(const char *stringa, char simbolo) {
  int i = 0;
  while (stringa[i] != simbolo && stringa[i] != '\0' && i < MAX_LENGTH) {
    i++;
  }
  return stringa[i] == simbolo ? i : (simbolo == '\0' ? MAX_LENGTH - 1 : -1);
}

// Ritorna true se il carattere e' ammesso nella
// parola, false altrimenti.
bool is_allowed(char simbolo) {
  return ((simbolo >= 'a' && simbolo <= 'z')
        || (simbolo >= 'A' && simbolo <= 'Z')
        || (simbolo >= '0' && simbolo <= '9')
        || (simbolo == '.')
        || (simbolo == '_'));
}

// Controlla se la parola compresa tra gli indici start/end
// e' valida. Ritorna true se la parola e' valida, false altrimenti
bool valid_word(const char * word, int start, int end) {
  bool ris = true;
  if ((start < 0) || (end <= start)) {
    // Gli indici che delimitano la parola devono essere validi
    // La parola deve essere lunga almeno due caratteri
    ris = false;
  }

  if ((word[start] == '.') || (word[end] == '.')) {
    // Una parola non puo' iniziare o finire con un punto
    ris = false;
  }
  // Controllo tutti i caratteri (compreso l'ultimo)
  for (int i = start; i <= end; i++) {
    if (!is_allowed(word[i])) {
      // Trovato carattere non permesso
      ris = false;
    }
  }
  return ris;
}

// Controlla se la stringa e' un indirizzo email valido
bool is_mail(char stringa[]) {
  bool ris = false;
  int lun = index_of(stringa, '\0');
  int at = index_of(stringa, '@');
  // Se le stringa contiene un carattere at (@) al suo interno
  if (at > -1) {
    if ((valid_word(stringa, 0, at - 1))
        && (valid_word(stringa, at + 1, terminatore - 1))) {
      ris = true;
    }
  }
  return ris;
}
