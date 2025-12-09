#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int DIMENSIONE_RIGA = 255 + 1;

int main(int argc, char * argv[]) {
  fstream in, out;
  int n_righe;
  char riga[DIMENSIONE_RIGA];
  char** righe;
  
  // Controllo argomenti passati in ingresso
  if (argc != 4) {
    cerr << "Sintassi: ./a.out <file_di_input> <numero_righe> <file_di_output>" << endl;
    exit(EXIT_FAILURE);
  }
  
  // Tentativo di apertura file di input
  in.open(argv[1], ios::in);
  if (in.fail()) {
    cerr << "Il file " << argv[1] << " non esiste o non e' accessibile.\n";
    exit(EXIT_FAILURE);
  }

  // Legge il numero di righe dal parametro a riga di comando
  // (supponiamo sia sempre <= al numero effettivo di righe del file)
  n_righe = atoi(argv[2]);

  // Alloca lo spazio per le righe
  righe = new char* [n_righe];
  // Leggo il file di input, riga per riga
  int r = 0;
  while(in.getline(riga, DIMENSIONE_RIGA) && r < n_righe) {
    int lun = strlen(riga);
    // Alloca lo spazio per questa riga
    righe[r] = new char[lun + 1];
    for(int i = 0; i < lun; i++) {
      if(riga[i] != ' ' && riga[i] != '\t') {
        // Trasformo il carattere secondo l'algoritmo
        righe[r][i] = (r % 2 == 0 ? '!' : '?');
      } else {
        // Aggiungo il separatore appena letto
        righe[r][i] = riga[i];
      }
    }
    // Aggiungo il terminatore di stringa
    righe[r][lun] = '\0';
    // Aggiorno il contatore delle righe lette
    r++;
  }

  // Chiude lo stream di input
  in.close();

  // Supponiamo che l'apertura del file di output
  // vada sempre a buon fine
  out.open(argv[3], ios::out);

  // Salva le righe al contrario
  for(int i = r - 1; i >= 0; i--) {
    out << righe[i] << endl;
  }

  // Chiude lo stream di output
  out.close();

  return 0;
}
