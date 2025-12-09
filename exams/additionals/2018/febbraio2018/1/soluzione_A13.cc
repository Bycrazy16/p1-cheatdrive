#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAX_LENGTH = 81;
const char AT_SYMBOL = '@';
const char HASH_SYMBOL = '#';

int index_of(const char stringa[], char simbolo);
int index_of(const char stringa[], int offset, char simbolo);
bool is_allowed(char simbolo);
bool is_valid_mention(const char stringa[], int length);
bool is_valid_hashtag(const char stringa[], int length);
bool is_valid_tag(const char stringa[]);

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
    if (is_valid_tag(token)) {
      // Il tag e' valido 
      cout << token << endl;
    }
    in >> token;
  }

  // Chiude il file
  in.close();

  return 0;
}

int index_of(const char stringa[], char simbolo) {
  // Ritorna l'indice della prima occorrenza di simbolo
  // in stringa, o -1 se non trovata.
  // Il primo carattere ha indice pari a 0 (zero)
  // E' possibile utilizzare questa funzione anche per ricercare 
  // l'indice del carattere terminatore
  int i = 0;
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

bool is_valid_hashtag(const char stringa[], int length) {
  bool ris = false;
  // Lunghezza minima: 5 caratteri
  if(length >= 5) {
    ris = true;
    for(int i = 0; i < length && ris; i++) {
      // Non e' nessuno dei caratteri ammessi
      if(!is_allowed(stringa[i]) && stringa[i] != AT_SYMBOL) {
        ris = false;
      }
    }
  }
  return ris;
}

bool is_valid_mention(const char stringa[], int length) {
  bool ris = false;
  // Deve essere lungo almeno 7 caratteri
  if(length >= 7) {
    ris = true;
    for(int i = 0; i < length && ris; i++) {
      // Non e' nessuno dei caratteri ammessi
      if(!is_allowed(stringa[i]) && stringa[i] != HASH_SYMBOL) {
        ris = false;
      }
    }
  }
  return ris;
}

bool is_valid_tag(const char stringa[]) {
  bool ris = false;
  // Calcola la lunghezza della stringa
  int len = index_of(stringa, '\0');
  // Deve cominciare con "#" oppure "@"
  if(HASH_SYMBOL == stringa[0]) {
    // L'hashtag deve essere valido
    if(is_valid_hashtag(stringa + 1, len - 1)) {
      ris = true;
    } 
  } else if(AT_SYMBOL == stringa[0]) {
    // La mention deve essere valida
    if(is_valid_mention(stringa + 1, len - 1)) {
      ris = true;
    }
  }
  return ris;
}
