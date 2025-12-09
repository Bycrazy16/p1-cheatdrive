using namespace std;
#include <iostream>
#include <fstream>

const int LUNGHEZZA_PAROLA = 255 + 1;	// per il termitore di riga

int main(int argc, char* argv[]) {
	// definisco gli stream
	fstream file_a, file_b, file_output;
	int maxnum;
	char tmp[LUNGHEZZA_PAROLA];
	
	// controllo dell'input utente
	if(argc != 4) {
		cerr << "Numero di argomenti non valido";
		exit(-1);
	}
	
	// apro gli stream
	my_input1.open(argc[1], ios::in);
	my_input2.open(argc[2], ios::in);
	my_output.open(argc[3], ios::out);

	
	
	// chiudo gli stream
	my_input1.close();
	my_input2.close();
	my_output.close();
	
	return 0;
}
