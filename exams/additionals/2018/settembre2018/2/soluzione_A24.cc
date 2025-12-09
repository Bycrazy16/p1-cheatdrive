#include <iostream>

using namespace std;

void stampa_array(double array[], int num);
void aggiungi_array(double x1[], double x2[], double risultato[], int num);
// Funzione ausiliaria
void aggiungi_array_ric(double x1[], double x2[], double risultato[], int num, int i);

const int SIZE = 10;

int main() {
   double ar1[] = {7.3, 2, 5.2, 7.8, 10, 15, 9.0, 8.1, 5, 13};
   double ar2[] = {6.2, 3.1, 14.7, 1, 19.4, 11.1, 27, 2.9, 8.1, 20.5};
   double ar3[SIZE];
   
   cout << "Array1 = ";
   stampa_array(ar1, SIZE);
   cout << endl;
   cout << "Array2 = ";
   stampa_array(ar2, SIZE);
   cout << endl;
   
   aggiungi_array(ar1, ar2, ar3, SIZE);
      
   cout << "Somma  = ";
   stampa_array(ar3, SIZE);
   cout << endl;
   
   return 0;
}

void stampa_array(double array[], int num) {
   for (int i = 0; i < num; i++) {
      cout << array[i] << " ";
   }
}

// Inserire qui la definizione della funzione aggiungi_array

void aggiungi_array(double x1[], double x2[], double risultato[], int num) {
  aggiungi_array_ric(x1, x2, risultato, num, 0);
}

void aggiungi_array_ric(double x1[], double x2[], double risultato[], int num, int i) {
  if(i < num) {
    risultato[i] = x1[i] + x2[i];
    aggiungi_array_ric(x1, x2, risultato, num, i + 1);
  }
}
