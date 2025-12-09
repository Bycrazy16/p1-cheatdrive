#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int LUNGHEZZA_PAROLA = 255 + 1;	// per il termitore di riga

// Funzioni di utilita'
bool appartiene(char* s, char* lista[], int quanti);
bool appartiene(char* s, char* lista[], int inf, int sup);

int main(int argc, char* argv[]) {
	fstream file_a, file_b, file_output;	// definisco gli stream
	int maxnum;
	char parola[LUNGHEZZA_PAROLA];			// stringa che utilizzerò come stringa temporanea
	
	// controllo dell'input utente
	if(argc != 4) {
		cerr << "Numero di argomenti non valido";
		exit(-1);
	}
	
	// Apro il secondo file
	my_input2.open(argc[2], ios::in);
	// Prendo in ingresso il numero di righe presenti nel file
	file_b >> maxnum
	// Alloco dinamicamente un'array di stringhe
	// e lo inizializzo ad una stringa lunga quanto la parola più lunga
	char** parole = new char* [maxnum];
	// inizializzo un contatore
	int i = 0;
	
	// Prendo in ingresso la prima parola del secondo file e la salvo nella stringa appena creata
	file_b >> parola;
	// Finchè non raggiungo la file del file
	while (!file_b.eof()) {
		// Alloco dinamicamente la serie di parole memorizzate nell'array di stringhe
		parole[i] = new char[strlen(parola) + 1];
		
		strcpy(parole[i], parola);
		
		// Continua la lettura del file
		file_b >> parola;
		// Incrementa il contatore delle parole lette
		i++;
	}
	// A questi punto, il file_b non serve più quindi chiudo lo stream
	file_b.close();
	
	// Apri il primo file
	file_a.open(argv[1], ios::in);
	// Apro il file di output
	file_output.open(argv[3], ios::out);
	
	// Leggo e scarto il numero di righe del primo file
	// perchè non mi serve e quindi non lo utilizzo
	// ma devo portarmi una riga sotto
	file_a >> parola;
	
	while(!file_a.eof()) {
		// Se la parola non e' presente anche in file_b,
		// allora la salva nel file di output
		if (!appartiene(parola, parole, maxnum)) {
			file_output << parola << endl;
		}
		
		// Continua la lettura del file
		file_a >> parola;
	}
	// Chiusura dello stream del primo file
	file_a.close();
	// Chiusura dello stream del file di outoput
	file_output.close();
	
	return(0);
}

bool appartiene(char* s, char* lista[], int quanti) {
	bool trovato = false;
	
	// Ricerca per bisezione (ricorsiva)
	trovato = appartiene(s, lista, 0, quanti - 1);
	// Ritorno il risultato
	return trovato;
}
	
bool appartiene(char* s, char* lista[], int inf, int sup) {
	
	bool ris = false;
	
	if (inf <= sup) {
		
		int mid = (inf + sup) / 2;
		int cmp = strcmp(s, lista[mid]);
		
		if (cmp == 0) {
			ris = true;
		} else if (cmp < 0) {	// 
			ris = appartiene(s, lista, inf, mid - 1);
		} else {				// 
			ris = appartiene(s, lista, mid + 1, sup);
		}
	}
	return ris;
}
