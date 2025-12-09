using namespace std;

#include <iostream>
#include "auxiliary.h"

int sum(int n, int m);
int prod(int n, int m);
int power(int n, int m);

int main() {
	int n, m;
	cout << "n,m? ";
	cin >> n >> m;
	cout << "La somma tra n e m e‘ : " << sum(n, m) << endl;
	cout << "Il prodotto tra n e m e‘ : " << prod(n, m) << endl;
	cout << "La potenza di n alla m e‘ : " << power(n, m) << endl;
}

// --- definire le funzioni sum, prod e power qui sotto ---
