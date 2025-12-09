using namespace std;

#include <iostream>
#include <fstream>
#include <cstring>

// dichiarazioni costanti
const int MAX_PAROLE = 10000;
const int LUNGHEZZA_MAX_PAROLA = 100;

// NON VIENE UTILIZZATA (!)
void inserisciSenzaDoppioni(char parola[LUNGHEZZA_MAX_PAROLA + 1],
							char array[][LUNGHEZZA_MAX_PAROLA + 1],
							int& lunghezzaArray);

int main (int argc, char* argv[]) {
	
	// apertura stream
	fstream primo, secondo, output;
	// stream temporaneo
	char tmp[LUNGHEZZA_MAX_PAROLA + 1]

	// contatori
	int parolePrimoFile = 0;
	int paroleIntersezione = 0;
	
	// string di inserimento
	char parole[MAX_PAROLE][LUNGHEZZA_MAX_PAROLA + 1];
	
	// stringa contenente le parole comuni ai due file in input
	char intersezione[MAX_PAROLE][LUNGHEZZA_MAX_PAROLA + 1];
	
	// controllo input utente
	if (argc != 4) {
		cerr << "Utilizzo: ./a.out <primo_file> <secondo_file> <file_di_output>\n";
		return -1;
	}
	
	// apertura degli stream
	primo.open(argc[1], ios::in);
	secondo.open(argc[2], ios::in);
	output.open(argc[3], ios::out);
	
	// LETTURA DEL PRIMO FILE
	primo >> tmp;
	while(!primo.eof()) {
		// Inserimento della prima parola letta in fondo al primo array
		strcpy(parole[parolePrimoFile], tmp);				// in modo da essere paragonato con lo stream temporaneo
		// Aggiorna l'indice
		parolePrimoFile++;
		// Lettura prossima parola
		primo >> tmp
	}
	
	// LETTURA DEL SECONDO FILE
	// COSTRUZIONE DELL'INSIEME DELLE PAROLE COMUNI AI DUE FILE
	secondo >> tmp;
	while(!secondo.eof()) {
		// variabili utili
		int i = 0;
		bool trovata = false;
		// RICERCA DELLA PAROLA LETTA TRA QUELLE DEL PRIMO FILE
		while (i < parolePrimoFile && !trovata) {			// condizione di permanenza nel ciclo
			if(strcmp(tmp, parole[i]) == 0) {				// paragona lo stream temporaneo all'i-esimo elemento 
				trovata = true;
			}
			i++;
		}
		
		if (trovata) {
			// Allora devo aggiungere una nuova parola
			// all'array contenente le parole comuni ai due file
			strcpy(intersezione[paroleIntersezione], tmp);	// copia 
			// Aggiorna l'indice
			paroleIntersezione++;
		}
		secondo >> tmp;
	}
	
	// SCRITTURA SUL FILE DI OUTPUT
	for(int i = o; i < paroleIntersezione; i++) {
		output << intersezione[i] << endl;
	}
	
	// chiusura degli stream
	primo.close();
	secondo.close();
	output.close();
	
	return (0); 
	}
}
