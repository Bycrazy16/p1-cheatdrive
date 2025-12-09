using namespace std;

#include <iostream>
#include "stack.h"

void init(stack &s) {
	s = NULL;			// inizializza la pila
}

void deinit(stack &s) {
	node *n = s;
	while (n != NULL) {
		node *tmp = n;
		n = n->next;
		delete tmp;
	}
	s = NULL;
}

retval empty(const stack &s) {
	return (s == NULL ? TRUE : FALSE);
}

void push(stack &s, int val) {
	node *n = new node;
	n->val = val;
	n->next = s;
	s = n;				// non ho capito il significato
}

retval pop(stack &s) {
	if (empty(s))
		return FALSE;
	node *first = s;
	s = s->next;
	delete first;
	return TRUE;
}

retval top(const stack &s, int &result) {
	if (empty(s))
		return FALSE;
	result = s->val;
	return TRUE;
}

void print(const stack &s) {
	node *n = s;
	while (n != NULL) {
		cout << n->val << " ";
		n = n->next;
	}
	cout << endl;
}
