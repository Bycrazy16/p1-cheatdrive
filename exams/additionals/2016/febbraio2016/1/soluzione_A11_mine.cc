#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	
	fstream my_input, my_output;
	char temp[30 + 1];
	
	my_input.open(argc[1], ios::in);	// apro lo stream in lettura
	my_output.open(argc[2], ios::out);	// apro lo stream in scrittura
	
	if(argc != 3) {						// controllo l'input dell'utente
		cerr << "Numero di argomenti non valido";
		exit(-1);						// EXIT_ON_FAILURE
	}
	
	// chiudo gli stream
	my_input.close();
	my_output.close();
}
