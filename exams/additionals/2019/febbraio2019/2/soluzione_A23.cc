#include <iostream>

using namespace std;

void stampa_array(const long array[], int len);
long* moltiplica_array(const long b1[], const long b2[], int len);
// Funzione ausiliaria
void moltiplica_array_ric(const long b1[], const long b2[], long risultato[], int len, int i);

const int SIZE = 10;

int main() {
   long ar1[] = {5, 9, 2, 7, 5, 4, 19, 8, 1, 11};
   long ar2[] = {6, 3, 2, 1, 31, 11, 7, 9, 51, 19};
   long* ar3;
   
   cout << "Array1 = ";
   stampa_array(ar1, SIZE);
   cout << endl;
   cout << "Array2 = ";
   stampa_array(ar2, SIZE);
   cout << endl;
   
   ar3 = moltiplica_array(ar1, ar2, SIZE);
      
   cout << "Prodotto  = ";
   stampa_array(ar3, SIZE);
   cout << endl;
   
   return 0;
}

void stampa_array(const long array[], int len) {
   for (int i = 0; i < len; i++) {
      cout << array[i] << " ";
   }
}

long* moltiplica_array(const long b1[], const long b2[], int len) {
  long* risultato = new long[len];
  moltiplica_array_ric(b1, b2, risultato, len, 0);
  return risultato;
}

void moltiplica_array_ric(const long b1[], const long b2[], long risultato[], int len, int i) {
  if(i < len) {
    risultato[i] = b1[i] * b2[i];
    moltiplica_array_ric(b1, b2, risultato, len, i + 1);
  }
}
