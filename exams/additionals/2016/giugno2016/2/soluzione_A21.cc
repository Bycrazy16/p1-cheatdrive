using namespace std;
#include <iostream>

// Dichiarare qui sotto la funzione invert
void invert(char in[], int dim);
void invert_ric(char in[], int i, int l);

int main () {
   char sequence[30];
   int dim;

   cout << "Dimensione: ";
   cin >> dim;
   cout << "Array: ";
   for (int i = 0; i < dim; i++) {
      cin >> sequence[i];      
   }
   
   invert(sequence, dim);

   cout << "Array invertito: ";
   for (int i = 0; i < dim; i++) {
      cout << sequence[i] << " ";      
   }
   cout << endl;
   
   return 0;
}


// Definire qui sotto la funzione invert

void invert(char in[], int dim) {
   invert_ric(in, 0, dim);
}

void invert_ric(char in[], int i, int dim) {
   if (i >= dim/2) {
      return;
   } else {
      int tmp = in[dim - 1 - i];
      in[dim - 1 - i] = in[i];
      in[i] = tmp;
      invert_ric(in, i + 1, dim);
   }
}


