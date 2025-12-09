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

// a b c d e
void invert_ric(char in[], int i, int dim) {
   if (i >= dim/2) {				// si ferma a metà array in quanto è già ordinata
      return;						// nel nostro esempio entra in c e non fa nulla
   } else {							// in quanto 5/2 = 2, 1 = 3 esce dalla funzione
      int tmp = in[dim - 1 - i];	// tmp = e;
      in[dim - 1 - i] = in[i];		// in[5-1-0] = a; a va in ultima posizione
      in[i] = tmp;					// in[0] = a -> e; e va in prima posizione
      invert_ric(in, i + 1, dim);
   }
}
