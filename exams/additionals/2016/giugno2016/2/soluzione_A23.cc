using namespace std;
#include <iostream>

// Dichiarare qui sotto la funzione reverse
void reverse(long in[], int dim);
void reverse_ric(long in[], int i, int l);

int main () {
   long sequence[30];
   int dim;

   cout << "Dimensione: ";
   cin >> dim;
   cout << "Array: ";
   for (int i = 0; i < dim; i++) {
      cin >> sequence[i];      
   }
   
   reverse(sequence, dim);

   cout << "Array invertito: ";
   for (int i = 0; i < dim; i++) {
      cout << sequence[i] << " ";      
   }
   cout << endl;
   
   return 0;
}


// Definire qui sotto la funzione reverse

void reverse(long in[], int dim) {
   reverse_ric(in,0,dim);
}

void reverse_ric(long in[], int i, int dim) {
   if (i >= dim/2) {
      return;
   } else {
      int tmp = in[dim-1-i];
      in[dim-1-i] = in[i];
      in[i] = tmp;
      reverse_ric(in, i+1, dim);
   }
}


