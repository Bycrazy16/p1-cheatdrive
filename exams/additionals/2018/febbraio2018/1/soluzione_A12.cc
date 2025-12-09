#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAX_LENGTH = 81;
const int PREAMBLE_LENGTH = 7;
const char PREAMBLE[PREAMBLE_LENGTH + 1] = "http://";
const char DOMAIN_SEPARATOR = '.';
const char PATH_SEPARATOR = '/';

int index_of(const char stringa[], char simbolo);
int index_of(const char stringa[], int offset, char simbolo);
bool startsWith(const char ricerca[], const char in[]);
bool is_allowed(char simbolo);
bool is_valid_domain(const char stringa[], int offset, int end);
bool is_valid_path(const char stringa[], int offset, int end);
bool is_valid_url(const char stringa[]);

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
    if (is_valid_url(token)) {
      // L'indirizzo e' valido
      cout << token << endl;
    }
    in >> token;
  }

  // Chiude il file
  in.close();

  return 0;
}

int index_of(const char stringa[], char simbolo) {
  return index_of(stringa, 0, simbolo);
}

int index_of(const char stringa[], int offset, char simbolo) {
  // Ritorna l'indice della prima occorrenza di simbolo
  // in stringa, o -1 se non trovata.
  // Il primo carattere ha indice pari a 0 (zero)
  // E' possibile utilizzare questa funzione anche per ricercare 
  // l'indice del carattere terminatore
  int i = offset;
  // Attenzione: non controlla se "offset" e'
  // minore della lunghezza della stringa
  while (stringa[i] != simbolo && stringa[i] != '\0' && i < MAX_LENGTH) {
    i++;
  }
  return stringa[i] == simbolo ? i : (simbolo == '\0' ? MAX_LENGTH - 1 : -1);
}

bool is_allowed(char simbolo) {
  // Ritorna true se il carattere e' ammesso nella
  // parola, false altrimenti
  return ((simbolo >= 'a' && simbolo <= 'z')
        || (simbolo >= 'A' && simbolo <= 'Z')
        || (simbolo >= '0' && simbolo <= '9')
        || (simbolo == '_'));
}

bool startsWith(const char ricerca[], const char in[]) {
  // Ritorna vero se e solo se "in" comincia
  // con "ricerca"
  bool ris = false;
  // Calcola la lunghezza delle due stringhe
  int lun_ricerca = index_of(ricerca, '\0'),
      lun_in = index_of(in, '\0');
  if(lun_ricerca <= lun_in) {
    ris = true;
    for(int i = 0; i < lun_ricerca && ris; i++) {
      if(ricerca[i] != in[i]) {
        ris = false;
      }
    }
  }
  return ris;
}

bool is_valid_domain(const char stringa[], int offset, int end) {
  bool ris = false;
  // Lunghezza minima: 3 caratteri
  if(end - offset >= 2) {
    ris = true;
    for(int i = offset; i < end && ris; i++) {
      // Non e' nessuno dei caratteri ammessi
      if(!is_allowed(stringa[i]) && stringa[i] != DOMAIN_SEPARATOR) {
        ris = false;
      }
    }
  }
  return ris;
}

bool is_valid_path(const char stringa[], int offset, int end) {
  bool ris = false;
  // Puo' anche essere vuoto
  if(end - offset >= 0) {
    ris = true;
    for(int i = offset; i < end && ris; i++) {
      // Non e' nessuno dei caratteri ammessi
      if(!is_allowed(stringa[i]) && stringa[i] != PATH_SEPARATOR) {
        ris = false;
      }
    }
  }
  return ris;
}

bool is_valid_url(const char stringa[]) {
  bool ris = false;
  // Calcola la lunghezza della stringa
  int len = index_of(stringa, '\0');
  // Deve cominciare con "http://"
  if(startsWith(PREAMBLE, stringa)) {
    int firstSeparator = index_of(stringa, PREAMBLE_LENGTH, PATH_SEPARATOR); 
    // Il nome del dominio deve essere valido
    if(is_valid_domain(stringa, PREAMBLE_LENGTH + 1, firstSeparator)) {
      // Il percorso alla risorsa deve essere valido
      if(is_valid_path(stringa, firstSeparator + 1, len)) {
        ris = true;
      }
    } 
  }
  return ris;
}
