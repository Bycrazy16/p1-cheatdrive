using namespace std;

#include <iostream>
#include <iomanip>
#include "array.h"

void readarray(int v[], int & n) {
	cout << "\ndimensione array?: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "v[" << i << "]?: ";
		cin >> v[i];
	}
}

void printarray(int v[], int n) {
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

