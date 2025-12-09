using namespace std;
#include "stack.h"
#include <iostream>

static bool is_empty(const stack &s)
{
    return s.index == 0;
}

static bool is_full(const stack &s) 
{
    return s.index == s.dim;
}

void init(stack &s, int maxdim)
{
    s.index = 0;
    s.dim = maxdim;
    s.elem = new int[maxdim];
}

void deinit(stack &s)
{
    delete[] s.elem;
}

bool top(const stack &s, int &out) 
{
    if (is_empty(s)) {
        return false;
    } else {
        out = s.elem[s.index-1];
        return true;
    }
}

bool push(stack &s, int n) 
{
    if (is_full(s)) {
        return false;
    } else {
        s.elem[s.index++] = n;
        return true;
    }
}
    
bool pop(stack &s) 
{
    if (is_empty(s)) {
        return false;
    } else {
        s.index--;
        return true;
    }
}
    
void print(const stack &s) 
{
    for (int i = 0; i < s.index; i++) {
        cout << s.elem[i] << " ";
    }
    cout << endl;
}
