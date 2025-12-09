using namespace std;

#include <iostream>
#include <iomanip>

long long f(int n);

int main() {
	int n;
	cout << "n? (n >= 0): ";
	cin >> n;
	for (int i = 0; i <= n; i++)
		cout << "f(" << setw(2) << i << ")=" << setw(10) << f(i) << endl;
	return 0;
}

// Scrivere qui la definizione della funzione ricorsiva in coda f:
