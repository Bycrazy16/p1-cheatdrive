// Soluzione 1 (iterativa, con allocazione dinamica e due letture)

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int DIM_PAROLA = 50 + 1;
const char* PAROLA_STOP = "HALT";

int main(int argc, char * argv[]) {
  fstream file_input, file_output;

  // Controllo argomenti passati in ingresso
  if (argc != 3) {
      cerr << "Sintassi: ./a.out <file_di_input> <file_di_output>" << endl;
      exit(EXIT_FAILURE);
  }

  // Tentativo di apertura file di input
  file_input.open(argv[1], ios::in);
  if (file_input.fail()) {
      cerr << "Non riesco ad accedere al file di input (" << argv[1] << ")\n";
      exit(EXIT_FAILURE);
  }

  // Buffer per una parola
  char parola[DIM_PAROLA];
  // Contatore parole del file
  int numero_parole = 0;
  // Leggo la prima parola del file
  file_input >> parola;
  // Primo ciclo di lettura, per stimare la dimensione del file
  while(!file_input.eof() && (strcmp(parola, PAROLA_STOP) != 0)) {
    numero_parole++;
    file_input >> parola;
  }

  // Chiudo e riapro il file
  file_input.close();
  file_input.open(argv[1], ios::in);

  // Alloco lo spazio per salvare le parole in memoria
  char** parole = new char* [numero_parole];
  // Secondo ciclo di lettura, per salvare il contenuto in memoria
  for(int i = 0; i < numero_parole; i++) {
    file_input >> parola;
    // Alloco lo spazio per ciascuna parola
    parole[i] = new char[strlen(parola)];
    strcpy(parole[i], parola);
  }
  // Chiude il file di input
  file_input.close();

  // Apertura file di output
  file_output.open(argv[2], ios::out);
  // Salvo le parole sul secondo file, in ordine inverso
  for(int i = numero_parole - 1; i >= 0; i--) {
    file_output << parole[i] << " ";
  }
  // Chiude il file di output
  file_output.close();

  return 0;
}
