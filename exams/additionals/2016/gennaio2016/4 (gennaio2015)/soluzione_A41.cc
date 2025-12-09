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

// SOLUZIONE:

long long f1(long long fimenodue, long long fimenouno, int i, int n) {
	
	long long fn;
	
	if (i == n)
		fn = fimenodue + fimenouno;
	else
		fn = f1(fimenouno, fimenouno + fimenodue, i + 1, n);
	return fn;
}

long long f(int n) {
	
	long long fn;
	
	if (n == 0 || n == 1)
		fn = 1;
	else
		fn = f1(1, 1, 2, n);
	return fn;
}

