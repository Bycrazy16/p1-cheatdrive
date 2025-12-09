using namespace std;

#include <iostream>     /* cout */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

// definizione delle funzioni
int tira_dado();

int main() {
	// init random seed
	srand (time(NULL));

int	num_lanci, somma_max;
	gioca(num_lanci, somma_max);
	cout << "Il programma termina al lancio numero "
	<< num_lanci << " con un punteggio massimo di "
	<< somma_max << endl;

	return(0);
}

int tira_dado() {
	return 1 + rand() % 6;
}
