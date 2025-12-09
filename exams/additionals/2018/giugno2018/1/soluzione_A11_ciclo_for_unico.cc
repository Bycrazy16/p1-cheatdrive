#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAX_CHAR = 255 + 1;

int main(int argc,char* argv[]){
  fstream file_a, file_b, file_output;
  int maxnum_a, maxnum_b;
  char parola_a[MAX_CHAR], parola_b[MAX_CHAR];
  
  // Controllo parametri in ingresso
  if (argc != 4) {
    cerr << "Sintassi: ./a.out <file_a> <file_b> <risultato>\n";
    exit(-1);
  }

  // Apro il primo file
  file_a.open(argv[1],ios::in);
  // Controllo apertura primo file
  if(file_a.fail()) {
    cerr << "Errore apertura primo file di input\n";
    exit(-1);
  }
  // Numero righe del primo file
  file_a >> maxnum_a;
  // Apro il secondo file
  file_b.open(argv[2],ios::in);
  // Controllo apertura secondo file
  if(file_b.fail()) {
    cerr << "Errore apertura secondo file di input\n";
    exit(-1);
  }
  // Numero righe del secondo file
  file_b >> maxnum_b;
  // Apro file di output
  file_output.open(argv[3],ios::out);

  // Prima parola del primo file
  file_a >> parola_a;
  // Prima parola del secondo file
  file_b >> parola_b;
  for(int indice_a = 0, indice_b = 0; 
      indice_a < maxnum_a && indice_b < maxnum_b;) {
    // Confronto tra le parole lette nei due file
    int test = strcmp(parola_a, parola_b);
    // Verifica risultato test
    if(test == 0) {
      // Sono uguali; allora la parola va salvata
      file_output << parola_a << endl;
      // E vanno letti entrambi i file
      file_a >> parola_a;
      file_b >> parola_b;
      // E aggiornati entrambi gli indici
      indice_a++;
      indice_b++;
    } else if(test < 0) {
      // "parola_a" precede "parola_b"; allora
      // leggo dal primo file
      file_a >> parola_a;
      // E aggiorno l'indice
      indice_a++;
    } else {
      // "parola_b" precede "parola_a"; allora
      // leggo dal secondo file
      file_b >> parola_b;
      // E aggiorno l'indice
      indice_b++;
    }
  }

  // Chiusura stream primo file
  file_a.close();
  // Chiusura stream secondo file
  file_b.close();
  // Chiusura stream file di output
  file_output.close();

  return(0);
}
