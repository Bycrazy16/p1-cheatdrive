#include <iostream>
using namespace std;

long prodotto_somma_incrociata(int a[], int b[], int dim);
long prodotto_somma_incrociata_ric(int a[], int b[], int indice, int dim);

int main() {
  int primo[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int secondo[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
  
  cout << "Il prodotto delle somme incrociate dei due array e' " <<
    prodotto_somma_incrociata(primo, secondo, 10) << endl;

  return 0;
}

long prodotto_somma_incrociata(int a[], int b[], int dim) {
  return prodotto_somma_incrociata_ric(a, b, 0, dim);
}

long prodotto_somma_incrociata_ric(int a[], int b[], int indice, int dim) {
  long ris = 1l;
  if(indice < dim) {
    ris = (a[indice] + b[(indice + 1) % dim]) * 
      prodotto_somma_incrociata_ric(a, b, indice + 1, dim);
  }
  return ris;
}
