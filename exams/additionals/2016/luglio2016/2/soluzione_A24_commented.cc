using namespace std;
#include <iostream>

// Inserire qui sotto la dichiarazione della funzione shift

char* shift(char v[], int n, int j);
void left_shift(char v1[], char v2[], int n, int j, int i);
	
int main() {
	 
	int J = 0;      
	const int N = 10;
	char vector[] = {'A', 'Z', 'E', 'I', 'K', 'P', 'N', 'F', 'D', 'J'};
	
	cout << "Array iniziale: ";   
	for (int i = 0; i < N; i++) {
	cout << vector[i] << " ";
	}
	cout << endl;
	
	cout << "Numero spostamenti a sinistra: ";
	cin >> J;
	
	char* new_vect = shift(vector, N, J);
	
	cout << "Nuovo array: ";
	for (int i = 0; i < N; i++) {
		cout << new_vect[i] << " ";
	}
	cout << endl;
	
	delete[] new_vect;
	
	return 0;
}

// Inserire qui sotto la definizione della funzione shift

char* shift(char v[], int n, int j) {
	char *new_v = new char[n];			// creo un nuovo vettore formato da caratteri
	left_shift(v, new_v, n, j, 0);		// effettuo la chiamata ricorsiva 
	return new_v;						// restituisco un nuovo vettore
}  

void left_shift(char v1[], char v2[], int n, int j, int i) {
	// se la posizione del cursore eccede la lunghezza del vettore allora ritorna
	// non ha bisogno di ritornare un valore perchè il vettore è passato per valore
	if (i >= n) {
		return;
	} else {
		if (i+j < n) {
		// se la somma della posizione del cursore (i) e dello spostamento a sinistra (J)
		// non eccede la lunghezza del vettore allora scrivi nel nuovo vettore in posizione i
		// ciò che c'è scritto nel vecchio vettore in posizione i+j
			v2[i] = v1[i+j];         
		} else {
		// altrimenti scrivi il carattere 'Y' nelle posizioni rimanenti
			v2[i] = 'Y';
		}
		// effettua ricorsivamente la funzione sulla prossima posizione del cursore
		left_shift(v1, v2, n, j, i+1);
	}  
}
