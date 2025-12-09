#include <iostream>

using namespace std;

void stampa_array(const double array[], int num);
double* aggiungi_array(const double x1[], const double x2[], int num);
// Funzione ausiliaria
void aggiungi_array_ric(const double x1[], const double x2[], double risultato[], int num, int i);

const int SIZE = 10;

int main() {
   double ar1[] = {7.3, 2, 5.2, 7.8, 10, 15, 9.0, 8.1, 5, 13};
   double ar2[] = {6.2, 3.1, 14.7, 1, 19.4, 11.1, 27, 2.9, 8.1, 20.5};
   double* ar3;
   
   cout << "Array1 = ";
   stampa_array(ar1, SIZE);
   cout << endl;
   cout << "Array2 = ";
   stampa_array(ar2, SIZE);
   cout << endl;
   
   ar3 = aggiungi_array(ar1, ar2, SIZE);
      
   cout << "Somma  = ";
   stampa_array(ar3, SIZE);
   cout << endl;
   
   return 0;
}

void stampa_array(const double array[], int num) {
   for (int i = 0; i < num; i++) {
      cout << array[i] << " ";
   }
}

double* aggiungi_array(const double x1[], const double x2[], int num) {
  double* risultato = new double[num];
  aggiungi_array_ric(x1, x2, risultato, num, 0);
  return risultato;
}

void aggiungi_array_ric(const double x1[], const double x2[], double risultato[], int num, int i) {
  if(i < num) {
    risultato[i] = x1[i] + x2[i];
    aggiungi_array_ric(x1, x2, risultato, num, i + 1);
  }
}
