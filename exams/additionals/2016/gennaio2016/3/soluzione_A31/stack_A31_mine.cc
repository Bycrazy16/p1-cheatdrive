using namespace std;
#include "stack.h"
#include <iostream>

static bool is_full(const stack &s) {
	return s.index == s.dim;
}

static bool is_empty(const stack &s) {
	return s.index == 0;
}

void init(stack &s, int maxdim) {
	s.index = 0;
	s.dim = maxdim;
	s.elem = new double[maxdim];
}

void deinit(stack &s) {
	delete[] s.elem;
}

bool push(stack &s, double n) {
	if(is_full(s)) {
		return false;
	}
	s.elem[index] = n;
	s.index++;
}

bool top(const stack &s, double &out) {
	if(is_empty(s)) {
		return false;
	} else {
		out = s.elem[index-1];
		return true;
	}
}

bool pop(stack &s) {
	if(is_empty(s)) {
		return false;
	} else {
		s.index--;
		return true;
	}
}

void print(const stack &s) {
	if(is_empty) {
		cout << "La pila e' vuota!" << endl;
	}
	for(int i = 0; i < s.index; i++) {
		cout << "[ " << i << "]: " << s.elem[i] << endl;
	}
}
