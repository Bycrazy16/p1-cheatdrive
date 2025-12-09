// Soluzione 2 (ricorsiva)

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int DIM_PAROLA = 50 + 1;
const char* PAROLA_STOP = "HALT";

void leggi_e_stampa(fstream& in, fstream& out);

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

  // Apertura file di output
  file_output.open(argv[2], ios::out);

  // Chiamata ricorsiva
  leggi_e_stampa(file_input, file_output);

  // Chiude i file
  file_input.close();
  file_output.close();

  return 0;
}

void leggi_e_stampa(fstream& in, fstream& out) {
  // MP: escludo il caso base
  if(!in.eof()) {
    // Buffer per una parola
    char parola[DIM_PAROLA];
    // Leggo una parola del file
    in >> parola;
    // Test sulla parola di stop
    if(strcmp(parola, PAROLA_STOP) != 0) {
      // Chiamata ricorsiva
      leggi_e_stampa(in, out);
      // Salvo la parola sul file di output
      out << parola << " ";
    }
  }
}
