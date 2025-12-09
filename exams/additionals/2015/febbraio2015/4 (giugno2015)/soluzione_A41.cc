using namespace std;

#include "array.h"

const int MAXDIM = 100;

void swap(int & a, int & b);
void push_max_upfront_rec(int v[], int i, int k);
void push_max_upfront(int v[], int k);
void bubblesort(int v[], int n);

int main() {
	int myarray[MAXDIM];
	int dim;
	/*
	int myarray[MAXDIM] = {41,3,9,1,5,17,6,20,37,2,8,23,10,0,11,19};
	int dim = 16;
	bubblesort(myarray,dim);
	printarray(myarray,dim);
	*/
	readarray(myarray, dim);
	bubblesort(myarray, dim);
	printarray(myarray, dim);
}

void swap(int & a, int & b) {
	int c = a;
	a = b;
	b = c;
}

// sposta il max da v[i] a v[k] in posizione v[k]
void push_max_upfront_rec(int v[], int i, int k) {
	if (i < k) {
		if (v[i] > v[i + 1])
			swap(v[i], v[i + 1]);
		push_max_upfront_rec(v, i + 1, k);
	}
}

// sposta il max da v[0] a v[k] in posizione v[k]
void push_max_upfront(int v[], int k) {
	push_max_upfront_rec(v, 0, k);
}

void bubblesort(int v[], int n) {
	if (n > 0) {
		push_max_upfront(v, n - 1);
		bubblesort(v, n - 1);
	}
}
