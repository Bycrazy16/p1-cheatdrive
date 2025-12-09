#include <iostream>
#include <iomanip>

using namespace std;

double valoreAssoluto(double valore);
double pot(double x, int n);
double calcola(double x, int n, double epsilon);

int main() {
	double epsilon, x;
	int n;
	
	cout << "Inserisci il numero di termini dell'approssimazione: ";
	cin >> n;
	cout << "Inserisci l'errore massimo epsilon: ";
	cin >> epsilon;
	
	char c;
	do {
		cout << "Inserisci il valore x in cui vuoi calcolare f(x) = x / (1 - x) ^ 2: ";
		cin >> x;
		while (x >= 1 || x <= -1) {
			cout << "Valore errato, prego reintrodurre (-1 < x < 1): ";
			cin >> x;
		}
		cout << "L'approssimazione di f(x) e': ";
		cout << setprecision(10) << calcola(x, n, epsilon);
		cout << endl;
		cout << "Continuare (s/n)? ";
		cin >> c;
	} while (c != 'n' && c != 'N');
	
	return (0);
}

double valoreAssoluto(double valore) {
	return valore < 0 ? -valore : valore;
}

double pot(double x, int n) {
	// Potenza (ricorsiva)
	if (n == 0) {
		return 1.0;
	} else {
		return x * pot(x, n - 1);
	}
}

double calcola(double x, int n, double epsilon) {
	double risultato, passo_precedente;
	// Condizioni iniziali
	risultato = 0.0;
	int i = 0;
	// Doppia condizione di uscita
	do {
		// Salvo lo step precedente
		passo_precedente = risultato;
		// Sfasatura rispetto al conteggio dei passi iterativi
		int indice = i + 1;
		// Sommo l'i-esimo termine della serie
		risultato += indice * pot(x, indice);
		// Incremento il contatore
		i++;
	} while (i < n && valoreAssoluto(risultato - passo_precedente) >= epsilon);
	
	return risultato;
}
