using namespace std;
#include <iostream>

const int DIM = 81;

char* estrai(const char[]);
void estrai_ric(const char[], int, char[], int);

int main () {
   char stringa[DIM + 1], *estratta, risposta;

   do {
     cout << "Inserisci la stringa da controllare: ";
     cin >> stringa;
   
     estratta = estrai(stringa);

     cout << "La stringa estratta e': " << estratta << endl;
     cout << "Vuoi inserire un'altra stringa? [s/n] ";
     cin >> risposta;
   } while (risposta != 'n' && risposta != 'N');

   return 0;
}

char* estrai(const char input[]) {
  // Allocazione dinamica
  char* output = new char[DIM + 1];
  estrai_ric(input, 0, output, 0);
  return output; 
}

void estrai_ric(const char input[], int indice_input, char output[], int indice_output) {
  char c = input[indice_input];
  if(c == '\0' || indice_input == DIM) {
    // Caso base
    output[indice_output] = '\0';
  } else { 
    // Estrazione caratteri filtrati
    if(c >= 'a' && c <= 'z') {
      output[indice_output] = c;
      indice_output++;
    }
    // Chiamata ricorsiva
    estrai_ric(input, indice_input + 1, output, indice_output);
  }
}
