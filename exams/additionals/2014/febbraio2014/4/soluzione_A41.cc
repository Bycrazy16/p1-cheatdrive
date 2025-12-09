#include <iostream>
#include <iomanip>

using namespace std;

const int DIM = 16;

void printarray(int v[], int min, int max);
void swap(int & a, int & b);
void sposta(int v[], int p, int u, int & piv);
void ordina1(int v[], int primo, int ultimo);
void ordina(int v[], int n);

int main() {
	// Esempio
	int myarray[DIM] = { 41, 3, 9, 1, 5, 17, 6, 20, 37, 2, 8, 23, 10, 0, 11, 19 };
	printarray(myarray, 0, DIM - 1);
	cout << endl;
	ordina(myarray, DIM);
	printarray(myarray, 0, DIM - 1);
}

void printarray(int v[], int min, int max) {
	int i;
	cout << "[";
	for (i = min; i <= max; i++) {
		cout << setw(2) << v[i] << " ";
	}
	cout << "]\n";
}

void swap(int & a, int & b) {
	int c = a;
	a = b;
	b = c;
}

void sposta(int v[], int p, int u, int & piv) {
	if (p >= u) {
		swap(v[p], v[piv]);
		piv = p;
	} else if (v[p] <= v[piv]) {
		sposta(v, p + 1, u, piv);
	} else if (v[u] >= v[piv]) {
		sposta(v, p, u - 1, piv);
	} else { // v[p] > v[piv] > v[u] 
		swap(v[p], v[u]);
		sposta(v, p + 1, u - 1, piv);
	}
}

void ordina1(int v[], int primo, int ultimo) {
	if (primo < ultimo) {
		int piv = ultimo;
		sposta(v, primo, ultimo, piv);
		ordina1(v, primo, piv - 1);
		ordina1(v, piv + 1, ultimo);
	}
}

void ordina(int v[], int n) {
	ordina1(v, 0, n - 1);
}
