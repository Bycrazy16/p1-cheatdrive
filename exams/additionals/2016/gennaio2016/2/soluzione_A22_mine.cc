#include <iostream>

using namespace std;

void stampa_array(float array[], int lun);
void prodotto_array(float a1[], float a2[], float risultato[], int lun);
// Funzione ausiliaria
void prodotto_array_ric(float a1[], float a2[], float risultato[], int lun, int i);

const int SIZE = 10;

int main() {
   float vet1[] = {5.7, 9, 2.1, 7, 5.6, 5.4, 3.1, 4.3, 4.2, 2.1};
   float vet2[] = {6, 3.5, 2.6, 1.2, 1.7, 11, 2.3, 9.3, 8.7, 9.2};
   float vet3[SIZE];
   
   cout << "Array1 = ";
   stampa_array(vet1, SIZE);
   cout << endl;
   cout << "Array2 = ";
   stampa_array(vet2, SIZE);
   cout << endl;
   
   prodotto_array(vet1, vet2, vet3, SIZE);
      
   cout << "Prodotto  = ";
   stampa_array(vet3, SIZE);
   cout << endl;
   
   return 0;
}

void stampa_array(float array[], int lun) {
   for (int i = 0; i < lun; i++) {
      cout << array[i] << " ";
   }
}

// Inserire qui la definizione della funzione prodotto_array

void prodotto_array(float a1[], float a2[], float risultato[], int lun) {
	prodotto_array_ric(a1, a2, risultato, lun, 0);
}

void prodotto_array_ric(float a1[], float a2[], float risultato[], int lun, int i) {
	if (i < lun) {
		risultato[i] = a1[i] * a2[i];
		prodotto_array_ric(a1, a2, risultato, lun i + 1);
	}
}
