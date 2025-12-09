using namespace std;

#include "array.h"

const int MAXDIM = 100;

// Inserire qui le DICHIARAZIONI delle funzioni

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

// Inserire qui le DEFINIZIONI delle funzioni
