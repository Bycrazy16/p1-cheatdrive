#include <iostream>
#include <string>

using namespace std;

const char SEGNAPOSTO = '!';
const int DIMMAX = 40;

// Dichiarare qui sotto la funzione reverse_array
void reverse_array(char* in, int dim);
bool vocale_minuscola(char c);

int main (int argc, char* argv[]) {
	char input[DIMMAX];
	cout << "Introdurre stringa da invertire: ";
	cin >> input;
	
	// Assumiamo che sia sempre strlen(input) < DIMMAX
	reverse_array(input, strlen(input));
	cout << "Array invertito: " << input << endl;
	
	return 0;
}

// Definire qui sotto la funzione reverse_array

void reverse_array(char* in, int dim) {
	if(dim > 0) {
		if (vocale_minuscola(in[dim-1]) && vocale_minuscola(in[0])) {
			in[dim - 1] = in[0] = SEGNAPOSTO;
		} else if (vocale_minuscola(in[dim-1])) {
			in[dim-1] = in[0];
			in[0] = SEGNAPOSTO;
		} else if (vocale_minuscola(in[0])) {
			in[0] = in[dim-1];
			in[dim-1] = SEGNAPOSTO;
		} else {
			char tmp = in[dim-1];
			in[dim-1] = in[0];
			in[0] = tmp;
		}
		reverse_array(in + 1, dim - 2);
	}
}

bool vocale_minuscola(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
