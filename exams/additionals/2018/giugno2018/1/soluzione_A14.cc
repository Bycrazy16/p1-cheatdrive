#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAX_CHAR = 255 + 1;

// Funzioni di utilita'
bool appartiene(char* s, char* lista[], int quanti);
bool appartiene(char* s, char* lista[], int inf, int sup);

int main(int argc,char* argv[]){
  fstream file_a, file_b, file_output;
  int maxnum;
  char parola[MAX_CHAR];
  
  // Controllo parametri in ingresso
  if (argc != 4) {
    cerr << "Sintassi: ./a.out <file_a> <file_b> <risultato>\n";
    exit(-1);
  }

  // Apro il secondo file
  file_b.open(argv[2],ios::in);
  // Controllo apertura secondo file
  if(file_b.fail()) {
    cerr << "Errore apertura secondo file di input\n";
    exit(-1);
  }
  // Numero righe del file
  file_b >> maxnum;
  // Allocazione dinamica
  char** parole = new char* [maxnum];
  int i;
  // Prima parola del file
  file_b >> parola;
  for(i = 0; !file_b.eof(); i++) {
    // Allocazione dinamica
    parole[i] = new char[strlen(parola) + 1];
    // Non e' necessario utilizzare strncpy,
    // perche' "parola" e', per costruzione,
    // una stringa "ben formata"
    strcpy(parole[i], parola);
    // Continua lettura file
    file_b >> parola;
  }
  // A questo punto, file_b non serve piu'
  file_b.close();

  // Apro il primo file
  file_a.open(argv[1],ios::in);
  // Controllo apertura primo file
  if(file_a.fail()) {
    cerr << "Errore apertura primo file di input\n";
    exit(-1);
  }
  // Apro file di output
  file_output.open(argv[3],ios::out);
  // Leggo e scarto il numero righe del secondo file
  // perche' non lo utilizzo
  file_a >> i;
  // Prima parola del file
  file_a >> parola;
  while(!file_a.eof()) { 
    // Se parola e' presente anche in file_b,
    // allora non la salva nel file di output
    if(!appartiene(parola, parole, maxnum)) {
      file_output << parola << endl;
    }
    // Continua lettura file
    file_a >> parola;
  }
  // Chiusura stream secondo file
  file_a.close();
  // Chiusura stream file di output
  file_output.close();

  return(0);
}

bool appartiene(char* s, char* lista[], int quanti) {
  bool trovato = false;
  // Ricerca lineare (funziona, ma vale
  // un punto in meno)
  /*
  int i = 0;
  while(!trovato && i < quanti) {
    if(strcmp(s, lista[i]) == 0) {
      trovato = true;
    }
    i++;
  }
  */
  // Ricerca per bisezione (ricorsiva)
  trovato = appartiene(s, lista, 0, quanti - 1);
  // Ritorno il risultato
  return trovato;
}

bool appartiene(char* s, char* lista[], int inf, int sup) {
  bool ris = false;
  if(inf <= sup) {
    int mid = (inf + sup) / 2;
    int cmp = strcmp(s, lista[mid]);
    if(cmp == 0) {
      ris = true;
    } else if(cmp > 0) {
      ris = appartiene(s, lista, inf, mid - 1);
    } else {
      ris = appartiene(s, lista, mid + 1, sup);
    }
  }
  return ris;
}
