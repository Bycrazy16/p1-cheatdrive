#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

// Spazio per il terminatore ('\0')
const int DIM_RIGA = 80 + 1;

int min(int a, int b);

int main(int argc,char* argv[]) {
  // Stream ingresso/uscita
  fstream my_in, my_out;
  char riga[DIM_RIGA];

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
  // Allocazione dinamica
  char** righe = new char* [numero_righe];

  // Supponiamo che vada sempre a buon fine
  my_out.open(argv[3],ios::out);

  // Leggo la prima riga del file
  my_in.getline(riga, DIM_RIGA);
  int i;
  for(i = 0;!my_in.eof() && i < numero_righe; i++) {
    // Allocazione dinamica
    righe[i] = new char[strlen(riga) + 1];
    // "strncpy" non e' necessaria qui, riga non puo'
    // superare DIM_RIGA caratteri
    strcpy(righe[i], riga);
    // Leggo la riga successiva del file
    my_in.getline(riga, DIM_RIGA);
  }
  
  // Salvo le righe nel file di output
  for(int j = min(i, numero_righe) - 1; j >= 0; j--) {
    // Salva solo righe dispari
    if((j % 2) == 1) {
      my_out << righe[j] << endl;
    }
    // Dealloco la riga gia' salvata
    delete [] righe[j];
  }

  // Chiusura stream
  my_in.close();
  my_out.close();
  return(0);
}

int min(int a, int b) {
  return a < b ? a : b;
}
