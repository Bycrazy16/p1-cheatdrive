#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 1000;

bool palindroma(char * stringa, char *& err);

int main() {
  int n;
  char a[SIZE];
  char * b;

  do {
    if (palindroma(a, b))
      cout << "La frase `" << a << "' e` palindroma\n";
    else 
      cout << "La sotto-frase `" << b << "' non e` palindroma\n";     
    cout << "\nImmetti un'altra frase che ritieni palindroma: ";
    cin.getline(a,SIZE);
  } while (a[0] != '\0');

  return 0;
}
