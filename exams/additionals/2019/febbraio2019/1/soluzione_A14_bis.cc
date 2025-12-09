#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

// Spazio per il terminatore ('\0')
const int DIM_RIGA = 80 + 1;
const char VOCALI[11] = "aAeEiIoOuU";

bool vocale(char c);
void reverse_copy(fstream& in, fstream& out, int num_righe, int indice_riga);

int main(int argc,char* argv[]) {
  // Stream ingresso/uscita
  fstream my_in, my_out;

  // Controllo parametri in ingresso
  if (argc != 4) {
    cerr << "Utilizzo: ./a.out <ingresso> <numero_righe> <uscita>\n";
    exit(-1);
  }

  // Apertura file in ingresso
  my_in.open(argv[1],ios::in);
  if (my_in.fail()) {
    cerr << "Apertura file " << argv[1] << " fallita.\n";
    exit(-1);
  }

  // Numero di righe da parametro da riga comando
  int numero_righe = atoi(argv[2]);

  // Supponiamo che vada sempre a buon fine
  my_out.open(argv[3],ios::out);

  // Copia all'incontrario ricorsiva
  reverse_copy(my_in, my_out, numero_righe, 0);

  my_in.close();
  my_out.close();
  return(0);
}

void reverse_copy(fstream& in, fstream& out, int num_righe, int indice_riga) {
  // Verifico che il numero di righe lette non sia gia'
  // sufficiente
  if(indice_riga < num_righe) {
    char riga[DIM_RIGA];
    // Leggo una riga del file
    in.getline(riga, DIM_RIGA);
    // Se il file non e' concluso
    if(!in.eof()) {
      // Ricorsione
      reverse_copy(in, out, num_righe, indice_riga + 1);
    }
    // Stampo la riga nel file di output
    // se non comincia per vocale
    if(strlen(riga) > 0 && !vocale(riga[0])) {
      out << riga << endl;
    }
  }
}

bool vocale(char c) {
  return (strchr(VOCALI, c) != NULL);
}
