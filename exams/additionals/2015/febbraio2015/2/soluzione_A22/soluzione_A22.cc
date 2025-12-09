#include <iostream>
#include <cmath>		/* sqrt */
#include "array.h"		/* leggi, stampa, MAX_DIM */

using namespace std;

double calcola_norma_ricorsivo(long arr[], int n, long sum);
void dividi_ricorsivo(long source[], double dest[], double norma, int n);
double* normalizza(long source[], int dim);

int main() {
	long array[MAX_DIM];
	int dim;
	leggi(array, dim);
	double* normalizzato = normalizza(array, dim);
	cout << "Array normalizzato: " << endl;
	stampa(normalizzato, dim);
	return 0;
}

double calcola_norma_ricorsivo(long arr[], int n, long sum) {
	double res;
	if (n < 0) {
		res = sqrt(sum);
	} else {
		sum += arr[n] * arr[n];
		res = calcola_norma_ricorsivo(arr, n - 1, sum);
	}
	return res;
}

void dividi_ricorsivo(long source[], double dest[], double norma, int n) {
	if (n >= 0) {
		dest[n] = source[n] / norma;
		dividi_ricorsivo(source, dest, norma, n - 1);
	}
}

double* normalizza(long source[], int dim) {
	double* normalizzato = new double[dim];
	double norma = calcola_norma_ricorsivo(source, dim - 1, 0);
	dividi_ricorsivo(source, normalizzato, norma, dim - 1);
	
	return normalizzato;
}
