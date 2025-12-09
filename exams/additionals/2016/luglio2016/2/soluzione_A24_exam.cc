using namespace std;
#include <iostream>

// Inserire qui sotto la dichiarazione della funzione shift
char* shift(char vector[],const int N,int J);
// funzione ausiliaria
char* shift_ric(char vector[],const int N,int J, int i);

	
int main(){
         
	int J = 0;      
	const int N = 10;
	char vector[] = {'A', 'Z', 'E', 'I', 'K', 'P', 'N', 'F', 'D', 'J'};

	cout << "Array iniziale: ";   
	for(int i = 0; i < N; i++) {
	  cout << vector[i] << " ";
	} 
	cout << endl;

	cout << "Numero spostamenti a sinistra: ";
	cin >> J;

	char* new_vect = shift(vector, N, J);

	cout << "Nuovo array: ";
	for(int i = 0; i < N; i++) {
	  cout << new_vect[i] << " ";
	}
	cout << endl;

	delete[] new_vect;
        
	return 0;
}

// Inserire qui sotto la definizione della funzione shift
// NON HO RITORNATO UN NUOVO VETTORE

char* shift(char vector[], const int N, int J) {
	return shift_ric(vector, N, J, 0);
}

char* shift_ric(char vector[], const int N, int J, int i) {
	if(i < (N - J)) {					// finche' i e' minore della lunghezza dall'array - J, condizione dell'else (i - J)
		vector[i] = vector[i + J];		// scrivi nell'i-esima posizione l'elemento che si trova nella posizione J - 1
	} else if (i <= N) {				// i < N
		// IN QUESTO MODO ACCEDE AD UN AREA DI MEMORIA A CUI NON E' PERMESSO ACCEDERE
		vector[i] = 'Y';				// per le posizioni rimanenti scrivi Y all'interno dell'array
	}
	// chiamata ricorsiva aumentando la posizione che va a scrivere
	return shift_ric(vector, N, J, i+1);
}

