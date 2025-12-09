#ifndef STACK_STRUCT_H
#define STACK_STRUCT_H

using namespace std;
#include <iostream>


enum retval {FAIL,OK};

struct nodo{
  int val;
  nodo *next;
};

typedef nodo * stack ;

void init(stack & );
void deinit(stack & );
retval push (int, stack &);
retval top (int &, const stack &);
retval pop (stack &);
void print(const stack &);

#endif
