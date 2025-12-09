#include <iostream>
using namespace std;

// Dichiarare qui sotto la funzione rovescia_array
void rovescia_array(float in[], int dim);
void rovescia_array_ric(float in[], int i, int l);

int main () {
   float array[30], dim;

   cout << "Dimensione: ";
   cin >> dim;
   cout << "Array: ";
   for (int i = 0; i < dim; i++) {
      cin >> array[i];      
   }
   
   rovescia_array(array, dim);

   cout << "Array rovesciato: ";
   for (int i = 0; i < dim; i++) {
      cout << array[i] << " ";      
   }
   cout << endl;
   
   return 0;
}


// Definire qui sotto la funzione rovescia_array

void rovescia_array(float in[], int dim) {
   rovescia_array_ric(in,0,dim);
}

void rovescia_array_ric(float in[], int i, int dim) {
   if (i >= dim/2) {
      return;
   } else {
      int tmp = in[dim-1-i];
      in[dim-1-i] = in[i];
      in[i] = tmp;
      rovescia_array_ric(in, i+1, dim);
   }
}


