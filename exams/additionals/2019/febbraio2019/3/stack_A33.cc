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
    bool res = false;
    if (!is_empty(s)) {
        out = s.elem[s.index-1];
        res = true;
    }
    return res;
}

bool push(stack &s, int n) 
{
    bool res = false;
    if (!is_full(s)) {
        s.elem[s.index++] = n;
        res = true;
    }
    return res;
}

bool pop(stack &s) 
{
    bool res = false;
    if (!is_empty(s)) {
        s.index--;
        res = true;
    }
    return res;
}
    
void print(const stack &s) 
{
    for (int i = 0; i < s.index; i++) {
        cout << s.elem[i] << " ";
    }
    cout << endl;
}
