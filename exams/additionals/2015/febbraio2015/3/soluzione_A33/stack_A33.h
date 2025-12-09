#ifndef STACK_H
#define STACK_H

struct node {
	char val;
	node *next;
};

typedef node *stack;

enum retval {
	FALSE = 0, TRUE = 1
};
	
void init (stack &s);
void deinit (stack &s);
void push (stack &s, char val);
retval pop (stack &s);
retval nempty (const stack &s);
retval top (const stack &s, char &result);
void print (const stack &s);

#endif
