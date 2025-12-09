#include <iostream>
using namespace std;

// Dichiarare qui sotto la funzione inverti_array
void inverti_array(int in[], int dim);
void inverti_array_ric(int in[], int i, int l);

int main () {
   int array[30], dim;

   cout << "Dimensione: ";
   cin >> dim;
   cout << "Array: ";
   for (int i = 0; i < dim; i++) {
      cin >> array[i];      
   }
   
   inverti_array(array, dim);

   cout << "Array invertito: ";
   for (int i = 0; i < dim; i++) {
      cout << array[i] << " ";      
   }
   cout << endl;
   
   return 0;
}


// Definire qui sotto la funzione inverti_array

void inverti_array(int in[], int dim) {
   inverti_array_ric(in,0,dim);
}

void inverti_array_ric(int in[], int i, int dim) {
   if (i >= dim/2) {
      return;
   } else {
      int tmp = in[dim-1-i];
      in[dim-1-i] = in[i];
      in[i] = tmp;
      inverti_array_ric(in, i+1, dim);
   }
}


