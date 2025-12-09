using namespace std;
#include <iostream>

// Dichiarare qui sotto la funzione invert
void inverti(char input[], int dimensione);
void inverti_ricorsivo(char input[], int i, int dimensione);

int main () {
	char sequenza[30];
	int dimensione;
	
	cout << "Dimensione: ";
	cin >> dimensione;
	cout << "Array: ";
	for (int i = 0; i < dimensione; i++) {
		cin >> sequenza[i];      
	}
	
	inverti(sequenza, dimensione);
	
	cout << "Array invertito: ";
	for (int i = 0; i < dimensione; i++) {
		cout << sequenza[i] << " ";      
	}
	cout << endl;
	
	return 0;
}

void inverti(char input[], int dimensione) {
	inverti_ricorsivo(input, 0, dimensione);
}

void inverti_ricorsivo(char input[], int i, int dimensione) {
	if (i >= dimensione/2) {
		return;
	} else {
		int temp;								// dichiaro una variabile temporanea
		temp = input[dimensione - i - 1];		// salvo l'ultima posizione
		input[dimensione - i - 1] = input[i];	// scrivo sull'ultima posizione l'elemento in prima posizione
		input[i] = temp;						// scrivo in prima posizione l'ultimo elemento
		inverti_ricorsivo(input, i + 1, dimensione);
	}
}
