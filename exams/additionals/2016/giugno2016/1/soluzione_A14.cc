#include <iostream>
#include <iomanip>
using namespace std;

double valoreAssoluto(double valore);
double pot(double x, int n);
double fatt(double x);
double meno_coseno_iperbolico(double x, int nmax, double epsilon);

int main () {
  double epsilon, x;
  int nmax;

  cout << "Inserisci il massimo numero di termini dell'approssimazione nmax: ";
  cin >> nmax;
  cout << "Inserisci l'errore massimo epsilon: ";
  cin >> epsilon;

  char c;
  do {
    cout << "Inserisci il valore x in cui vuoi calcolare -cosh(x): ";
    cin >> x;
    cout << "L'approssimazione di -cosh(x) e': " << setprecision(10) 
         << meno_coseno_iperbolico(x, nmax, epsilon) << endl;
    cout << "Continuare (s/n)? ";
    cin >> c;
  } while(c != 'n' && c != 'N');

  return(0);
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

double fatt(double x) {
  // Fattoriale (ricorsivo)
  if (x == 0.0) {
    return 1.0;
  } else {
    return x * fatt(x - 1);
  }
}

double meno_coseno_iperbolico(double x, int nmax, double epsilon) {
  double risultato, passo_precedente;
  // Condizioni iniziali
  risultato = 0.0;
  int i = 0;
  // Doppia condizione di uscita
  do {
    // Salvo lo step precedente
    passo_precedente = risultato;
    // Sommo l'i-esimo termine della serie
    risultato -= pot(x, 2 * i) / fatt(2 * i);
    // Incremento il contatore
    i++;
  } while(i <= nmax && 
          valoreAssoluto(risultato - passo_precedente)
          >= epsilon * valoreAssoluto(passo_precedente));
  return risultato;
}
